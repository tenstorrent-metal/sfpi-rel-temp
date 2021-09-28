///////////////////////////////////////////////////////////////////////////////
// sfpi.h: SFPu Interface
//   This file provides a C++ wrapper around GCC style __builtin functions
//   which map to SFPU instructions.
//
// Note: Op refers to "Operation" while Operand is spelled out.  Usually.
//
// Local Register (LREG) Operations:
//   class VecUShort
//   class VecShort
//   class VecHalf
//
//   These classes are the workhorse classes of sfpi.  Operators are
//   overloaded to provide functionality such as:
//     VecHalf a, b, c, d;
//     VecHalf d = a * b + c;
//
//   Mathematical operations such as the above are supported out to the level
//   of a MAD so the above won't work if you add an extra operator at the
//   end.
//
//   The classes also support conditional operators for use in conjunction
//   with the CCCtrl class to enable predicated execution, for example:
//     VecHalf a;
//     (a < 5.0F)
//   will load an immediate value of 5.0F into an LReg, perform the subtract
//   and test the result to set the CC.
//
//   Additional operations such as load immediate, extract/set exp, etc are
//   supported through class methods.
//
//
// Offset Operand:
//   constexpr OffsetOperand half;
//
//   There is a special operand called half to access Grayskull's ability to
//   bias math operations by 0.5F, used as:
//       d = a * b + c + half;
//   which will collapse down into a single SFPU instruction.
//
//
// Destination Register:
//   class DReg
//   constexpr RegFile<DReg, 64> dregs;
//
//   The Destination Register is modeled by a global variable which is
//   essentially an array of class Dreg.  DRegs provide much the same
//   functionality as LRegs, eg, the following is legal:
//       dregs[0] = dregs[1] * dregs[2] + dregs[3];
//   The above is expanded out to load local registers, perform the operation
//   and store back into the destination register.  Any missing functionality
//   (eg, there is no load immediate) can be added later if needed or accessed
//   through LRegs.
//
//
// Constant Local Registers:
//   class CReg
//   constexpr CReg CReg_0p692871094(5);
//
//   The constant value local registers are used in expressions by referencing
//   one of the names above and using them in mathematical operations such as:
//       a = b * c + CReg_0p692871094;
//
// Predicated Execution:
//   class CCCtrl
//   macros p_if(), p_elseif(), p_else, p_endif
//
//   The class CCCtrl is used in conjunction with the LReg based classes to
//   enable predicated execution.  By convention the test infastructure indents
//   the code as if executing if/then/else in C++, for example:
//     CCCtrl cc;
//     VecHalf v = dregs[0];
//     cc.cc_if(v < 5.0F); {
//         // if side
//     } cc.cc_else(); {
//         // else side
//     }
//     cc.cc_endif();
//   The above chatter is reduced w/ use of macros listed above.  The macros
//   also balance {} to auto-destruct the CCCtrl when appropriate.
//
//  Boolean Operators:
//   && and || are handled by building a tree of operations and traversing
//   this at compile time, all with 0 run time overhead.  This requires some
//   compromises.  Ideally, this would be handled by an inline recursive
//   function, which gcc can do, but not with "always_inline".  Instead, the
//   emit() function uses a macro to expand out to 3 levels of recursiion.
//   This is ripe for moving into the compiler.
//
//  Internals:
//   The idea behind this wrapper is that it all collapses down to
//   typically one and sometimes more SFPU instructions at compile time
//   without any runtime overhead.  Many of the classes below are used to
//   track operations/operands as the compiler parses the code and then at a
//   trigger operation (eg, assignment) the operation gets expanded into an
//   instruction.  All of this working relies on compiling w/ optimization
//   enabled (-O) and that the vectors never get written to the stack.
//
//  Variable Liveness with Predicated Execution
//   The compiler does not understand predication and so if a variable is
//   assigned, then letter written to within a conditional, it will assume
//   this variable was dead in between the two statements and so re-assign
//   the register resulting in badness.  This is summarized as: "The
//   compiler should not conclude that a variable is dead just because a
//   subsequent assignment is inside a conditional".
//
//   This is avoided through a combined compiler/wrapper implementation as
//   follows:
//     1) All instructions which modify the CC bump a counter (including each
//        of those used within boolean operators)
//     2) Variables are tagged, at initial assignment, with the counter
//     3) Subsequent assignments at a higher counter level pass the variable
//        into the operator as an argument (preserving liveness)
//     4) endif resets the counter to the level outside the associated if
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <type_traits>
#include "sfpi_internal.h"

namespace sfpi {

enum ExExpDebias {
    ExExpDoDebias = SFPEXEXP_MOD1_DEBIAS,
    ExExpNoDebias = SFPEXEXP_MOD1_NODEBIAS,
};
enum ExExpCC {
    ExExpCCLT0 = SFPEXEXP_MOD1_SET_CC_SGN_EXP,
    ExExpCCComp = SFPEXEXP_MOD1_SET_CC_COMP_EXP,
    ExExpCCGTE0 = SFPEXEXP_MOD1_SET_CC_SGN_COMP_EXP,
};
enum ExManPad {
    ExManPad9 = SFPEXMAN_MOD1_PAD9,
    ExManPad8 = SFPEXMAN_MOD1_PAD8,
};
enum LzCC {
    LzCCNE0 = SFPLZ_MOD1_CC_NE0,
    LzCCEQ0 = SFPLZ_MOD1_CC_EQ0
};
enum IAddCC {
    IAddCCLT0 = SFPIADD_MOD1_CC_LT0,
    IAddCCGTE0 = SFPIADD_MOD1_CC_GTE0
};
enum LUTOffset {
    LUTOffsetNone = SFPLUT_MOD0_BIAS_NONE,
    LUTOffsetPos = SFPLUT_MOD0_BIAS_POS,
    LUTOffsetNeg = SFPLUT_MOD0_BIAS_NEG
};
enum LUTSgn {
    LUTSgnUpdate = SFPLUT_MOD0_SGN_UPDATE,
    LUTSgnRetain = SFPLUT_MOD0_SGN_RETAIN,
};

//////////////////////////////////////////////////////////////////////////////
enum class OpType {
    Add,
    Sub,
    Mul
};

//////////////////////////////////////////////////////////////////////////////
// Forward declarations
class CReg;
class Vec;
class VecHalf;
class VecShort;
class VecUShort;
class SubBaseOp;
class AddShortOp;
class MulOp;
class CondComp;
class CondOpExExp;
class CondOpIAddI;
class CondOpIAddV;
class CondOpLz;
class CondBool;
class CondOp;
class CCCtrlBase;

template <OpType opType> class BinaryOp;
typedef BinaryOp<OpType::Add> AddOp;
typedef BinaryOp<OpType::Sub> SubOp;

//////////////////////////////////////////////////////////////////////////////
template<class Type, int N>
class RegFile {

public:
    constexpr Type operator[](const int x) const;
};

//////////////////////////////////////////////////////////////////////////////
class RegBase {
protected:
    int reg;

public:
    constexpr explicit RegBase(int r) : reg(r) {}
    constexpr int get() const { return reg; }
};

class RegBaseInitializer {
    int n;

 public:
    constexpr RegBaseInitializer(int in) : n(in) {}
    constexpr int get() const { return n; }
};

//////////////////////////////////////////////////////////////////////////////
class DReg : public RegBase {
private:
    template<class Type, int N> friend class RegFile;
    constexpr explicit DReg(const RegBaseInitializer i) : RegBase(i.get() * SFP_DESTREG_STRIDE) {}

public:
    // Assign register to register
    template <typename vecType, typename std::enable_if_t<std::is_base_of<Vec, vecType>::value>* = nullptr>
    sfpi_inline void operator=(const vecType vec) const;
    sfpi_inline void operator=(const DReg dreg) const;
    sfpi_inline void operator=(const CReg creg) const;
    sfpi_inline void operator=(const float f) const;
    sfpi_inline void operator=(const int i) const;

    // Construct operator classes from operations
    sfpi_inline AddOp operator+(const VecHalf b) const;
    sfpi_inline AddOp operator+(const CReg b) const;
    sfpi_inline SubOp operator-(const VecHalf b) const;
    sfpi_inline VecHalf operator-() const;
    sfpi_inline MulOp operator*(const VecHalf b) const;
    sfpi_inline MulOp operator*(const CReg b) const;

    // Conditionals
    sfpi_inline CondComp operator==(const float x) const;
    sfpi_inline CondComp operator!=(const float x) const;
    sfpi_inline CondComp operator<(const float x) const;
    sfpi_inline CondComp operator>=(const float x) const;

    // Decompose and assign operations to destination register
    template <typename opType, typename std::enable_if_t<std::is_base_of<SubBaseOp, opType>::value>* = nullptr>
    sfpi_inline void operator=(const opType& op) const;
};

//////////////////////////////////////////////////////////////////////////////
class CReg : public RegBase {
public:
    constexpr explicit CReg(int r) : RegBase(r) {}

    // Construct operator classes from operations
    sfpi_inline AddOp operator+(const VecHalf b) const;
    sfpi_inline AddOp operator+(const CReg b) const;
    sfpi_inline SubOp operator-(const VecHalf b) const;
    sfpi_inline MulOp operator*(const VecHalf b) const;
    sfpi_inline MulOp operator*(const CReg b) const;
};

//////////////////////////////////////////////////////////////////////////////
class Vec {
protected:
    bool initialized;
    __rvtt_vec_t v;

public:
    sfpi_inline Vec() : initialized(false) {}

    sfpi_inline __rvtt_vec_t get() const { return v; }
    sfpi_inline __rvtt_vec_t& get() { return v; }

    // Associate variable w/ a value pre-loaded into a particular lreg
    sfpi_inline void load_lreg(int i);
};

//////////////////////////////////////////////////////////////////////////////
class VecHalf : public Vec {
public:
    VecHalf() = default;

    sfpi_inline VecHalf(const DReg dreg);
    sfpi_inline VecHalf(const float f) { loadi_f16b(f); }
    sfpi_inline VecHalf(const __rvtt_vec_t& t) { initialized = true; v = t; }

    // Construct VecHalf by assigning from an operator (eg, VecHalf a = b + c)
    template <typename opType, typename std::enable_if_t<std::is_base_of<SubBaseOp, opType>::value>* = nullptr>
    sfpi_inline VecHalf(const opType& op) { initialized = true; v = op.get_result(); }

    // Assign operations to VecHalf
    template <typename opType, typename std::enable_if_t<std::is_base_of<SubBaseOp, opType>::value>* = nullptr>
    sfpi_inline void operator=(const opType& op) { initialized = true; v = op.get_result(); }
    sfpi_inline void operator=(const float f) { loadi_f16b(f); }
    sfpi_inline void operator*=(const VecHalf);
    sfpi_inline void operator+=(const VecHalf);
    sfpi_inline void operator-=(const VecHalf);

    // Conversion
    template <typename vType, typename std::enable_if_t<std::is_base_of<Vec, vType>::value>* = nullptr>
    sfpi_inline vType reinterpret() const { return vType(v); }

    // Immediate loads
    sfpi_inline void loadi_f16a(const float val);
    sfpi_inline void loadi_f16b(const float val);
    sfpi_inline void loadi_bits_16a(const unsigned int val);
    sfpi_inline void loadi_bits_16b(const unsigned int val);

    // Construct operator from operations
    sfpi_inline AddOp operator+(const VecHalf b) const;
    sfpi_inline AddOp operator+(const CReg b) const;
    sfpi_inline SubOp operator-(const VecHalf b) const;
    sfpi_inline VecHalf operator-() const;
    sfpi_inline MulOp operator*(const VecHalf b) const;
    sfpi_inline MulOp operator*(const CReg b) const;
    sfpi_inline VecHalf operator+(const float val) const;
    sfpi_inline void operator+=(const float val);
    sfpi_inline VecHalf operator*(const float val) const;
    sfpi_inline void operator*=(const float val);

    // Conditionals
    sfpi_inline CondComp operator==(const float x) const;
    sfpi_inline CondComp operator!=(const float x) const;
    sfpi_inline CondComp operator<(const float x) const;
    sfpi_inline CondComp operator>=(const float x) const;

    // More complex operations
    sfpi_inline VecShort ex_exp(const ExExpDebias debias) const;
    sfpi_inline VecShort ex_man(ExManPad pad) const;

    sfpi_inline VecHalf set_exp(const unsigned int exp) const;
    sfpi_inline VecHalf set_exp(const VecShort src) const;
    sfpi_inline VecHalf set_man(const unsigned int man) const;
    sfpi_inline VecHalf set_man(const VecShort src) const; // Grayskull HW bug, is this useful?
    sfpi_inline VecHalf set_sgn(const unsigned int sgn) const;
    sfpi_inline VecHalf set_sgn(const VecHalf src) const;
    sfpi_inline VecHalf set_sgn(const VecShort src) const;

    // Misc
    sfpi_inline void add_exp(const VecHalf src, const int exp);
    sfpi_inline void lut(const VecUShort l0, const VecUShort l1, const VecUShort l2, LUTSgn sgn = LUTSgnUpdate, LUTOffset offset = LUTOffsetNone);
    sfpi_inline VecHalf abs() const;
    sfpi_inline VecShort lz() const;

    static sfpi_inline unsigned int f32_to_f16a(const float val);
    static sfpi_inline unsigned int f32_to_f16b(const float val);
};

//////////////////////////////////////////////////////////////////////////////
class VecShort : public Vec {
private:

public:
    VecShort() = default;

    sfpi_inline VecShort(const __rvtt_vec_t& in) { initialized = true; v = in; }
    sfpi_inline VecShort(short val) { *this = val; }

    sfpi_inline explicit operator VecUShort() const;

    // Assignment
    sfpi_inline void operator=(__rvtt_vec_t& in) { initialized = true; v = in; }
    sfpi_inline void operator=(int val) { loadi(val); }
    sfpi_inline void operator=(const AddShortOp& op);

    // Conversion
    template <typename vType, typename std::enable_if_t<std::is_base_of<Vec, vType>::value>* = nullptr>
    sfpi_inline vType reinterpret() const { return vType(v); }

    // Operations
    sfpi_inline VecShort operator&(const VecShort b) const;
    sfpi_inline void operator&=(const VecShort b);
    sfpi_inline VecShort operator|(const VecShort b) const;
    sfpi_inline void operator|=(const VecShort b);
    sfpi_inline VecShort operator~() const;

    sfpi_inline AddShortOp operator+(int val) const;
    sfpi_inline VecShort operator+(const VecShort& val) const;
    sfpi_inline VecShort operator+(const CReg& creg) const;
    sfpi_inline VecShort operator-(int val) const;
    sfpi_inline VecShort operator-(const VecShort& val) const;
    sfpi_inline VecShort operator-(const CReg& creg) const;
    sfpi_inline void operator+=(int val);
    sfpi_inline void operator+=(const VecShort& val);
    sfpi_inline void operator+=(const CReg& creg);
    sfpi_inline void operator-=(int val);
    sfpi_inline void operator-=(const VecShort& val);
    sfpi_inline void operator-=(const CReg& creg);

    // Immediate load
    sfpi_inline void loadi(int val);

    // Conditionals
    sfpi_inline const CondOpExExp ex_exp_cc(VecHalf src, const ExExpDebias debias, const ExExpCC cc);
    sfpi_inline const CondOpLz lz_cc(const Vec src, LzCC cc);
    sfpi_inline const CondOpIAddI add_cc(const VecShort src, int val, IAddCC cc);
    sfpi_inline const CondOpIAddV add_cc(const VecShort src, IAddCC cc);
    sfpi_inline const CondOpIAddV add_cc(const CReg src, IAddCC cc);

    // Note: compare is against 12 bit sign extended value
    sfpi_inline const CondComp operator==(int val) const;
    sfpi_inline const CondComp operator!=(int val) const;
    sfpi_inline const CondOpIAddI operator<(int val);
    sfpi_inline const CondOpIAddI operator>=(int val);

    sfpi_inline const CondOpIAddV operator<(const VecShort src);
    sfpi_inline const CondOpIAddV operator>=(const VecShort src);

    sfpi_inline VecShort abs() const;
    sfpi_inline VecShort lz() const;
};

//////////////////////////////////////////////////////////////////////////////
class VecUShort : public Vec {
private:

public:
    VecUShort() = default;
    sfpi_inline VecUShort(const __rvtt_vec_t& in) { initialized = true; v = in; }
    sfpi_inline VecUShort(unsigned int val) { *this = val; }

    // Assignment
    sfpi_inline void operator=(const __rvtt_vec_t& in) { initialized = true; v = in; }
    sfpi_inline void operator=(unsigned int val) { loadi(val); }
    sfpi_inline explicit operator VecShort() const { return VecShort(v); }

    // Conversion
    template <typename vType, typename std::enable_if_t<std::is_base_of<Vec, vType>::value>* = nullptr>
    sfpi_inline vType reinterpret() const { return vType(v); }

    // Operations
    sfpi_inline VecUShort operator&(const VecUShort b) const;
    sfpi_inline void operator&=(const VecUShort b);
    sfpi_inline VecUShort operator|(const VecUShort b) const;
    sfpi_inline void operator|=(const VecUShort b);
    sfpi_inline VecUShort operator~() const;

    sfpi_inline VecUShort operator<<(unsigned int amt) const;
    sfpi_inline VecUShort operator>>(unsigned int amt) const;
    sfpi_inline void operator<<=(unsigned int amt);
    sfpi_inline void operator>>=(unsigned int amt);
    sfpi_inline VecUShort shft(const VecShort amt) const;

    // Immediate load
    sfpi_inline void loadi(unsigned int val);

    // Conditionals
    sfpi_inline const CondOpLz lz_cc(const Vec src, LzCC cc);
    sfpi_inline VecShort lz() const;
};

//////////////////////////////////////////////////////////////////////////////
class Operand {
public:
    enum class Type {
        Null,
        Vec,
        VecPtr,
        CReg,
        Float,
    };

private:
    const Type kind;

    union {
        // Some __builtins require the dst LREG as an Operand, can't be const
        // Ripe for const abuse
        const void* const null_ptr;
        const Vec vec;
        Vec* const vec_ptr;
        const unsigned int uint_val;
        const float float_val;
    };

    const bool negate;

public:
    sfpi_inline Operand() : kind(Type::Null), null_ptr(nullptr), negate(false) {}
    sfpi_inline Operand(const Vec v, bool neg = false) : kind(Type::Vec), vec(v), negate(neg) {}
    sfpi_inline Operand(Vec* const v, bool neg = false) : kind(Type::VecPtr), vec_ptr(v), negate(neg) {}
    sfpi_inline Operand(const CReg c, bool neg = false) : kind(Type::CReg), uint_val(c.get()), negate(neg) {}
    sfpi_inline Operand(const float v) : kind(Type::Float), float_val(v), negate(false) {}

    sfpi_inline Type get_type() const { return kind; }
    sfpi_inline bool is_neg() const { return negate; }

    sfpi_inline const Vec get_vec() const { return vec; }
    sfpi_inline Vec* const get_vec_ptr() const { return vec_ptr; }
    sfpi_inline const unsigned int get_creg() const { return uint_val; }
    sfpi_inline const float get_float() const { return float_val; }
};

//////////////////////////////////////////////////////////////////////////////
class OffsetOperand {};

//////////////////////////////////////////////////////////////////////////////
// All Ops inherit from this to conditionally enable template instances
// based on if the type is an Op
class SubBaseOp {
protected:
    static sfpi_inline const __rvtt_vec_t mad_helper(const Operand opA, const Operand opB, const Operand opC, unsigned int offset);
};

//////////////////////////////////////////////////////////////////////////////
template <int num_ops>
class BaseOp : protected SubBaseOp {
public:
    enum OperandIdx {
        OperandIdxA,
        OperandIdxB,
        OperandIdxC
    };

protected:
    const Operand operands[num_ops];

public:
    template <class typeA, class typeB>
    sfpi_inline BaseOp(const typeA a, const typeB b, bool negB = false) : operands{Operand(a), Operand(b, negB)} {}

    sfpi_inline BaseOp(const Operand a, const Operand b) : operands{a, b} {}

    template <class typeA, class typeB, class typeC>
    sfpi_inline BaseOp(const typeA a, const typeB b, const typeC c) : operands{a, b, c} {}

    sfpi_inline BaseOp(const Operand a, const Operand b, const Operand c) : operands{a, b, c} {}

    template <class typeC>
    sfpi_inline BaseOp(const Operand a, const Operand b, const typeC c, bool negC = false) : operands{a, b, Operand(c, negC)} {}

    sfpi_inline const VecHalf get_vec(OperandIdx idx) const;
    sfpi_inline const unsigned int get_creg(OperandIdx idx) const { return operands[idx].get_creg(); }
};

//////////////////////////////////////////////////////////////////////////////
class MadOp : public BaseOp<3> {
protected:
    unsigned int offset;

    sfpi_inline MadOp(const Operand a, const Operand b, const Operand c, const unsigned int off) : BaseOp(a, b, c), offset(off) {}

public:
    template <class typeA, class typeB, class typeC>
    sfpi_inline MadOp(const typeA a, const typeB b, const typeC c, const unsigned int off = SFPMAD_MOD1_OFFSET_NONE) : BaseOp(a, b, c), offset(off) {}

    template <class typeA, class typeB, class typeC>
    sfpi_inline MadOp(const typeA a, const typeB b, const typeC c, const bool negC) : BaseOp(a, b, c, negC), offset(SFPMAD_MOD1_OFFSET_NONE) {}

    sfpi_inline MadOp operator+(OffsetOperand offset) const { return MadOp(this->operands[OperandIdxA], this->operands[OperandIdxB], this->operands[OperandIdxC], SFPMAD_MOD1_OFFSET_POSH); }
    sfpi_inline MadOp operator-(OffsetOperand offset) const { return MadOp(this->operands[OperandIdxA], this->operands[OperandIdxB], this->operands[OperandIdxC], SFPMAD_MOD1_OFFSET_NEGH); }

    sfpi_inline unsigned int get_offset() const { return offset; };
    sfpi_inline const __rvtt_vec_t get_result() const;
};

//////////////////////////////////////////////////////////////////////////////
template <OpType opType>
class BinaryOp : public BaseOp<2> {
private:

protected:
    unsigned int offset;

public:
    template <class typeA, class typeB, OpType thisOp = opType, typename std::enable_if_t<thisOp != OpType::Sub>* = nullptr>
    sfpi_inline BinaryOp<opType>(const typeA a, const typeB b) : BaseOp(a, b), offset(SFPMAD_MOD1_OFFSET_NONE) {}

    template <class typeA, class typeB, OpType thisOp = opType, typename std::enable_if_t<thisOp == OpType::Sub>* = nullptr>
    sfpi_inline BinaryOp<opType>(const typeA a, const typeB b) : BaseOp(a, b, true), offset(SFPMAD_MOD1_OFFSET_NONE) {}

    template <class typeA, class typeB>
    sfpi_inline BinaryOp<opType>(const typeA a, const typeB b, const unsigned int off) : BaseOp(a, b), offset(off) {}

    sfpi_inline BinaryOp<opType> operator+(OffsetOperand offset) const { return BinaryOp<opType>(this->operands[OperandIdxA], this->operands[OperandIdxB], SFPMAD_MOD1_OFFSET_POSH); }
    sfpi_inline BinaryOp<opType> operator-(OffsetOperand offset) const { return BinaryOp<opType>(this->operands[OperandIdxA], this->operands[OperandIdxB], SFPMAD_MOD1_OFFSET_NEGH); }

    sfpi_inline unsigned int get_offset() const { return offset; };
    sfpi_inline const __rvtt_vec_t get_result() const;
};

//////////////////////////////////////////////////////////////////////////////
// Multiply operations (require extra methods to build the Mad Ops)
class MulOp : public BinaryOp<OpType::Mul> {
public:
    template <class typeA, class typeB>
    sfpi_inline MulOp(const typeA a, const typeB b) : BinaryOp<OpType::Mul>(a, b) {}
    template <class typeA, class typeB>
    sfpi_inline MulOp(const typeA a, const typeB b, const unsigned int off) : BinaryOp<OpType::Mul>(a, b, off) {}

    sfpi_inline MulOp operator+(OffsetOperand offset) const { return MulOp(this->operands[OperandIdxA], this->operands[OperandIdxB], SFPMAD_MOD1_OFFSET_POSH); }
    sfpi_inline MulOp operator-(OffsetOperand offset) const { return MulOp(this->operands[OperandIdxA], this->operands[OperandIdxB], SFPMAD_MOD1_OFFSET_NEGH); }

    sfpi_inline MadOp operator+(const VecHalf c) const;
    sfpi_inline MadOp operator+(const CReg c) const;
    sfpi_inline MadOp operator-(const VecHalf c) const;
};

//////////////////////////////////////////////////////////////////////////////
class AddShortOp {
 private:
    const __rvtt_vec_t src;
    const unsigned int imm;

 public:
    sfpi_inline AddShortOp(__rvtt_vec_t in, const int v) : src(in), imm(v) {}
    sfpi_inline void emit(__rvtt_vec_t& result, bool& initialized) const;
};

//////////////////////////////////////////////////////////////////////////////
// Handle conditionals.  Leaves are CondOp, CondBool builds trees of Bools and
// CondOp
class CondOperand {
public:
    enum class Type {
        CondOp,
        CondBool,
    };

private:
    const Type type;
    union {
        const CondOp* const op;
        const CondBool* const cond;
    };

public:
    sfpi_inline CondOperand(const CondOp& a) : type(Type::CondOp), op(&a) {}
    sfpi_inline CondOperand(const CondBool& a) : type(Type::CondBool), cond(&a) {}

    sfpi_inline Type get_type() const { return type; }
    sfpi_inline const CondBool& get_cond() const { return *cond; }
    sfpi_inline const CondOp& get_op() const { return *op; }

    sfpi_inline void emit() const;
};

//////////////////////////////////////////////////////////////////////////////
// Build a tree of conditionals as the compiler parses them
// Traverse the tree at emit time to generate the code
class CondBool {
public:
    enum class CondBoolType {
        Or,
        And,
    };

private:
    const CondBoolType type;
    CondOperand op_a;
    CondOperand op_b;
    bool negate;

public:
    sfpi_inline CondBool(CondBoolType t, const CondOp& a, const CondOp& b) : type(t), op_a(a), op_b(b), negate(false) {}
    sfpi_inline CondBool(CondBoolType t, const CondOp& a, const CondBool& b) : type(t), op_a(a), op_b(b), negate(false) {}
    sfpi_inline CondBool(CondBoolType t, const CondBool& a, const CondOp& b) : type(t), op_a(a), op_b(b), negate(false) {}
    sfpi_inline CondBool(CondBoolType t, const CondBool& a, const CondBool& b) : type(t), op_a(a), op_b(b), negate(false) {}

    sfpi_inline const CondBool operator!() const;

    sfpi_inline const CondBool operator&&(const CondOp& b) const { return CondBool(CondBoolType::And, *this, b); }
    sfpi_inline const CondBool operator||(const CondOp& b) const { return CondBool(CondBoolType::Or, *this, b); }
    sfpi_inline const CondBool operator&&(const CondBool& b) const { return CondBool(CondBoolType::And, *this, b); }
    sfpi_inline const CondBool operator||(const CondBool& b) const { return CondBool(CondBoolType::Or, *this, b); }

    sfpi_inline CondBoolType get_type() const { return type; }
    sfpi_inline CondBoolType get_neg_type() const { return (type == CondBoolType::Or) ? CondBoolType::And : CondBoolType::Or; }
    sfpi_inline const CondOperand& get_op_a() const { return op_a; }
    sfpi_inline const CondOperand& get_op_b() const { return op_b; }

    sfpi_inline void emit(bool negate = false) const;
};

//////////////////////////////////////////////////////////////////////////////
class CondOp {
protected:
    enum class CondOpType {
        Evaluated,
        CompareFloat,
        CompareShort,
        ExExp,
        Lz,
        IAddI,
        IAddV
    };

private:
    const CondOpType type;
    const Operand op_a;
    Operand op_b;
    const int imm;
    unsigned int mod1;
    unsigned int neg_mod1;

public:
    sfpi_inline CondOp(CondOpType t) : type(t), op_a(), op_b(), imm(0), mod1(0), neg_mod1(0) {}

    template <class typeA, class typeB>
    sfpi_inline CondOp(CondOpType t, const typeA a, const typeB b, int i, unsigned int m, unsigned int nm) : type(t), op_a(a), op_b(b), imm(i), mod1(m), neg_mod1(nm) {}

    template <class typeA>
    sfpi_inline CondOp(CondOpType t, const typeA a, Vec* const b, int i, unsigned int m, unsigned int nm) : type(t), op_a(a), op_b(b), imm(i), mod1(m), neg_mod1(nm) {}

    template <class typeA>
    sfpi_inline CondOp(CondOpType t, const typeA a, int i, unsigned int m, unsigned int nm) : type(t), op_a(a), op_b(), imm(i), mod1(m), neg_mod1(nm) {}

    template <class typeA>
    sfpi_inline CondOp(CondOpType t, const typeA a, const float b, int i, unsigned int m, unsigned int nm) : type(t), op_a(a), op_b(b), imm(i), mod1(m), neg_mod1(nm) {}

    sfpi_inline CondOp(CondOpType t, const VecShort a, int i, unsigned int m, unsigned int nm);

    // Negate
    sfpi_inline const CondOp operator!() const;

    // Create boolean operations from conditional operations
    sfpi_inline const CondBool operator&&(const CondOp& b) const { return CondBool(CondBool::CondBoolType::And, *this, b); }
    sfpi_inline const CondBool operator||(const CondOp& b) const { return CondBool(CondBool::CondBoolType::Or, *this, b); }
    sfpi_inline const CondBool operator&&(const CondBool& b) const { return CondBool(CondBool::CondBoolType::And, *this, b); }
    sfpi_inline const CondBool operator||(const CondBool& b) const { return CondBool(CondBool::CondBoolType::Or, *this, b); }

    sfpi_inline void emit(bool negate) const;
};

//////////////////////////////////////////////////////////////////////////////
// Conditional Comparison
class CondComp : public CondOp {
public:
    enum CondCompOpType {
        CompLT0 = SFPSETCC_MOD1_LREG_SIGN,
        CompNE0 = SFPSETCC_MOD1_LREG_NE0,
        CompGTE0 = SFPSETCC_MOD1_LREG_GTE0,
        CompEQ0 = SFPSETCC_MOD1_LREG_EQ0,
    };

private:
    sfpi_inline CondCompOpType not_cond(const CondCompOpType t) const;

public:
    template <class type>
    sfpi_inline CondComp(const CondCompOpType t, const type a, const float b) : CondOp(CondOpType::CompareFloat, a, b, 0, t, not_cond(t)) {}

    template <class type>
    sfpi_inline CondComp(const CondCompOpType t, const type a, const int b) : CondOp(CondOpType::CompareShort, a, b, t, not_cond(t)) {}
};

//////////////////////////////////////////////////////////////////////////////
// Conditional Operations

class CondOpExExp : public CondOp {
    sfpi_inline ExExpCC not_cond(ExExpCC cc) const;

public:
    sfpi_inline CondOpExExp(Vec* const d, const Vec s, ExExpDebias debias, ExExpCC cc) : CondOp(CondOpType::ExExp, s, d, 0, debias | cc, debias | not_cond(cc)) {}
};

class CondOpLz : public CondOp {
    sfpi_inline LzCC not_cond(LzCC cc) const;

public:
    sfpi_inline CondOpLz(Vec* const d, const Vec s, LzCC cc) : CondOp(CondOpType::Lz, s, d, 0, cc, not_cond(cc)) {}
};

class CondOpIAddI : public CondOp {
    sfpi_inline IAddCC not_cond(IAddCC cc) const;

public:
    sfpi_inline CondOpIAddI(const Vec s, IAddCC cc, int imm) : CondOp(CondOpType::IAddI, s, imm, cc | SFPIADD_MOD1_ARG_IMM, not_cond(cc) | SFPIADD_MOD1_ARG_IMM) {}
    sfpi_inline CondOpIAddI(Vec* const d, const Vec s, IAddCC cc, int imm) : CondOp(CondOpType::IAddI, s, d, imm, cc | SFPIADD_MOD1_ARG_IMM, not_cond(cc) | SFPIADD_MOD1_ARG_IMM) {}
};

class CondOpIAddV : public CondOp {
    sfpi_inline IAddCC not_cond(IAddCC cc) const;

public:
    sfpi_inline CondOpIAddV(Vec* d, const Vec s, IAddCC cc) : CondOp(CondOpType::IAddV, s, d, 0, cc | SFPIADD_MOD1_ARG_LREG_DST, not_cond(cc) | SFPIADD_MOD1_ARG_LREG_DST) {}
    sfpi_inline CondOpIAddV(Vec d, const Vec s, IAddCC cc) : CondOp(CondOpType::IAddV, s, d, 0, cc | SFPIADD_MOD1_ARG_LREG_DST, not_cond(cc) | SFPIADD_MOD1_ARG_LREG_DST) {}

    sfpi_inline CondOpIAddV(Vec* d, const CReg s, IAddCC cc) : CondOp(CondOpType::IAddV, s, d, 0, cc | SFPIADD_MOD1_ARG_LREG_DST, not_cond(cc) | SFPIADD_MOD1_ARG_LREG_DST) {}
};

class CondOpEvaluated : public CondOp {
public:
    sfpi_inline CondOpEvaluated(const CondOp& op) : CondOp(CondOpType::Evaluated) { op.emit(false); }
};


//////////////////////////////////////////////////////////////////////////////
class CCCtrl {
protected:
    int push_count;

    sfpi_inline void pop();

public:
    sfpi_inline CCCtrl(bool dopush);

    sfpi_inline void cc_if(const CondOperand& op) const;
    sfpi_inline void cc_if(const CondOp& op) const;
    sfpi_inline void cc_else() const;
    sfpi_inline void cc_elseif(const CondOperand& cond);
    sfpi_inline void cc_elseif(const CondOp& cond);
    sfpi_inline void cc_endif();

    sfpi_inline void push();

    static sfpi_inline void enable_cc();
};

class CCCtrlOpt : public CCCtrl {
public:
    sfpi_inline CCCtrlOpt();

    sfpi_inline ~CCCtrlOpt();
};

//////////////////////////////////////////////////////////////////////////////
constexpr CReg CReg_0(CREG_IDX_0);
constexpr CReg CReg_0p692871094(CREG_IDX_0P692871094);
constexpr CReg CReg_Neg_1p00683594(CREG_IDX_NEG_1P00683594);
constexpr CReg CReg_1p442382813(CREG_IDX_1P442382813);
constexpr CReg CReg_0p836914063(CREG_IDX_0P836914063);
constexpr CReg CReg_Neg_0p5(CREG_IDX_NEG_0P5);
constexpr CReg CReg_1(CREG_IDX_1);
constexpr CReg CReg_Neg_1(CREG_IDX_NEG_1);
constexpr CReg CReg_0p001953125(CREG_IDX_0P001953125);
constexpr CReg CReg_Neg_0p67480469(CREG_IDX_NEG_0P67480469);
constexpr CReg CReg_Neg_0p34472656(CREG_IDX_NEG_0P34472656);
constexpr CReg CReg_TileId(CREG_IDX_TILEID);

constexpr RegFile<DReg, 64> dregs;
constexpr OffsetOperand kHalf;

//////////////////////////////////////////////////////////////////////////////
template<class TYPE, int N>
constexpr TYPE RegFile<TYPE, N>::operator[](const int x) const {
    return TYPE(RegBaseInitializer(x));
}

sfpi_inline AddOp DReg::operator+(const VecHalf b) const {return AddOp(VecHalf(*this), b); }
sfpi_inline AddOp DReg::operator+(const CReg b) const { return AddOp(VecHalf(*this), b); }
sfpi_inline SubOp DReg::operator-(const VecHalf b) const { return SubOp(VecHalf(*this), b); }
sfpi_inline MulOp DReg::operator*(const VecHalf b) const  { return MulOp(VecHalf(*this), b); }
sfpi_inline MulOp DReg::operator*(const CReg b) const  { return MulOp(VecHalf(*this), b); }
sfpi_inline CondComp DReg::operator==(const float x) const {return CondComp(CondComp::CompEQ0, VecHalf(*this), x); }
sfpi_inline CondComp DReg::operator!=(const float x) const { return CondComp(CondComp::CompNE0, VecHalf(*this), x); }
sfpi_inline CondComp DReg::operator<(const float x) const { return CondComp(CondComp::CompLT0, VecHalf(*this), x); }
sfpi_inline CondComp DReg::operator>=(const float x) const { return CondComp(CondComp::CompGTE0, VecHalf(*this), x); }

template <>
sfpi_inline void DReg::operator=(const VecHalf vec) const
{
    // For  half, rebias
    __builtin_rvtt_sfpstore_v(vec.get(), SFPSTORE_MOD0_FLOAT_REBIAS_EXP, reg);
}

template <typename vecType, typename std::enable_if_t<std::is_base_of<Vec, vecType>::value>*>
sfpi_inline void DReg::operator=(const vecType vec) const
{
    // For short/ushort, do not rebias
    __builtin_rvtt_sfpstore_v(vec.get(), SFPSTORE_MOD0_INT, reg);
}

sfpi_inline void DReg::operator=(const DReg dreg) const
{
    VecHalf tmp = dreg;
    __builtin_rvtt_sfpstore_v(tmp.get(), SFPSTORE_MOD0_FLOAT_REBIAS_EXP, reg);
}

sfpi_inline void DReg::operator=(const CReg creg) const
{
    __builtin_rvtt_sfpstore_r(creg.get(), SFPSTORE_MOD0_FLOAT_REBIAS_EXP, reg);
}

sfpi_inline void DReg::operator=(float f) const
{
    VecHalf v;
    v.loadi_f16b(f);
    *this = v;
}

sfpi_inline void DReg::operator=(int i) const
{
    VecShort v;
    v.loadi(i);
    *this = v;
}

template <typename opType, typename std::enable_if_t<std::is_base_of<SubBaseOp, opType>::value>*>
sfpi_inline void DReg::operator=(const opType& op) const
{
    __builtin_rvtt_sfpstore_v(op.get_result(), SFPSTORE_MOD0_FLOAT_REBIAS_EXP, reg);
}

sfpi_inline VecHalf DReg::operator-() const
{
    VecHalf tmp = *this;
    __rvtt_vec_t result = __builtin_rvtt_sfpmov(tmp.get(), SFPMOV_MOD1_COMPSIGN);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();

    return result;
}

//////////////////////////////////////////////////////////////////////////////
sfpi_inline AddOp CReg::operator+(const CReg b) const { return AddOp(*this, b); }
sfpi_inline MulOp CReg::operator*(const CReg b) const { return MulOp(*this, b); }
sfpi_inline AddOp CReg::operator+(const VecHalf b) const { return AddOp(*this, b); }
sfpi_inline SubOp CReg::operator-(const VecHalf b) const { return SubOp(*this, b); }
sfpi_inline MulOp CReg::operator*(const VecHalf b) const { return MulOp(*this, b); }

//////////////////////////////////////////////////////////////////////////////
sfpi_inline void Vec::load_lreg(int val)
{
    initialized = true;

    switch (val) {
    case 0:
        v = __builtin_rvtt_sfploadl0(0);
        break;
    case 1:
        v = __builtin_rvtt_sfploadl1(0);
        break;
    case 2:
        v = __builtin_rvtt_sfploadl2(0);
        break;
    case 3:
        v = __builtin_rvtt_sfploadl3(0);
        break;
    default:
        break;
    }
}

//////////////////////////////////////////////////////////////////////////////
sfpi_inline AddOp VecHalf::operator+(const VecHalf b) const { return AddOp(*this, b); }
sfpi_inline AddOp VecHalf::operator+(const CReg b) const { return AddOp(*this, b); }
sfpi_inline SubOp VecHalf::operator-(const VecHalf b) const { return SubOp(*this, b); }
sfpi_inline MulOp VecHalf::operator*(const VecHalf b) const { return MulOp(*this, b); }
sfpi_inline MulOp VecHalf::operator*(const CReg b) const { return MulOp(*this, b); }
sfpi_inline CondComp VecHalf::operator==(const float x) const { return CondComp(CondComp::CompEQ0, *this, x); }
sfpi_inline CondComp VecHalf::operator!=(const float x) const { return CondComp(CondComp::CompNE0, *this, x); }
sfpi_inline CondComp VecHalf::operator<(const float x) const { return CondComp(CondComp::CompLT0, *this, x); }
sfpi_inline CondComp VecHalf::operator>=(const float x) const { return CondComp(CondComp::CompGTE0, *this, x); }

sfpi_inline void VecHalf::operator*=(const VecHalf m)
{
    v = __builtin_rvtt_sfpmad_vvr(v, m.get(), CReg_0.get(), SFPMAD_MOD1_OFFSET_NONE);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecHalf::operator+=(const VecHalf a)
{
    v = __builtin_rvtt_sfpmad_vrv(v, CReg_1.get(), a.get(), SFPMAD_MOD1_OFFSET_NONE);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecHalf::operator-=(const VecHalf a)
{
    v = __builtin_rvtt_sfpmad_vrv(v, CReg_1.get(), (-a).get(), SFPMAD_MOD1_OFFSET_NONE);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline VecHalf::VecHalf(const DReg dreg)
{
    v = initialized ?
        __builtin_rvtt_sfpload_lv(v, SFPLOAD_MOD0_REBIAS_EXP, dreg.get()) :
        __builtin_rvtt_sfpload(SFPLOAD_MOD0_REBIAS_EXP, dreg.get());
    initialized = true;
}

sfpi_inline VecHalf VecHalf::operator-() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpmov(v, SFPMOV_MOD1_COMPSIGN);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecHalf VecHalf::operator+(const float val) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpaddi(tmp, f32_to_f16b(val), 0);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecHalf::operator+=(const float val)
{
    v = __builtin_rvtt_sfpaddi(v, f32_to_f16b(val), 0);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline VecHalf VecHalf::operator*(const float val) const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpmuli(v, f32_to_f16b(val), 0);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline void VecHalf::operator*=(const float val)
{
    v = __builtin_rvtt_sfpmuli(v, f32_to_f16b(val), 0);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecHalf::loadi_bits_16a(const unsigned int val)
{
    v = initialized ?
        __builtin_rvtt_sfploadi_lv(v, SFPLOADI_MOD0_FLOATA, val) :
        __builtin_rvtt_sfploadi(SFPLOADI_MOD0_FLOATA, val);
    initialized = true;
}

sfpi_inline void VecHalf::loadi_bits_16b(const unsigned int val)
{
    v = initialized ?
        __builtin_rvtt_sfploadi_lv(v, SFPLOADI_MOD0_FLOATB, val) :
        __builtin_rvtt_sfploadi(SFPLOADI_MOD0_FLOATB, val);
    initialized = true;
}

sfpi_inline unsigned int VecHalf::f32_to_f16a(const float val)
{
    union {
        float vfloat;
        unsigned int vui;
    } tmp;

    // TTFIXME: this doesn't handle large/small values correctly.  Do we care?
    tmp.vfloat = val;

    return ((tmp.vui >> 16) &0x8000) | ((((tmp.vui & 0x7F800000) - 0x38000000) >> 13) & 0x7c00) | ((tmp.vui >> 13) & 0x03FF);
}

sfpi_inline void VecHalf::loadi_f16a(const float val)
{
    v = initialized ?
        __builtin_rvtt_sfploadi_lv(v, SFPLOADI_MOD0_FLOATA, f32_to_f16a(val)) :
        __builtin_rvtt_sfploadi(SFPLOADI_MOD0_FLOATA, f32_to_f16a(val));
    initialized = true;
}

sfpi_inline unsigned int VecHalf::f32_to_f16b(const float val)
{
    union {
        float vfloat;
        unsigned int vui;
    } tmp;

    tmp.vfloat = val;
    return tmp.vui >> 16;
}

sfpi_inline void VecHalf::loadi_f16b(const float val)
{
    v = initialized ?
        __builtin_rvtt_sfploadi_lv(v, SFPLOADI_MOD0_FLOATB, f32_to_f16b(val)) :
        __builtin_rvtt_sfploadi(SFPLOADI_MOD0_FLOATB, f32_to_f16b(val));
    initialized = true;
}

sfpi_inline VecShort VecHalf::ex_exp(ExExpDebias debias) const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpexexp(v, debias);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecShort VecHalf::ex_man(ExManPad pad) const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpexman(v, pad);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecHalf VecHalf::set_exp(const unsigned int exp) const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpsetexp_i(exp, v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecHalf VecHalf::set_exp(const VecShort exp) const
{
    // Odd: dst is both exponent and result so undergoes a type change
    // If exp is not used later, compiler renames tmp and doesn't issue a mov
    __rvtt_vec_t tmp = exp.get();
    tmp = __builtin_rvtt_sfpsetexp_v(tmp, v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecHalf::add_exp(const VecHalf in, const int exp)
{
    initialized = true;
    v = __builtin_rvtt_sfpdivp2(exp, in.get(), SFPSDIVP2_MOD1_ADD);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline VecHalf VecHalf::set_man(const unsigned int man) const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpsetman_i(man, v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecHalf VecHalf::set_man(const VecShort man) const
{
    // Grayskull HW bug, is this useful?  Should there be a "Half" form?
    // Odd: dst is both man and result so undergoes a type change
    // If man is not used later, compiler renames tmp and doesn't issue a mov
    __rvtt_vec_t tmp = man.get();
    tmp = __builtin_rvtt_sfpsetman_v(tmp, v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline VecHalf VecHalf::set_sgn(const unsigned int sgn) const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpsetsgn_i(sgn, v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecHalf VecHalf::set_sgn(const VecHalf sgn) const
{
    // Odd: dst is both sgn and result so undergoes a type change
    // If sgn is not used later, compiler renames tmp and doesn't issue a mov
    __rvtt_vec_t tmp = sgn.get();
    tmp = __builtin_rvtt_sfpsetsgn_v(tmp, v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline VecHalf VecHalf::set_sgn(const VecShort sgn) const
{
    // Odd: dst is both sgn and result so undergoes a type change
    // If sgn is not used later, compiler renames tmp and doesn't issue a mov
    __rvtt_vec_t tmp = sgn.get();
    tmp = __builtin_rvtt_sfpsetsgn_v(tmp, v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline VecShort VecHalf::lz() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfplz(v, SFPLZ_MOD1_CC_NONE);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecHalf VecHalf::abs() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpabs(v, SFPABS_MOD1_FLOAT);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline void VecHalf::lut(const VecUShort l0, const VecUShort l1, const VecUShort l2,
                         LUTSgn sgn, LUTOffset offset)
{
    initialized = true;
    v = __builtin_rvtt_sfplut(l0.get(), l1.get(), l2.get(), v, sgn | offset);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

//////////////////////////////////////////////////////////////////////////////
sfpi_inline void VecShort::operator=(const AddShortOp& op) { op.emit(v, initialized); }
sfpi_inline AddShortOp VecShort::operator+(int val) const { return AddShortOp(v, val); }
sfpi_inline const CondOpExExp VecShort::ex_exp_cc(VecHalf src, const ExExpDebias debias, const ExExpCC cc) { return CondOpExExp(this, src, debias, cc); }
sfpi_inline const CondOpLz VecShort::lz_cc(const Vec src, LzCC cc) { return CondOpLz(this, src, cc); }
sfpi_inline const CondOpIAddI VecShort::add_cc(const VecShort src, int val, IAddCC cc) { return CondOpIAddI(this, src, cc, val); }
sfpi_inline const CondOpIAddV VecShort::add_cc(const VecShort src, IAddCC cc) { return CondOpIAddV(this, src, cc); }
sfpi_inline const CondOpIAddV VecShort::add_cc(const CReg src, IAddCC cc) { return CondOpIAddV(this, src, cc); }

// Note: compare is against 12 bit sign extended value
sfpi_inline const CondComp VecShort::operator==(int val) const { return CondComp(CondComp::CompEQ0, *this, val); };
sfpi_inline const CondComp VecShort::operator!=(int val) const {return CondComp(CondComp::CompNE0, *this, val); };

// The flipped conditionals are correct, see comment in emit()
sfpi_inline const CondOpIAddV VecShort::operator<(const VecShort src) { return CondOpIAddV(*this, src, IAddCCGTE0); }
sfpi_inline const CondOpIAddV VecShort::operator>=(const VecShort src) { return CondOpIAddV(*this, src, IAddCCLT0); }

sfpi_inline VecShort::operator VecUShort() const
{
    return VecUShort(v);
}

sfpi_inline VecShort VecShort::abs() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpabs(v, SFPABS_MOD1_INT);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecShort VecShort::lz() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfplz(v, SFPLZ_MOD1_CC_NONE);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecShort VecShort::operator&(const VecShort b) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpand(tmp, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecShort::operator&=(const VecShort b)
{
    v = __builtin_rvtt_sfpand(v, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline VecShort VecShort::operator|(const VecShort b) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpor(tmp, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecShort::operator|=(const VecShort b)
{
    v = __builtin_rvtt_sfpor(v, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline VecShort VecShort::operator~() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpnot(v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline void VecShort::loadi(int val)
{
    v = initialized ?
        __builtin_rvtt_sfploadi_lv(v, SFPLOADI_MOD0_SHORT, val) :
        __builtin_rvtt_sfploadi(SFPLOADI_MOD0_SHORT, val);
    initialized = true;
}

sfpi_inline VecShort VecShort::operator+(const VecShort& val) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpiadd_v(tmp, val.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline VecShort VecShort::operator+(const CReg& creg) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpiadd_r(tmp, creg.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_2SCOMP_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline VecShort VecShort::operator-(int val) const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpiadd_i(-val, v, SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_IMM);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecShort VecShort::operator-(const VecShort& val) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpiadd_v(tmp, val.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_2SCOMP_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline VecShort VecShort::operator-(const CReg& creg) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpiadd_r(tmp, creg.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_2SCOMP_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecShort::operator+=(int val)
{
    v = __builtin_rvtt_sfpiadd_i(val, v, SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_IMM);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecShort::operator+=(const VecShort& val)
{
    v = __builtin_rvtt_sfpiadd_v(v, val.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecShort::operator+=(const CReg& creg)
{
    v = __builtin_rvtt_sfpiadd_r(v, creg.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecShort::operator-=(int val)
{
    v = __builtin_rvtt_sfpiadd_i(-val, v, SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_IMM);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecShort::operator-=(const VecShort& val)
{
    v = __builtin_rvtt_sfpiadd_v(v, val.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void VecShort::operator-=(const CReg& creg)
{
    v = __builtin_rvtt_sfpiadd_r(v, creg.get(), SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_2SCOMP_LREG_DST);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

//////////////////////////////////////////////////////////////////////////////
 sfpi_inline const CondOpLz VecUShort::lz_cc(const Vec src, LzCC cc) { return CondOpLz(this, src, cc); }

sfpi_inline VecShort VecUShort::lz() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfplz(v, SFPLZ_MOD1_CC_NONE);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline VecUShort VecUShort::operator<<(unsigned int amt) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpshft_i(tmp, amt);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecUShort::operator<<=(unsigned int amt)
{
    v = (*this << amt).get();
}

sfpi_inline VecUShort VecUShort::operator>>(unsigned int amt) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpshft_i(tmp, -amt);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecUShort::operator>>=(unsigned int amt)
{
    v = (*this >> amt).get();
}

sfpi_inline VecUShort VecUShort::shft(const VecShort amt) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpshft_v(tmp, amt.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline VecUShort VecUShort::operator&(const VecUShort b) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpand(tmp, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecUShort::operator&=(const VecUShort b)
{
    v = __builtin_rvtt_sfpand(v, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline VecUShort VecUShort::operator|(const VecUShort b) const
{
    __rvtt_vec_t tmp = v;
    tmp = __builtin_rvtt_sfpor(tmp, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return tmp;
}

sfpi_inline void VecUShort::operator|=(const VecUShort b)
{
    v = __builtin_rvtt_sfpor(v, b.get());
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
}

sfpi_inline VecUShort VecUShort::operator~() const
{
    __rvtt_vec_t result = __builtin_rvtt_sfpnot(v);
    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();
    return result;
}

sfpi_inline void VecUShort::loadi(unsigned int val)
{
    v = initialized ?
        __builtin_rvtt_sfploadi_lv(v, SFPLOADI_MOD0_USHORT, val) :
        __builtin_rvtt_sfploadi(SFPLOADI_MOD0_USHORT, val);
    initialized = true;
}

//////////////////////////////////////////////////////////////////////////////
sfpi_inline __rvtt_vec_t prep_neg(const __rvtt_vec_t v, bool neg)
{
    if (neg) {
        __rvtt_vec_t t = __builtin_rvtt_sfpmov(v, SFPMOV_MOD1_COMPSIGN);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return t;
    } else {
        return v;
    }
}

sfpi_inline const __rvtt_vec_t SubBaseOp::mad_helper(const Operand op_a, const Operand op_b, const Operand op_c, unsigned int offset)
{
    unsigned int permutation = 0;

    if (op_a.get_type() == Operand::Type::CReg) permutation |= 0B100;
    if (op_b.get_type() == Operand::Type::CReg) permutation |= 0B010;
    if (op_c.get_type() == Operand::Type::CReg) permutation |= 0B001;

    switch (permutation) {
    case 0B000: {
        __rvtt_vec_t a = op_a.get_vec().get();
        __rvtt_vec_t b = op_b.get_vec().get();
        __rvtt_vec_t c = prep_neg(op_c.get_vec().get(), op_c.is_neg());
        __rvtt_vec_t result = __builtin_rvtt_sfpmad_vvv(a, b, c, offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    case 0B001: {
        __rvtt_vec_t a = op_a.get_vec().get();
        __rvtt_vec_t b = op_b.get_vec().get();
        __rvtt_vec_t result =  __builtin_rvtt_sfpmad_vvr(a, b, op_c.get_creg(), offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    case 0B010: {
        __rvtt_vec_t a = op_a.get_vec().get();
        __rvtt_vec_t c = prep_neg(op_c.get_vec().get(), op_c.is_neg());
        __rvtt_vec_t result =  __builtin_rvtt_sfpmad_vrv(a, op_b.get_creg(), c, offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    case 0B011: {
        __rvtt_vec_t a = op_a.get_vec().get();
        __rvtt_vec_t result =  __builtin_rvtt_sfpmad_vrr(a, op_b.get_creg(), op_c.get_creg(), offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    case 0B100: {
        __rvtt_vec_t b = op_b.get_vec().get();
        __rvtt_vec_t c = prep_neg(op_c.get_vec().get(), op_c.is_neg());
        __rvtt_vec_t result =  __builtin_rvtt_sfpmad_rvv(op_a.get_creg(), b, c, offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    case 0B101: {
        __rvtt_vec_t b = op_b.get_vec().get();
        __rvtt_vec_t result =  __builtin_rvtt_sfpmad_rvr(op_a.get_creg(), b, op_c.get_creg(), offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    case 0B110: {
        __rvtt_vec_t c = prep_neg(op_c.get_vec().get(), op_c.is_neg());
        __rvtt_vec_t result =  __builtin_rvtt_sfpmad_rrv(op_a.get_creg(), op_b.get_creg(), c, offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    case 0B111: {
        __rvtt_vec_t result =  __builtin_rvtt_sfpmad_rrr(op_a.get_creg(), op_b.get_creg(), op_c.get_creg(), offset);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        return result;
    }
    default:
        __rvtt_vec_t result;
        return result;
    };
}

//////////////////////////////////////////////////////////////////////////////
sfpi_inline MadOp MulOp::operator+(const VecHalf c) const { return MadOp(this->operands[OperandIdxA], this->operands[OperandIdxB], c); }
sfpi_inline MadOp MulOp::operator+(const CReg c) const { return MadOp(this->operands[OperandIdxA], this->operands[OperandIdxB], c); }
sfpi_inline MadOp MulOp::operator-(const VecHalf c) const { return MadOp(this->operands[OperandIdxA], this->operands[OperandIdxB], c, true); }

template<>
sfpi_inline const __rvtt_vec_t BinaryOp<OpType::Add>::get_result() const
{
    const Operand one(CReg_1);
    return mad_helper(operands[BaseOp::OperandIdxA], one, operands[BaseOp::OperandIdxB], offset);
}

template<>
sfpi_inline const __rvtt_vec_t BinaryOp<OpType::Sub>::get_result() const
{
    const Operand one(CReg_1);
    return mad_helper(operands[BaseOp::OperandIdxA], one, operands[BaseOp::OperandIdxB], offset);
}

template<>
sfpi_inline const __rvtt_vec_t BinaryOp<OpType::Mul>::get_result() const
{
    const Operand zero(CReg_0);
    return mad_helper(operands[BaseOp::OperandIdxA], operands[BaseOp::OperandIdxB], zero, offset);
}

sfpi_inline const __rvtt_vec_t MadOp::get_result() const
{
    return mad_helper(operands[BaseOp::OperandIdxA], operands[BaseOp::OperandIdxB], operands[BaseOp::OperandIdxC], offset);
}

template<int nOps>
sfpi_inline const VecHalf BaseOp<nOps>::get_vec(OperandIdx idx) const { return operands[idx].get_vec(); }

//////////////////////////////////////////////////////////////////////////////
sfpi_inline void AddShortOp::emit(__rvtt_vec_t& dst, bool& initialized) const
{
    dst = initialized ?
        __builtin_rvtt_sfpiadd_i_lv(dst, imm, src, SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_IMM) :
        __builtin_rvtt_sfpiadd_i(imm, src, SFPIADD_MOD1_CC_NONE | SFPIADD_MOD1_ARG_IMM);

    __builtin_rvtt_sfpnop();
    __builtin_rvtt_sfpnop();

    initialized = true;
}

sfpi_inline const CondOpIAddI VecShort::operator>=(int val)
{
    val = (val & 0x0800) ? (val | 0xF000) : val;
    return CondOpIAddI(*this, IAddCCGTE0, -val);
}

sfpi_inline const CondOpIAddI VecShort::operator<(int val)
{
    val = (val & 0x0800) ? (val | 0xF000) : val;
    return CondOpIAddI(*this, IAddCCLT0, -val);
}

//////////////////////////////////////////////////////////////////////////////
sfpi_inline void CondOperand::emit() const
{
    if (type == Type::CondOp) {
        op->emit(false);
    } else {
        cond->emit();
    }
}

sfpi_inline const CondBool CondBool::operator!() const
{
    CondBool result(*this);
    result.negate = true;
    return result;
}

// Recursively process the conditional tree
// gcc inline bails out due to complexity and always_inline doesn't allow
// recursive inlining.  Instead, manually expand the code with "recursive"
// macro usage up to reasonable compile time limits.  Eventually this has to
// be pushed down into the compiler
// Use De Morgan's laws to convert || to !&& pass the ! down as we go
// Each node may be negated from above, if the current node is an OR, then it
// always negates itself and upates the propagated negate by flipping it
#define emit_loop(leftside, rightside)                                  \
{                                                                       \
    const CondBool* local_node = node;                                  \
    bool negate_node = node->negate;                                    \
    bool negate_child = negate;                                         \
                                                                        \
    CondBool::CondBoolType node_type = negate ? node->get_neg_type() : node->get_type(); \
    if (node_type == CondBool::CondBoolType::Or) {                      \
        negate_node = !negate_node;                                     \
        negate_child = !negate;                                         \
    }                                                                   \
                                                                        \
    if (node->op_a.get_type() == CondOperand::Type::CondBool) {         \
        node = &node->op_a.get_cond();                                  \
        leftside;                                                       \
        node = local_node;                                              \
    } else {                                                            \
        node->op_a.get_op().emit(negate_child);                         \
    }                                                                   \
                                                                        \
    if (node->op_b.get_type() == CondOperand::Type::CondBool) {         \
        node = &node->op_b.get_cond();                                  \
        rightside;                                                      \
        node = local_node;                                              \
    } else {                                                            \
        node->op_b.get_op().emit(negate_child);                         \
    }                                                                   \
                                                                        \
    if (negate_node) {                                                  \
        __builtin_rvtt_sfpcompc();                                      \
        __builtin_rvtt_sfpnop();                                        \
    }                                                                   \
}

#define emit_loop_mid(leftside, rightside)                              \
    bool negate = negate_child;                                         \
    emit_loop(leftside, rightside)


sfpi_inline void CondBool::emit(bool negate) const
{
    const CondBool* node = this;

    emit_loop(emit_loop_mid(emit_loop(,), emit_loop(,)),
              emit_loop_mid(emit_loop(,), emit_loop(,)));
}

sfpi_inline CondOp::CondOp(CondOpType t, const VecShort a, int i, unsigned int m, unsigned int nm) :
    type(t), op_a(a), op_b(), imm(i), mod1(m), neg_mod1(nm)
{
}

sfpi_inline const CondOp CondOp::operator!() const
{
    CondOp result(*this);

    result.mod1 = neg_mod1;
    result.neg_mod1 = mod1;

    return result;
}

sfpi_inline void CondOp::emit(bool negate) const
{
    unsigned int use_mod1 = negate ? neg_mod1 : mod1;

    switch (type) {
    case CondOp::CondOpType::Evaluated:
        break;

    case CondOp::CondOpType::CompareFloat:
        {
            __rvtt_vec_t l_op_a = op_a.get_vec().get();
            float l_op_b = op_b.get_float();

            if (l_op_b != 0.0F) {
                __rvtt_vec_t tmp;
                if (l_op_b == 1.0F) {
                    // Accelerate expected semi-common case
                    tmp = __builtin_rvtt_sfpmad_vrr(l_op_a, CREG_IDX_1, CREG_IDX_NEG_1, 0);
                    __builtin_rvtt_sfpnop();
                    __builtin_rvtt_sfpnop();
                } else {
                    __rvtt_vec_t neg_op_b = __builtin_rvtt_sfploadi(SFPLOADI_MOD0_FLOATB, VecHalf::f32_to_f16b(-l_op_b));
                    tmp = __builtin_rvtt_sfpmad_vrv(l_op_a, CREG_IDX_1, neg_op_b, 0);
                    __builtin_rvtt_sfpnop();
                    __builtin_rvtt_sfpnop();
                }

                __builtin_rvtt_sfpsetcc_v(tmp, use_mod1);
                __builtin_rvtt_sfpnop();
            } else {
                __builtin_rvtt_sfpsetcc_v(l_op_a, use_mod1);
                __builtin_rvtt_sfpnop();
            }
        }
        break;

    case CondOp::CondOpType::CompareShort:
        {
            // If comparing >= n or <= n, use iadd_i
            // If comparing == 0 or != 0, use setcc
            // If comparing == n or != n (n != 0), use both

            __rvtt_vec_t l_op_a = op_a.get_vec().get();

            if (use_mod1 == CondComp::CompGTE0 || use_mod1 == CondComp::CompLT0 || imm != 0) {
                // use_mod1 contains the CondCompOpType (SETCC's mod1)
                if (use_mod1 == CondComp::CompNE0 || use_mod1 == CondComp::CompEQ0) {
                    l_op_a = __builtin_rvtt_sfpiadd_i(-imm, l_op_a, SFPIADD_MOD1_ARG_IMM);
                    __builtin_rvtt_sfpnop();
                    __builtin_rvtt_sfpnop();
                } else {
                    unsigned int mod1 = (use_mod1 == CondComp::CompGTE0) ? SFPIADD_MOD1_CC_GTE0 : SFPIADD_MOD1_CC_LT0;
                    __builtin_rvtt_sfpiadd_i(-imm, l_op_a, mod1 | SFPIADD_MOD1_ARG_IMM);
                    __builtin_rvtt_sfpnop();
                    __builtin_rvtt_sfpnop();
                    __builtin_rvtt_sfpnop();

                    // Early out!
                    break;
                }
            }

            __builtin_rvtt_sfpsetcc_v(l_op_a, use_mod1);
            __builtin_rvtt_sfpnop();
        }
        break;

    case CondOp::CondOpType::ExExp:
        op_b.get_vec_ptr()->get() = __builtin_rvtt_sfpexexp(op_a.get_vec().get(), use_mod1);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        break;

    case CondOp::CondOpType::Lz:
        op_b.get_vec_ptr()->get() = __builtin_rvtt_sfplz(op_a.get_vec().get(), use_mod1);
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        __builtin_rvtt_sfpnop();
        break;

    case CondOp::CondOpType::IAddI:
        if (op_b.get_type() == Operand::Type::Null) {
            __builtin_rvtt_sfpiadd_i(imm, op_a.get_vec().get(), use_mod1);
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
        } else {
            op_b.get_vec_ptr()->get() = __builtin_rvtt_sfpiadd_i(imm, op_a.get_vec().get(), use_mod1);
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
        }
        break;

    case CondOp::CondOpType::IAddV:
        if (op_b.get_type() == Operand::Type::Vec) {
            // This is the "no assignment" form
            // Grayskull has no integer move to invert a
            // Also, iadd_v trashes the dst
            // Save an op by switching a, b and doing a 2s comp - 1
            // Think this is correct...
            __rvtt_vec_t tmp = __builtin_rvtt_sfpnot(op_b.get_vec().get());
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpiadd_v(tmp, op_a.get_vec().get(), use_mod1);
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
        } else {
            if (op_a.get_type() == Operand::Type::CReg) {
                op_b.get_vec_ptr()->get() = __builtin_rvtt_sfpiadd_r(op_b.get_vec_ptr()->get(), op_a.get_creg(), use_mod1);
            } else {
                op_b.get_vec_ptr()->get() = __builtin_rvtt_sfpiadd_v(op_b.get_vec_ptr()->get(), op_a.get_vec().get(), use_mod1);
            }
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
            __builtin_rvtt_sfpnop();
        }
        break;
    }
}

sfpi_inline CondComp::CondCompOpType CondComp::not_cond(const CondCompOpType t) const
{
    switch (t) {
    case CompLT0:
        return CompGTE0;
    case CompNE0:
        return CompEQ0;
    case CompGTE0:
        return CompLT0;
    case CompEQ0:
        return CompNE0;
    default:
        // Should never get here
        return CompNE0;
    }
}

sfpi_inline ExExpCC CondOpExExp::not_cond(const ExExpCC t) const
{
    return (t == ExExpCCLT0) ? ExExpCCGTE0 : ExExpCCLT0;
}

sfpi_inline LzCC CondOpLz::not_cond(const LzCC t) const
{
    return (t == LzCCNE0) ? LzCCEQ0 : LzCCNE0;
}

sfpi_inline IAddCC CondOpIAddI::not_cond(const IAddCC t) const
{
    return (t == IAddCCLT0) ? IAddCCGTE0 : IAddCCLT0;
}

sfpi_inline IAddCC CondOpIAddV::not_cond(const IAddCC t) const
{
    return (t == IAddCCLT0) ? IAddCCGTE0 : IAddCCLT0;
}

//////////////////////////////////////////////////////////////////////////////
sfpi_inline CCCtrl::CCCtrl(bool dopush) : push_count(0)
{
    if (dopush) {
        push();
    }
}

sfpi_inline void CCCtrl::cc_if(const CondOperand& op) const
{
    op.emit();
}

sfpi_inline void CCCtrl::cc_if(const CondOp& op) const
{
    op.emit(false);
}

sfpi_inline void CCCtrl::cc_elseif(const CondOperand& op)
{
    cc_if(op);
}

sfpi_inline void CCCtrl::cc_elseif(const CondOp& op)
{
    cc_if(op);
}

sfpi_inline void CCCtrl::cc_else() const
{
    __builtin_rvtt_sfpcompc();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void CCCtrl::cc_endif()
{
    while (push_count != 0) {
        pop();
    }
}

sfpi_inline void CCCtrl::push()
{
    push_count++;
    __builtin_rvtt_sfppushc();
}

sfpi_inline void CCCtrl::pop()
{
    push_count--;
    __builtin_rvtt_sfppopc();
    __builtin_rvtt_sfpnop();
}

sfpi_inline void CCCtrl::enable_cc()
{
    __builtin_rvtt_sfpencc(SFPENCC_IMM12_BOTH, SFPENCC_MOD1_EI_RI);
    __builtin_rvtt_sfpnop();
}

sfpi_inline CCCtrlOpt::CCCtrlOpt() : CCCtrl(false)
{
}

sfpi_inline CCCtrlOpt::~CCCtrlOpt()
{
    enable_cc();
    __builtin_rvtt_sfpnop();
}

} // namespace sfpi


#define p_if(x)             \
{                           \
    CCCtrl __cc(true);      \
    __cc.cc_if(x);

#define po_if(x)            \
{                           \
    CCCtrlOpt __cc;         \
    __cc.cc_if(x);

#define p_tail_if(x)        \
    __cc.cc_if(x);

#define p_elseif(x)         \
    __cc.cc_else();         \
    __cc.push();            \
    __cc.cc_elseif(x);

#define p_else              \
    __cc.cc_else();

#define p_endif             \
    __cc.cc_endif();        \
}