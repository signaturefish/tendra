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


/**** bitvec.h --- Bit vector manipulation.
 *
 ** Author: Steve Folkes <smf@hermes.mod.uk>
 *
 **** Commentary:
 *
 ***=== INTRODUCTION =========================================================
 *
 * This file specifies the interface to a single size bit vector manipulation
 * facility.  It is necessary to call the ``bitvec_set_size'' function to set
 * the size of these bit vectors, before any are actually created.
 *
 ***=== TYPES ================================================================
 *
 ** Type:	BitVecT
 ** Type:	BitVecT *
 ** Repr:	<private>
 *
 * This is the bit vector type.
 *
 ***=== FUNCTIONS ============================================================
 *
 ** Function:	void			bitvec_set_size
 *			(unsigned size)
 ** Exceptions:
 *
 * This function should be called once, before any bit vectors are
 * initialised.  Its argument should specify the number of bits in a bit
 * vector.  The bits will be numbered from zero to one less than the number
 * specified.
 *
 ** Function:	void			bitvec_init
 *			(BitVecT * bitvec)
 ** Exceptions:	XX_dalloc_no_memory
 *
 * This function initialises the specified bit vector.  Initially, all bits
 * are zero.
 *
 ** Function:	void			bitvec_copy
 *			(BitVecT * to, BitVecT * from)
 ** Exceptions:	XX_dalloc_no_memory
 *
 * This function initialises the to bit vector from the from bit vector.  It
 * is not necessary to have initialised the to bit vector with the
 * `bitvec_init' function previously.
 *
 ** Function:	void			bitvec_replace
 *			(BitVecT * to, BitVecT * from)
 ** Exceptions:
 *
 * This function copies the from bit vector into the to bit vector.  The to
 * bit vector must have been initialised previously.
 *
 ** Function:	void			bitvec_empty
 *			(BitVecT * bitvec)
 ** Exceptions:
 *
 * This function sets all of the bits in the specified bit vector to zero.
 *
 ** Function:	BoolT			bitvec_is_empty
 *			(BitVecT * bitvec)
 ** Exceptions:
 *
 * This function returns true if all of the bits in the specified bit vector
 * are zero, and false otherwise.
 *
 ** Function:	BoolT			bitvec_is_full
 *			(BitVecT * bitvec)
 ** Exceptions:
 *
 * This function returns true if all of the bits in the specified bit vector
 * are set, and false otherwise.
 *
 ** Function:	void			bitvec_set
 *			(BitVecT * bitvec, unsigned bit)
 ** Exceptions:
 *
 * This function sets the specified bit in the specified bit vector to one.
 * Bits are numbered from zero.  If the bit is out of range, then the effect
 * of this function is undefined.
 *
 ** Function:	BoolT			bitvec_is_set
 *			(BitVecT * bitvec, unsigned bit)
 ** Exceptions:
 *
 * This function returns true if the specified bit in the specified bit vector
 * is set to one, and false otherwise.  Bits are numbered from zero.  If the
 * bit is out of range, the effect of this function is undefined.
 *
 ** Function:	void			bitvec_or
 *			(BitVecT * to, BitVecT * from)
 ** Exceptions:
 *
 * This function performs an in-place bitwise or of the to bit vector and the
 * from bit vector, leaving the result in the to bit vector.
 *
 ** Function:	void			bitvec_and
 *			(BitVecT * to, BitVecT *from)
 ** Exceptions:
 *
 * This function performs an in-place bitwise and of the to bit vector and the
 * from bit vector, leaving the result in the to bit vector.
 *
 ** Function:	void			bitvec_not
 *			(BitVecT * to)
 ** Exceptions:
 *
 * This function performs an in-place bitwise negation of the to bit vector.
 *
 ** Function:	BoolT			bitvec_equal
 *			(BitVecT * bitvec1, BitVecT * bitvec2)
 ** Exceptions:
 *
 * This function returns true if both of the specified bit vectors are equal,
 * and false otherwise.
 *
 ** Function:	BoolT			bitvec_intersects
 *			(BitVecT * bitvec1, BitVecT * bitvec2)
 ** Exceptions:
 *
 * This function returns true if the bitwise and of the specified bit vectors
 * contains at least one bit that is set to one, and false otherwise.
 *
 ** Function:	unsigned		bitvec_num_bits
 *			(BitVecT * bitvec)
 ** Exceptions:
 *
 * This function returns the number of bits in the bit vector that are set to
 * one.
 *
 ** Function:	unsigned		bitvec_first_bit
 *			(BitVecT * bitvec)
 ** Exceptions:
 *
 * This function returns the index of the first bit in the specified bit
 * vector that is set to one.
 *
 ** Function:	BoolT			bitvec_next_bit
 *			(BitVecT * bitvec, unsigned *next_ref)
 ** Exceptions:
 *
 * This function looks for the first bit set to one in the specified bit
 * vector with a higher index than that specified in the number pointed to by
 * next_ref.  If such a bit is found, then the index of that bit is written
 * back into next_ref, and the function returns true.  If no such bit is
 * found, then the function returns false.
 *
 ** Function:	void			bitvec_destroy
 *			(BitVecT * bitvec)
 ** Exceptions:
 *
 * This function destroys the specified bit vector.  After this, it should be
 * reinitialised before it is used.
 *
 ** Function:	void			write_bitvec_indices
 *			(OStreamT * ostream, BitVecT * bitvec)
 ** Exceptions:	XX_dalloc_no_memory, XX_ostream_write_error
 *
 * This function writes out to the specified ostream the indices of all bits
 * in the specified bit vector that are set to one.
 *
 **** Change log:
 * $Log: bitvec.h,v $
 * Revision 1.1.1.1  1998/01/17  15:57:45  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1994/12/15  09:57:01  smf
 * Brought into line with OSSG C Coding Standards Document, as per
 * "CR94_178.sid+tld-update".
 *
 * Revision 1.1.1.1  1994/07/25  16:05:47  smf
 * Initial import of library shared files.
 *
**/

/****************************************************************************/

#ifndef H_BITVEC
#define H_BITVEC

#include "os-interface.h"
#include "dalloc.h"
#include "ostream.h"

/*--------------------------------------------------------------------------*/

typedef struct BitVecT {
    ByteT *		bits;
} BitVecT;

/*--------------------------------------------------------------------------*/

extern void		bitvec_set_size(unsigned);
extern void		bitvec_init(BitVecT *);
extern void		bitvec_copy(BitVecT *, BitVecT *);
extern void		bitvec_replace(BitVecT *, BitVecT *);
extern void		bitvec_empty(BitVecT *);
extern BoolT		bitvec_is_empty(BitVecT *);
extern BoolT		bitvec_is_full(BitVecT *);
extern void		bitvec_set(BitVecT *, unsigned);
extern BoolT		bitvec_is_set(BitVecT *, unsigned);
extern void		bitvec_or(BitVecT *, BitVecT *);
extern void		bitvec_and(BitVecT *, BitVecT *);
extern void		bitvec_not(BitVecT *);
extern BoolT		bitvec_equal(BitVecT *, BitVecT *);
extern BoolT		bitvec_intersects(BitVecT *, BitVecT *);
extern unsigned		bitvec_num_bits(BitVecT *);
extern unsigned		bitvec_first_bit(BitVecT *);
extern BoolT		bitvec_next_bit(BitVecT *, unsigned *);
extern void		bitvec_destroy(BitVecT *);

extern void		write_bitvec_indices(OStreamT *, BitVecT *);

#endif /* !defined (H_BITVEC) */
