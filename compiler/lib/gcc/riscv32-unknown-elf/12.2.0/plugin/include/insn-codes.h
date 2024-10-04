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
  CODE_FOR_smuldi3_highpart = 23,
  CODE_FOR_umuldi3_highpart = 24,
  CODE_FOR_usmuldi3_highpart = 25,
  CODE_FOR_smulsi3_highpart = 26,
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
  CODE_FOR_zero_extendqihi2 = 87,
  CODE_FOR_zero_extendqisi2 = 88,
  CODE_FOR_zero_extendqidi2 = 89,
  CODE_FOR_extendsidi2 = 90,
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
  CODE_FOR_jump = 240,
  CODE_FOR_indirect_jumpsi = 241,
  CODE_FOR_indirect_jumpdi = 242,
  CODE_FOR_tablejumpsi = 243,
  CODE_FOR_tablejumpdi = 244,
  CODE_FOR_blockage = 245,
  CODE_FOR_simple_return = 246,
  CODE_FOR_simple_return_internal = 247,
  CODE_FOR_eh_set_lr_si = 248,
  CODE_FOR_eh_set_lr_di = 249,
  CODE_FOR_eh_return_internal = 250,
  CODE_FOR_sibcall_internal = 251,
  CODE_FOR_sibcall_value_internal = 252,
  CODE_FOR_call_internal = 253,
  CODE_FOR_call_value_internal = 254,
  CODE_FOR_nop = 255,
  CODE_FOR_trap = 256,
  CODE_FOR_gpr_save = 257,
  CODE_FOR_gpr_restore = 258,
  CODE_FOR_gpr_restore_return = 259,
  CODE_FOR_riscv_frflags = 260,
  CODE_FOR_riscv_fsflags = 261,
  CODE_FOR_riscv_mret = 262,
  CODE_FOR_riscv_sret = 263,
  CODE_FOR_riscv_uret = 264,
  CODE_FOR_stack_tiesi = 265,
  CODE_FOR_stack_tiedi = 266,
  CODE_FOR_stack_protect_set_si = 267,
  CODE_FOR_stack_protect_set_di = 268,
  CODE_FOR_stack_protect_test_si = 269,
  CODE_FOR_stack_protect_test_di = 270,
  CODE_FOR_clzsi2 = 283,
  CODE_FOR_ctzsi2 = 284,
  CODE_FOR_popcountsi2 = 285,
  CODE_FOR_clzdi2 = 289,
  CODE_FOR_ctzdi2 = 290,
  CODE_FOR_popcountdi2 = 291,
  CODE_FOR_rotrsi3 = 302,
  CODE_FOR_rotrdi3 = 303,
  CODE_FOR_rotrsi3_sext = 304,
  CODE_FOR_rotlsi3 = 305,
  CODE_FOR_rotldi3 = 306,
  CODE_FOR_rotlsi3_sext = 307,
  CODE_FOR_bswapsi2 = 308,
  CODE_FOR_bswapdi2 = 309,
  CODE_FOR_sminsi3 = 310,
  CODE_FOR_uminsi3 = 311,
  CODE_FOR_smaxsi3 = 312,
  CODE_FOR_umaxsi3 = 313,
  CODE_FOR_smindi3 = 314,
  CODE_FOR_umindi3 = 315,
  CODE_FOR_smaxdi3 = 316,
  CODE_FOR_umaxdi3 = 317,
  CODE_FOR_mem_thread_fence_1 = 340,
  CODE_FOR_atomic_storesi = 341,
  CODE_FOR_atomic_storedi = 342,
  CODE_FOR_atomic_addsi = 343,
  CODE_FOR_atomic_orsi = 344,
  CODE_FOR_atomic_xorsi = 345,
  CODE_FOR_atomic_andsi = 346,
  CODE_FOR_atomic_adddi = 347,
  CODE_FOR_atomic_ordi = 348,
  CODE_FOR_atomic_xordi = 349,
  CODE_FOR_atomic_anddi = 350,
  CODE_FOR_atomic_fetch_addsi = 351,
  CODE_FOR_atomic_fetch_orsi = 352,
  CODE_FOR_atomic_fetch_xorsi = 353,
  CODE_FOR_atomic_fetch_andsi = 354,
  CODE_FOR_atomic_fetch_adddi = 355,
  CODE_FOR_atomic_fetch_ordi = 356,
  CODE_FOR_atomic_fetch_xordi = 357,
  CODE_FOR_atomic_fetch_anddi = 358,
  CODE_FOR_atomic_exchangesi = 359,
  CODE_FOR_atomic_exchangedi = 360,
  CODE_FOR_atomic_cas_value_strongsi = 361,
  CODE_FOR_atomic_cas_value_strongdi = 362,
  CODE_FOR_rvtt_load_immediate = 415,
  CODE_FOR_rvtt_sfpassignlreg_int = 416,
  CODE_FOR_rvtt_sfpnonimm_dst = 417,
  CODE_FOR_rvtt_sfpnonimm_dst_src = 418,
  CODE_FOR_rvtt_sfpnonimm_src = 419,
  CODE_FOR_rvtt_sfpnonimm_store = 420,
  CODE_FOR_rvtt_sfpincrwc = 421,
  CODE_FOR_rvtt_gs_l1_load_war = 422,
  CODE_FOR_rvtt_gs_sfpgccmov_cc = 423,
  CODE_FOR_rvtt_gs_sfpassign_lv = 424,
  CODE_FOR_rvtt_gs_sfppreservelreg0_int = 425,
  CODE_FOR_rvtt_gs_sfppreservelreg1_int = 426,
  CODE_FOR_rvtt_gs_sfppreservelreg2_int = 427,
  CODE_FOR_rvtt_gs_sfppreservelreg3_int = 428,
  CODE_FOR_rvtt_gs_sfpload_int = 429,
  CODE_FOR_rvtt_gs_sfploadi_int = 430,
  CODE_FOR_rvtt_gs_sfpstore_int = 431,
  CODE_FOR_rvtt_gs_sfpmuli_int = 432,
  CODE_FOR_rvtt_gs_sfpaddi_int = 433,
  CODE_FOR_rvtt_gs_sfpdivp2_int = 434,
  CODE_FOR_rvtt_gs_sfpexexp_int = 435,
  CODE_FOR_rvtt_gs_sfpexman_int = 436,
  CODE_FOR_rvtt_gs_sfpabs_int = 437,
  CODE_FOR_rvtt_gs_sfpmov_int = 438,
  CODE_FOR_rvtt_gs_sfplz_int = 439,
  CODE_FOR_rvtt_gs_sfpmul_int = 440,
  CODE_FOR_rvtt_gs_sfpadd_int = 441,
  CODE_FOR_rvtt_gs_sfpiadd_v_int = 442,
  CODE_FOR_rvtt_gs_sfpiadd_i_int = 443,
  CODE_FOR_rvtt_gs_sfpshft_v = 444,
  CODE_FOR_rvtt_gs_sfpshft_i_int = 445,
  CODE_FOR_rvtt_gs_sfpand = 446,
  CODE_FOR_rvtt_gs_sfpor = 447,
  CODE_FOR_rvtt_gs_sfpnot_int = 448,
  CODE_FOR_rvtt_gs_sfpsetexp_v = 449,
  CODE_FOR_rvtt_gs_sfpsetman_v = 450,
  CODE_FOR_rvtt_gs_sfpsetsgn_v = 451,
  CODE_FOR_rvtt_gs_sfpsetexp_i_int = 452,
  CODE_FOR_rvtt_gs_sfpsetman_i_int = 453,
  CODE_FOR_rvtt_gs_sfpsetsgn_i_int = 454,
  CODE_FOR_rvtt_gs_sfpmad_int = 455,
  CODE_FOR_rvtt_gs_sfpsetcc_i = 456,
  CODE_FOR_rvtt_gs_sfpsetcc_v = 457,
  CODE_FOR_rvtt_gs_sfpencc = 458,
  CODE_FOR_rvtt_gs_sfpcompc = 459,
  CODE_FOR_rvtt_gs_sfppushc = 460,
  CODE_FOR_rvtt_gs_sfppopc = 461,
  CODE_FOR_rvtt_gs_sfplut = 462,
  CODE_FOR_rvtt_gs_sfpnop = 463,
  CODE_FOR_rvtt_wh_sfpgccmov_cc = 464,
  CODE_FOR_rvtt_wh_sfpassign_lv = 465,
  CODE_FOR_rvtt_wh_sfppreservelreg0_int = 466,
  CODE_FOR_rvtt_wh_sfppreservelreg1_int = 467,
  CODE_FOR_rvtt_wh_sfppreservelreg2_int = 468,
  CODE_FOR_rvtt_wh_sfppreservelreg3_int = 469,
  CODE_FOR_rvtt_wh_sfppreservelreg4_int = 470,
  CODE_FOR_rvtt_wh_sfppreservelreg5_int = 471,
  CODE_FOR_rvtt_wh_sfppreservelreg6_int = 472,
  CODE_FOR_rvtt_wh_sfppreservelreg7_int = 473,
  CODE_FOR_rvtt_wh_sfpload_int = 474,
  CODE_FOR_rvtt_wh_sfploadi_int = 475,
  CODE_FOR_rvtt_wh_sfpstore_int = 476,
  CODE_FOR_rvtt_wh_sfpmuli_int = 477,
  CODE_FOR_rvtt_wh_sfpaddi_int = 478,
  CODE_FOR_rvtt_wh_sfpdivp2_int = 479,
  CODE_FOR_rvtt_wh_sfpexexp_int = 480,
  CODE_FOR_rvtt_wh_sfpexman_int = 481,
  CODE_FOR_rvtt_wh_sfpabs_int = 482,
  CODE_FOR_rvtt_wh_sfpmov_int = 483,
  CODE_FOR_rvtt_wh_sfplz_int = 484,
  CODE_FOR_rvtt_wh_sfpmul_int = 485,
  CODE_FOR_rvtt_wh_sfpadd_int = 486,
  CODE_FOR_rvtt_wh_sfpiadd_v_int = 487,
  CODE_FOR_rvtt_wh_sfpiadd_i_int = 488,
  CODE_FOR_rvtt_wh_sfpshft_v = 489,
  CODE_FOR_rvtt_wh_sfpshft_i_int = 490,
  CODE_FOR_rvtt_wh_sfpand = 491,
  CODE_FOR_rvtt_wh_sfpor = 492,
  CODE_FOR_rvtt_wh_sfpxor = 493,
  CODE_FOR_rvtt_wh_sfpnot_int = 494,
  CODE_FOR_rvtt_wh_sfpcast_int = 495,
  CODE_FOR_rvtt_wh_sfpshft2_e_int = 496,
  CODE_FOR_rvtt_wh_sfpstochrnd_i_int = 497,
  CODE_FOR_rvtt_wh_sfpstochrnd_v_int = 498,
  CODE_FOR_rvtt_wh_sfpsetexp_v = 499,
  CODE_FOR_rvtt_wh_sfpsetman_v = 500,
  CODE_FOR_rvtt_wh_sfpsetsgn_v = 501,
  CODE_FOR_rvtt_wh_sfpsetexp_i_int = 502,
  CODE_FOR_rvtt_wh_sfpsetsgn_i_int = 503,
  CODE_FOR_rvtt_wh_sfpsetman_i_int = 504,
  CODE_FOR_rvtt_wh_sfpmad_int = 505,
  CODE_FOR_rvtt_wh_sfpsetcc_i = 506,
  CODE_FOR_rvtt_wh_sfpsetcc_v = 507,
  CODE_FOR_rvtt_wh_sfpencc = 508,
  CODE_FOR_rvtt_wh_sfpcompc = 509,
  CODE_FOR_rvtt_wh_sfppushc = 510,
  CODE_FOR_rvtt_wh_sfppopc = 511,
  CODE_FOR_rvtt_wh_sfplut = 512,
  CODE_FOR_rvtt_wh_sfplutfp32_3r = 513,
  CODE_FOR_rvtt_wh_sfplutfp32_6r = 514,
  CODE_FOR_rvtt_wh_sfpconfig_v = 515,
  CODE_FOR_rvtt_wh_sfpreplay = 516,
  CODE_FOR_rvtt_wh_sfpswap_int = 517,
  CODE_FOR_rvtt_wh_sfptransp = 518,
  CODE_FOR_rvtt_wh_sfpshft2_g = 519,
  CODE_FOR_rvtt_wh_sfpshft2_ge = 520,
  CODE_FOR_rvtt_wh_sfpnop = 521,
  CODE_FOR_rvtt_bh_sfpgccmov_cc = 522,
  CODE_FOR_rvtt_bh_sfpassign_lv = 523,
  CODE_FOR_rvtt_bh_sfppreservelreg0_int = 524,
  CODE_FOR_rvtt_bh_sfppreservelreg1_int = 525,
  CODE_FOR_rvtt_bh_sfppreservelreg2_int = 526,
  CODE_FOR_rvtt_bh_sfppreservelreg3_int = 527,
  CODE_FOR_rvtt_bh_sfppreservelreg4_int = 528,
  CODE_FOR_rvtt_bh_sfppreservelreg5_int = 529,
  CODE_FOR_rvtt_bh_sfppreservelreg6_int = 530,
  CODE_FOR_rvtt_bh_sfppreservelreg7_int = 531,
  CODE_FOR_rvtt_bh_sfpload_int = 532,
  CODE_FOR_rvtt_bh_sfploadi_int = 533,
  CODE_FOR_rvtt_bh_sfpstore_int = 534,
  CODE_FOR_rvtt_bh_sfpmuli_int = 535,
  CODE_FOR_rvtt_bh_sfpaddi_int = 536,
  CODE_FOR_rvtt_bh_sfpdivp2_int = 537,
  CODE_FOR_rvtt_bh_sfpexexp_int = 538,
  CODE_FOR_rvtt_bh_sfpexman_int = 539,
  CODE_FOR_rvtt_bh_sfpabs_int = 540,
  CODE_FOR_rvtt_bh_sfpmov_int = 541,
  CODE_FOR_rvtt_bh_sfplz_int = 542,
  CODE_FOR_rvtt_bh_sfpmul_int = 543,
  CODE_FOR_rvtt_bh_sfpadd_int = 544,
  CODE_FOR_rvtt_bh_sfpiadd_v_int = 545,
  CODE_FOR_rvtt_bh_sfpiadd_i_int = 546,
  CODE_FOR_rvtt_bh_sfpshft_v = 547,
  CODE_FOR_rvtt_bh_sfpshft_i_int = 548,
  CODE_FOR_rvtt_bh_sfpand = 549,
  CODE_FOR_rvtt_bh_sfpor = 550,
  CODE_FOR_rvtt_bh_sfpxor = 551,
  CODE_FOR_rvtt_bh_sfpnot_int = 552,
  CODE_FOR_rvtt_bh_sfpcast_int = 553,
  CODE_FOR_rvtt_bh_sfpshft2_e_int = 554,
  CODE_FOR_rvtt_bh_sfpstochrnd_i_int = 555,
  CODE_FOR_rvtt_bh_sfpstochrnd_v_int = 556,
  CODE_FOR_rvtt_bh_sfpsetexp_v = 557,
  CODE_FOR_rvtt_bh_sfpsetman_v = 558,
  CODE_FOR_rvtt_bh_sfpsetsgn_v = 559,
  CODE_FOR_rvtt_bh_sfpsetexp_i_int = 560,
  CODE_FOR_rvtt_bh_sfpsetsgn_i_int = 561,
  CODE_FOR_rvtt_bh_sfpsetman_i_int = 562,
  CODE_FOR_rvtt_bh_sfpmad_int = 563,
  CODE_FOR_rvtt_bh_sfpsetcc_i = 564,
  CODE_FOR_rvtt_bh_sfpsetcc_v = 565,
  CODE_FOR_rvtt_bh_sfpencc = 566,
  CODE_FOR_rvtt_bh_sfpcompc = 567,
  CODE_FOR_rvtt_bh_sfppushc = 568,
  CODE_FOR_rvtt_bh_sfppopc = 569,
  CODE_FOR_rvtt_bh_sfplut = 570,
  CODE_FOR_rvtt_bh_sfplutfp32_3r = 571,
  CODE_FOR_rvtt_bh_sfplutfp32_6r = 572,
  CODE_FOR_rvtt_bh_sfpconfig_v = 573,
  CODE_FOR_rvtt_bh_sfpreplay = 574,
  CODE_FOR_rvtt_bh_sfpswap_int = 575,
  CODE_FOR_rvtt_bh_sfptransp = 576,
  CODE_FOR_rvtt_bh_sfpshft2_g = 577,
  CODE_FOR_rvtt_bh_sfpshft2_ge = 578,
  CODE_FOR_rvtt_bh_sfpnop = 579,
  CODE_FOR_rvtt_bh_sfpmul24_int = 580,
  CODE_FOR_rvtt_bh_sfparecip_int = 581,
  CODE_FOR_rvtt_bh_sfpgt = 582,
  CODE_FOR_rvtt_bh_sfple = 583,
  CODE_FOR_addvsi4 = 584,
  CODE_FOR_addvdi4 = 585,
  CODE_FOR_uaddvsi4 = 586,
  CODE_FOR_uaddvdi4 = 587,
  CODE_FOR_subvsi4 = 588,
  CODE_FOR_subvdi4 = 589,
  CODE_FOR_usubvsi4 = 590,
  CODE_FOR_usubvdi4 = 591,
  CODE_FOR_mulvsi4 = 592,
  CODE_FOR_mulvdi4 = 593,
  CODE_FOR_umulvsi4 = 594,
  CODE_FOR_umulvdi4 = 595,
  CODE_FOR_mulditi3 = 596,
  CODE_FOR_umulditi3 = 597,
  CODE_FOR_usmulditi3 = 598,
  CODE_FOR_mulsidi3 = 599,
  CODE_FOR_umulsidi3 = 600,
  CODE_FOR_usmulsidi3 = 601,
  CODE_FOR_zero_extendsidi2 = 602,
  CODE_FOR_zero_extendhisi2 = 603,
  CODE_FOR_zero_extendhidi2 = 604,
  CODE_FOR_extendqihi2 = 605,
  CODE_FOR_extendqisi2 = 606,
  CODE_FOR_extendqidi2 = 607,
  CODE_FOR_extendhihi2 = 608,
  CODE_FOR_extendhisi2 = 609,
  CODE_FOR_extendhidi2 = 610,
  CODE_FOR_movdi = 611,
  CODE_FOR_movsi = 612,
  CODE_FOR_movhi = 613,
  CODE_FOR_movqi = 614,
  CODE_FOR_movsf = 615,
  CODE_FOR_movdf = 616,
  CODE_FOR_cpymemsi = 617,
  CODE_FOR_clear_cache = 618,
  CODE_FOR_movsicc = 619,
  CODE_FOR_movdicc = 620,
  CODE_FOR_condjump = 621,
  CODE_FOR_cbranchqi4 = 622,
  CODE_FOR_cbranchsi4 = 623,
  CODE_FOR_cbranchdi4 = 624,
  CODE_FOR_cbranchsf4 = 625,
  CODE_FOR_cbranchdf4 = 626,
  CODE_FOR_cstoresi4 = 627,
  CODE_FOR_cstoredi4 = 628,
  CODE_FOR_cstoresf4 = 629,
  CODE_FOR_cstoredf4 = 630,
  CODE_FOR_flt_quietsfsi4 = 631,
  CODE_FOR_fle_quietsfsi4 = 632,
  CODE_FOR_flt_quietsfdi4 = 633,
  CODE_FOR_fle_quietsfdi4 = 634,
  CODE_FOR_flt_quietdfsi4 = 635,
  CODE_FOR_fle_quietdfsi4 = 636,
  CODE_FOR_flt_quietdfdi4 = 637,
  CODE_FOR_fle_quietdfdi4 = 638,
  CODE_FOR_indirect_jump = 639,
  CODE_FOR_tablejump = 640,
  CODE_FOR_prologue = 641,
  CODE_FOR_epilogue = 642,
  CODE_FOR_sibcall_epilogue = 643,
  CODE_FOR_return = 644,
  CODE_FOR_eh_return = 645,
  CODE_FOR_sibcall = 646,
  CODE_FOR_sibcall_value = 647,
  CODE_FOR_call = 648,
  CODE_FOR_call_value = 649,
  CODE_FOR_untyped_call = 650,
  CODE_FOR_restore_stack_nonlocal = 651,
  CODE_FOR_get_thread_pointersi = 652,
  CODE_FOR_get_thread_pointerdi = 653,
  CODE_FOR_stack_protect_set = 654,
  CODE_FOR_stack_protect_test = 655,
  CODE_FOR_mem_thread_fence = 656,
  CODE_FOR_atomic_compare_and_swapsi = 657,
  CODE_FOR_atomic_compare_and_swapdi = 658,
  CODE_FOR_atomic_test_and_set = 659,
  CODE_FOR_movv64sf = 660,
  CODE_FOR_rvtt_sfpassignlreg = 661,
  CODE_FOR_rvtt_sfpxicmps = 662,
  CODE_FOR_rvtt_sfpxicmpv = 663,
  CODE_FOR_rvtt_sfpxvif = 664,
  CODE_FOR_rvtt_sfpxbool = 665,
  CODE_FOR_rvtt_sfpxcondb = 666,
  CODE_FOR_rvtt_sfpxcondi = 667,
  CODE_FOR_rvtt_gs_sfppreservelreg = 668,
  CODE_FOR_rvtt_gs_sfpload = 669,
  CODE_FOR_rvtt_gs_sfpload_lv = 670,
  CODE_FOR_rvtt_gs_sfpxloadi = 671,
  CODE_FOR_rvtt_gs_sfpxloadi_lv = 672,
  CODE_FOR_rvtt_gs_sfpstore = 673,
  CODE_FOR_rvtt_gs_sfpmuli = 674,
  CODE_FOR_rvtt_gs_sfpaddi = 675,
  CODE_FOR_rvtt_gs_sfpdivp2 = 676,
  CODE_FOR_rvtt_gs_sfpdivp2_lv = 677,
  CODE_FOR_rvtt_gs_sfpexexp = 678,
  CODE_FOR_rvtt_gs_sfpexman = 679,
  CODE_FOR_rvtt_gs_sfpabs = 680,
  CODE_FOR_rvtt_gs_sfpmov = 681,
  CODE_FOR_rvtt_gs_sfplz = 682,
  CODE_FOR_rvtt_gs_sfpexexp_lv = 683,
  CODE_FOR_rvtt_gs_sfpexman_lv = 684,
  CODE_FOR_rvtt_gs_sfpabs_lv = 685,
  CODE_FOR_rvtt_gs_sfpmov_lv = 686,
  CODE_FOR_rvtt_gs_sfplz_lv = 687,
  CODE_FOR_rvtt_gs_sfpmul = 688,
  CODE_FOR_rvtt_gs_sfpadd = 689,
  CODE_FOR_rvtt_gs_sfpmul_lv = 690,
  CODE_FOR_rvtt_gs_sfpadd_lv = 691,
  CODE_FOR_rvtt_gs_sfpxiadd_v = 692,
  CODE_FOR_rvtt_gs_sfpxiadd_i = 693,
  CODE_FOR_rvtt_gs_sfpxiadd_i_lv = 694,
  CODE_FOR_rvtt_gs_sfpshft_i = 695,
  CODE_FOR_rvtt_gs_sfpnot = 696,
  CODE_FOR_rvtt_gs_sfpnot_lv = 697,
  CODE_FOR_rvtt_gs_sfpsetexp_i = 698,
  CODE_FOR_rvtt_gs_sfpsetman_i = 699,
  CODE_FOR_rvtt_gs_sfpsetsgn_i = 700,
  CODE_FOR_rvtt_gs_sfpsetexp_i_lv = 701,
  CODE_FOR_rvtt_gs_sfpsetman_i_lv = 702,
  CODE_FOR_rvtt_gs_sfpsetsgn_i_lv = 703,
  CODE_FOR_rvtt_gs_sfpmad = 704,
  CODE_FOR_rvtt_gs_sfpmad_lv = 705,
  CODE_FOR_rvtt_gs_sfpxfcmps = 706,
  CODE_FOR_rvtt_gs_sfpxfcmpv = 707,
  CODE_FOR_rvtt_wh_sfppreservelreg = 708,
  CODE_FOR_rvtt_wh_sfpload = 709,
  CODE_FOR_rvtt_wh_sfpload_lv = 710,
  CODE_FOR_rvtt_wh_sfpxloadi = 711,
  CODE_FOR_rvtt_wh_sfpxloadi_lv = 712,
  CODE_FOR_rvtt_wh_sfpstore = 713,
  CODE_FOR_rvtt_wh_sfpmuli = 714,
  CODE_FOR_rvtt_wh_sfpaddi = 715,
  CODE_FOR_rvtt_wh_sfpdivp2 = 716,
  CODE_FOR_rvtt_wh_sfpdivp2_lv = 717,
  CODE_FOR_rvtt_wh_sfpexexp = 718,
  CODE_FOR_rvtt_wh_sfpexman = 719,
  CODE_FOR_rvtt_wh_sfpabs = 720,
  CODE_FOR_rvtt_wh_sfpmov = 721,
  CODE_FOR_rvtt_wh_sfplz = 722,
  CODE_FOR_rvtt_wh_sfpexexp_lv = 723,
  CODE_FOR_rvtt_wh_sfpexman_lv = 724,
  CODE_FOR_rvtt_wh_sfpabs_lv = 725,
  CODE_FOR_rvtt_wh_sfpmov_lv = 726,
  CODE_FOR_rvtt_wh_sfplz_lv = 727,
  CODE_FOR_rvtt_wh_sfpmul = 728,
  CODE_FOR_rvtt_wh_sfpadd = 729,
  CODE_FOR_rvtt_wh_sfpmul_lv = 730,
  CODE_FOR_rvtt_wh_sfpadd_lv = 731,
  CODE_FOR_rvtt_wh_sfpxiadd_v = 732,
  CODE_FOR_rvtt_wh_sfpxiadd_i = 733,
  CODE_FOR_rvtt_wh_sfpxiadd_i_lv = 734,
  CODE_FOR_rvtt_wh_sfpshft_i = 735,
  CODE_FOR_rvtt_wh_sfpnot = 736,
  CODE_FOR_rvtt_wh_sfpnot_lv = 737,
  CODE_FOR_rvtt_wh_sfpcast = 738,
  CODE_FOR_rvtt_wh_sfpcast_lv = 739,
  CODE_FOR_rvtt_wh_sfpshft2_e = 740,
  CODE_FOR_rvtt_wh_sfpshft2_e_lv = 741,
  CODE_FOR_rvtt_wh_sfpstochrnd_i = 742,
  CODE_FOR_rvtt_wh_sfpstochrnd_i_lv = 743,
  CODE_FOR_rvtt_wh_sfpstochrnd_v = 744,
  CODE_FOR_rvtt_wh_sfpstochrnd_v_lv = 745,
  CODE_FOR_rvtt_wh_sfpsetexp_i = 746,
  CODE_FOR_rvtt_wh_sfpsetsgn_i = 747,
  CODE_FOR_rvtt_wh_sfpsetexp_i_lv = 748,
  CODE_FOR_rvtt_wh_sfpsetsgn_i_lv = 749,
  CODE_FOR_rvtt_wh_sfpsetman_i = 750,
  CODE_FOR_rvtt_wh_sfpsetman_i_lv = 751,
  CODE_FOR_rvtt_wh_sfpmad = 752,
  CODE_FOR_rvtt_wh_sfpmad_lv = 753,
  CODE_FOR_rvtt_wh_sfpxfcmps = 754,
  CODE_FOR_rvtt_wh_sfpxfcmpv = 755,
  CODE_FOR_rvtt_wh_sfpswap = 756,
  CODE_FOR_rvtt_bh_sfppreservelreg = 757,
  CODE_FOR_rvtt_bh_sfpload = 758,
  CODE_FOR_rvtt_bh_sfpload_lv = 759,
  CODE_FOR_rvtt_bh_sfpxloadi = 760,
  CODE_FOR_rvtt_bh_sfpxloadi_lv = 761,
  CODE_FOR_rvtt_bh_sfpstore = 762,
  CODE_FOR_rvtt_bh_sfpmuli = 763,
  CODE_FOR_rvtt_bh_sfpaddi = 764,
  CODE_FOR_rvtt_bh_sfpdivp2 = 765,
  CODE_FOR_rvtt_bh_sfpdivp2_lv = 766,
  CODE_FOR_rvtt_bh_sfpexexp = 767,
  CODE_FOR_rvtt_bh_sfpexman = 768,
  CODE_FOR_rvtt_bh_sfpabs = 769,
  CODE_FOR_rvtt_bh_sfpmov = 770,
  CODE_FOR_rvtt_bh_sfplz = 771,
  CODE_FOR_rvtt_bh_sfpexexp_lv = 772,
  CODE_FOR_rvtt_bh_sfpexman_lv = 773,
  CODE_FOR_rvtt_bh_sfpabs_lv = 774,
  CODE_FOR_rvtt_bh_sfpmov_lv = 775,
  CODE_FOR_rvtt_bh_sfplz_lv = 776,
  CODE_FOR_rvtt_bh_sfpmul = 777,
  CODE_FOR_rvtt_bh_sfpadd = 778,
  CODE_FOR_rvtt_bh_sfpmul_lv = 779,
  CODE_FOR_rvtt_bh_sfpadd_lv = 780,
  CODE_FOR_rvtt_bh_sfpxiadd_v = 781,
  CODE_FOR_rvtt_bh_sfpxiadd_i = 782,
  CODE_FOR_rvtt_bh_sfpxiadd_i_lv = 783,
  CODE_FOR_rvtt_bh_sfpshft_i = 784,
  CODE_FOR_rvtt_bh_sfpnot = 785,
  CODE_FOR_rvtt_bh_sfpnot_lv = 786,
  CODE_FOR_rvtt_bh_sfpcast = 787,
  CODE_FOR_rvtt_bh_sfpcast_lv = 788,
  CODE_FOR_rvtt_bh_sfpshft2_e = 789,
  CODE_FOR_rvtt_bh_sfpshft2_e_lv = 790,
  CODE_FOR_rvtt_bh_sfpstochrnd_i = 791,
  CODE_FOR_rvtt_bh_sfpstochrnd_i_lv = 792,
  CODE_FOR_rvtt_bh_sfpstochrnd_v = 793,
  CODE_FOR_rvtt_bh_sfpstochrnd_v_lv = 794,
  CODE_FOR_rvtt_bh_sfpsetexp_i = 795,
  CODE_FOR_rvtt_bh_sfpsetsgn_i = 796,
  CODE_FOR_rvtt_bh_sfpsetexp_i_lv = 797,
  CODE_FOR_rvtt_bh_sfpsetsgn_i_lv = 798,
  CODE_FOR_rvtt_bh_sfpsetman_i = 799,
  CODE_FOR_rvtt_bh_sfpsetman_i_lv = 800,
  CODE_FOR_rvtt_bh_sfpmad = 801,
  CODE_FOR_rvtt_bh_sfpmad_lv = 802,
  CODE_FOR_rvtt_bh_sfpxfcmps = 803,
  CODE_FOR_rvtt_bh_sfpxfcmpv = 804,
  CODE_FOR_rvtt_bh_sfpswap = 805,
  CODE_FOR_rvtt_bh_sfpmul24 = 806,
  CODE_FOR_rvtt_bh_sfpmul24_lv = 807,
  CODE_FOR_rvtt_bh_sfparecip = 808,
  CODE_FOR_rvtt_bh_sfparecip_lv = 809
};

const unsigned int NUM_INSN_CODES = 810;
#endif /* GCC_INSN_CODES_H */