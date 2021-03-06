/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


#ifndef TDF_H
#define TDF_H


/* AUTOMATICALLY GENERATED BY make_tdf VERSION 2.0 FROM TDF 4.1 */

void init_constructs(void);
sortname find_sort(char);

node *de_access(void);
node *de_al_tag(void);
long de_al_tagdef_bits(void);
node *de_alignment(void);
node *de_bitfield_variety(void);
node *de_bool(void);
node *de_callees(void);
node *de_error_code(void);
node *de_error_treatment(void);
node *de_exp(void);
long de_external_bits(void);
node *de_floating_variety(void);
node *de_label(void);
node *de_nat(void);
node *de_ntest(void);
node *de_procprops(void);
node *de_rounding_mode(void);
node *de_shape(void);
node *de_signed_nat(void);
long de_sortname_bits(void);
node *de_string(void);
node *de_tag(void);
long de_tagdec_bits(void);
long de_tagdef_bits(void);
long de_tokdec_bits(void);
long de_tokdef_bits(void);
long de_token_bits(void);
long de_token_defn_bits(void);
node *de_transfer_mode(void);
node *de_variety(void);
long de_version_bits(void);

#ifdef ENC_TYPES_H
void enc_al_tag_bits(bitstream *, int);
void enc_al_tagdef_bits(bitstream *, int);
void enc_external_bits(bitstream *, int);
void enc_label_bits(bitstream *, int);
void enc_sortname_bits(bitstream *, int);
void enc_tag_bits(bitstream *, int);
void enc_tagdec_bits(bitstream *, int);
void enc_tagdef_bits(bitstream *, int);
void enc_tokdec_bits(bitstream *, int);
void enc_tokdef_bits(bitstream *, int);
void enc_token_bits(bitstream *, int);
void enc_token_defn_bits(bitstream *, int);
void enc_version_bits(bitstream *, int);
#endif /* ENC_TYPES_H */

node *read_access(long);
node *read_al_tag(long);
node *read_alignment(long);
node *read_bitfield_variety(long);
node *read_bool(long);
node *read_callees(long);
node *read_error_code(long);
node *read_error_treatment(long);
node *read_exp(long);
node *read_floating_variety(long);
node *read_label(long);
node *read_nat(long);
node *read_ntest(long);
node *read_procprops(long);
node *read_rounding_mode(long);
node *read_shape(long);
node *read_signed_nat(long);
node *read_string(long);
node *read_tag(long);
node *read_transfer_mode(long);
node *read_variety(long);

#define VERSION_capsule				MAGIC_NUMBER
#define VERSION_library				MAGIC_LINK_NUMBER
#define VERSION_major				4
#define VERSION_minor				1

#define LINK_al_tagdef_props			"aldef"
#define LINK_tagdec_props			"tagdec"
#define LINK_tagdef_props			"tagdef"
#define LINK_tokdec_props			"tokdec"
#define LINK_tokdef_props			"tokdef"
#define LINK_version_props			"versions"
#define LINK_tld_props				"tld"

#define LINK_al_tag				"alignment"
#define LINK_tag				"tag"
#define LINK_token				"token"

#define SORT_access				1
#define SORT_al_tag				2
#define SORT_alignment				3
#define SORT_bitfield_variety			4
#define SORT_bool				5
#define SORT_error_treatment			6
#define SORT_exp				7
#define SORT_floating_variety			8
#define SORT_foreign_sort			9
#define SORT_label				10
#define SORT_nat				11
#define SORT_ntest				12
#define SORT_procprops				13
#define SORT_rounding_mode			14
#define SORT_shape				15
#define SORT_signed_nat				16
#define SORT_string				17
#define SORT_tag				18
#define SORT_transfer_mode			19
#define SORT_token				20
#define SORT_variety				21
#define SORT_foreign				ENC_foreign_sort
#define SORT_callees				22
#define SORT_error_code				23
#define SORT_sortname				0
#define SORT_unknown				0
#define SORT_repeat				(-1)
#define SORT_option				(-2)
#define SORT_completion				(-3)
#define SORT_small_tdfint			(-4)
#define SORT_bitstream				(-5)
#define SORT_bytestream				(-6)
#define SORT_tdfbool				(-7)
#define SORT_tdfident				(-8)
#define SORT_tdfint				(-9)
#define SORT_tdfstring				(-10)
#define SORT_max				21
#define SORT_no					24

#define ENC_access_apply_token			1
#define ENC_access_cond				2
#define ENC_add_accesses			3
#define ENC_constant				4
#define ENC_long_jump_access			5
#define ENC_no_other_read			6
#define ENC_no_other_write			7
#define ENC_out_par				8
#define ENC_preserve				9
#define ENC_register				10
#define ENC_standard_access			11
#define ENC_used_as_volatile			12
#define ENC_visible				13
#define ENC_al_tag_apply_token			2
#define ENC_make_al_tag				1
#define ENC_make_al_tagdef			1
#define ENC_alignment_apply_token		1
#define ENC_alignment_cond			2
#define ENC_alignment				3
#define ENC_alloca_alignment			4
#define ENC_callees_alignment			5
#define ENC_callers_alignment			6
#define ENC_code_alignment			7
#define ENC_locals_alignment			8
#define ENC_obtain_al_tag			9
#define ENC_parameter_alignment			10
#define ENC_unite_alignments			11
#define ENC_var_param_alignment			12
#define ENC_bfvar_apply_token			1
#define ENC_bfvar_cond				2
#define ENC_bfvar_bits				3
#define ENC_bool_apply_token			1
#define ENC_bool_cond				2
#define ENC_false				3
#define ENC_true				4
#define ENC_make_callee_list			1
#define ENC_make_dynamic_callees		2
#define ENC_same_callees			3
#define ENC_nil_access				1
#define ENC_overflow				2
#define ENC_stack_overflow			3
#define ENC_errt_apply_token			1
#define ENC_errt_cond				2
#define ENC_continue				3
#define ENC_error_jump				4
#define ENC_trap				5
#define ENC_wrap				6
#define ENC_impossible				7
#define ENC_exp_apply_token			1
#define ENC_exp_cond				2
#define ENC_abs					3
#define ENC_add_to_ptr				4
#define ENC_and					5
#define ENC_apply_proc				6
#define ENC_apply_general_proc			7
#define ENC_assign				8
#define ENC_assign_with_mode			9
#define ENC_bitfield_assign			10
#define ENC_bitfield_assign_with_mode		11
#define ENC_bitfield_contents			12
#define ENC_bitfield_contents_with_mode		13
#define ENC_case				14
#define ENC_change_bitfield_to_int		15
#define ENC_change_floating_variety		16
#define ENC_change_variety			17
#define ENC_change_int_to_bitfield		18
#define ENC_complex_conjugate			19
#define ENC_component				20
#define ENC_concat_nof				21
#define ENC_conditional				22
#define ENC_contents				23
#define ENC_contents_with_mode			24
#define ENC_current_env				25
#define ENC_div0				26
#define ENC_div1				27
#define ENC_div2				28
#define ENC_env_offset				29
#define ENC_env_size				30
#define ENC_fail_installer			31
#define ENC_float_int				32
#define ENC_floating_abs			33
#define ENC_floating_div			34
#define ENC_floating_minus			35
#define ENC_floating_maximum			36
#define ENC_floating_minimum			37
#define ENC_floating_mult			38
#define ENC_floating_negate			39
#define ENC_floating_plus			40
#define ENC_floating_power			41
#define ENC_floating_test			42
#define ENC_goto				43
#define ENC_goto_local_lv			44
#define ENC_identify				45
#define ENC_ignorable				46
#define ENC_imaginary_part			47
#define ENC_initial_value			48
#define ENC_integer_test			49
#define ENC_labelled				50
#define ENC_last_local				51
#define ENC_local_alloc				52
#define ENC_local_alloc_check			53
#define ENC_local_free				54
#define ENC_local_free_all			55
#define ENC_long_jump				56
#define ENC_make_complex			57
#define ENC_make_compound			58
#define ENC_make_floating			59
#define ENC_make_general_proc			60
#define ENC_make_int				61
#define ENC_make_local_lv			62
#define ENC_make_nof				63
#define ENC_make_nof_int			64
#define ENC_make_null_local_lv			65
#define ENC_make_null_proc			66
#define ENC_make_null_ptr			67
#define ENC_make_proc				68
#define ENC_make_stack_limit			116
#define ENC_make_top				69
#define ENC_make_value				70
#define ENC_maximum				71
#define ENC_minimum				72
#define ENC_minus				73
#define ENC_move_some				74
#define ENC_mult				75
#define ENC_n_copies				76
#define ENC_negate				77
#define ENC_not					78
#define ENC_obtain_tag				79
#define ENC_offset_add				80
#define ENC_offset_div				81
#define ENC_offset_div_by_int			82
#define ENC_offset_max				83
#define ENC_offset_mult				84
#define ENC_offset_negate			85
#define ENC_offset_pad				86
#define ENC_offset_subtract			87
#define ENC_offset_test				88
#define ENC_offset_zero				89
#define ENC_or					90
#define ENC_plus				91
#define ENC_pointer_test			92
#define ENC_power				93
#define ENC_proc_test				94
#define ENC_profile				95
#define ENC_real_part				96
#define ENC_rem0				97
#define ENC_rem1				98
#define ENC_rem2				99
#define ENC_repeat				100
#define ENC_return				101
#define ENC_return_to_label			102
#define ENC_round_with_mode			103
#define ENC_rotate_left				104
#define ENC_rotate_right			105
#define ENC_sequence				106
#define ENC_set_stack_limit			107
#define ENC_shape_offset			108
#define ENC_shift_left				109
#define ENC_shift_right				110
#define ENC_subtract_ptrs			111
#define ENC_tail_call				112
#define ENC_untidy_return			113
#define ENC_variable				114
#define ENC_xor					115
#define ENC_string_extern			1
#define ENC_unique_extern			2
#define ENC_chain_extern			3
#define ENC_flvar_apply_token			1
#define ENC_flvar_cond				2
#define ENC_flvar_parms				3
#define ENC_complex_parms			4
#define ENC_float_of_complex			5
#define ENC_complex_of_float			6
#define ENC_label_apply_token			2
#define ENC_make_label				1
#define ENC_nat_apply_token			1
#define ENC_nat_cond				2
#define ENC_computed_nat			3
#define ENC_error_val				4
#define ENC_make_nat				5
#define ENC_ntest_apply_token			1
#define ENC_ntest_cond				2
#define ENC_equal				3
#define ENC_greater_than			4
#define ENC_greater_than_or_equal		5
#define ENC_less_than				6
#define ENC_less_than_or_equal			7
#define ENC_not_equal				8
#define ENC_not_greater_than			9
#define ENC_not_greater_than_or_equal		10
#define ENC_not_less_than			11
#define ENC_not_less_than_or_equal		12
#define ENC_less_than_or_greater_than		13
#define ENC_not_less_than_and_not_great		14
#define ENC_comparable				15
#define ENC_not_comparable			16
#define ENC_procprops_apply_token		1
#define ENC_procprops_cond			2
#define ENC_add_procprops			3
#define ENC_check_stack				4
#define ENC_inline				5
#define ENC_no_long_jump_dest			6
#define ENC_untidy				7
#define ENC_var_callees				8
#define ENC_var_callers				9
#define ENC_rounding_mode_apply_token		1
#define ENC_rounding_mode_cond			2
#define ENC_round_as_state			3
#define ENC_to_nearest				4
#define ENC_toward_larger			5
#define ENC_toward_smaller			6
#define ENC_toward_zero				7
#define ENC_shape_apply_token			1
#define ENC_shape_cond				2
#define ENC_bitfield				3
#define ENC_bottom				4
#define ENC_compound				5
#define ENC_floating				6
#define ENC_integer				7
#define ENC_nof					8
#define ENC_offset				9
#define ENC_pointer				10
#define ENC_proc				11
#define ENC_top					12
#define ENC_shape_none				13
#define ENC_signed_nat_apply_token		1
#define ENC_signed_nat_cond			2
#define ENC_computed_signed_nat			3
#define ENC_make_signed_nat			4
#define ENC_snat_from_nat			5
#define ENC_access				1
#define ENC_al_tag				2
#define ENC_alignment_sort			3
#define ENC_bitfield_variety			4
#define ENC_bool				5
#define ENC_error_treatment			6
#define ENC_exp					7
#define ENC_floating_variety			8
#define ENC_foreign_sort			9
#define ENC_label				10
#define ENC_nat					11
#define ENC_ntest				12
#define ENC_procprops				13
#define ENC_rounding_mode			14
#define ENC_shape				15
#define ENC_signed_nat				16
#define ENC_string				17
#define ENC_tag					18
#define ENC_transfer_mode			19
#define ENC_token				20
#define ENC_variety				21
#define ENC_string_apply_token			1
#define ENC_string_cond				2
#define ENC_concat_string			3
#define ENC_make_string				4
#define ENC_tag_apply_token			2
#define ENC_make_tag				1
#define ENC_make_id_tagdec			1
#define ENC_make_var_tagdec			2
#define ENC_common_tagdec			3
#define ENC_make_id_tagdef			1
#define ENC_make_var_tagdef			2
#define ENC_common_tagdef			3
#define ENC_make_tokdec				1
#define ENC_make_tokdef				1
#define ENC_token_apply_token			1
#define ENC_make_tok				2
#define ENC_use_tokdef				3
#define ENC_token_definition			1
#define ENC_transfer_mode_apply_token		1
#define ENC_transfer_mode_cond			2
#define ENC_add_modes				3
#define ENC_overlap				4
#define ENC_standard_transfer_mode		5
#define ENC_trap_on_nil				6
#define ENC_volatile				7
#define ENC_complete				8
#define ENC_var_apply_token			1
#define ENC_var_cond				2
#define ENC_var_limits				3
#define ENC_var_width				4
#define ENC_make_version			1
#define ENC_user_info				2


#endif /* TDF_H */
