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


/* 
   operators.c
   produces code for common operations

   to do : add support for VAX floating types.
*/

/**/

#include "config.h"
#include "common_types.h"
#include "code_here.h"
#include "addresstypes.h"
#include "inst_fmt.h"
#include "move.h"
#include "maxminmacs.h"
#include "getregs.h"
#include "guard.h"
#include "tags.h"
#include "shapemacs.h"
#include "bitsmacs.h"
#include "alpha_ins.h"
#include "f64.h"
#include "reg_defs.h"
#include "cross.h"
#include "operators.h"
bool testover = 0;		/* always 0 for C */

void
tidyshort(int r, shape s)
{
  /* corrects possible overflows of chars
     and shorts in reg r */
  if (name (s) == SH_UCHAR) {
    operate_fmt_immediate (i_and, r,255,r);
  }
  else
    if (name (s) == SH_UWORD) {
      operate_fmt_immediate (i_and, r,0xffff,r);
    }
}


/* 
   given a list of expressions seq which
   contains one whose value is in 
   register reg, removes that exp from seq
   and delivers 1; otherwise delivers 0 
*/
bool
regremoved(exp *seq, int reg)
{
  exp s = *seq;
  exp t = bro (s);
  if (abs (regofval (s)) == reg) {
    (*seq) = t;
    return 1;
  }
  for (;;) {
    if (abs (regofval (t)) == reg) {
      bro (s) = bro (t);
      if (last (t))
	setlast (s);
      return 1;
    }
    if (last (t)) {
      return 0;
    }
    s = t;
    t = bro (t);
  }
}


void
do_comm(exp seq, space sp, int final, instruction rins)
{
  int   r = 0;
  space nsp;
  int   a1;
  int   a2;
  a1 = reg_operand (seq, sp);
  /* evaluate 1st operand into a1 */
  for (;;) {
    nsp = guardreg (a1, sp);
    seq = bro (seq);
    if (name (seq) == val_tag) {/* next operand is a constant */
      if (last (seq)) {
	if(isbigval(seq)){
	  int ov;
	  flt64 res;
	  INT64 ires;
	  res = flt_to_f64(no(seq),is_signed(sh(seq)),&ov);
	  ires = flt64_to_INT64(res);
	  operate_fmt_big_immediate(rins,a1,ires,final);
	}
	else
	  operate_fmt_immediate (rins,a1,no(seq),final);
	return;
      }
      else {
	if (r == 0)
	  r = getreg (sp.fixed);
	if(isbigval(seq)){
	  int ov;
	  flt64 res;
	  INT64 ires;
	  res = flt_to_f64(no(seq),is_signed(sh(seq)),&ov);
	  ires = flt64_to_INT64(res);
	  operate_fmt_big_immediate(rins,a1,ires,r);
	}
	else
	  operate_fmt_immediate(rins,a1,no(seq),r);
      }
    }
    else {
      exp sq = seq;
      instruction ins = rins;
      a2 = reg_operand (sq, nsp);
      /* evaluate next operand */
      if (last (seq)) {
	operate_fmt(ins,a1,a2,final);
	return;
      }
      else {
	if (r == 0)
	  r = getreg (sp.fixed);
	operate_fmt (ins,a1, a2,r);
      }
    }
    a1 = r;
  }
  return;
}

/* 
   evaluate commutative operation rrins given by e into d, using 
   sp to get t-regs 
*/
int
comm_op(exp e, space sp, where d, instruction rrins)
{
  instruction rins = rrins;
  switch (d.answhere.discrim) {
    case inreg: {
      int   dest = regalt (d.answhere);
      bool usesdest = regremoved (&son (e), dest);
      exp seq = son (e);
      if(dest == NO_REG) {
	dest = getreg(sp.fixed);
      }
      
      /* the destination is in a register; take care that 
	 we don't alter it before possible use as an operand .... */
      if (usesdest && last (seq)) {
	/* ...it was used, but there is only one
	   other operand */
	if (name (seq) == val_tag) {
	  operate_fmt_immediate (rins, dest, no (seq),dest);
	}
	else {
	  operate_fmt (rins, dest,reg_operand (seq, sp),dest);
	}
	tidyshort (dest, sh (e));
	return dest;
      }
      else if (usesdest) {	/* ... it was used so ... */
        int   r = getreg (sp.fixed);
	do_comm (seq, sp, r, rins);
	/* ... evaluate the remainder of the expression into r... */
	operate_fmt (rins, dest, r,dest);
	/* ... and do dest = dest rins r */
	tidyshort (dest, sh (e));
	return dest;
      }
      else {		/* ... it wasn't used */
	do_comm (seq, sp, dest, rins);
	tidyshort (dest, sh (e));
	return dest;
      }	
    }					/* end inreg */
    default:{
      ans a;
      int   r = getreg (sp.fixed);
      space nsp;
      setregalt (a, r);
      do_comm (son (e), sp, r, rins);
      /* evaluate the expression into r ... */
      tidyshort (r, sh (e));
      nsp = guardreg (r, sp);
      move (a, d, nsp, 1);
      /* ... and move into a */
      return r;
    }				/* notinreg */
  }	      			/* end switch */
}



int
non_comm_op(exp e, space sp, where dest, instruction rins)
{
  /* evaluate binary operation e with rins
     into dest */
  exp l = son (e);
  exp r = bro (l);
  int   a1 = reg_operand (l, sp);
  space nsp;
  int   a2;
  instruction ins = rins;
  nsp = guardreg (a1, sp);
  a2 = reg_operand (r, nsp);
  /* regs a1 and a2 contain the operands */
  switch (dest.answhere.discrim) {
    case inreg: {
      int   d = regalt (dest.answhere);
      if(d!=NO_REG){
	operate_fmt(ins,a1,a2,d);
	tidyshort (d, sh (e));
      }
      return d;
    }
    default:{
      ans a;
      int   r1 = getreg (nsp.fixed);
      setregalt (a, r1);
      operate_fmt (ins, a1,a2,r1);
      tidyshort (r1, sh (e));
      nsp = guardreg (r1, sp);
      move (a, dest, nsp, 1);
      return r1;
    }
  }
}



/* evaluate floating dyadic operation e using ins into dest */
int
fop(exp e, space sp, where dest, instruction ins)
{
  exp l = son (e);
  exp r = bro (l);
  int   a1;
  space nsp;
  int   a2;
  
  if (IsRev(e)) {
    a2 = freg_operand (r, sp);
    nsp = guardfreg (a2, sp);
    a1 = freg_operand(l, nsp);
  }
  else {
    a1 = freg_operand (l, sp);
    nsp = guardfreg (a1, sp);
    a2 = freg_operand(r, nsp);
  }
  switch (dest.answhere.discrim) {
    case infreg:{ 		/* dest in register */
      freg fr;
      fr = fregalt (dest.answhere);
      float_op(ins,a1,a2,fr.fr);
      return((fr.type==IEEE_double)?-(fr.fr+32):(fr.fr+32));
    }
    default:{ 			/* destination elsewhere */
      ans a;
      freg fr;
      int   r1 = getfreg (nsp.flt);
      fr.fr = r1;
      if(dest.ashwhere.ashsize==64)
	fr.type=IEEE_double;
      else
	fr.type=IEEE_single;
      setfregalt (a, fr);
      
      float_op(ins,a1,a2,r1);
#if 1
      if(dest.answhere.discrim == insomefreg){
	*dest.answhere.val.somefregans.fr = r1;
	dest.answhere.val.somefregans.type = fr.type;
      }
      else{
#endif
	move (a, dest, sp, 1);
#if 1
      }
#endif
      return ((fr.type==IEEE_double)?-(fr.fr+32):(fr.fr+32));
    }
  }
}





