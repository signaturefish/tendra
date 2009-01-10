/*
 * Copyright (c) 2002, The Tendra Project <http://www.ten15.org/>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *    		 Crown Copyright (c) 1997
 *    
 *    This TenDRA(r) Computer Program is subject to Copyright
 *    owned by the United Kingdom Secretary of State for Defence
 *    acting through the Defence Evaluation and Research Agency
 *    (DERA).  It is made available to Recipients with a
 *    royalty-free licence for its use, reproduction, transfer
 *    to other parties and amendment for any purpose not excluding
 *    product development provided that any such use et cetera
 *    shall be deemed to be acceptance of the following conditions:-
 *    
 *        (1) Its Recipients shall ensure that this Notice is
 *        reproduced upon any copies or amended versions of it;
 *    
 *        (2) Any amended version of it shall be clearly marked to
 *        show both the nature of and the organisation responsible
 *        for the relevant amendment or amendments;
 *    
 *        (3) Its onward transfer from a recipient to another
 *        party shall be deemed to be that party's acceptance of
 *        these conditions;
 *    
 *        (4) DERA gives no warranty or assurance as to its
 *        quality or suitability for any purpose and DERA accepts
 *        no liability whatsoever in relation to any use to which
 *        it may be put.
 *
 * $TenDRA$
 */


#include "config.h"
#include "producer.h"

#include "tdf_types.h"
#include "tdf_stream.h"

#include "version.h"
#include "c_types.h"
#include "exp_ops.h"
#include "type_ops.h"
#include "error.h"
#include "tdf.h"
#include "allocate.h"
#include "basetype.h"
#include "capsule.h"
#include "chktype.h"
#include "compile.h"
#include "destroy.h"
#include "diag.h"
#include "encode.h"
#include "exception.h"
#include "exp.h"
#include "init.h"
#include "inttype.h"
#include "shape.h"
#include "statement.h"
#include "stmt.h"
#include "struct.h"
#include "syntax.h"
#include "throw.h"
#include "tok.h"
#include "typeid.h"
#include "ustring.h"
#if TDF_OUTPUT


/*
 *    ENCODE THE ADDRESS OF A DESTRUCTOR
 *
 *    This routine adds the address of the destructor function corresponding
 *    to d to the bitstream bs.
 */

BITSTREAM
*enc_destr_func(BITSTREAM *bs, EXP d)
{
    if (!IS_NULL_exp (d)) {
		EXP f;
		while (IS_exp_nof (d)) {
			d = DEREF_exp (exp_nof_pad (d));
		}
		f = DEREF_exp (exp_destr_call (d));
		if (IS_exp_func_id (f)) {
			ulong n;
			IDENTIFIER fn = DEREF_id (exp_func_id_id (f));
			IGNORE capsule_id (fn, VAR_tag);
			n = unit_no (bs, fn, VAR_tag, 0);
			ENC_obtain_tag (bs);
			ENC_make_tag (bs, n);
			return (bs);
		}
    }
    ENC_make_null_proc (bs);
    return (bs);
}


/*
 *    EXCEPTION HANDLING ROUTINES
 *
 *    The exception handling routines are only included in the C++ producer.
 */

#if LANGUAGE_CPP


/*
 *    ENCODE A CATCH STATEMENT
 *
 *    This routine adds the start of a catch statement to the bitstream bs.
 *    It checks whether the type t can handle the current exception.  If
 *    the label lab is given then catching the exception causes a jump to
 *    lab.  Otherwise the handler body, consisting of seq statements,
 *    followed by the code if the exception is not caught, needs to be
 *    added later.
 */

static BITSTREAM
*enc_catch(BITSTREAM *bs, TYPE t, ulong lab,
		   unsigned seq)
{
    BITSTREAM *ts;
    NTEST tst = ntest_eq;
    if (lab == LINK_NONE) {
		/* Create label if necessary */
		lab = unit_no (bs, NULL_id, VAR_label, 1);
		ENC_conditional (bs);
		ENC_make_label (bs, lab);
		ENC_SEQUENCE (bs, seq);
		tst = ntest_not_eq;
    }
    ENC_integer_test (bs);
    ENC_OFF (bs);
    bs = enc_ntest (bs, tst);
    ENC_make_label (bs, lab);
    bs = enc_special (bs, TOK_except_catch);
    ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
    ts = enc_rtti_type (ts, t, lex_typeid);
    tdf_en_bitstream (bs, ts);
    bs = enc_make_int (bs, type_sint, 0);
    return (bs);
}


/*
 *    ENCODE THE START OF A TRY BLOCK
 *
 *    This routine adds the start of a try block to the bitstream bs.  seq
 *    gives the number of statements to follow.
 */

BITSTREAM
*enc_try_start(BITSTREAM *bs, ulong *pn, unsigned seq)
{
    ulong n;
    ulong lab;
    BITSTREAM *ts;
	
    /* Must be in a function definition */
    if (in_dynamic_init) output_init = 1;
	
    /* Encode the try block jump buffer */
    n = unit_no (bs, NULL_id, VAR_tag, 1);
    ENC_variable (bs);
    bs = enc_access (bs, crt_func_access);
    ENC_make_tag (bs, n);
    ENC_make_value (bs);
    bs = enc_special (bs, TOK_try_type);
    *pn = n;
	
    /* Encode the try block label */
    lab = unit_no (bs, NULL_id, VAR_label, 1);
    ENC_conditional (bs);
    ENC_make_label (bs, lab);
	
    /* Encode the try block body */
    ENC_SEQUENCE (bs, seq);
    bs = enc_special (bs, TOK_try_begin);
    ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
    ENC_obtain_tag (ts);
    ENC_make_tag (ts, n);
    ENC_current_env (ts);
    ENC_make_local_lv (ts);
    ENC_make_label (ts, lab);
    tdf_en_bitstream (bs, ts);
    return (bs);
}


/*
 *    ENCODE THE END OF A TRY BLOCK
 *
 *    This routine adds the end of the current try block to the bitstream bs.
 */

BITSTREAM
*enc_try_end(BITSTREAM *bs, ulong n)
{
    BITSTREAM *ts;
    bs = enc_special (bs, TOK_try_end);
    ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
    ENC_obtain_tag (ts);
    ENC_make_tag (ts, n);
    tdf_en_bitstream (bs, ts);
    return (bs);
}


/*
 *    ENCODE A TRY BLOCK
 *
 *    This routine adds the try block e to the bitstream bs.
 */

BITSTREAM
*enc_try(BITSTREAM *bs, EXP e)
{
    int uc;
    ulong ex;
    unsigned seq;
    EXP a = DEREF_exp (exp_try_block_body (e));
    LIST (EXP) p = DEREF_list (exp_try_block_handlers (e));
    LIST (TYPE) q = DEREF_list (exp_try_block_htypes (e));
    EXP c = DEREF_exp (exp_try_block_ellipsis (e));
	
    /* Ignore handlers if exception handling disabled */
    if (!output_except) {
		bs = enc_stmt (bs, a);
		return (bs);
    }
	
    /* Encode the try block */
    no_destructors++;
    if (output_new_diag) {
		seq = 2;
    } else {
		seq = stmt_length (a) + 1;
    }
    bs = enc_try_start (bs, &ex, seq);
    COPY_ulong (exp_try_block_no (e), ex);
    if (output_new_diag) {
		BITSTREAM *ts = enc_diag_begin (&bs);
		ts = enc_stmt (ts, a);
		bs = enc_diag_end (bs, ts, e, 1);
    } else {
		bs = enc_compound_stmt (bs, a);
    }
    bs = enc_try_end (bs, ex);
    uc = unreached_code;
	
    /* Encode the handlers */
    while (!IS_NULL_list (p)) {
		EXP b = DEREF_exp (HEAD_list (p));
		TYPE t = DEREF_type (HEAD_list (q));
		unreached_code = 0;
		if (!output_new_diag) {
			b = DEREF_exp (exp_handler_body (b));
		}
		seq = stmt_length (b) + 1;
		bs = enc_catch (bs, t, LINK_NONE, seq);
		bs = enc_compound_stmt (bs, b);
		bs = enc_special (bs, TOK_except_end);
		if (!unreached_code) uc = 0;
		q = TAIL_list (q);
		p = TAIL_list (p);
    }
	
    /* Encode the default handler */
    unreached_code = 0;
    if (IS_exp_handler (c)) {
		if (!output_new_diag) {
			c = DEREF_exp (exp_handler_body (c));
		}
		seq = stmt_length (c);
		if (seq) {
			ENC_SEQUENCE (bs, seq);
			bs = enc_compound_stmt (bs, c);
		}
		bs = enc_special (bs, TOK_except_end);
    } else {
		/* Re-throw current exception */
		bs = enc_exp (bs, c);
    }
    if (!unreached_code) uc = 0;
    unreached_code = uc;
    no_destructors--;
    return (bs);
}


/*
 *    RETHROW THE CURRENT EXCEPTION
 *
 *    This routine adds the expression 'throw' to the bitstream bs.
 */

BITSTREAM
*enc_rethrow(BITSTREAM *bs)
{
    if (output_except) {
		bs = enc_special (bs, TOK_except_rethrow);
    } else {
		BITSTREAM *ts;
		bs = enc_special (bs, TOK_except_bad);
		ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
		ts = enc_make_snat (ts, 0);
		tdf_en_bitstream (bs, ts);
    }
    unreached_code = 1;
    return (bs);
}


/*
 *    ENCODE A THROW EXPRESSION
 *
 *    This routine adds the expression 'throw a' to the bitstream bs.  If
 *    a is the null expression then the current exception is rethrown.  b
 *    and d give the size and destructor for the exception type.
 */

BITSTREAM
*enc_throw(BITSTREAM *bs, EXP a, EXP b, EXP d)
{
    if (!IS_NULL_exp (a) && output_except) {
		/* Set up variable */
		EXP c;
		BITSTREAM *ts, *us;
		TYPE t = DEREF_type (exp_type (a));
		ulong n = unit_no (bs, NULL_id, VAR_tag, 1);
		ENC_variable (bs);
		bs = enc_access (bs, dspec_none);
		ENC_make_tag (bs, n);
		MAKE_exp_dummy (t, NULL_exp, n, NULL_off, 2, c);
		
		/* Allocate space for exception value */
		bs = enc_special (bs, TOK_from_ptr_void);
		ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
		ts = enc_alignment (ts, t);
		ts = enc_special (ts, TOK_except_alloc);
		us = tdf_bs_create (NULL, TDFS_MODE_WRITE, ts->ts_link);
		us = enc_exp (us, b);
		tdf_en_bitstream (ts, us);
		tdf_en_bitstream (bs, ts);
		
		/* Assign exception value */
		ENC_SEQ_SMALL (bs, 1);
		bs = enc_init_tag (bs, n, NULL_off, 1, t, a, NULL_exp, 0);
		
		/* Throw the exception */
		bs = enc_special (bs, TOK_except_throw);
		ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
		ts = enc_special (ts, TOK_to_ptr_void);
		us = tdf_bs_create (NULL, TDFS_MODE_WRITE, ts->ts_link);
		us = enc_alignment (us, t);
		us = enc_exp (us, c);
		tdf_en_bitstream (ts, us);
		ts = enc_rtti_type (ts, t, lex_typeid);
		ts = enc_destr_func (ts, d);
		tdf_en_bitstream (bs, ts);
		unreached_code = 1;
		free_exp (c, 1);
		
    } else {
		/* Rethrow the current exception */
		bs = enc_rethrow (bs);
    }
    return (bs);
}


/*
 *    ENCODE A CAUGHT EXPRESSION
 *
 *    This routine adds the initialiser for an exception handler variable
 *    of type t to the bitstream bs.  This is obtained by casting the
 *    current exception value to a pointer to t.
 */

BITSTREAM
*enc_thrown(BITSTREAM *bs, TYPE t)
{
    BITSTREAM *ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
    bs = enc_special (bs, TOK_from_ptr_void);
    ts = enc_alignment (ts, t);
    ts = enc_special (ts, TOK_except_value);
    tdf_en_bitstream (bs, ts);
    return (bs);
}


/*
 *    EXCEPTION SPECIFICATION FLAG
 *
 *    This flag is set to true if the current function has an exception
 *    specification.
 */

int in_exception_spec = 0;


/*
 *    ENCODE THE START OF A FUNCTION EXCEPTION HANDLER
 *
 *    This routine is called at the start of a function definition declared
 *    with a non-trivial exception specification.  It sets up a try block
 *    enclosing the complete function body.
 */

BITSTREAM
*enc_try_func(BITSTREAM *bs, EXP a)
{
    if (!IS_NULL_exp (a)) {
		/* Declare counter variable */
		EXP b = sizeof_init (a, type_sint);
		ulong n = unit_no (bs, NULL_id, VAR_tag, 1);
		ENC_variable (bs);
		bs = enc_access (bs, crt_func_access);
		ENC_make_tag (bs, n);
		bs = enc_exp (bs, b);
		free_exp (b, 1);
		last_params [ DUMMY_count ] = n;
    }
    no_destructors++;
    in_exception_spec++;
    ENC_SEQ_SMALL (bs, 1);
    bs = enc_try_start (bs, last_params + DUMMY_catch, (unsigned) 1);
    return (bs);
}


/*
 *    BAD EXCEPTION TYPE
 *
 *    This type represents the standard class 'std::bad_exception' which has
 *    a special meaning within exception specifications.
 */

static TYPE bad_except = NULL_type;


/*
 *    ENCODE THE END OF A FUNCTION EXCEPTION HANDLER
 *
 *    This routine is called at the end of a function definition declared
 *    with the set of exceptions p.  It sets up a list of exception handlers
 *    for each element of p which re-throw the current exception.  If the
 *    exception remains uncaught then the bad exception token is called
 *    (which calls unexpected).
 */

BITSTREAM
*enc_catch_func(BITSTREAM *bs, LIST (TYPE) p,
				EXP a)
{
    int rethrow = 0;
    bs = enc_try_end (bs, last_params [ DUMMY_catch ]);
    if (!IS_NULL_exp (a)) {
		ENC_SEQ_SMALL (bs, 1);
		bs = enc_exp (bs, a);
    }
    if (EQ_list (p, univ_type_set)) {
		/* Can throw any exception */
		rethrow = 1;
    } else {
		BITSTREAM *ts;
		int have_bad = 0;
		if (!IS_NULL_list (p)) {
			/* Check list of exceptions */
			unsigned n = 0;
			LIST (TYPE) q = p;
			while (!IS_NULL_list (q)) {
				TYPE t = DEREF_type (HEAD_list (q));
				if (!IS_NULL_type (t)) n++;
				q = TAIL_list (q);
			}
			if (n) {
				ulong lab;
				TYPE s = bad_except;
				if (IS_NULL_type (s)) {
					s = find_std_type ("bad_exception", 1, 0);
					s = exception_type (s, 0);
					bad_except = s;
				}
				lab = unit_no (bs, NULL_id, VAR_label, 1);
				ENC_conditional (bs);
				ENC_make_label (bs, lab);
				ENC_SEQUENCE (bs, n);
				while (!IS_NULL_list (p)) {
					TYPE t = DEREF_type (HEAD_list (p));
					if (!IS_NULL_type (t)) {
						t = exception_type (t, 0);
						if (eq_type (t, s)) have_bad = 1;
						bs = enc_catch (bs, t, lab, (unsigned) 0);
					}
					p = TAIL_list (p);
				}
				rethrow = 1;
			}
		}
		bs = enc_special (bs, TOK_except_bad);
		ts = tdf_bs_create (NULL, TDFS_MODE_WRITE, bs->ts_link);
		ts = enc_make_snat (ts, have_bad);
		tdf_en_bitstream (bs, ts);
    }
    if (rethrow) {
		/* Re-throw the current exception */
		bs = enc_special (bs, TOK_except_rethrow);
		unreached_code = 1;
    }
    in_exception_spec--;
    no_destructors--;
    UNUSED (a);
    return (bs);
}


#endif /* LANGUAGE_CPP */
#endif /* TDF_OUTPUT */