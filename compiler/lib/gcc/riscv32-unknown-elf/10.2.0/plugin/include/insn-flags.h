/* Generated automatically by the program `genflags'
   from the machine description file `md'.  */

#ifndef GCC_INSN_FLAGS_H
#define GCC_INSN_FLAGS_H

#define HAVE_addsf3 (TARGET_HARD_FLOAT)
#define HAVE_adddf3 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_addsi3 1
#define HAVE_adddi3 (TARGET_64BIT)
#define HAVE_subsf3 (TARGET_HARD_FLOAT)
#define HAVE_subdf3 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_subdi3 (TARGET_64BIT)
#define HAVE_subsi3 1
#define HAVE_negdi2 (TARGET_64BIT)
#define HAVE_negsi2 1
#define HAVE_mulsf3 (TARGET_HARD_FLOAT)
#define HAVE_muldf3 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_mulsi3 (TARGET_MUL)
#define HAVE_muldi3 (TARGET_MUL && TARGET_64BIT)
#define HAVE_muldi3_highpart (TARGET_MUL && TARGET_64BIT)
#define HAVE_umuldi3_highpart (TARGET_MUL && TARGET_64BIT)
#define HAVE_usmuldi3_highpart (TARGET_MUL && TARGET_64BIT)
#define HAVE_mulsi3_highpart (TARGET_MUL && !TARGET_64BIT)
#define HAVE_umulsi3_highpart (TARGET_MUL && !TARGET_64BIT)
#define HAVE_usmulsi3_highpart (TARGET_MUL && !TARGET_64BIT)
#define HAVE_divsi3 (TARGET_DIV)
#define HAVE_udivsi3 (TARGET_DIV)
#define HAVE_modsi3 (TARGET_DIV)
#define HAVE_umodsi3 (TARGET_DIV)
#define HAVE_divdi3 (TARGET_DIV && TARGET_64BIT)
#define HAVE_udivdi3 (TARGET_DIV && TARGET_64BIT)
#define HAVE_moddi3 (TARGET_DIV && TARGET_64BIT)
#define HAVE_umoddi3 (TARGET_DIV && TARGET_64BIT)
#define HAVE_divsf3 ((TARGET_HARD_FLOAT && TARGET_FDIV) && (TARGET_HARD_FLOAT))
#define HAVE_divdf3 ((TARGET_HARD_FLOAT && TARGET_FDIV) && (TARGET_DOUBLE_FLOAT))
#define HAVE_sqrtsf2 ((TARGET_HARD_FLOAT && TARGET_FDIV) && (TARGET_HARD_FLOAT))
#define HAVE_sqrtdf2 ((TARGET_HARD_FLOAT && TARGET_FDIV) && (TARGET_DOUBLE_FLOAT))
#define HAVE_fmasf4 (TARGET_HARD_FLOAT)
#define HAVE_fmadf4 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_fmssf4 (TARGET_HARD_FLOAT)
#define HAVE_fmsdf4 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_fnmssf4 (TARGET_HARD_FLOAT)
#define HAVE_fnmsdf4 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_fnmasf4 (TARGET_HARD_FLOAT)
#define HAVE_fnmadf4 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_abssf2 (TARGET_HARD_FLOAT)
#define HAVE_absdf2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_copysignsf3 (TARGET_HARD_FLOAT)
#define HAVE_copysigndf3 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_negsf2 (TARGET_HARD_FLOAT)
#define HAVE_negdf2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_sminsf3 (TARGET_HARD_FLOAT)
#define HAVE_smindf3 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_smaxsf3 (TARGET_HARD_FLOAT)
#define HAVE_smaxdf3 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_andsi3 (!TARGET_64BIT)
#define HAVE_iorsi3 (!TARGET_64BIT)
#define HAVE_xorsi3 (!TARGET_64BIT)
#define HAVE_anddi3 (TARGET_64BIT)
#define HAVE_iordi3 (TARGET_64BIT)
#define HAVE_xordi3 (TARGET_64BIT)
#define HAVE_one_cmplsi2 (!TARGET_64BIT)
#define HAVE_one_cmpldi2 (TARGET_64BIT)
#define HAVE_truncdfsf2 (TARGET_DOUBLE_FLOAT)
#define HAVE_zero_extendsidi2 (TARGET_64BIT)
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendhidi2 (TARGET_64BIT)
#define HAVE_zero_extendqihi2 1
#define HAVE_zero_extendqisi2 1
#define HAVE_zero_extendqidi2 (TARGET_64BIT)
#define HAVE_extendsidi2 (TARGET_64BIT)
#define HAVE_extendqihi2 1
#define HAVE_extendqisi2 1
#define HAVE_extendqidi2 (TARGET_64BIT)
#define HAVE_extendhihi2 1
#define HAVE_extendhisi2 1
#define HAVE_extendhidi2 (TARGET_64BIT)
#define HAVE_extendsfdf2 (TARGET_DOUBLE_FLOAT)
#define HAVE_fix_truncsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_fix_truncsfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_HARD_FLOAT)))
#define HAVE_fix_truncdfsi2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_fix_truncdfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)))
#define HAVE_fixuns_truncsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_fixuns_truncsfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_HARD_FLOAT)))
#define HAVE_fixuns_truncdfsi2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_fixuns_truncdfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)))
#define HAVE_floatsisf2 (TARGET_HARD_FLOAT)
#define HAVE_floatdisf2 ((TARGET_HARD_FLOAT) && ((TARGET_HARD_FLOAT) && (TARGET_64BIT)))
#define HAVE_floatsidf2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_floatdidf2 ((TARGET_HARD_FLOAT) && ((TARGET_DOUBLE_FLOAT) && (TARGET_64BIT)))
#define HAVE_floatunssisf2 (TARGET_HARD_FLOAT)
#define HAVE_floatunsdisf2 ((TARGET_HARD_FLOAT) && ((TARGET_HARD_FLOAT) && (TARGET_64BIT)))
#define HAVE_floatunssidf2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_floatunsdidf2 ((TARGET_HARD_FLOAT) && ((TARGET_DOUBLE_FLOAT) && (TARGET_64BIT)))
#define HAVE_lrintsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_lroundsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_lrintsfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_HARD_FLOAT)))
#define HAVE_lroundsfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_HARD_FLOAT)))
#define HAVE_lrintdfsi2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_lrounddfsi2 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_lrintdfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)))
#define HAVE_lrounddfdi2 ((TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)))
#define HAVE_got_loadsi (Pmode == SImode)
#define HAVE_got_loaddi (Pmode == DImode)
#define HAVE_tls_add_tp_lesi (Pmode == SImode)
#define HAVE_tls_add_tp_ledi (Pmode == DImode)
#define HAVE_got_load_tls_gdsi (Pmode == SImode)
#define HAVE_got_load_tls_gddi (Pmode == DImode)
#define HAVE_got_load_tls_iesi (Pmode == SImode)
#define HAVE_got_load_tls_iedi (Pmode == DImode)
#define HAVE_auipcsi (Pmode == SImode)
#define HAVE_auipcdi (Pmode == DImode)
#define HAVE_fence 1
#define HAVE_fence_i 1
#define HAVE_ashlsi3 1
#define HAVE_ashrsi3 1
#define HAVE_lshrsi3 1
#define HAVE_ashldi3 (TARGET_64BIT)
#define HAVE_ashrdi3 (TARGET_64BIT)
#define HAVE_lshrdi3 (TARGET_64BIT)
#define HAVE_zero_extendsidi2_shifted (TARGET_64BIT \
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff))
#define HAVE_jump 1
#define HAVE_indirect_jumpsi (Pmode == SImode)
#define HAVE_indirect_jumpdi (Pmode == DImode)
#define HAVE_tablejumpsi 1
#define HAVE_tablejumpdi (TARGET_64BIT)
#define HAVE_blockage 1
#define HAVE_simple_return 1
#define HAVE_simple_return_internal 1
#define HAVE_eh_set_lr_si (! TARGET_64BIT)
#define HAVE_eh_set_lr_di (TARGET_64BIT)
#define HAVE_eh_return_internal 1
#define HAVE_sibcall_internal (SIBLING_CALL_P (insn))
#define HAVE_sibcall_value_internal (SIBLING_CALL_P (insn))
#define HAVE_call_internal 1
#define HAVE_call_value_internal 1
#define HAVE_nop 1
#define HAVE_trap 1
#define HAVE_gpr_save 1
#define HAVE_gpr_restore 1
#define HAVE_gpr_restore_return 1
#define HAVE_riscv_frflags (TARGET_HARD_FLOAT)
#define HAVE_riscv_fsflags (TARGET_HARD_FLOAT)
#define HAVE_riscv_mret 1
#define HAVE_riscv_sret 1
#define HAVE_riscv_uret 1
#define HAVE_stack_tiesi (!TARGET_64BIT)
#define HAVE_stack_tiedi (TARGET_64BIT)
#define HAVE_mem_thread_fence_1 1
#define HAVE_atomic_storesi (TARGET_ATOMIC)
#define HAVE_atomic_storedi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_addsi (TARGET_ATOMIC)
#define HAVE_atomic_orsi (TARGET_ATOMIC)
#define HAVE_atomic_xorsi (TARGET_ATOMIC)
#define HAVE_atomic_andsi (TARGET_ATOMIC)
#define HAVE_atomic_adddi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_ordi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_xordi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_anddi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_fetch_addsi (TARGET_ATOMIC)
#define HAVE_atomic_fetch_orsi (TARGET_ATOMIC)
#define HAVE_atomic_fetch_xorsi (TARGET_ATOMIC)
#define HAVE_atomic_fetch_andsi (TARGET_ATOMIC)
#define HAVE_atomic_fetch_adddi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_fetch_ordi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_fetch_xordi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_fetch_anddi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_exchangesi (TARGET_ATOMIC)
#define HAVE_atomic_exchangedi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_cas_value_strongsi (TARGET_ATOMIC)
#define HAVE_atomic_cas_value_strongdi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_riscv_sfpassignlr_int (TARGET_SFPU_GS || TARGET_SFPU_WH)
#define HAVE_riscv_sfpnonimm_dst (TARGET_SFPU_GS || TARGET_SFPU_WH)
#define HAVE_riscv_sfpnonimm_dst_src (TARGET_SFPU_GS || TARGET_SFPU_WH)
#define HAVE_riscv_sfpnonimm_src (TARGET_SFPU_GS || TARGET_SFPU_WH)
#define HAVE_riscv_sfpnonimm_store (TARGET_SFPU_GS || TARGET_SFPU_WH)
#define HAVE_riscv_gs_sfpassign_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpkeepalive0_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpkeepalive1_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpkeepalive2_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpkeepalive3_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpload_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfploadi_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpstore_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmuli_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpaddi_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpdivp2_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpexexp_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpexman_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpabs_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmov_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfplz_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmul_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpadd_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpiadd_v (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpiadd_i_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpshft_v (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpshft_i_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpand (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpor (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpnot_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetexp_v (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetman_v (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetsgn_v (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetexp_i_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetman_i_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetsgn_i_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmad_int (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetcc_i (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetcc_v (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpencc (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpcompc (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfppushc (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfppopc (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfplut (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpnop (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpincrwc (TARGET_SFPU_GS)
#define HAVE_riscv_wh_sfpassign_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive0_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive1_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive2_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive3_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive4_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive5_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive6_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive7_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpload_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfploadi_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstore_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmuli_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpaddi_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpdivp2_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpexexp_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpexman_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpabs_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmov_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfplz_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmul_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpadd_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpiadd_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpiadd_i_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft_i_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpand (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpor (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxor (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpnot_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpcast_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft2_e_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstochrnd_i_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstochrnd_v_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetexp_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetman_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetsgn_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetexp_i_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetsgn_i_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetman_i_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmad_int (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetcc_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetcc_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpencc (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpcompc (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfppushc (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfppopc (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfplut (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfplutfp32_3r (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfplutfp32_6r (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpconfig_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpreplay (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpswap (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfptransp (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft2_g (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft2_ge (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpnop (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpincrwc (TARGET_SFPU_WH)
#define HAVE_mulditi3 (TARGET_MUL && TARGET_64BIT)
#define HAVE_umulditi3 (TARGET_MUL && TARGET_64BIT)
#define HAVE_usmulditi3 (TARGET_MUL && TARGET_64BIT)
#define HAVE_mulsidi3 (TARGET_MUL && !TARGET_64BIT)
#define HAVE_umulsidi3 (TARGET_MUL && !TARGET_64BIT)
#define HAVE_usmulsidi3 (TARGET_MUL && !TARGET_64BIT)
#define HAVE_movdi 1
#define HAVE_movsi 1
#define HAVE_movhi 1
#define HAVE_movqi 1
#define HAVE_movsf 1
#define HAVE_movdf 1
#define HAVE_cpymemsi 1
#define HAVE_clear_cache 1
#define HAVE_movsicc (TARGET_SFB_ALU)
#define HAVE_movdicc ((TARGET_SFB_ALU) && (TARGET_64BIT))
#define HAVE_condjump 1
#define HAVE_cbranchqi4 (TARGET_64BIT)
#define HAVE_cbranchsi4 1
#define HAVE_cbranchdi4 (TARGET_64BIT)
#define HAVE_cbranchsf4 (TARGET_HARD_FLOAT)
#define HAVE_cbranchdf4 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_cstoresi4 1
#define HAVE_cstoredi4 (TARGET_64BIT)
#define HAVE_cstoresf4 (TARGET_HARD_FLOAT)
#define HAVE_cstoredf4 ((TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT))
#define HAVE_flt_quietsfsi4 ((TARGET_HARD_FLOAT) && ((((!TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (!TARGET_64BIT)))
#define HAVE_fle_quietsfsi4 ((TARGET_HARD_FLOAT) && ((((!TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (!TARGET_64BIT)))
#define HAVE_flt_quietsfdi4 ((TARGET_HARD_FLOAT) && ((((TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (TARGET_64BIT)))
#define HAVE_fle_quietsfdi4 ((TARGET_HARD_FLOAT) && ((((TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (TARGET_64BIT)))
#define HAVE_flt_quietdfsi4 ((TARGET_HARD_FLOAT) && ((((!TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (!TARGET_64BIT)))
#define HAVE_fle_quietdfsi4 ((TARGET_HARD_FLOAT) && ((((!TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (!TARGET_64BIT)))
#define HAVE_flt_quietdfdi4 ((TARGET_HARD_FLOAT) && ((((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (TARGET_64BIT)))
#define HAVE_fle_quietdfdi4 ((TARGET_HARD_FLOAT) && ((((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (TARGET_64BIT)))
#define HAVE_indirect_jump 1
#define HAVE_tablejump 1
#define HAVE_prologue 1
#define HAVE_epilogue 1
#define HAVE_sibcall_epilogue 1
#define HAVE_return (riscv_can_use_return_insn ())
#define HAVE_eh_return 1
#define HAVE_sibcall 1
#define HAVE_sibcall_value 1
#define HAVE_call 1
#define HAVE_call_value 1
#define HAVE_untyped_call 1
#define HAVE_restore_stack_nonlocal 1
#define HAVE_mem_thread_fence 1
#define HAVE_atomic_compare_and_swapsi (TARGET_ATOMIC)
#define HAVE_atomic_compare_and_swapdi ((TARGET_ATOMIC) && (TARGET_64BIT))
#define HAVE_atomic_test_and_set (TARGET_ATOMIC)
#define HAVE_movv64sf 1
#define HAVE_riscv_gs_sfpassignlr (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpkeepalive (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpload (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpload_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxloadi (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxloadi_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpstore (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmuli (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpaddi (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpdivp2 (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpdivp2_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpexexp (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpexman (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpabs (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmov (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfplz (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpexexp_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpexman_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpabs_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmov_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfplz_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmul (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpadd (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmul_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpadd_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpiadd_i (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpiadd_i_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxiadd_v (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxiadd_i (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxiadd_i_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpshft_i (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpnot (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpnot_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetexp_i (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetman_i (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetsgn_i (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetexp_i_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetman_i_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpsetsgn_i_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmad (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpmad_lv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxfcmps (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxfcmpv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxicmps (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxicmpv (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxvif (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxbool (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxcondb (TARGET_SFPU_GS)
#define HAVE_riscv_gs_sfpxcondi (TARGET_SFPU_GS)
#define HAVE_riscv_wh_sfpassignlr (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpkeepalive (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpload (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpload_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxloadi (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxloadi_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstore (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmuli (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpaddi (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpdivp2 (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpdivp2_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpexexp (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpexman (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpabs (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmov (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfplz (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpexexp_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpexman_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpabs_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmov_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfplz_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmul (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpadd (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmul_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpadd_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpiadd_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpiadd_i_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxiadd_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxiadd_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxiadd_i_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpnot (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpnot_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpcast (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpcast_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft2_e (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpshft2_e_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstochrnd_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstochrnd_i_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstochrnd_v (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpstochrnd_v_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetexp_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetsgn_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetexp_i_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetsgn_i_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetman_i (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpsetman_i_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmad (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpmad_lv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxfcmps (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxfcmpv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxicmps (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxicmpv (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxvif (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxbool (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxcondb (TARGET_SFPU_WH)
#define HAVE_riscv_wh_sfpxcondi (TARGET_SFPU_WH)
extern rtx        gen_addsf3                     (rtx, rtx, rtx);
extern rtx        gen_adddf3                     (rtx, rtx, rtx);
extern rtx        gen_addsi3                     (rtx, rtx, rtx);
extern rtx        gen_adddi3                     (rtx, rtx, rtx);
extern rtx        gen_subsf3                     (rtx, rtx, rtx);
extern rtx        gen_subdf3                     (rtx, rtx, rtx);
extern rtx        gen_subdi3                     (rtx, rtx, rtx);
extern rtx        gen_subsi3                     (rtx, rtx, rtx);
extern rtx        gen_negdi2                     (rtx, rtx);
extern rtx        gen_negsi2                     (rtx, rtx);
extern rtx        gen_mulsf3                     (rtx, rtx, rtx);
extern rtx        gen_muldf3                     (rtx, rtx, rtx);
extern rtx        gen_mulsi3                     (rtx, rtx, rtx);
extern rtx        gen_muldi3                     (rtx, rtx, rtx);
extern rtx        gen_muldi3_highpart            (rtx, rtx, rtx);
extern rtx        gen_umuldi3_highpart           (rtx, rtx, rtx);
extern rtx        gen_usmuldi3_highpart          (rtx, rtx, rtx);
extern rtx        gen_mulsi3_highpart            (rtx, rtx, rtx);
extern rtx        gen_umulsi3_highpart           (rtx, rtx, rtx);
extern rtx        gen_usmulsi3_highpart          (rtx, rtx, rtx);
extern rtx        gen_divsi3                     (rtx, rtx, rtx);
extern rtx        gen_udivsi3                    (rtx, rtx, rtx);
extern rtx        gen_modsi3                     (rtx, rtx, rtx);
extern rtx        gen_umodsi3                    (rtx, rtx, rtx);
extern rtx        gen_divdi3                     (rtx, rtx, rtx);
extern rtx        gen_udivdi3                    (rtx, rtx, rtx);
extern rtx        gen_moddi3                     (rtx, rtx, rtx);
extern rtx        gen_umoddi3                    (rtx, rtx, rtx);
extern rtx        gen_divsf3                     (rtx, rtx, rtx);
extern rtx        gen_divdf3                     (rtx, rtx, rtx);
extern rtx        gen_sqrtsf2                    (rtx, rtx);
extern rtx        gen_sqrtdf2                    (rtx, rtx);
extern rtx        gen_fmasf4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fmadf4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fmssf4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsdf4                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmssf4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsdf4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmasf4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmadf4                    (rtx, rtx, rtx, rtx);
extern rtx        gen_abssf2                     (rtx, rtx);
extern rtx        gen_absdf2                     (rtx, rtx);
extern rtx        gen_copysignsf3                (rtx, rtx, rtx);
extern rtx        gen_copysigndf3                (rtx, rtx, rtx);
extern rtx        gen_negsf2                     (rtx, rtx);
extern rtx        gen_negdf2                     (rtx, rtx);
extern rtx        gen_sminsf3                    (rtx, rtx, rtx);
extern rtx        gen_smindf3                    (rtx, rtx, rtx);
extern rtx        gen_smaxsf3                    (rtx, rtx, rtx);
extern rtx        gen_smaxdf3                    (rtx, rtx, rtx);
extern rtx        gen_andsi3                     (rtx, rtx, rtx);
extern rtx        gen_iorsi3                     (rtx, rtx, rtx);
extern rtx        gen_xorsi3                     (rtx, rtx, rtx);
extern rtx        gen_anddi3                     (rtx, rtx, rtx);
extern rtx        gen_iordi3                     (rtx, rtx, rtx);
extern rtx        gen_xordi3                     (rtx, rtx, rtx);
extern rtx        gen_one_cmplsi2                (rtx, rtx);
extern rtx        gen_one_cmpldi2                (rtx, rtx);
extern rtx        gen_truncdfsf2                 (rtx, rtx);
extern rtx        gen_zero_extendsidi2           (rtx, rtx);
extern rtx        gen_zero_extendhisi2           (rtx, rtx);
extern rtx        gen_zero_extendhidi2           (rtx, rtx);
extern rtx        gen_zero_extendqihi2           (rtx, rtx);
extern rtx        gen_zero_extendqisi2           (rtx, rtx);
extern rtx        gen_zero_extendqidi2           (rtx, rtx);
extern rtx        gen_extendsidi2                (rtx, rtx);
extern rtx        gen_extendqihi2                (rtx, rtx);
extern rtx        gen_extendqisi2                (rtx, rtx);
extern rtx        gen_extendqidi2                (rtx, rtx);
extern rtx        gen_extendhihi2                (rtx, rtx);
extern rtx        gen_extendhisi2                (rtx, rtx);
extern rtx        gen_extendhidi2                (rtx, rtx);
extern rtx        gen_extendsfdf2                (rtx, rtx);
extern rtx        gen_fix_truncsfsi2             (rtx, rtx);
extern rtx        gen_fix_truncsfdi2             (rtx, rtx);
extern rtx        gen_fix_truncdfsi2             (rtx, rtx);
extern rtx        gen_fix_truncdfdi2             (rtx, rtx);
extern rtx        gen_fixuns_truncsfsi2          (rtx, rtx);
extern rtx        gen_fixuns_truncsfdi2          (rtx, rtx);
extern rtx        gen_fixuns_truncdfsi2          (rtx, rtx);
extern rtx        gen_fixuns_truncdfdi2          (rtx, rtx);
extern rtx        gen_floatsisf2                 (rtx, rtx);
extern rtx        gen_floatdisf2                 (rtx, rtx);
extern rtx        gen_floatsidf2                 (rtx, rtx);
extern rtx        gen_floatdidf2                 (rtx, rtx);
extern rtx        gen_floatunssisf2              (rtx, rtx);
extern rtx        gen_floatunsdisf2              (rtx, rtx);
extern rtx        gen_floatunssidf2              (rtx, rtx);
extern rtx        gen_floatunsdidf2              (rtx, rtx);
extern rtx        gen_lrintsfsi2                 (rtx, rtx);
extern rtx        gen_lroundsfsi2                (rtx, rtx);
extern rtx        gen_lrintsfdi2                 (rtx, rtx);
extern rtx        gen_lroundsfdi2                (rtx, rtx);
extern rtx        gen_lrintdfsi2                 (rtx, rtx);
extern rtx        gen_lrounddfsi2                (rtx, rtx);
extern rtx        gen_lrintdfdi2                 (rtx, rtx);
extern rtx        gen_lrounddfdi2                (rtx, rtx);
extern rtx        gen_got_loadsi                 (rtx, rtx);
extern rtx        gen_got_loaddi                 (rtx, rtx);
extern rtx        gen_tls_add_tp_lesi            (rtx, rtx, rtx, rtx);
extern rtx        gen_tls_add_tp_ledi            (rtx, rtx, rtx, rtx);
extern rtx        gen_got_load_tls_gdsi          (rtx, rtx);
extern rtx        gen_got_load_tls_gddi          (rtx, rtx);
extern rtx        gen_got_load_tls_iesi          (rtx, rtx);
extern rtx        gen_got_load_tls_iedi          (rtx, rtx);
extern rtx        gen_auipcsi                    (rtx, rtx, rtx);
extern rtx        gen_auipcdi                    (rtx, rtx, rtx);
extern rtx        gen_fence                      (void);
extern rtx        gen_fence_i                    (void);
extern rtx        gen_ashlsi3                    (rtx, rtx, rtx);
extern rtx        gen_ashrsi3                    (rtx, rtx, rtx);
extern rtx        gen_lshrsi3                    (rtx, rtx, rtx);
extern rtx        gen_ashldi3                    (rtx, rtx, rtx);
extern rtx        gen_ashrdi3                    (rtx, rtx, rtx);
extern rtx        gen_lshrdi3                    (rtx, rtx, rtx);
extern rtx        gen_zero_extendsidi2_shifted   (rtx, rtx, rtx, rtx);
extern rtx        gen_jump                       (rtx);
extern rtx        gen_indirect_jumpsi            (rtx);
extern rtx        gen_indirect_jumpdi            (rtx);
extern rtx        gen_tablejumpsi                (rtx, rtx);
extern rtx        gen_tablejumpdi                (rtx, rtx);
extern rtx        gen_blockage                   (void);
extern rtx        gen_simple_return              (void);
extern rtx        gen_simple_return_internal     (rtx);
extern rtx        gen_eh_set_lr_si               (rtx);
extern rtx        gen_eh_set_lr_di               (rtx);
extern rtx        gen_eh_return_internal         (void);
extern rtx        gen_sibcall_internal           (rtx, rtx);
extern rtx        gen_sibcall_value_internal     (rtx, rtx, rtx);
extern rtx        gen_call_internal              (rtx, rtx);
extern rtx        gen_call_value_internal        (rtx, rtx, rtx);
extern rtx        gen_nop                        (void);
extern rtx        gen_trap                       (void);
extern rtx        gen_gpr_save                   (rtx, rtx);
extern rtx        gen_gpr_restore                (rtx);
extern rtx        gen_gpr_restore_return         (rtx);
extern rtx        gen_riscv_frflags              (rtx);
extern rtx        gen_riscv_fsflags              (rtx);
extern rtx        gen_riscv_mret                 (void);
extern rtx        gen_riscv_sret                 (void);
extern rtx        gen_riscv_uret                 (void);
extern rtx        gen_stack_tiesi                (rtx, rtx);
extern rtx        gen_stack_tiedi                (rtx, rtx);
extern rtx        gen_mem_thread_fence_1         (rtx, rtx);
extern rtx        gen_atomic_storesi             (rtx, rtx, rtx);
extern rtx        gen_atomic_storedi             (rtx, rtx, rtx);
extern rtx        gen_atomic_addsi               (rtx, rtx, rtx);
extern rtx        gen_atomic_orsi                (rtx, rtx, rtx);
extern rtx        gen_atomic_xorsi               (rtx, rtx, rtx);
extern rtx        gen_atomic_andsi               (rtx, rtx, rtx);
extern rtx        gen_atomic_adddi               (rtx, rtx, rtx);
extern rtx        gen_atomic_ordi                (rtx, rtx, rtx);
extern rtx        gen_atomic_xordi               (rtx, rtx, rtx);
extern rtx        gen_atomic_anddi               (rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addsi         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_orsi          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_xorsi         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_andsi         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_adddi         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_ordi          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_xordi         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_anddi         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangesi          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangedi          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_cas_value_strongsi  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_cas_value_strongdi  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_sfpassignlr_int      (rtx);
extern rtx        gen_riscv_sfpnonimm_dst        (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_sfpnonimm_dst_src    (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_sfpnonimm_src        (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_sfpnonimm_store      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpassign_lv      (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpkeepalive0_int (rtx);
extern rtx        gen_riscv_gs_sfpkeepalive1_int (rtx);
extern rtx        gen_riscv_gs_sfpkeepalive2_int (rtx);
extern rtx        gen_riscv_gs_sfpkeepalive3_int (rtx);
extern rtx        gen_riscv_gs_sfpload_int       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfploadi_int      (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpstore_int      (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmuli_int       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpaddi_int       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpdivp2_int      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpexexp_int      (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpexman_int      (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpabs_int        (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmov_int        (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfplz_int         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmul_int        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpadd_int        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpiadd_v         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpiadd_i_int     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpshft_v         (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpshft_i_int     (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpand            (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpor             (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpnot_int        (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetexp_v       (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetman_v       (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetsgn_v       (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetexp_i_int   (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetman_i_int   (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetsgn_i_int   (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmad_int        (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetcc_i        (rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetcc_v        (rtx, rtx);
extern rtx        gen_riscv_gs_sfpencc           (rtx, rtx);
extern rtx        gen_riscv_gs_sfpcompc          (void);
extern rtx        gen_riscv_gs_sfppushc          (void);
extern rtx        gen_riscv_gs_sfppopc           (void);
extern rtx        gen_riscv_gs_sfplut            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpnop            (void);
extern rtx        gen_riscv_gs_sfpincrwc         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpassign_lv      (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpkeepalive0_int (rtx);
extern rtx        gen_riscv_wh_sfpkeepalive1_int (rtx);
extern rtx        gen_riscv_wh_sfpkeepalive2_int (rtx);
extern rtx        gen_riscv_wh_sfpkeepalive3_int (rtx);
extern rtx        gen_riscv_wh_sfpkeepalive4_int (rtx);
extern rtx        gen_riscv_wh_sfpkeepalive5_int (rtx);
extern rtx        gen_riscv_wh_sfpkeepalive6_int (rtx);
extern rtx        gen_riscv_wh_sfpkeepalive7_int (rtx);
extern rtx        gen_riscv_wh_sfpload_int       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfploadi_int      (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstore_int      (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmuli_int       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpaddi_int       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpdivp2_int      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpexexp_int      (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpexman_int      (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpabs_int        (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmov_int        (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfplz_int         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmul_int        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpadd_int        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpiadd_v         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpiadd_i_int     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft_v         (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft_i_int     (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpand            (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpor             (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxor            (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpnot_int        (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpcast_int       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft2_e_int    (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstochrnd_i_int (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstochrnd_v_int (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetexp_v       (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetman_v       (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetsgn_v       (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetexp_i_int   (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetsgn_i_int   (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetman_i_int   (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmad_int        (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetcc_i        (rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetcc_v        (rtx, rtx);
extern rtx        gen_riscv_wh_sfpencc           (rtx, rtx);
extern rtx        gen_riscv_wh_sfpcompc          (void);
extern rtx        gen_riscv_wh_sfppushc          (rtx);
extern rtx        gen_riscv_wh_sfppopc           (rtx);
extern rtx        gen_riscv_wh_sfplut            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfplutfp32_3r     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfplutfp32_6r     (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpconfig_v       (rtx, rtx);
extern rtx        gen_riscv_wh_sfpreplay         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpswap           (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfptransp         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft2_g        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft2_ge       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpnop            (void);
extern rtx        gen_riscv_wh_sfpincrwc         (rtx, rtx, rtx, rtx);
extern rtx        gen_mulditi3                   (rtx, rtx, rtx);
extern rtx        gen_umulditi3                  (rtx, rtx, rtx);
extern rtx        gen_usmulditi3                 (rtx, rtx, rtx);
extern rtx        gen_mulsidi3                   (rtx, rtx, rtx);
extern rtx        gen_umulsidi3                  (rtx, rtx, rtx);
extern rtx        gen_usmulsidi3                 (rtx, rtx, rtx);
extern rtx        gen_movdi                      (rtx, rtx);
extern rtx        gen_movsi                      (rtx, rtx);
extern rtx        gen_movhi                      (rtx, rtx);
extern rtx        gen_movqi                      (rtx, rtx);
extern rtx        gen_movsf                      (rtx, rtx);
extern rtx        gen_movdf                      (rtx, rtx);
extern rtx        gen_cpymemsi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_clear_cache                (rtx, rtx);
extern rtx        gen_movsicc                    (rtx, rtx, rtx, rtx);
extern rtx        gen_movdicc                    (rtx, rtx, rtx, rtx);
extern rtx        gen_condjump                   (rtx, rtx);
extern rtx        gen_cbranchqi4                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsi4                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdi4                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsf4                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdf4                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresf4                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredf4                  (rtx, rtx, rtx, rtx);
extern rtx        gen_flt_quietsfsi4             (rtx, rtx, rtx);
extern rtx        gen_fle_quietsfsi4             (rtx, rtx, rtx);
extern rtx        gen_flt_quietsfdi4             (rtx, rtx, rtx);
extern rtx        gen_fle_quietsfdi4             (rtx, rtx, rtx);
extern rtx        gen_flt_quietdfsi4             (rtx, rtx, rtx);
extern rtx        gen_fle_quietdfsi4             (rtx, rtx, rtx);
extern rtx        gen_flt_quietdfdi4             (rtx, rtx, rtx);
extern rtx        gen_fle_quietdfdi4             (rtx, rtx, rtx);
extern rtx        gen_indirect_jump              (rtx);
extern rtx        gen_tablejump                  (rtx, rtx);
extern rtx        gen_prologue                   (void);
extern rtx        gen_epilogue                   (void);
extern rtx        gen_sibcall_epilogue           (void);
extern rtx        gen_return                     (void);
extern rtx        gen_eh_return                  (rtx);
extern rtx        gen_sibcall                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sibcall_value              (rtx, rtx, rtx, rtx);
extern rtx        gen_call                       (rtx, rtx, rtx, rtx);
extern rtx        gen_call_value                 (rtx, rtx, rtx, rtx);
extern rtx        gen_untyped_call               (rtx, rtx, rtx);
extern rtx        gen_restore_stack_nonlocal     (rtx, rtx);
extern rtx        gen_mem_thread_fence           (rtx);
extern rtx        gen_atomic_compare_and_swapsi  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapdi  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_test_and_set        (rtx, rtx, rtx);
extern rtx        gen_movv64sf                   (rtx, rtx);
extern rtx        gen_riscv_gs_sfpassignlr       (rtx, rtx);
extern rtx        gen_riscv_gs_sfpkeepalive      (rtx, rtx);
extern rtx        gen_riscv_gs_sfpload           (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpload_lv        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxloadi         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxloadi_lv      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpstore          (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmuli           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpaddi           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpdivp2          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpdivp2_lv       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpexexp          (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpexman          (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpabs            (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmov            (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfplz             (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpexexp_lv       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpexman_lv       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpabs_lv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmov_lv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfplz_lv          (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmul            (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpadd            (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmul_lv         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpadd_lv         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpiadd_i         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpiadd_i_lv      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxiadd_v        (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxiadd_i        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxiadd_i_lv     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpshft_i         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpnot            (rtx, rtx);
extern rtx        gen_riscv_gs_sfpnot_lv         (rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetexp_i       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetman_i       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetsgn_i       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetexp_i_lv    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetman_i_lv    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpsetsgn_i_lv    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmad            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpmad_lv         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxfcmps         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxfcmpv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxicmps         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxicmpv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_gs_sfpxvif           (rtx);
extern rtx        gen_riscv_gs_sfpxbool          (rtx, rtx);
extern rtx        gen_riscv_gs_sfpxcondb         (rtx, rtx);
extern rtx        gen_riscv_gs_sfpxcondi         (rtx, rtx);
extern rtx        gen_riscv_wh_sfpassignlr       (rtx, rtx);
extern rtx        gen_riscv_wh_sfpkeepalive      (rtx, rtx);
extern rtx        gen_riscv_wh_sfpload           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpload_lv        (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxloadi         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxloadi_lv      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstore          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmuli           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpaddi           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpdivp2          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpdivp2_lv       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpexexp          (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpexman          (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpabs            (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmov            (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfplz             (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpexexp_lv       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpexman_lv       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpabs_lv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmov_lv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfplz_lv          (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmul            (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpadd            (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmul_lv         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpadd_lv         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpiadd_i         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpiadd_i_lv      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxiadd_v        (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxiadd_i        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxiadd_i_lv     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft_i         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpnot            (rtx, rtx);
extern rtx        gen_riscv_wh_sfpnot_lv         (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpcast           (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpcast_lv        (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft2_e        (rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpshft2_e_lv     (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstochrnd_i     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstochrnd_i_lv  (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstochrnd_v     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpstochrnd_v_lv  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetexp_i       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetsgn_i       (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetexp_i_lv    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetsgn_i_lv    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetman_i       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpsetman_i_lv    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmad            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpmad_lv         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxfcmps         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxfcmpv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxicmps         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxicmpv         (rtx, rtx, rtx, rtx);
extern rtx        gen_riscv_wh_sfpxvif           (rtx);
extern rtx        gen_riscv_wh_sfpxbool          (rtx, rtx);
extern rtx        gen_riscv_wh_sfpxcondb         (rtx, rtx);
extern rtx        gen_riscv_wh_sfpxcondi         (rtx, rtx);

#endif /* GCC_INSN_FLAGS_H */
