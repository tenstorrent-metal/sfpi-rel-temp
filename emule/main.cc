#include <cstdio>

namespace ckernel {
    volatile unsigned int *instrn_buffer;
};

#ifdef COMPILE_FOR_EMULE
#include "sfpu.h"
#endif

#include <sfpi.h>

using namespace sfpi;

static void populate_dst_reg_row_with_ramp(int row)
{
#ifdef COMPILE_FOR_EMULE
    // Init ramp from 0..63
    for (int i = 0; i < 64; i++) {
        sfpu::sfpu_dreg.store_float(static_cast<float>(i), row, i);
    }
#endif
}

static void sample_kernel()
{
    VecHalf x;

    x = dst_reg[0];

#ifdef COMPILE_FOR_EMULE
    // print vector elements [2..3]
    x.get().dump(2, 4);

    // print vector element 5
    x.get().dump(5);
#endif

    dst_reg[0] = -x;
}

static void print_dst_reg_row(int row, bool printint)
{
#ifdef COMPILE_FOR_EMULE
    printf("Row: %d\n", row);
    for (int i = 0; i < 64; i++) {
        if (printint) {
            printf("%04x ", sfpu::sfpu_dreg.get(row * 4, i));
        } else {
            printf("%4.6f ", sfpu::sfpu_dreg.get_float(row * 4, i));
        }
    }
    printf("\n\n");
#endif
}

int main(int argc, char* argv[])
{
    // Loads dst reg row 0 w/ a ramp from 0..63
    populate_dst_reg_row_with_ramp(0);

    __builtin_rvtt_sfpencc(3, SFPENCC_MOD1_EI_RI);

    // Sample kernel just loads row 0 and saves it back negated
    sample_kernel();

    // Should print float -0..-63
    print_dst_reg_row(0, false);

    // Should print float -0..-63 in hex
    print_dst_reg_row(0, true);
}
