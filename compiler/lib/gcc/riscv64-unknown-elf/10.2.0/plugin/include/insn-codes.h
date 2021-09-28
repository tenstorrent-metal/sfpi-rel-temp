/* Generated automatically by the program `gencodes'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CODES_H
#define GCC_INSN_CODES_H

enum insn_code {
  CODE_FOR_nothing = 0,
  CODE_FOR_addsf3 = 1,
  CODE_FOR_adddf3 = 2,
  CODE_FOR_addsi3 = 3,
  CODE_FOR_adddi3 = 4,
  CODE_FOR_subsf3 = 7,
  CODE_FOR_subdf3 = 8,
  CODE_FOR_subdi3 = 9,
  CODE_FOR_subsi3 = 10,
  CODE_FOR_negdi2 = 13,
  CODE_FOR_negsi2 = 14,
  CODE_FOR_mulsf3 = 17,
  CODE_FOR_muldf3 = 18,
  CODE_FOR_mulsi3 = 19,
  CODE_FOR_muldi3 = 20,
  CODE_FOR_muldi3_highpart = 23,
  CODE_FOR_umuldi3_highpart = 24,
  CODE_FOR_usmuldi3_highpart = 25,
  CODE_FOR_mulsi3_highpart = 26,
  CODE_FOR_umulsi3_highpart = 27,
  CODE_FOR_usmulsi3_highpart = 28,
  CODE_FOR_divsi3 = 29,
  CODE_FOR_udivsi3 = 30,
  CODE_FOR_modsi3 = 31,
  CODE_FOR_umodsi3 = 32,
  CODE_FOR_divdi3 = 33,
  CODE_FOR_udivdi3 = 34,
  CODE_FOR_moddi3 = 35,
  CODE_FOR_umoddi3 = 36,
  CODE_FOR_divsf3 = 41,
  CODE_FOR_divdf3 = 42,
  CODE_FOR_sqrtsf2 = 43,
  CODE_FOR_sqrtdf2 = 44,
  CODE_FOR_fmasf4 = 45,
  CODE_FOR_fmadf4 = 46,
  CODE_FOR_fmssf4 = 47,
  CODE_FOR_fmsdf4 = 48,
  CODE_FOR_fnmssf4 = 49,
  CODE_FOR_fnmsdf4 = 50,
  CODE_FOR_fnmasf4 = 51,
  CODE_FOR_fnmadf4 = 52,
  CODE_FOR_abssf2 = 61,
  CODE_FOR_absdf2 = 62,
  CODE_FOR_copysignsf3 = 63,
  CODE_FOR_copysigndf3 = 64,
  CODE_FOR_negsf2 = 65,
  CODE_FOR_negdf2 = 66,
  CODE_FOR_sminsf3 = 67,
  CODE_FOR_smindf3 = 68,
  CODE_FOR_smaxsf3 = 69,
  CODE_FOR_smaxdf3 = 70,
  CODE_FOR_andsi3 = 71,
  CODE_FOR_iorsi3 = 72,
  CODE_FOR_xorsi3 = 73,
  CODE_FOR_anddi3 = 74,
  CODE_FOR_iordi3 = 75,
  CODE_FOR_xordi3 = 76,
  CODE_FOR_one_cmplsi2 = 80,
  CODE_FOR_one_cmpldi2 = 81,
  CODE_FOR_truncdfsf2 = 83,
  CODE_FOR_zero_extendsidi2 = 84,
  CODE_FOR_zero_extendhisi2 = 85,
  CODE_FOR_zero_extendhidi2 = 86,
  CODE_FOR_zero_extendqihi2 = 87,
  CODE_FOR_zero_extendqisi2 = 88,
  CODE_FOR_zero_extendqidi2 = 89,
  CODE_FOR_extendsidi2 = 90,
  CODE_FOR_extendqihi2 = 91,
  CODE_FOR_extendqisi2 = 92,
  CODE_FOR_extendqidi2 = 93,
  CODE_FOR_extendhihi2 = 94,
  CODE_FOR_extendhisi2 = 95,
  CODE_FOR_extendhidi2 = 96,
  CODE_FOR_extendsfdf2 = 97,
  CODE_FOR_fix_truncsfsi2 = 98,
  CODE_FOR_fix_truncsfdi2 = 99,
  CODE_FOR_fix_truncdfsi2 = 100,
  CODE_FOR_fix_truncdfdi2 = 101,
  CODE_FOR_fixuns_truncsfsi2 = 102,
  CODE_FOR_fixuns_truncsfdi2 = 103,
  CODE_FOR_fixuns_truncdfsi2 = 104,
  CODE_FOR_fixuns_truncdfdi2 = 105,
  CODE_FOR_floatsisf2 = 106,
  CODE_FOR_floatdisf2 = 107,
  CODE_FOR_floatsidf2 = 108,
  CODE_FOR_floatdidf2 = 109,
  CODE_FOR_floatunssisf2 = 110,
  CODE_FOR_floatunsdisf2 = 111,
  CODE_FOR_floatunssidf2 = 112,
  CODE_FOR_floatunsdidf2 = 113,
  CODE_FOR_lrintsfsi2 = 114,
  CODE_FOR_lroundsfsi2 = 115,
  CODE_FOR_lrintsfdi2 = 116,
  CODE_FOR_lroundsfdi2 = 117,
  CODE_FOR_lrintdfsi2 = 118,
  CODE_FOR_lrounddfsi2 = 119,
  CODE_FOR_lrintdfdi2 = 120,
  CODE_FOR_lrounddfdi2 = 121,
  CODE_FOR_got_loadsi = 122,
  CODE_FOR_got_loaddi = 123,
  CODE_FOR_tls_add_tp_lesi = 124,
  CODE_FOR_tls_add_tp_ledi = 125,
  CODE_FOR_got_load_tls_gdsi = 126,
  CODE_FOR_got_load_tls_gddi = 127,
  CODE_FOR_got_load_tls_iesi = 128,
  CODE_FOR_got_load_tls_iedi = 129,
  CODE_FOR_auipcsi = 130,
  CODE_FOR_auipcdi = 131,
  CODE_FOR_fence = 148,
  CODE_FOR_fence_i = 149,
  CODE_FOR_ashlsi3 = 150,
  CODE_FOR_ashrsi3 = 151,
  CODE_FOR_lshrsi3 = 152,
  CODE_FOR_ashldi3 = 159,
  CODE_FOR_ashrdi3 = 160,
  CODE_FOR_lshrdi3 = 161,
  CODE_FOR_zero_extendsidi2_shifted = 180,
  CODE_FOR_jump = 251,
  CODE_FOR_indirect_jumpsi = 252,
  CODE_FOR_indirect_jumpdi = 253,
  CODE_FOR_tablejumpsi = 254,
  CODE_FOR_tablejumpdi = 255,
  CODE_FOR_blockage = 256,
  CODE_FOR_simple_return = 257,
  CODE_FOR_simple_return_internal = 258,
  CODE_FOR_eh_set_lr_si = 259,
  CODE_FOR_eh_set_lr_di = 260,
  CODE_FOR_eh_return_internal = 261,
  CODE_FOR_sibcall_internal = 262,
  CODE_FOR_sibcall_value_internal = 263,
  CODE_FOR_call_internal = 264,
  CODE_FOR_call_value_internal = 265,
  CODE_FOR_nop = 266,
  CODE_FOR_trap = 267,
  CODE_FOR_gpr_save = 268,
  CODE_FOR_gpr_restore = 269,
  CODE_FOR_gpr_restore_return = 270,
  CODE_FOR_riscv_frflags = 271,
  CODE_FOR_riscv_fsflags = 272,
  CODE_FOR_riscv_mret = 273,
  CODE_FOR_riscv_sret = 274,
  CODE_FOR_riscv_uret = 275,
  CODE_FOR_stack_tiesi = 276,
  CODE_FOR_stack_tiedi = 277,
  CODE_FOR_mem_thread_fence_1 = 278,
  CODE_FOR_atomic_storesi = 279,
  CODE_FOR_atomic_storedi = 280,
  CODE_FOR_atomic_addsi = 281,
  CODE_FOR_atomic_orsi = 282,
  CODE_FOR_atomic_xorsi = 283,
  CODE_FOR_atomic_andsi = 284,
  CODE_FOR_atomic_adddi = 285,
  CODE_FOR_atomic_ordi = 286,
  CODE_FOR_atomic_xordi = 287,
  CODE_FOR_atomic_anddi = 288,
  CODE_FOR_atomic_fetch_addsi = 289,
  CODE_FOR_atomic_fetch_orsi = 290,
  CODE_FOR_atomic_fetch_xorsi = 291,
  CODE_FOR_atomic_fetch_andsi = 292,
  CODE_FOR_atomic_fetch_adddi = 293,
  CODE_FOR_atomic_fetch_ordi = 294,
  CODE_FOR_atomic_fetch_xordi = 295,
  CODE_FOR_atomic_fetch_anddi = 296,
  CODE_FOR_atomic_exchangesi = 297,
  CODE_FOR_atomic_exchangedi = 298,
  CODE_FOR_atomic_cas_value_strongsi = 299,
  CODE_FOR_atomic_cas_value_strongdi = 300,
  CODE_FOR_riscv_sfpload_int_imm = 354,
  CODE_FOR_riscv_sfpload_int_reg = 355,
  CODE_FOR_riscv_sfpload_int_imm_lv = 356,
  CODE_FOR_riscv_sfpload_int_reg_lv = 357,
  CODE_FOR_riscv_sfploadl0 = 358,
  CODE_FOR_riscv_sfploadl1 = 359,
  CODE_FOR_riscv_sfploadl2 = 360,
  CODE_FOR_riscv_sfploadl3 = 361,
  CODE_FOR_riscv_sfploadi_int_imm = 362,
  CODE_FOR_riscv_sfploadi_int_reg = 363,
  CODE_FOR_riscv_sfploadi_int_imm_lv = 364,
  CODE_FOR_riscv_sfploadi_int_reg_lv = 365,
  CODE_FOR_riscv_sfpstore_v_int_imm = 366,
  CODE_FOR_riscv_sfpstore_v_int_reg = 367,
  CODE_FOR_riscv_sfpstore_r_int_imm = 368,
  CODE_FOR_riscv_sfpstore_r_int_reg = 369,
  CODE_FOR_riscv_sfpmuli = 370,
  CODE_FOR_riscv_sfpaddi_int_imm = 371,
  CODE_FOR_riscv_sfpaddi_int_reg = 372,
  CODE_FOR_riscv_sfpdivp2_int_imm = 373,
  CODE_FOR_riscv_sfpdivp2_int_reg = 374,
  CODE_FOR_riscv_sfpexexp = 375,
  CODE_FOR_riscv_sfpexman = 376,
  CODE_FOR_riscv_sfpmov = 377,
  CODE_FOR_riscv_sfpmul = 378,
  CODE_FOR_riscv_sfpadd = 379,
  CODE_FOR_riscv_sfpiadd_v = 380,
  CODE_FOR_riscv_sfpiadd_i_int_imm = 381,
  CODE_FOR_riscv_sfpiadd_i_int_reg = 382,
  CODE_FOR_riscv_sfpiadd_i_int_imm_lv = 383,
  CODE_FOR_riscv_sfpiadd_i_int_reg_lv = 384,
  CODE_FOR_riscv_sfpiadd_r = 385,
  CODE_FOR_riscv_sfpshft_v = 386,
  CODE_FOR_riscv_sfpshft_i_int_imm = 387,
  CODE_FOR_riscv_sfpshft_i_int_reg = 388,
  CODE_FOR_riscv_sfpabs = 389,
  CODE_FOR_riscv_sfpand = 390,
  CODE_FOR_riscv_sfpor = 391,
  CODE_FOR_riscv_sfpnot = 392,
  CODE_FOR_riscv_sfplz = 393,
  CODE_FOR_riscv_sfpsetman_v = 394,
  CODE_FOR_riscv_sfpsetman_i_int_imm = 395,
  CODE_FOR_riscv_sfpsetman_i_int_reg = 396,
  CODE_FOR_riscv_sfpsetexp_v = 397,
  CODE_FOR_riscv_sfpsetexp_i_int_imm = 398,
  CODE_FOR_riscv_sfpsetexp_i_int_reg = 399,
  CODE_FOR_riscv_sfpsetsgn_v = 400,
  CODE_FOR_riscv_sfpsetsgn_i_int_imm = 401,
  CODE_FOR_riscv_sfpsetsgn_i_int_reg = 402,
  CODE_FOR_riscv_sfpmad_vvv = 403,
  CODE_FOR_riscv_sfpmad_rvv = 404,
  CODE_FOR_riscv_sfpmad_vrv = 405,
  CODE_FOR_riscv_sfpmad_vvr = 406,
  CODE_FOR_riscv_sfpmad_rrv = 407,
  CODE_FOR_riscv_sfpmad_vrr = 408,
  CODE_FOR_riscv_sfpmad_rvr = 409,
  CODE_FOR_riscv_sfpmad_rrr = 410,
  CODE_FOR_riscv_sfpsetcc_i = 411,
  CODE_FOR_riscv_sfpsetcc_v = 412,
  CODE_FOR_riscv_sfpencc = 413,
  CODE_FOR_riscv_sfpcompc = 414,
  CODE_FOR_riscv_sfppushc = 415,
  CODE_FOR_riscv_sfppopc = 416,
  CODE_FOR_riscv_sfplut = 417,
  CODE_FOR_riscv_sfpnop = 418,
  CODE_FOR_mulditi3 = 419,
  CODE_FOR_umulditi3 = 420,
  CODE_FOR_usmulditi3 = 421,
  CODE_FOR_mulsidi3 = 422,
  CODE_FOR_umulsidi3 = 423,
  CODE_FOR_usmulsidi3 = 424,
  CODE_FOR_movdi = 425,
  CODE_FOR_movsi = 426,
  CODE_FOR_movhi = 427,
  CODE_FOR_movqi = 428,
  CODE_FOR_movsf = 429,
  CODE_FOR_movdf = 430,
  CODE_FOR_cpymemsi = 431,
  CODE_FOR_clear_cache = 432,
  CODE_FOR_movsicc = 433,
  CODE_FOR_movdicc = 434,
  CODE_FOR_condjump = 435,
  CODE_FOR_cbranchqi4 = 436,
  CODE_FOR_cbranchsi4 = 437,
  CODE_FOR_cbranchdi4 = 438,
  CODE_FOR_cbranchsf4 = 439,
  CODE_FOR_cbranchdf4 = 440,
  CODE_FOR_cstoresi4 = 441,
  CODE_FOR_cstoredi4 = 442,
  CODE_FOR_cstoresf4 = 443,
  CODE_FOR_cstoredf4 = 444,
  CODE_FOR_flt_quietsfsi4 = 445,
  CODE_FOR_fle_quietsfsi4 = 446,
  CODE_FOR_flt_quietsfdi4 = 447,
  CODE_FOR_fle_quietsfdi4 = 448,
  CODE_FOR_flt_quietdfsi4 = 449,
  CODE_FOR_fle_quietdfsi4 = 450,
  CODE_FOR_flt_quietdfdi4 = 451,
  CODE_FOR_fle_quietdfdi4 = 452,
  CODE_FOR_indirect_jump = 453,
  CODE_FOR_tablejump = 454,
  CODE_FOR_prologue = 455,
  CODE_FOR_epilogue = 456,
  CODE_FOR_sibcall_epilogue = 457,
  CODE_FOR_return = 458,
  CODE_FOR_eh_return = 459,
  CODE_FOR_sibcall = 460,
  CODE_FOR_sibcall_value = 461,
  CODE_FOR_call = 462,
  CODE_FOR_call_value = 463,
  CODE_FOR_untyped_call = 464,
  CODE_FOR_restore_stack_nonlocal = 465,
  CODE_FOR_mem_thread_fence = 466,
  CODE_FOR_atomic_compare_and_swapsi = 467,
  CODE_FOR_atomic_compare_and_swapdi = 468,
  CODE_FOR_atomic_test_and_set = 469,
  CODE_FOR_movv64sf = 470,
  CODE_FOR_riscv_sfpload = 471,
  CODE_FOR_riscv_sfpload_lv = 472,
  CODE_FOR_riscv_sfploadi = 473,
  CODE_FOR_riscv_sfploadi_lv = 474,
  CODE_FOR_riscv_sfpstore_v = 475,
  CODE_FOR_riscv_sfpstore_r = 476,
  CODE_FOR_riscv_sfpaddi = 477,
  CODE_FOR_riscv_sfpdivp2 = 478,
  CODE_FOR_riscv_sfpiadd_i = 479,
  CODE_FOR_riscv_sfpiadd_i_lv = 480,
  CODE_FOR_riscv_sfpshft_i = 481,
  CODE_FOR_riscv_sfpsetman_i = 482,
  CODE_FOR_riscv_sfpsetexp_i = 483,
  CODE_FOR_riscv_sfpsetsgn_i = 484
};

const unsigned int NUM_INSN_CODES = 485;
#endif /* GCC_INSN_CODES_H */