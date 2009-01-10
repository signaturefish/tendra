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
#include "common_types.h"
#include "tags.h"
#include "exp.h"

#include "overlap.h"

/* PROCEDURES */

/* false if a value of shape sha at
 *   w1 cannot overlap with one at w2.
 *   true if it does or might overlap.
 *   only used by move, so we can assume
 *   that w1 and w2 are addressable.
 */
int
might_overlap(shape sha, where w1, where w2)
{
	exp e1 = w1.where_exp;
	exp e2 = w2.where_exp;
	exp i1, i2;
	int off1, off2, sz;

	if (name(e1) != name_tag) {
		if (name(e2) == name_tag && iscaonly(son(e2)))
			return 0;
		return 1;
	}

	if (name(e2) != name_tag) {
		if (name(e1) == name_tag && iscaonly(son(e1)))
			return 0;
		return 1;
	}

	/* both are name_tags */
	i1 = son(e1);
	i2 = son(e2);
	if (isglob(i1)) {
		if (i1 != i2)
			return 0;
		sz = shape_size(sha);
		off1 = no(e1) + w1.where_off;
		off2 = no(e2) + w2.where_off;
		if (off1 <= off2 && (off1 + sz) > off2)
			return 1;
		if (off2 <= off1 && (off2 + sz) > off1)
			return 1;
		return 0;
	}
	if (isglob(i2))
		return 0;

	/* both are local */
	if (ptno(i1) != ptno(i2))
		return 0;

	sz = shape_size(sha);
	off1 = no(e1) + no(i1) + w1.where_off;
	off2 = no(e2) + no(i2) + w2.where_off;
	if (off1 <= off2 && (off1 + sz) > off2)
		return 1;
	if (off2 <= off1 && (off2 + sz) > off1)
		return 1;
	return 0;

}