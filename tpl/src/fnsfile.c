/*
 * Copyright (c) 2002-2006 The TenDRA Project <http://www.tendra.org/>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of The TenDRA Project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific, prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
/*
    		 Crown Copyright (c) 1997

    This TenDRA(r) Computer Program is subject to Copyright
    owned by the United Kingdom Secretary of State for Defence
    acting through the Defence Evaluation and Research Agency
    (DERA).  It is made available to Recipients with a
    royalty-free licence for its use, reproduction, transfer
    to other parties and amendment for any purpose not excluding
    product development provided that any such use et cetera
    shall be deemed to be acceptance of the following conditions:-

        (1) Its Recipients shall ensure that this Notice is
        reproduced upon any copies or amended versions of it;

        (2) Any amended version of it shall be clearly marked to
        show both the nature of and the organisation responsible
        for the relevant amendment or amendments;

        (3) Its onward transfer from a recipient to another
        party shall be deemed to be that party's acceptance of
        these conditions;

        (4) DERA gives no warranty or assurance as to its
        quality or suitability for any purpose and DERA accepts
        no liability whatsoever in relation to any use to which
        it may be put.
*/


/* AUTOMATICALLY GENERATED BY make_tdf VERSION 2.0 FROM TDF 4.0 */

#include "config.h"
#include "encodings.h"
#include "enc_nos.h"
#include "defs.h"
#include "analyse_sort.h"
#include "consfile.h"
#include "lex.h"
#include "syntax.h"

void
c_add_accesses(void)
{
	    skip_term(lex_ord);
	o_add_accesses(
	      read_access();
	      skip_term(lex_comma),
	      read_access();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_constant(void)
{
	    o_constant;
	    return;
}

void
c_long_jump_access(void)
{
	    o_long_jump_access;
	    return;
}

void
c_no_other_read(void)
{
	    o_no_other_read;
	    return;
}

void
c_no_other_write(void)
{
	    o_no_other_write;
	    return;
}

void
c_out_par(void)
{
	    o_out_par;
	    return;
}

void
c_preserve(void)
{
	    o_preserve;
	    return;
}

void
c_register(void)
{
	    o_register;
	    return;
}

void
c_standard_access(void)
{
	    o_standard_access;
	    return;
}

void
c_used_as_volatile(void)
{
	    o_used_as_volatile;
	    return;
}

void
c_visible(void)
{
	    o_visible;
	    return;
}

void
c_alignment(void)
{
	    skip_term(lex_ord);
	o_alignment(
	      read_shape();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_alloca_alignment(void)
{
	    o_alloca_alignment;
	    return;
}

void
c_callees_alignment(void)
{
	    skip_term(lex_ord);
	o_callees_alignment(
	      read_bool();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_callers_alignment(void)
{
	    skip_term(lex_ord);
	o_callers_alignment(
	      read_bool();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_code_alignment(void)
{
	    o_code_alignment;
	    return;
}

void
c_locals_alignment(void)
{
	    o_locals_alignment;
	    return;
}

void
c_parameter_alignment(void)
{
	    skip_term(lex_ord);
	o_parameter_alignment(
	      read_shape();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_unite_alignments(void)
{
	    skip_term(lex_ord);
	o_unite_alignments(
	      read_alignment();
	      skip_term(lex_comma),
	      read_alignment();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_var_param_alignment(void)
{
	    o_var_param_alignment;
	    return;
}

void
c_bfvar_bits(void)
{
	    skip_term(lex_ord);
	o_bfvar_bits(
	      read_bool();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_false(void)
{
	    o_false;
	    return;
}

void
c_true(void)
{
	    o_true;
	    return;
}

void
c_nil_access(void)
{
	    o_nil_access;
	    return;
}

void
c_overflow(void)
{
	    o_overflow;
	    return;
}

void
c_stack_overflow(void)
{
	    o_stack_overflow;
	    return;
}

void
c_continue(void)
{
	    o_continue;
	    return;
}

void
c_trap(void)
{
	    skip_term(lex_ord);
	o_trap(
	      read_error__code__list();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_wrap(void)
{
	    o_wrap;
	    return;
}

void
c_impossible(void)
{
	    o_impossible;
	    return;
}

void
c_abs(void)
{
	    skip_term(lex_ord);
	o_abs(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_add_to_ptr(void)
{
	    skip_term(lex_ord);
	o_add_to_ptr(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_and(void)
{
	    skip_term(lex_ord);
	o_and(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_assign(void)
{
	    skip_term(lex_ord);
	o_assign(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_assign_with_mode(void)
{
	    skip_term(lex_ord);
	o_assign_with_mode(
	      read_transfer__mode();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_bitfield_assign(void)
{
	    skip_term(lex_ord);
	o_bitfield_assign(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_bitfield_assign_with_mode(void)
{
	    skip_term(lex_ord);
	o_bitfield_assign_with_mode(
	      read_transfer__mode();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_bitfield_contents(void)
{
	    skip_term(lex_ord);
	o_bitfield_contents(
	      read_bitfield__variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_bitfield_contents_with_mode(void)
{
	    skip_term(lex_ord);
	o_bitfield_contents_with_mode(
	      read_transfer__mode();
	      skip_term(lex_comma),
	      read_bitfield__variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_change_bitfield_to_int(void)
{
	    skip_term(lex_ord);
	o_change_bitfield_to_int(
	      read_variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_change_floating_variety(void)
{
	    skip_term(lex_ord);
	o_change_floating_variety(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_floating__variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_change_variety(void)
{
	    skip_term(lex_ord);
	o_change_variety(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_change_int_to_bitfield(void)
{
	    skip_term(lex_ord);
	o_change_int_to_bitfield(
	      read_bitfield__variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_complex_conjugate(void)
{
	    skip_term(lex_ord);
	o_complex_conjugate(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_component(void)
{
	    skip_term(lex_ord);
	o_component(
	      read_shape();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_concat_nof(void)
{
	    skip_term(lex_ord);
	o_concat_nof(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_conditional(void)
{
	    skip_term(lex_ord);
	o_conditional(
	      read_label();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_contents(void)
{
	    skip_term(lex_ord);
	o_contents(
	      read_shape();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_contents_with_mode(void)
{
	    skip_term(lex_ord);
	o_contents_with_mode(
	      read_transfer__mode();
	      skip_term(lex_comma),
	      read_shape();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_current_env(void)
{
	    o_current_env;
	    return;
}

void
c_div0(void)
{
	    skip_term(lex_ord);
	o_div0(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_div1(void)
{
	    skip_term(lex_ord);
	o_div1(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_div2(void)
{
	    skip_term(lex_ord);
	o_div2(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_env_offset(void)
{
	    skip_term(lex_ord);
	o_env_offset(
	      read_alignment();
	      skip_term(lex_comma),
	      read_alignment();
	      skip_term(lex_comma),
	      read_tag();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_env_size(void)
{
	    skip_term(lex_ord);
	o_env_size(
	      read_tag();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_fail_installer(void)
{
	    skip_term(lex_ord);
	o_fail_installer(
	      read_string();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_float_int(void)
{
	    skip_term(lex_ord);
	o_float_int(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_floating__variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_abs(void)
{
	    skip_term(lex_ord);
	o_floating_abs(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_div(void)
{
	    skip_term(lex_ord);
	o_floating_div(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_minus(void)
{
	    skip_term(lex_ord);
	o_floating_minus(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_maximum(void)
{
	    skip_term(lex_ord);
	o_floating_maximum(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_minimum(void)
{
	    skip_term(lex_ord);
	o_floating_minimum(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_mult(void)
{
	    skip_term(lex_ord);
	o_floating_mult(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp__list();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_negate(void)
{
	    skip_term(lex_ord);
	o_floating_negate(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_plus(void)
{
	    skip_term(lex_ord);
	o_floating_plus(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp__list();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_power(void)
{
	    skip_term(lex_ord);
	o_floating_power(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating_test(void)
{
	    skip_term(lex_ord);
	o_floating_test(
	      read_nat__option();
	      skip_term(lex_comma),
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_ntest();
	      skip_term(lex_comma),
	      read_label();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_goto(void)
{
	    skip_term(lex_ord);
	o_goto(
	      read_label();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_goto_local_lv(void)
{
	    skip_term(lex_ord);
	o_goto_local_lv(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_ignorable(void)
{
	    skip_term(lex_ord);
	o_ignorable(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_imaginary_part(void)
{
	    skip_term(lex_ord);
	o_imaginary_part(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_initial_value(void)
{
	    skip_term(lex_ord);
	o_initial_value(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_integer_test(void)
{
	    skip_term(lex_ord);
	o_integer_test(
	      read_nat__option();
	      skip_term(lex_comma),
	      read_ntest();
	      skip_term(lex_comma),
	      read_label();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_last_local(void)
{
	    skip_term(lex_ord);
	o_last_local(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_local_alloc(void)
{
	    skip_term(lex_ord);
	o_local_alloc(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_local_alloc_check(void)
{
	    skip_term(lex_ord);
	o_local_alloc_check(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_local_free(void)
{
	    skip_term(lex_ord);
	o_local_free(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_local_free_all(void)
{
	    o_local_free_all;
	    return;
}

void
c_long_jump(void)
{
	    skip_term(lex_ord);
	o_long_jump(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_complex(void)
{
	    skip_term(lex_ord);
	o_make_complex(
	      read_floating__variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_compound(void)
{
	    skip_term(lex_ord);
	o_make_compound(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp__list();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_local_lv(void)
{
	    skip_term(lex_ord);
	o_make_local_lv(
	      read_label();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_nof(void)
{
	    skip_term(lex_ord);
	o_make_nof(
	      read_exp__list();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_nof_int(void)
{
	    skip_term(lex_ord);
	o_make_nof_int(
	      read_variety();
	      skip_term(lex_comma),
	      read_string();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_null_local_lv(void)
{
	    o_make_null_local_lv;
	    return;
}

void
c_make_null_proc(void)
{
	    o_make_null_proc;
	    return;
}

void
c_make_null_ptr(void)
{
	    skip_term(lex_ord);
	o_make_null_ptr(
	      read_alignment();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_stack_limit(void)
{
	    skip_term(lex_ord);
	o_make_stack_limit(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_top(void)
{
	    o_make_top;
	    return;
}

void
c_make_value(void)
{
	    skip_term(lex_ord);
	o_make_value(
	      read_shape();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_maximum(void)
{
	    skip_term(lex_ord);
	o_maximum(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_minimum(void)
{
	    skip_term(lex_ord);
	o_minimum(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_minus(void)
{
	    skip_term(lex_ord);
	o_minus(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_move_some(void)
{
	    skip_term(lex_ord);
	o_move_some(
	      read_transfer__mode();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_mult(void)
{
	    skip_term(lex_ord);
	o_mult(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_n_copies(void)
{
	    skip_term(lex_ord);
	o_n_copies(
	      read_nat();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_negate(void)
{
	    skip_term(lex_ord);
	o_negate(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_not(void)
{
	    skip_term(lex_ord);
	o_not(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_add(void)
{
	    skip_term(lex_ord);
	o_offset_add(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_div(void)
{
	    skip_term(lex_ord);
	o_offset_div(
	      read_variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_div_by_int(void)
{
	    skip_term(lex_ord);
	o_offset_div_by_int(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_max(void)
{
	    skip_term(lex_ord);
	o_offset_max(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_mult(void)
{
	    skip_term(lex_ord);
	o_offset_mult(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_negate(void)
{
	    skip_term(lex_ord);
	o_offset_negate(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_pad(void)
{
	    skip_term(lex_ord);
	o_offset_pad(
	      read_alignment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_subtract(void)
{
	    skip_term(lex_ord);
	o_offset_subtract(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_test(void)
{
	    skip_term(lex_ord);
	o_offset_test(
	      read_nat__option();
	      skip_term(lex_comma),
	      read_ntest();
	      skip_term(lex_comma),
	      read_label();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset_zero(void)
{
	    skip_term(lex_ord);
	o_offset_zero(
	      read_alignment();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_or(void)
{
	    skip_term(lex_ord);
	o_or(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_plus(void)
{
	    skip_term(lex_ord);
	o_plus(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_pointer_test(void)
{
	    skip_term(lex_ord);
	o_pointer_test(
	      read_nat__option();
	      skip_term(lex_comma),
	      read_ntest();
	      skip_term(lex_comma),
	      read_label();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_power(void)
{
	    skip_term(lex_ord);
	o_power(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_proc_test(void)
{
	    skip_term(lex_ord);
	o_proc_test(
	      read_nat__option();
	      skip_term(lex_comma),
	      read_ntest();
	      skip_term(lex_comma),
	      read_label();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_profile(void)
{
	    skip_term(lex_ord);
	o_profile(
	      read_nat();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_real_part(void)
{
	    skip_term(lex_ord);
	o_real_part(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_rem0(void)
{
	    skip_term(lex_ord);
	o_rem0(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_rem1(void)
{
	    skip_term(lex_ord);
	o_rem1(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_rem2(void)
{
	    skip_term(lex_ord);
	o_rem2(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_repeat(void)
{
	    skip_term(lex_ord);
	o_repeat(
	      read_label();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_return(void)
{
	    skip_term(lex_ord);
	o_return(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_return_to_label(void)
{
	    skip_term(lex_ord);
	o_return_to_label(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_round_with_mode(void)
{
	    skip_term(lex_ord);
	o_round_with_mode(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_rounding__mode();
	      skip_term(lex_comma),
	      read_variety();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_rotate_left(void)
{
	    skip_term(lex_ord);
	o_rotate_left(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_rotate_right(void)
{
	    skip_term(lex_ord);
	o_rotate_right(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_set_stack_limit(void)
{
	    skip_term(lex_ord);
	o_set_stack_limit(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_shape_offset(void)
{
	    skip_term(lex_ord);
	o_shape_offset(
	      read_shape();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_shift_left(void)
{
	    skip_term(lex_ord);
	o_shift_left(
	      read_error__treatment();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_shift_right(void)
{
	    skip_term(lex_ord);
	o_shift_right(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_subtract_ptrs(void)
{
	    skip_term(lex_ord);
	o_subtract_ptrs(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_untidy_return(void)
{
	    skip_term(lex_ord);
	o_untidy_return(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_xor(void)
{
	    skip_term(lex_ord);
	o_xor(
	      read_exp();
	      skip_term(lex_comma),
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_flvar_parms(void)
{
	    skip_term(lex_ord);
	o_flvar_parms(
	      read_nat();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_complex_parms(void)
{
	    skip_term(lex_ord);
	o_complex_parms(
	      read_nat();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_float_of_complex(void)
{
	    skip_term(lex_ord);
	o_float_of_complex(
	      read_shape();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_complex_of_float(void)
{
	    skip_term(lex_ord);
	o_complex_of_float(
	      read_shape();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_computed_nat(void)
{
	    skip_term(lex_ord);
	o_computed_nat(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_error_val(void)
{
	    skip_term(lex_ord);
	o_error_val(
	      read_error__code();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_equal(void)
{
	    o_equal;
	    return;
}

void
c_greater_than(void)
{
	    o_greater_than;
	    return;
}

void
c_greater_than_or_equal(void)
{
	    o_greater_than_or_equal;
	    return;
}

void
c_less_than(void)
{
	    o_less_than;
	    return;
}

void
c_less_than_or_equal(void)
{
	    o_less_than_or_equal;
	    return;
}

void
c_not_equal(void)
{
	    o_not_equal;
	    return;
}

void
c_not_greater_than(void)
{
	    o_not_greater_than;
	    return;
}

void
c_not_greater_than_or_equal(void)
{
	    o_not_greater_than_or_equal;
	    return;
}

void
c_not_less_than(void)
{
	    o_not_less_than;
	    return;
}

void
c_not_less_than_or_equal(void)
{
	    o_not_less_than_or_equal;
	    return;
}

void
c_less_than_or_greater_than(void)
{
	    o_less_than_or_greater_than;
	    return;
}

void
c_not_less_than_and_not_greater_than(void)
{
	    o_not_less_than_and_not_greater_than;
	    return;
}

void
c_comparable(void)
{
	    o_comparable;
	    return;
}

void
c_not_comparable(void)
{
	    o_not_comparable;
	    return;
}

void
c_round_as_state(void)
{
	    o_round_as_state;
	    return;
}

void
c_to_nearest(void)
{
	    o_to_nearest;
	    return;
}

void
c_toward_larger(void)
{
	    o_toward_larger;
	    return;
}

void
c_toward_smaller(void)
{
	    o_toward_smaller;
	    return;
}

void
c_toward_zero(void)
{
	    o_toward_zero;
	    return;
}

void
c_bitfield(void)
{
	    skip_term(lex_ord);
	o_bitfield(
	      read_bitfield__variety();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_bottom(void)
{
	    o_bottom;
	    return;
}

void
c_compound(void)
{
	    skip_term(lex_ord);
	o_compound(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_floating(void)
{
	    skip_term(lex_ord);
	o_floating(
	      read_floating__variety();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_integer(void)
{
	    skip_term(lex_ord);
	o_integer(
	      read_variety();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_nof(void)
{
	    skip_term(lex_ord);
	o_nof(
	      read_nat();
	      skip_term(lex_comma),
	      read_shape();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_offset(void)
{
	    skip_term(lex_ord);
	o_offset(
	      read_alignment();
	      skip_term(lex_comma),
	      read_alignment();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_pointer(void)
{
	    skip_term(lex_ord);
	o_pointer(
	      read_alignment();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_proc(void)
{
	    o_proc;
	    return;
}

void
c_top(void)
{
	    o_top;
	    return;
}

void
c_computed_signed_nat(void)
{
	    skip_term(lex_ord);
	o_computed_signed_nat(
	      read_exp();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_make_signed_nat(void)
{
	    skip_term(lex_ord);
	o_make_signed_nat(
	      read_tdfbool();
	      skip_term(lex_comma),
	      read_tdfint();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_snat_from_nat(void)
{
	    skip_term(lex_ord);
	o_snat_from_nat(
	      read_bool();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_add_modes(void)
{
	    skip_term(lex_ord);
	o_add_modes(
	      read_transfer__mode();
	      skip_term(lex_comma),
	      read_transfer__mode();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_overlap(void)
{
	    o_overlap;
	    return;
}

void
c_standard_transfer_mode(void)
{
	    o_standard_transfer_mode;
	    return;
}

void
c_trap_on_nil(void)
{
	    o_trap_on_nil;
	    return;
}

void
c_volatile(void)
{
	    o_volatile;
	    return;
}

void
c_complete(void)
{
	    o_complete;
	    return;
}

void
c_var_limits(void)
{
	    skip_term(lex_ord);
	o_var_limits(
	      read_signed__nat();
	      skip_term(lex_comma),
	      read_signed__nat();
	      skip_term(lex_crd)
	     )
	    return;
}

void
c_var_width(void)
{
	    skip_term(lex_ord);
	o_var_width(
	      read_bool();
	      skip_term(lex_comma),
	      read_nat();
	      skip_term(lex_crd)
	     )
	    return;
}
