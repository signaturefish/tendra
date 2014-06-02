/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <stddef.h>

#include <reader/exptypes.h>
#include <reader/expmacs.h>

#include <construct/installglob.h>
#include <construct/exp.h>
#include <construct/tags.h>
#include <construct/shapemacs.h>

#include <main/flags.h>

#include <refactor/optimise.h>

#include <utility/complexity.h>

#define crit_inline	300
#define crit_decs	5
#define crit_decsatapp	5
#define apply_cost      3

/*
 * delivers 0 if no uses of this proc can be inlined.
 * delivers 1 if this use cannot be inlined
 * delivers 2 if this use can be inlined.
 */
int inlinechoice
(exp t, exp def, int total_uses)
{
  int res;

  exp apars;
  exp fpars;

  int newdecs = 0;
  int no_actuals;
  int max_complexity;

  int nparam;
  const int CONST_BONUS_UNIT = 16;
  int const_param_bonus;
  int adjusted_max_complexity;

  shape shdef = pt(def) /* Oh, yes it is! */;

  if (!eq_shape(sh(father(t)), shdef)) {
     /* shape required by application is different from definition */
	return 1;
  }

  nparam = 0;
  const_param_bonus = 0;


  max_complexity = (crit_inline / total_uses);

  if (max_complexity < 15) {
    max_complexity = 15;
  } else if (max_complexity > 120) {
    max_complexity = 120;
  }

  apars = bro(t); /* only uses are applications */
  no_actuals = last(t);		/* if so then apars is apply_tag... */
  fpars = son(def);

  for (;;) {
     if (name(fpars)!=ident_tag || !isparam(fpars)) {
		 /* first beyond formals */
       if (!no_actuals)
	 newdecs = 10;
	 /* more actuals than formals, since last(apars)->break */
       break;
     }
     nparam++;

     switch (name(apars)) {
      case val_tag: case real_tag: case string_tag: case name_tag:
      	   break;
      case cont_tag: {
      	   if (name(son(apars)) ==name_tag && isvar(son(son(apars))) &&
      	        		!isvar(fpars))break;
      	   } /* ... else continue */
      default: newdecs++;
     }
     switch (name(apars))
     {
      case val_tag: {
	int n = no(apars);
	if (isbigval(apars))break;

	/* Simple constant param. Increase desire to
	   inline since a constant may cause further
	   optimisation, eg strength reduction (mul
	   to shift) or dead code savings */

#define IS_POW2(c)	((c)!= 0 && ((c) & ((c) - 1)) == 0)

	if (0) {
	  /* needs a register - poor */
	  const_param_bonus += CONST_BONUS_UNIT / 4;
	} else if (n == 0 || (n > 0 && IS_POW2(n))) {
	  /* very good */
	  const_param_bonus += CONST_BONUS_UNIT;
	} else {
	  /* less good */
	  const_param_bonus += CONST_BONUS_UNIT / 2;
	}
	break;
      }

#undef IS_POW2

      case real_tag:
	/* reals not that useful */
	const_param_bonus += CONST_BONUS_UNIT / 4;
	break;

      case string_tag:
       case name_tag:
	 break;

      case cont_tag:
	if (name(son(apars)) == name_tag &&
	    isvar(son(son(apars))) &&
	    !isvar(fpars)) {
	  break;
	}
	/* FALL THROUGH */

      default : {
	newdecs++;
	break;
      }
     }
     fpars = bro(son(fpars));
     if (last(apars))break;
     apars = bro(apars);
   }

  adjusted_max_complexity = max_complexity;

  /* increase to up to 3 times (average around 2) according
     to const params */
  if (nparam != 0) {
    adjusted_max_complexity +=
     (2 * max_complexity * const_param_bonus) /
	(CONST_BONUS_UNIT * nparam);
  }

  /* increase by number of instructions saved for call */
    adjusted_max_complexity += nparam - newdecs + 1;

  if ((complexity(fpars, adjusted_max_complexity, newdecs, crit_decs, crit_decsatapp, apply_cost)) >= 0)
    res = 2;
  else if (newdecs == 0)
    res = 0;
  else
    res = 1;


  return res;

}
