/*
 * Copyright (c) 2002-2005 The TenDRA Project <http://www.tendra.org/>.
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

#include <assert.h>
#include <string.h>

#include "xalloc/xalloc.h"
#include "error/error.h"

#include "keyword.h"
#include "zone.h"
#include "instruction.h"

struct keyword_tag {
	const char *name;
	instruction *instr;

	/* All keywords are formed into a list using the next field */
	keyword *next;
};


/*
    ADD A KEYWORD

    This routine adds the keyword nm with its associated data to the list
    of all keywords.
*/

void
add_keyword(zone* z, const char *nm, instruction* instr)
{
	assert(nm != NULL);
	assert(strlen(nm) > 0);

    keyword *p = z->keywords, *q = NULL;
    while (p) {
	int c = strcmp(nm, p->name);
	if (c == 0) {
	    error(ERROR_SERIOUS, "Keyword '%s' already defined", nm);
	    return;
	}
	if (c < 0)break;
	q = p;
	p = p->next;
    }
    p = xmalloc(sizeof *p);
    p->name = nm;
    p->instr = instr;
    if (q == NULL) {
	p->next = z->keywords;
	z->keywords = p;
    } else {
	p->next = q->next;
	q->next = p;
    }
    return;
}

void
keywords_iterate(keyword *kw, void (*f)(keyword *, void *), void *opaque)
{
	keyword *k;

	assert(kw != NULL);
	assert(f != NULL);

	for (k = kw; k; k = k->next) {
		f(k, opaque);
	}
}

instruction *
keyword_instruction(keyword *kw)
{
	assert(kw != NULL);

	return kw->instr;
}

const char *
keyword_name(keyword *kw)
{
	assert(kw != NULL);

	return kw->name;
}
