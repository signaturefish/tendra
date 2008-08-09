/*
 * Automatically generated from the files:
 *	syntax.sid
 * and
 *	syntax.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */

#line 131 "syntax.act"

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

#include <string.h>
#include <stdio.h>

#include "exds/common.h"
#include "exds/exception.h"
#include "exds/dalloc.h"
#include "exds/dstring.h"

#include "error/error.h"
#include "xalloc/xalloc.h"

#include "char.h"
#include "adt.h"
#include "lexer.h"
#include "syntax.h"
#include "options.h"


#define ADVANCE_LEXER ADVANCE_LXI_LEXER
#define CURRENT_TERMINAL CURRENT_LXI_TERMINAL 
#define SAVE_LEXER SAVE_LXI_LEXER
#define RESTORE_LEXER RESTORE_LXI_LEXER

/* TODO see main.c; this is a work-around for the copyright file */
extern cmd_line_options options;



/*
    PARSER TYPES

    These types give the implementation of the types used in the syntax.
*/

typedef letter *SID_CHARS ;
typedef char *SID_STRING ;
/*typedef zone* zoneP; Done in syntax.h */
typedef instruction* instructionP ;
typedef instructions_list* instructions_listP ;
typedef arg* argP;
typedef args_list* args_listP;

/*
    SID IDENTIFIER PREFIX

    This string is added to the start of each sid identifier.
*/

char *token_prefix = "lex_" ;


/*
    COMPILATION MODE

    We allow unreached code in the automatically generated sections.
*/

#if FS_TENDRA
#pragma TenDRA begin
#ifndef OLD_PRODUCER
#pragma TenDRA unreachable code allow
#endif
#endif


#line 109 "tmp.syntax.c"

/* BEGINNING OF FUNCTION DECLARATIONS */

static void ZR134(void);
static void ZRexpected__semicolon(void);
static void ZRfunction_Haction_Hcall_C_Crhs_Htuple(args_listP *);
static void ZRtuple_Hargs(args_listP *);
static void ZRzone_Hdefn(zoneP);
static void ZRstring_Hplus(SID_STRING *);
static void ZRfunction_Haction_Hcall_C_Clhs_Harg(args_listP);
static void ZRtype_Hdefn(zoneP);
static void ZRchars(zoneP, SID_CHARS *);
static void ZR277(zoneP *, args_listP *, SID_STRING *, instructionP *);
static void ZR278(argP *, args_listP *);
static void ZRfunction_Haction_Hcall_C_Crhs_Harg(argP *);
static void ZR279(argP *, args_listP *);
static void ZR283(zoneP *, TypeTupleT *);
static void ZRtype_Htuple(zoneP, TypeTupleT *);
static void ZR164(void);
static void ZR165(void);
static void ZR166(void);
static void ZRinstructions_Hlist(zoneP, instructions_listP *);
static void ZRtype_Htuple_C_Ctype_Hname(zoneP, TypeTupleT *);
static void ZRargs(args_listP *);
static void ZRtrigraph_Hdefn(zoneP);
static void ZRfunction_Haction_Hcall_C_Clhs_Htuple1(args_listP);
static void ZRfunction_Haction_Hcall_C_Crhs_Htuple1(args_listP *);
static void ZR187(args_listP *);
extern void read_lex(zoneP);
static void ZRaction_Hdecl(zoneP);
static void ZRinstruction(zoneP, instructionP *);
static void ZR207(zoneP *, SID_CHARS *);
static void ZRcommand_Hlist(zoneP);
static void ZR209(zoneP *, instructions_listP *);
static void ZRkeyword_Hdefn(zoneP);
static void ZRcopyright_Hstmt(zoneP);
static void ZRcommand(zoneP);
static void ZRnon_Hempty_Htuple_Hargs(args_listP *);
static void ZR231(zoneP, instructions_listP, zoneP *, instructions_listP *);
static void ZRtype_Htuple_C_Ctype_Htuple1(zoneP, TypeTupleT *);
static void ZR233(zoneP *);
static void ZR234(zoneP *);
static void ZR236(zoneP *, args_listP *, instructionP *);
static void ZRnon_Hempty_Hchars(zoneP, SID_CHARS *);
static void ZRsingle_Harg(argP *);
static void ZR249(zoneP *, args_listP *, SID_STRING *, instructionP *);
static void ZR253(zoneP *, args_listP *, instructionP *);

/* BEGINNING OF STATIC VARIABLES */

static int ZI0;

/* BEGINNING OF FUNCTION DEFINITIONS */

static void
ZR134(void)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 20:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	/* BEGINNING OF ACTION: E_expected_equal */
	{
#line 965 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected equal \'=\'");
#line 187 "tmp.syntax.c"
	}
	/* END OF ACTION: E_expected_equal */
    }
}

static void
ZRexpected__semicolon(void)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 22:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	/* BEGINNING OF ACTION: E_expected_semicolon */
	{
#line 957 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected semicolon \';\'");
#line 216 "tmp.syntax.c"
	}
	/* END OF ACTION: E_expected_semicolon */
    }
}

static void
ZRfunction_Haction_Hcall_C_Crhs_Htuple(args_listP *ZOr)
{
    args_listP ZIr;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 14:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF INLINE: 184 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 0: case 1: case 2: case 24:
	      case 31: case 32: case 33: case 34:
	      case 35: case 36:
		{
		    ZRfunction_Haction_Hcall_C_Crhs_Htuple1 (&ZIr);
		    if ((CURRENT_TERMINAL) == 42) {
			RESTORE_LEXER;
			goto ZL1;
		    }
		}
		break;
	      default:
		{
		    /* BEGINNING OF ACTION: empty-args-list */
		    {
#line 457 "syntax.act"

    (ZIr)=add_args_list();
#line 259 "tmp.syntax.c"
		    }
		    /* END OF ACTION: empty-args-list */
		}
		break;
	    }
	}
	/* END OF INLINE: 184 */
	switch (CURRENT_TERMINAL) {
	  case 15:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOr = ZIr;
}

static void
ZRtuple_Hargs(args_listP *ZOl)
{
    args_listP ZIl;

    switch (CURRENT_TERMINAL) {
      case 37:
	{
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: empty-args-list */
	    {
#line 457 "syntax.act"

    (ZIl)=add_args_list();
#line 297 "tmp.syntax.c"
	    }
	    /* END OF ACTION: empty-args-list */
	}
	break;
      case 0: case 1: case 2: case 24:
      case 31: case 32: case 33: case 34:
      case 35: case 36:
	{
	    ZRnon_Hempty_Htuple_Hargs (&ZIl);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      default:
	{
	    argP ZItmp;

	    /* BEGINNING OF ACTION: empty-args-list */
	    {
#line 457 "syntax.act"

    (ZIl)=add_args_list();
#line 322 "tmp.syntax.c"
	    }
	    /* END OF ACTION: empty-args-list */
	    /* BEGINNING OF ACTION: arg-char-list-tmp */
	    {
#line 416 "syntax.act"

      (ZItmp)=add_arg(arg_chars_list,0);
#line 330 "tmp.syntax.c"
	    }
	    /* END OF ACTION: arg-char-list-tmp */
	    /* BEGINNING OF ACTION: args-list-push-front */
	    {
#line 430 "syntax.act"

    (ZItmp)->next=(ZIl)->head;
    (ZIl)->head=(ZItmp);
    if((ZItmp)->type==arg_return_terminal)
	(ZIl)->nb_return_terminal++;
#line 341 "tmp.syntax.c"
	    }
	    /* END OF ACTION: args-list-push-front */
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOl = ZIl;
}

static void
ZRzone_Hdefn(zoneP ZIz)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIzid;
	SID_CHARS ZIb;
	instructions_listP ZIentry_Hinstl;
	int ZIlendclosed;
	SID_CHARS ZIe;
	instructions_listP ZIleaving_Hinstl;
	zoneP ZInew_Hzone;

	switch (CURRENT_TERMINAL) {
	  case 13:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF INLINE: 199 */
	{
	    {
		switch (CURRENT_TERMINAL) {
		  case 0:
		    /* BEGINNING OF EXTRACT: identifier */
		    {
#line 202 "syntax.act"

    ZIzid = xstrcpy ( token_buff ) ;
#line 389 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: identifier */
		    break;
		  default:
		    goto ZL3;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL2;
	  ZL3:;
	    {
		/* BEGINNING OF ACTION: E_expected_identifier */
		{
#line 930 "syntax.act"

	(ZIzid)="";
	error(ERROR_SERIOUS, "Syntax error: expected identifier");
#line 407 "tmp.syntax.c"
		}
		/* END OF ACTION: E_expected_identifier */
	    }
	  ZL2:;
	}
	/* END OF INLINE: 199 */
	/* BEGINNING OF INLINE: 201 */
	{
	    {
		switch (CURRENT_TERMINAL) {
		  case 23:
		    break;
		  default:
		    goto ZL5;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL4;
	  ZL5:;
	    {
		/* BEGINNING OF ACTION: E_expected_colon */
		{
#line 953 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected colon \':\'");
#line 433 "tmp.syntax.c"
		}
		/* END OF ACTION: E_expected_colon */
	    }
	  ZL4:;
	}
	/* END OF INLINE: 201 */
	ZR207 (&ZIz, &ZIb);
	ZR209 (&ZIz, &ZIentry_Hinstl);
	/* BEGINNING OF INLINE: 205 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 25:
		{
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: true */
		    {
#line 742 "syntax.act"
 (ZIlendclosed) = 1 ; 
#line 452 "tmp.syntax.c"
		    }
		    /* END OF ACTION: true */
		}
		break;
	      case 26:
		{
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: true */
		    {
#line 742 "syntax.act"
 (ZIlendclosed) = 1 ; 
#line 464 "tmp.syntax.c"
		    }
		    /* END OF ACTION: true */
		}
		break;
	      case 27:
		{
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: false */
		    {
#line 743 "syntax.act"
 (ZIlendclosed) = 0 ; 
#line 476 "tmp.syntax.c"
		    }
		    /* END OF ACTION: false */
		}
		break;
	      case 42:
		RESTORE_LEXER;
		goto ZL7;
	      default:
		goto ZL7;
	    }
	    goto ZL6;
	  ZL7:;
	    {
		/* BEGINNING OF ACTION: E_expected_range */
		{
#line 936 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected range");
#line 495 "tmp.syntax.c"
		}
		/* END OF ACTION: E_expected_range */
		/* BEGINNING OF ACTION: false */
		{
#line 743 "syntax.act"
 (ZIlendclosed) = 0 ; 
#line 502 "tmp.syntax.c"
		}
		/* END OF ACTION: false */
	    }
	  ZL6:;
	}
	/* END OF INLINE: 205 */
	ZR207 (&ZIz, &ZIe);
	ZR209 (&ZIz, &ZIleaving_Hinstl);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	/* BEGINNING OF ACTION: make-zone */
	{
#line 762 "syntax.act"

    instruction* inst;
    instructions_list* inst_list;
    (ZInew_Hzone)=add_zone((ZIz),(ZIzid),(ZIe), (ZIlendclosed) );

    (ZInew_Hzone)->leaving_instructions=(ZIleaving_Hinstl);
    if((ZInew_Hzone)->leaving_instructions->nb_return_terminal)
	(ZInew_Hzone)->type= typezone_pseudo_token;
    (ZInew_Hzone)->entering_instructions=(ZIentry_Hinstl);
    if((ZInew_Hzone)->entering_instructions->nb_return_terminal)
	(ZInew_Hzone)->type=typezone_general_zone;
    inst=add_instruction_pushzone((ZInew_Hzone));
    inst_list=add_instructions_list();
    *(inst_list->tail)=inst;
    inst_list->tail=&(inst->next);
    add_char ( (ZIz), (ZIz)->zone_main_pass, (ZIb), inst_list, NULL ) ;
#line 534 "tmp.syntax.c"
	}
	/* END OF ACTION: make-zone */
	switch (CURRENT_TERMINAL) {
	  case 16:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	ZRcommand_Hlist (ZInew_Hzone);
	switch (CURRENT_TERMINAL) {
	  case 17:
	    break;
	  case 42:
	    RESTORE_LEXER;
	    goto ZL1;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF ACTION: update-zone-type */
	{
#line 778 "syntax.act"

	switch((ZInew_Hzone)->type) {
		case typezone_pseudo_token:
		case typezone_general_zone:
			(ZIz)->type = typezone_general_zone;
			break;
		case typezone_pure_function:
			break; //do nothing

	}
#line 568 "tmp.syntax.c"
	}
	/* END OF ACTION: update-zone-type */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRstring_Hplus(SID_STRING *ZOs)
{
    SID_STRING ZIs;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIa;

	/* BEGINNING OF INLINE: 118 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 5:
		{
		    /* BEGINNING OF EXTRACT: digit */
		    {
#line 259 "syntax.act"
 ZIa = "0123456789" ; 
#line 598 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: digit */
		    ADVANCE_LEXER;
		}
		break;
	      case 4:
		{
		    /* BEGINNING OF EXTRACT: lower */
		    {
#line 258 "syntax.act"
 ZIa = "abcdefghijklmnopqrstuvwxyz" ; 
#line 610 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: lower */
		    ADVANCE_LEXER;
		}
		break;
	      case 2:
		{
		    /* BEGINNING OF EXTRACT: string */
		    {
#line 247 "syntax.act"

    ZIa = xstrcpy ( token_buff ) ;
#line 623 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: string */
		    ADVANCE_LEXER;
		}
		break;
	      case 3:
		{
		    /* BEGINNING OF EXTRACT: upper */
		    {
#line 257 "syntax.act"
 ZIa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ; 
#line 635 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: upper */
		    ADVANCE_LEXER;
		}
		break;
	      default:
		goto ZL1;
	    }
	}
	/* END OF INLINE: 118 */
	/* BEGINNING OF INLINE: 120 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 21:
		{
		    SID_STRING ZIb;

		    ADVANCE_LEXER;
		    ZRstring_Hplus (&ZIb);
		    if ((CURRENT_TERMINAL) == 42) {
			RESTORE_LEXER;
			goto ZL1;
		    }
		    /* BEGINNING OF ACTION: string-concat */
		    {
#line 298 "syntax.act"

    (ZIs) = xstrcat ( (ZIa), (ZIb) ) ;
#line 664 "tmp.syntax.c"
		    }
		    /* END OF ACTION: string-concat */
		}
		break;
	      default:
		{
		    ZIs = ZIa;
		}
		break;
	    }
	}
	/* END OF INLINE: 120 */
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOs = ZIs;
}

static void
ZRfunction_Haction_Hcall_C_Clhs_Harg(args_listP ZIl)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	argP ZIa;

	/* BEGINNING OF INLINE: 171 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 31:
		{
		    argP ZIb;

		    /* BEGINNING OF EXTRACT: arg-char-list */
		    {
#line 265 "syntax.act"

      ZIb=add_arg(arg_chars_list,0);
#line 707 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: arg-char-list */
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_none */
		    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 716 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_none */
		    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
		    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 724 "tmp.syntax.c"
		    }
		    /* END OF ACTION: E_sharp_arg_in_lhs */
		}
		break;
	      case 33:
		{
		    argP ZIb;

		    /* BEGINNING OF EXTRACT: arg-char-nb */
		    {
#line 273 "syntax.act"

      ZIb=add_arg(arg_char_nb,number_buffer);
#line 738 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: arg-char-nb */
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_none */
		    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 747 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_none */
		    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
		    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 755 "tmp.syntax.c"
		    }
		    /* END OF ACTION: E_sharp_arg_in_lhs */
		}
		break;
	      case 32:
		{
		    argP ZIb;

		    /* BEGINNING OF EXTRACT: arg-char-string */
		    {
#line 269 "syntax.act"

      ZIb=add_arg(arg_charP,0);
#line 769 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: arg-char-string */
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_none */
		    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 778 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_none */
		    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
		    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 786 "tmp.syntax.c"
		    }
		    /* END OF ACTION: E_sharp_arg_in_lhs */
		}
		break;
	      case 36:
		{
		    /* BEGINNING OF EXTRACT: arg-ignore */
		    {
#line 285 "syntax.act"

      ZIa=add_arg(arg_ignore,0);
#line 798 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: arg-ignore */
		    ADVANCE_LEXER;
		}
		break;
	      case 34:
		{
		    argP ZIb;

		    /* BEGINNING OF EXTRACT: arg-nb-of-chars */
		    {
#line 277 "syntax.act"

      ZIb=add_arg(arg_nb_of_chars,0);
#line 813 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: arg-nb-of-chars */
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_none */
		    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 822 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_none */
		    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
		    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 830 "tmp.syntax.c"
		    }
		    /* END OF ACTION: E_sharp_arg_in_lhs */
		}
		break;
	      case 35:
		{
		    /* BEGINNING OF EXTRACT: arg-return-terminal */
		    {
#line 281 "syntax.act"

      ZIa=add_arg(arg_return_terminal,0);
#line 842 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: arg-return-terminal */
		    ADVANCE_LEXER;
		}
		break;
	      case 0:
		{
		    SID_STRING ZIi;

		    /* BEGINNING OF EXTRACT: identifier */
		    {
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 857 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: identifier */
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_from_identifier */
		    {
#line 795 "syntax.act"

	(ZIa) = add_identifier_arg ((ZIi));
#line 866 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_from_identifier */
		}
		break;
	      case 24:
		{
		    SID_STRING ZIi;

		    ADVANCE_LEXER;
		    switch (CURRENT_TERMINAL) {
		      case 0:
			/* BEGINNING OF EXTRACT: identifier */
			{
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 883 "tmp.syntax.c"
			}
			/* END OF EXTRACT: identifier */
			break;
		      default:
			goto ZL1;
		    }
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_from_reference */
		    {
#line 799 "syntax.act"

	(ZIa) = add_reference_arg ((ZIi));
#line 896 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_from_reference */
		}
		break;
	      case 1:
		{
		    SID_STRING ZIb;

		    /* BEGINNING OF EXTRACT: sid-identifier */
		    {
#line 235 "syntax.act"

    int n ;
    char *s ;
    char buff [1000] ;
    strcpy ( buff, token_prefix ) ;
    n = ( int ) strlen ( buff ) ;
    for ( s = token_buff ; *s ; s++ ) {
	if ( *s == '-' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = 'H' ;
	} else if ( *s == '_' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = '_' ;
	} else {
	    buff [ n++ ] = *s ;
	}
	if ( n >= 900 ) {
	    error ( ERROR_SERIOUS, "Identifier too long" ) ;
	    break ;
	}
    }
    buff [n] = 0 ;
    ZIb = xstrcpy ( buff ) ;
#line 931 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: sid-identifier */
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_none */
		    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 940 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_none */
		    /* BEGINNING OF ACTION: E_terminal_in_lhs */
		    {
#line 1018 "syntax.act"

	error(ERROR_SERIOUS, "Terminal argument in left handside");
#line 948 "tmp.syntax.c"
		    }
		    /* END OF ACTION: E_terminal_in_lhs */
		}
		break;
	      case 2:
		{
		    SID_STRING ZIb;

		    /* BEGINNING OF EXTRACT: string */
		    {
#line 247 "syntax.act"

    ZIb = xstrcpy ( token_buff ) ;
#line 962 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: string */
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: make_arg_none */
		    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 971 "tmp.syntax.c"
		    }
		    /* END OF ACTION: make_arg_none */
		    /* BEGINNING OF ACTION: E_string_arg_in_lhs */
		    {
#line 986 "syntax.act"

	error(ERROR_SERIOUS, "Argument of type "" are rvalues and should not appear on a left handside");
#line 979 "tmp.syntax.c"
		    }
		    /* END OF ACTION: E_string_arg_in_lhs */
		}
		break;
	      default:
		goto ZL1;
	    }
	}
	/* END OF INLINE: 171 */
	/* BEGINNING OF ACTION: append-arg-args-list */
	{
#line 423 "syntax.act"

    *(ZIl)->tail=(ZIa);
    (ZIl)->tail=&(ZIa)->next;
    if((ZIa)->type==arg_return_terminal)
	(ZIl)->nb_return_terminal++;
#line 997 "tmp.syntax.c"
	}
	/* END OF ACTION: append-arg-args-list */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRtype_Hdefn(zoneP ZIz)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIs;

	switch (CURRENT_TERMINAL) {
	  case 41:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	switch (CURRENT_TERMINAL) {
	  case 0:
	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZIs = xstrcpy ( token_buff ) ;
#line 1030 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF INLINE: 145 */
	{
	    {
		/* BEGINNING OF ACTION: is-global-zone */
		{
#line 817 "syntax.act"

   (ZI0)=((ZIz)==(ZIz)->top_level->global_zone);
#line 1046 "tmp.syntax.c"
		}
		/* END OF ACTION: is-global-zone */
		if (!ZI0)
		    goto ZL3;
		/* BEGINNING OF ACTION: make-type */
		{
#line 834 "syntax.act"

	NStringT str;
	nstring_copy_cstring(&str,(ZIs));
	xfree((ZIs));
	EntryT* entry;
	if(entry=table_get_entry((ZIz)->top_level->table, &str)) {
		nstring_destroy(&str);
		/* TODO switch ? */
		if(entry_is_type(entry))
			error(ERROR_SERIOUS, "Type %s already exists",(ZIs));
		else if(entry_is_localname(entry))
			error(ERROR_SERIOUS, "Can't create type %s, %s has been previously used as a local name. We do not allow retroactive hiding.",(ZIs),(ZIs));
		else if(entry_is_action(entry))
			error(ERROR_SERIOUS, "Can't create type %s, %s has already been declared as an action",(ZIs), (ZIs));
		else
			; /* TODO assert(0): we should never reach that place*/
	} else {
		table_add_type((ZIz)->top_level->table, &str, false);
	}
#line 1073 "tmp.syntax.c"
		}
		/* END OF ACTION: make-type */
	    }
	    goto ZL2;
	  ZL3:;
	    {
		/* BEGINNING OF ACTION: E_nonglobalzonetype */
		{
#line 919 "syntax.act"

    error( ERROR_SERIOUS, "Syntax error: type %s should not be declared inside a zone",(ZIs)) ;
#line 1085 "tmp.syntax.c"
		}
		/* END OF ACTION: E_nonglobalzonetype */
	    }
	  ZL2:;
	}
	/* END OF INLINE: 145 */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRchars(zoneP ZIz, SID_CHARS *ZOc)
{
    SID_CHARS ZIc;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIs;

	ZRstring_Hplus (&ZIs);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	/* BEGINNING OF ACTION: make-chars */
	{
#line 319 "syntax.act"

    (ZIc) = make_string ( (ZIs), (ZIz) ) ;
#line 1120 "tmp.syntax.c"
	}
	/* END OF ACTION: make-chars */
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOc = ZIc;
}

static void
ZR277(zoneP *ZIz, args_listP *ZIl, SID_STRING *ZI276, instructionP *ZOinst)
{
    instructionP ZIinst;

    switch (CURRENT_TERMINAL) {
      case 20:
	{
	    argP ZI270;

	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZI270) = add_none_arg();
#line 1147 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_terminal_in_lhs */
	    {
#line 1018 "syntax.act"

	error(ERROR_SERIOUS, "Terminal argument in left handside");
#line 1155 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_terminal_in_lhs */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI270);
    (*ZIl)->tail=&(ZI270)->next;
    if((ZI270)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 1166 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      default:
	{
	    args_listP ZIa;
	    int ZIb;

	    /* BEGINNING OF ACTION: null-args-list */
	    {
#line 464 "syntax.act"

    (ZIa) = NULL ;
#line 1187 "tmp.syntax.c"
	    }
	    /* END OF ACTION: null-args-list */
	    /* BEGINNING OF ACTION: true */
	    {
#line 742 "syntax.act"
 (ZIb) = 1 ; 
#line 1194 "tmp.syntax.c"
	    }
	    /* END OF ACTION: true */
	    /* BEGINNING OF ACTION: make-inst */
	    {
#line 366 "syntax.act"

    if((ZIa)) {
    	if((ZIb))
	    (ZIinst)=add_instruction_terminalfunction((*ZI276),(ZIa));
	else
	    (ZIinst)=add_instruction_purefunction((*ZI276),(ZIa));
    } 
    else {
        (ZIinst)=add_instruction_return_terminal((*ZI276));
    }
#line 1210 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-inst */
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOinst = ZIinst;
}

static void
ZR278(argP *ZIa, args_listP *ZOr)
{
    args_listP ZIr;

    switch (CURRENT_TERMINAL) {
      case 28:
	{
	    ADVANCE_LEXER;
	    ZRfunction_Haction_Hcall_C_Crhs_Htuple1 (&ZIr);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: args-list-push-front */
	    {
#line 430 "syntax.act"

    (*ZIa)->next=(ZIr)->head;
    (ZIr)->head=(*ZIa);
    if((*ZIa)->type==arg_return_terminal)
	(ZIr)->nb_return_terminal++;
#line 1248 "tmp.syntax.c"
	    }
	    /* END OF ACTION: args-list-push-front */
	}
	break;
      default:
	{
	    /* BEGINNING OF ACTION: empty-args-list */
	    {
#line 457 "syntax.act"

    (ZIr)=add_args_list();
#line 1260 "tmp.syntax.c"
	    }
	    /* END OF ACTION: empty-args-list */
	    /* BEGINNING OF ACTION: args-list-push-front */
	    {
#line 430 "syntax.act"

    (*ZIa)->next=(ZIr)->head;
    (ZIr)->head=(*ZIa);
    if((*ZIa)->type==arg_return_terminal)
	(ZIr)->nb_return_terminal++;
#line 1271 "tmp.syntax.c"
	    }
	    /* END OF ACTION: args-list-push-front */
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOr = ZIr;
}

static void
ZRfunction_Haction_Hcall_C_Crhs_Harg(argP *ZOa)
{
    argP ZIa;

    switch (CURRENT_TERMINAL) {
      case 31:
	{
	    argP ZIb;

	    /* BEGINNING OF EXTRACT: arg-char-list */
	    {
#line 265 "syntax.act"

      ZIb=add_arg(arg_chars_list,0);
#line 1302 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-list */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 1311 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_sharp_list_in_action_rhs */
	    {
#line 1009 "syntax.act"

	error(ERROR_SERIOUS, "Args of style ## are not implemented in actions right hand side. Whether they will be implemented in the future remains undecided at the moment.");
/* TODO take a decision.*/
#line 1320 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_sharp_list_in_action_rhs */
	}
	break;
      case 33:
	{
	    /* BEGINNING OF EXTRACT: arg-char-nb */
	    {
#line 273 "syntax.act"

      ZIa=add_arg(arg_char_nb,number_buffer);
#line 1332 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-nb */
	    ADVANCE_LEXER;
	}
	break;
      case 32:
	{
	    /* BEGINNING OF EXTRACT: arg-char-string */
	    {
#line 269 "syntax.act"

      ZIa=add_arg(arg_charP,0);
#line 1345 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-string */
	    ADVANCE_LEXER;
	}
	break;
      case 36:
	{
	    argP ZIb;

	    /* BEGINNING OF EXTRACT: arg-ignore */
	    {
#line 285 "syntax.act"

      ZIb=add_arg(arg_ignore,0);
#line 1360 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-ignore */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 1369 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_ignore_in_rhs */
	    {
#line 1014 "syntax.act"

	error(ERROR_SERIOUS, "Ignore argument in right handside");
#line 1377 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_ignore_in_rhs */
	}
	break;
      case 34:
	{
	    /* BEGINNING OF EXTRACT: arg-nb-of-chars */
	    {
#line 277 "syntax.act"

      ZIa=add_arg(arg_nb_of_chars,0);
#line 1389 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-nb-of-chars */
	    ADVANCE_LEXER;
	}
	break;
      case 35:
	{
	    argP ZIb;

	    /* BEGINNING OF EXTRACT: arg-return-terminal */
	    {
#line 281 "syntax.act"

      ZIb=add_arg(arg_return_terminal,0);
#line 1404 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-return-terminal */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 1413 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_return_terminal_in_rhs */
	    {
#line 990 "syntax.act"

	error(ERROR_SERIOUS, "Return terminal argument in right handside");
#line 1421 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_return_terminal_in_rhs */
	}
	break;
      case 0:
	{
	    SID_STRING ZIi;

	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 1435 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_from_identifier */
	    {
#line 795 "syntax.act"

	(ZIa) = add_identifier_arg ((ZIi));
#line 1444 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_from_identifier */
	}
	break;
      case 24:
	{
	    SID_STRING ZIi;

	    ADVANCE_LEXER;
	    switch (CURRENT_TERMINAL) {
	      case 0:
		/* BEGINNING OF EXTRACT: identifier */
		{
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 1461 "tmp.syntax.c"
		}
		/* END OF EXTRACT: identifier */
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_from_reference */
	    {
#line 799 "syntax.act"

	(ZIa) = add_reference_arg ((ZIi));
#line 1474 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_from_reference */
	}
	break;
      case 1:
	{
	    SID_STRING ZIb;

	    /* BEGINNING OF EXTRACT: sid-identifier */
	    {
#line 235 "syntax.act"

    int n ;
    char *s ;
    char buff [1000] ;
    strcpy ( buff, token_prefix ) ;
    n = ( int ) strlen ( buff ) ;
    for ( s = token_buff ; *s ; s++ ) {
	if ( *s == '-' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = 'H' ;
	} else if ( *s == '_' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = '_' ;
	} else {
	    buff [ n++ ] = *s ;
	}
	if ( n >= 900 ) {
	    error ( ERROR_SERIOUS, "Identifier too long" ) ;
	    break ;
	}
    }
    buff [n] = 0 ;
    ZIb = xstrcpy ( buff ) ;
#line 1509 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: sid-identifier */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_terminal */
	    {
#line 803 "syntax.act"

	(ZIa) = add_terminal_arg ((ZIb));
#line 1518 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_terminal */
	}
	break;
      case 2:
	{
	    SID_STRING ZIb;

	    /* BEGINNING OF EXTRACT: string */
	    {
#line 247 "syntax.act"

    ZIb = xstrcpy ( token_buff ) ;
#line 1532 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: string */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 1541 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_string_in_action_rhs */
	    {
#line 994 "syntax.act"

	error(ERROR_SERIOUS, "String argument in right handside of action call: purposefuly not implemented to avoid confusions. Will be implemented with an alternate meaning once direct function calls are removed from lexi");
#line 1549 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_string_in_action_rhs */
	}
	break;
      case 42:
	return;
      default:
	goto ZL1;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOa = ZIa;
}

static void
ZR279(argP *ZIa, args_listP *ZOl)
{
    args_listP ZIl;

    switch (CURRENT_TERMINAL) {
      case 28:
	{
	    ADVANCE_LEXER;
	    ZRnon_Hempty_Htuple_Hargs (&ZIl);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: args-list-push-front */
	    {
#line 430 "syntax.act"

    (*ZIa)->next=(ZIl)->head;
    (ZIl)->head=(*ZIa);
    if((*ZIa)->type==arg_return_terminal)
	(ZIl)->nb_return_terminal++;
#line 1589 "tmp.syntax.c"
	    }
	    /* END OF ACTION: args-list-push-front */
	}
	break;
      default:
	{
	    /* BEGINNING OF ACTION: empty-args-list */
	    {
#line 457 "syntax.act"

    (ZIl)=add_args_list();
#line 1601 "tmp.syntax.c"
	    }
	    /* END OF ACTION: empty-args-list */
	    /* BEGINNING OF ACTION: args-list-push-front */
	    {
#line 430 "syntax.act"

    (*ZIa)->next=(ZIl)->head;
    (ZIl)->head=(*ZIa);
    if((*ZIa)->type==arg_return_terminal)
	(ZIl)->nb_return_terminal++;
#line 1612 "tmp.syntax.c"
	    }
	    /* END OF ACTION: args-list-push-front */
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOl = ZIl;
}

static void
ZR283(zoneP *ZIz, TypeTupleT *ZIa)
{
    switch (CURRENT_TERMINAL) {
      case 0: case 23:
	{
	    ZRtype_Htuple_C_Ctype_Htuple1 (*ZIz, ZIa);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 42:
	return;
      default:
	break;
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRtype_Htuple(zoneP ZIz, TypeTupleT *ZOa)
{
    TypeTupleT ZIa;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	/* BEGINNING OF ACTION: init-tuple */
	{
#line 879 "syntax.act"

	typetuple_init(&(ZIa));
#line 1666 "tmp.syntax.c"
	}
	/* END OF ACTION: init-tuple */
	ZR283 (&ZIz, &ZIa);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    /* BEGINNING OF RESULT ASSIGNMENT: TYPETUPLE */
    {
#line 187 "syntax.act"

	typetuple_assign(ZOa, (&ZIa));
#line 1685 "tmp.syntax.c"
    }
    /* END OF RESULT ASSIGNMENT: TYPETUPLE */
}

static void
ZR164(void)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 18:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	/* BEGINNING OF ACTION: E_expected_arrow */
	{
#line 961 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected arrow \'->\'");
#line 1713 "tmp.syntax.c"
	}
	/* END OF ACTION: E_expected_arrow */
    }
}

static void
ZR165(void)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 14:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	/* BEGINNING OF ACTION: E_expected_open */
	{
#line 940 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected open \'(\'");
#line 1742 "tmp.syntax.c"
	}
	/* END OF ACTION: E_expected_open */
    }
}

static void
ZR166(void)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 15:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	/* BEGINNING OF ACTION: E_expected_close */
	{
#line 944 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected close \')\'");
#line 1771 "tmp.syntax.c"
	}
	/* END OF ACTION: E_expected_close */
    }
}

static void
ZRinstructions_Hlist(zoneP ZI225, instructions_listP *ZO230)
{
    instructions_listP ZI230;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	instructionP ZIinst;
	instructions_listP ZIinstl;
	zoneP ZI229;

	ZRinstruction (ZI225, &ZIinst);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	/* BEGINNING OF ACTION: empty-inst-list */
	{
#line 675 "syntax.act"

    (ZIinstl)=add_instructions_list();
#line 1800 "tmp.syntax.c"
	}
	/* END OF ACTION: empty-inst-list */
	/* BEGINNING OF ACTION: add-inst-to-list */
	{
#line 471 "syntax.act"

	if((ZIinst)!=NULL) { /* if (ZIinst) == NULL, an error has already been issued.*/
		LocalNamesT* locals = instructionslist_localnames((ZIinstl));
/*		if(((ZIinstl)->head !=NULL) && ((ZIinst)->type==return_terminal || (ZIinst)->type==do_nothing)) {
			error(ERROR_SERIOUS, "A $sid-identifier or a $$ can only appear at the end of an instruction-list"); Does not work anymore since we append and do not prepend anymore. No pb as this will be unecessary due to the upcoming removal of direct function calls.
		}*/
		if((ZIinstl)->nb_return_terminal>0 && (ZIinst)->type!=do_nothing)
			error(ERROR_SERIOUS, "No instruction may follow an instruction that returns a terminal");
		if((ZIinst)->type == return_terminal) {
			++((ZIinstl)->nb_return_terminal);
		}
		if((ZIinst)->type == terminal_apply_function) {
			++((ZIinstl)->nb_return_terminal);
		}
		if((ZIinst)->type == action_call) {
			(ZIinstl)->nb_return_terminal+=(ZIinst)->u.act.lhs->nb_return_terminal;
			if((ZIinstl)->nb_return_terminal>1)
				error(ERROR_SERIOUS, "Only one terminal may be returned per token");
			EntryT* entryaction = (ZIinst)->u.act.called_act;
			ActionT* action = entry_get_action(entryaction);
			args_list* rhs = (ZIinst)->u.act.rhs;
			args_list* lhs = (ZIinst)->u.act.lhs;

			arg* p;
			TypeTupleEntryT* q;

			/* CHECKING RHS COMPATIBILITY */ 
			for ( p = rhs->head, q = action->inputs.head; p!=NULL && q!=NULL; p=p->next, q=q->next) {
			      	EntryT* entrytype = NULL;
				NStringT str;
			      	switch (p->type) {
				case arg_identifier: 
				     	nstring_copy_cstring(&str, p->u.litteral);
					entrytype=localnames_get_type(locals, &str);
					nstring_destroy(&str);
					if(!entrytype) {
						EntryT* tableentry = table_get_entry((ZI225)->top_level->table, &str);
						if(!tableentry) {
							error(ERROR_SERIOUS, "local name %s has not been defined yet", p->u.litteral);
							entrytype = NULL;
						} else if (entry_is_localname(tableentry)) {
							error(ERROR_SERIOUS, "local name %s has been defined but not in this scope", p->u.litteral);
							entrytype = NULL;
						} else if (entry_is_action(tableentry)) {
							error(ERROR_SERIOUS, "%s is not a local name but an action which is not allowed", p->u.litteral);
							entrytype = NULL;
						} else if (entry_is_type(tableentry)) {
							error(ERROR_SERIOUS, "%s is not a local name but a type which is not allowed", p->u.litteral);
							entrytype = NULL;
						} else {
							; /* TODO assert(0) this should be unreachable*/
						}
					}
					break;
				case arg_charP:
					/* TODO assert(lexer_string_type(top_level)) */
					entrytype = lexer_string_type((ZI225)->top_level);
		 			break;
				case arg_char_nb:
					/* TODO assert(lexer_char_type(top_level)) */
					entrytype = lexer_char_type((ZI225)->top_level);
			 		break;
				case arg_terminal:
					/* TODO assert(lexer_terminal_type(top_level)) */
					entrytype = lexer_terminal_type((ZI225)->top_level);
					break;
				case arg_nb_of_chars:
					/* TODO assert(lexer_terminal_type(top_level)) */
					entrytype = lexer_int_type((ZI225)->top_level);
		 			break;
				case arg_none:
					break; //Error already detected, do nothing and leave p->lexitype = NULL
				case arg_litteral:
				case arg_chars_list:
				case arg_ignore:
				case arg_return_terminal:
					/* TODO assert(0): we should never reach this place */
				break;
			default:
				break;
				/* TODO assert(0): we should never reach this place either, doubly so*/
			}
			if(entrytype) {
				if( q->type!=entrytype || p->is_reference!=q->is_reference) {
						char* s1 = nstring_to_cstring(entry_key(entryaction));
						char* s2 = nstring_to_cstring(entry_key(entrytype));
						char* s3 = p->is_reference ? "&" : "";
						char* s4 = nstring_to_cstring(entry_key(q->type));
						char* s5 = q->is_reference ? "&" : "";
						error(ERROR_SERIOUS, "In call to action %s, argument \'%s\' has type \'%s%s\' when it should have type %s", s1, p->u.litteral, s2, s3, s4, s5);
						DEALLOCATE(s1);
						DEALLOCATE(s2);
						DEALLOCATE(s4);
					}
				}
			}
			if(p!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, too many arguments", s);
				DEALLOCATE(s);
			}
			if(q!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, not enough arguments", s);
				DEALLOCATE(s);
			}

			for ( p = lhs->head, q = action->outputs.head; p!=NULL && q!=NULL; p=p->next, q=q->next) {
			      	EntryT* entrytype;
				switch (p->type) {
				case arg_identifier: 
					{
						NStringT str;
						EntryT* entry; 
						nstring_copy_cstring(&str, p->u.litteral);
						entrytype = localnames_get_type(locals, &str);
						if(!entrytype) {
							EntryT* entry = table_get_entry((ZI225)->top_level->table, &str);
							localnames_add_nstring(locals, &str, q->type);
							if(entry) {
								nstring_destroy(&str);
								if (entry_is_action(entry)) {
									error(ERROR_SERIOUS, "In action lhs. Name %s is an action. Hiding globals by local names is not allowed", p->u.litteral);
								} else if (entry_is_type(entry)) {
									error(ERROR_SERIOUS, "In action lhs. Name %s is a type. Hiding globals by local names is not allowed", p->u.litteral);									
								}
							} else {
								table_add_local_name((ZI225)->top_level->table, &str);
							}
							if(p->is_reference) {
								char* s = nstring_to_cstring(entry_key(entryaction));
								error(ERROR_SERIOUS, "In action call %s, you can only use references %s for preexisting variables", s, p->u.litteral);
								DEALLOCATE(s);
							} 
						} else {
							nstring_destroy(&str);
							if(!p->is_reference) {
								char* s = nstring_to_cstring(entry_key(entryaction));
								error(ERROR_SERIOUS, "In action call %s, name %s already declared. Use references to change the value of an already existing variable", s, p->u.litteral);
								entrytype=q->type; /* To avoid outputting that error more than once*/
								DEALLOCATE(s);
							}
						}
					}
					break;
				case arg_return_terminal:
					entrytype = lexer_terminal_type((ZI225)->top_level);
					q->is_reference = false;
					/* TODO assert(q->is_reference == false) */
					break;
				case arg_ignore:
					/*always acceptable */
					entrytype=q->type;
					p->is_reference=q->is_reference;
					break;
				case arg_none:
					break;
					/* TODO asserting errored is already set */
					/* Error has already been detected */
				case arg_charP:
				case arg_char_nb:
				case arg_chars_list:
				case arg_terminal:
				case arg_nb_of_chars:
					break; /* UNREACHABLE */
				default:
					break; /* UNREACHABLE */
				}
				if(p->is_reference != q->is_reference) {
					/* XXX: state which action */
					if(p->is_reference)
						error(ERROR_SERIOUS, "In call to action, %s should not be a reference", p->u.litteral);
					else
						error(ERROR_SERIOUS, "In call to action, %s should not be a reference", p->u.litteral);
				}
			}
			if(p!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, too many results", s);
				DEALLOCATE(s);
			}
			if(q!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, not enough results", s);
				DEALLOCATE(s);
			}
		}
		/* TODO only append if no error */
		*(ZIinstl)->tail=(ZIinst);
		(ZIinstl)->tail=&(ZIinst)->next;
		++((ZIinstl)->size);
	}
#line 1998 "tmp.syntax.c"
	}
	/* END OF ACTION: add-inst-to-list */
	ZR231 (ZI225, ZIinstl, &ZI229, &ZI230);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZO230 = ZI230;
}

static void
ZRtype_Htuple_C_Ctype_Hname(zoneP ZIz, TypeTupleT *ZIa)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIname;
	SID_STRING ZItype;
	int ZIisref;

	/* BEGINNING OF INLINE: 149 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 0:
		{
		    /* BEGINNING OF EXTRACT: identifier */
		    {
#line 202 "syntax.act"

    ZIname = xstrcpy ( token_buff ) ;
#line 2036 "tmp.syntax.c"
		    }
		    /* END OF EXTRACT: identifier */
		    ADVANCE_LEXER;
		}
		break;
	      default:
		{
		    /* BEGINNING OF ACTION: empty-identifier */
		    {
#line 308 "syntax.act"

    (ZIname) = xstrcpy("");
#line 2049 "tmp.syntax.c"
		    }
		    /* END OF ACTION: empty-identifier */
		}
		break;
	    }
	}
	/* END OF INLINE: 149 */
	switch (CURRENT_TERMINAL) {
	  case 23:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	switch (CURRENT_TERMINAL) {
	  case 0:
	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZItype = xstrcpy ( token_buff ) ;
#line 2071 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF INLINE: 152 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 24:
		{
		    ADVANCE_LEXER;
		    /* BEGINNING OF ACTION: true */
		    {
#line 742 "syntax.act"
 (ZIisref) = 1 ; 
#line 2089 "tmp.syntax.c"
		    }
		    /* END OF ACTION: true */
		}
		break;
	      default:
		{
		    /* BEGINNING OF ACTION: false */
		    {
#line 743 "syntax.act"
 (ZIisref) = 0 ; 
#line 2100 "tmp.syntax.c"
		    }
		    /* END OF ACTION: false */
		}
		break;
	    }
	}
	/* END OF INLINE: 152 */
	/* BEGINNING OF ACTION: append-tuple */
	{
#line 884 "syntax.act"

	NStringT tstr, istr;
	nstring_copy_cstring(&tstr,(ZItype));
	nstring_copy_cstring(&istr,(ZIname));
	EntryT* entry = table_get_entry((ZIz)->top_level->table,&tstr);
	if(entry == NULL) {
		 error(ERROR_SERIOUS, "Unknown type %s", (ZItype));
		 nstring_destroy(&istr);
	}
	else if(!entry_is_type(entry)) {
		 error(ERROR_SERIOUS, "%s is not a type", (ZItype));
		 nstring_destroy(&istr);
	}
	else {
		typetuple_append((ZIa),typetupleentry_create(&istr,entry,(ZIisref)));
	}
	nstring_destroy(&tstr);
	xfree((ZItype));
	xfree((ZIname));
#line 2130 "tmp.syntax.c"
	}
	/* END OF ACTION: append-tuple */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRargs(args_listP *ZOl)
{
    args_listP ZIl;

    switch (CURRENT_TERMINAL) {
      case 14:
	{
	    ADVANCE_LEXER;
	    ZRtuple_Hargs (&ZIl);
	    switch (CURRENT_TERMINAL) {
	      case 15:
		break;
	      case 42:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	}
	break;
      default:
	{
	    /* BEGINNING OF ACTION: null-args-list */
	    {
#line 464 "syntax.act"

    (ZIl) = NULL ;
#line 2169 "tmp.syntax.c"
	    }
	    /* END OF ACTION: null-args-list */
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOl = ZIl;
}

static void
ZRtrigraph_Hdefn(zoneP ZIz)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_CHARS ZIs;
	SID_STRING ZIt;

	switch (CURRENT_TERMINAL) {
	  case 9:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	ZRchars (ZIz, &ZIs);
	ZR164 ();
	ZRstring_Hplus (&ZIt);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	/* BEGINNING OF ACTION: make-trigraph */
	{
#line 357 "syntax.act"

    add_char ( (ZIz), (ZIz)->zone_pre_pass, (ZIs), NULL, (ZIt)) ;
#line 2214 "tmp.syntax.c"
	}
	/* END OF ACTION: make-trigraph */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRfunction_Haction_Hcall_C_Clhs_Htuple1(args_listP ZIl)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
  ZL2_function_Haction_Hcall_C_Clhs_Htuple1:;
    {
	ZRfunction_Haction_Hcall_C_Clhs_Harg (ZIl);
	/* BEGINNING OF INLINE: 282 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 28:
		{
		    ADVANCE_LEXER;
		    /* BEGINNING OF INLINE: function-action-call::lhs-tuple1 */
		    goto ZL2_function_Haction_Hcall_C_Clhs_Htuple1;
		    /* END OF INLINE: function-action-call::lhs-tuple1 */
		}
		/*UNREACHED*/
	      case 42:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		break;
	    }
	}
	/* END OF INLINE: 282 */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRfunction_Haction_Hcall_C_Crhs_Htuple1(args_listP *ZOr)
{
    args_listP ZIr;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	argP ZIa;

	ZRfunction_Haction_Hcall_C_Crhs_Harg (&ZIa);
	ZR278 (&ZIa, &ZIr);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOr = ZIr;
}

static void
ZR187(args_listP *ZOr)
{
    args_listP ZIr;

    switch (CURRENT_TERMINAL) {
      case 14:
	{
	    ZRfunction_Haction_Hcall_C_Crhs_Htuple (&ZIr);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      default:
	{
	    /* BEGINNING OF ACTION: empty-args-list */
	    {
#line 457 "syntax.act"

    (ZIr)=add_args_list();
#line 2307 "tmp.syntax.c"
	    }
	    /* END OF ACTION: empty-args-list */
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOr = ZIr;
}

void
read_lex(zoneP ZIz)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	ZRcommand_Hlist (ZIz);
	/* BEGINNING OF INLINE: 214 */
	{
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		switch (CURRENT_TERMINAL) {
		  case 19:
		    break;
		  default:
		    goto ZL3;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL2;
	  ZL3:;
	    {
		/* BEGINNING OF ACTION: syntax-error */
		{
#line 978 "syntax.act"

	error ( ERROR_SERIOUS, "Syntax error" ) ;
#line 2354 "tmp.syntax.c"
		}
		/* END OF ACTION: syntax-error */
	    }
	  ZL2:;
	}
	/* END OF INLINE: 214 */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRaction_Hdecl(zoneP ZIz)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIi;
	TypeTupleT ZIit;
	TypeTupleT ZIot;

	switch (CURRENT_TERMINAL) {
	  case 38:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF INLINE: 157 */
	{
	    {
		switch (CURRENT_TERMINAL) {
		  case 39:
		    break;
		  default:
		    goto ZL3;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL2;
	  ZL3:;
	    {
		/* BEGINNING OF ACTION: E_expected_begin_action */
		{
#line 969 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected begin action \'<\'");
#line 2405 "tmp.syntax.c"
		}
		/* END OF ACTION: E_expected_begin_action */
	    }
	  ZL2:;
	}
	/* END OF INLINE: 157 */
	switch (CURRENT_TERMINAL) {
	  case 0:
	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 2419 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF INLINE: 158 */
	{
	    {
		switch (CURRENT_TERMINAL) {
		  case 40:
		    break;
		  default:
		    goto ZL5;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL4;
	  ZL5:;
	    {
		/* BEGINNING OF ACTION: E_expected_end_action */
		{
#line 973 "syntax.act"

	error(ERROR_SERIOUS, "Syntax error: expected end action \'>\'");
#line 2446 "tmp.syntax.c"
		}
		/* END OF ACTION: E_expected_end_action */
	    }
	  ZL4:;
	}
	/* END OF INLINE: 158 */
	/* BEGINNING OF INLINE: 159 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 23:
		{
		    ADVANCE_LEXER;
		    ZR165 ();
		    ZRtype_Htuple (ZIz, &ZIit);
		    ZR166 ();
		    ZR164 ();
		    ZR165 ();
		    ZRtype_Htuple (ZIz, &ZIot);
		    ZR166 ();
		    if ((CURRENT_TERMINAL) == 42) {
			RESTORE_LEXER;
			goto ZL1;
		    }
		}
		break;
	      default:
		{
		    /* BEGINNING OF ACTION: init-tuple */
		    {
#line 879 "syntax.act"

	typetuple_init(&(ZIit));
#line 2479 "tmp.syntax.c"
		    }
		    /* END OF ACTION: init-tuple */
		    /* BEGINNING OF ACTION: init-tuple */
		    {
#line 879 "syntax.act"

	typetuple_init(&(ZIot));
#line 2487 "tmp.syntax.c"
		    }
		    /* END OF ACTION: init-tuple */
		}
		break;
	    }
	}
	/* END OF INLINE: 159 */
	/* BEGINNING OF ACTION: make-action */
	{
#line 855 "syntax.act"

	NStringT str;
	nstring_copy_cstring(&str, (ZIi));
	EntryT* entry;
	if(entry=table_get_entry((ZIz)->top_level->table, &str)) {
		nstring_destroy(&str);
		/* TODO switch ? */
	   	if(entry_is_action(entry))
			error(ERROR_SERIOUS, "Action %s already exists",(ZIi));
		else if(entry_is_localname(entry))
			error(ERROR_SERIOUS, "Can't create type %s, %s has been previously used as a local name. We do not allow retroactive hiding.",(ZIi),(ZIi));
		else if(entry_is_type(entry))
			error(ERROR_SERIOUS, "Can't create action %s, %s has already been declared as a type",(ZIi), (ZIi));
		else
			; /* TODO assert(0): we should never reach that place*/
	} else {
		table_add_action((ZIz)->top_level->table, &str , (&ZIit), (&ZIot));
	}
	xfree((ZIi));
#line 2517 "tmp.syntax.c"
	}
	/* END OF ACTION: make-action */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRinstruction(zoneP ZIz, instructionP *ZOinst)
{
    instructionP ZIinst;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	args_listP ZIl;

	/* BEGINNING OF ACTION: empty-args-list */
	{
#line 457 "syntax.act"

    (ZIl)=add_args_list();
#line 2543 "tmp.syntax.c"
	}
	/* END OF ACTION: empty-args-list */
	ZR236 (&ZIz, &ZIl, &ZIinst);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOinst = ZIinst;
}

static void
ZR207(zoneP *ZIz, SID_CHARS *ZOe)
{
    SID_CHARS ZIe;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	ZRnon_Hempty_Hchars (*ZIz, &ZIe);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    {
	/* BEGINNING OF ACTION: E_expected_chars */
	{
#line 947 "syntax.act"

        (ZIe) = NULL ;
	error(ERROR_SERIOUS, "Syntax error: expected characters");
#line 2584 "tmp.syntax.c"
	}
	/* END OF ACTION: E_expected_chars */
    }
  ZL0:;
    *ZOe = ZIe;
}

static void
ZRcommand_Hlist(zoneP ZIz)
{
  ZL2_command_Hlist:;
    switch (CURRENT_TERMINAL) {
      case 6: case 7: case 8: case 9:
      case 10: case 13: case 16: case 22:
      case 38: case 41:
	{
	    ZRcommand (ZIz);
	    /* BEGINNING OF INLINE: command-list */
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    } else {
		goto ZL2_command_Hlist;
	    }
	    /* END OF INLINE: command-list */
	}
	/*UNREACHED*/
      case 42:
	return;
      default:
	break;
    }
    return;
  ZL1:;
    {
	/* BEGINNING OF ACTION: syntax-error */
	{
#line 978 "syntax.act"

	error ( ERROR_SERIOUS, "Syntax error" ) ;
#line 2625 "tmp.syntax.c"
	}
	/* END OF ACTION: syntax-error */
    }
}

static void
ZR209(zoneP *ZIz, instructions_listP *ZOleaving_Hinstl)
{
    instructions_listP ZIleaving_Hinstl;

    switch (CURRENT_TERMINAL) {
      case 18:
	{
	    ADVANCE_LEXER;
	    ZRinstructions_Hlist (*ZIz, &ZIleaving_Hinstl);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      default:
	{
	    /* BEGINNING OF ACTION: empty-inst-list */
	    {
#line 675 "syntax.act"

    (ZIleaving_Hinstl)=add_instructions_list();
#line 2654 "tmp.syntax.c"
	    }
	    /* END OF ACTION: empty-inst-list */
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOleaving_Hinstl = ZIleaving_Hinstl;
}

static void
ZRkeyword_Hdefn(zoneP ZIz)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIs;
	instructionP ZIinst;

	switch (CURRENT_TERMINAL) {
	  case 8:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	switch (CURRENT_TERMINAL) {
	  case 2:
	    /* BEGINNING OF EXTRACT: string */
	    {
#line 247 "syntax.act"

    ZIs = xstrcpy ( token_buff ) ;
#line 2694 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: string */
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	switch (CURRENT_TERMINAL) {
	  case 18:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	ZRinstruction (ZIz, &ZIinst);
	/* BEGINNING OF INLINE: 195 */
	{
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		/* BEGINNING OF ACTION: is-global-zone */
		{
#line 817 "syntax.act"

   (ZI0)=((ZIz)==(ZIz)->top_level->global_zone);
#line 2722 "tmp.syntax.c"
		}
		/* END OF ACTION: is-global-zone */
		if (!ZI0)
		    goto ZL3;
		/* BEGINNING OF ACTION: make-keyword */
		{
#line 717 "syntax.act"

    switch((ZIinst)->type) {
    case terminal_apply_function:
    case pure_apply_function:
      if((ZIinst)->u.fun->args->head!=NULL) {
        error(ERROR_SERIOUS, "Syntax error: for keywords using "
	"user defined functions, "
	"the arglist must remain empty");
        break;
      }
    case return_terminal: 
    /* Fallback is intentional */
      add_keyword ( (ZIz), (ZIs), (ZIinst) ) ;
    break;
    default:
      error(ERROR_SERIOUS, "Syntax error: only a function or a token might be returned for a keyword");
  }
#line 2747 "tmp.syntax.c"
		}
		/* END OF ACTION: make-keyword */
	    }
	    goto ZL2;
	  ZL3:;
	    {
		/* BEGINNING OF ACTION: E_nonglobalzonekeyword */
		{
#line 911 "syntax.act"

    error( ERROR_SERIOUS, "Keywords not yet implemented in a non global zone ") ;

#line 2760 "tmp.syntax.c"
		}
		/* END OF ACTION: E_nonglobalzonekeyword */
	    }
	  ZL2:;
	}
	/* END OF INLINE: 195 */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRcopyright_Hstmt(zoneP ZIz)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	SID_STRING ZIs;

	switch (CURRENT_TERMINAL) {
	  case 6:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	switch (CURRENT_TERMINAL) {
	  case 20:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	switch (CURRENT_TERMINAL) {
	  case 2:
	    /* BEGINNING OF EXTRACT: string */
	    {
#line 247 "syntax.act"

    ZIs = xstrcpy ( token_buff ) ;
#line 2804 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: string */
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	/* BEGINNING OF INLINE: 129 */
	{
	    {
		/* BEGINNING OF ACTION: is-global-zone */
		{
#line 817 "syntax.act"

   (ZI0)=((ZIz)==(ZIz)->top_level->global_zone);
#line 2820 "tmp.syntax.c"
		}
		/* END OF ACTION: is-global-zone */
		if (!ZI0)
		    goto ZL3;
		/* BEGINNING OF ACTION: make-copyright */
		{
#line 823 "syntax.act"

	/* TODO can copyright_file be passed in somehow, other than with options as a global? */
	if(options.copyright_file==NULL) {
		options.copyright_file=fopen((ZIs),"r");
		if(!options.copyright_file) {
			error(ERROR_SERIOUS, "Syntax error: unable to open copright file %s", (ZIs)) ;
		}
	}
	else 
		error(ERROR_SERIOUS, "Syntax error: you can only specify one copyright file") ;
#line 2838 "tmp.syntax.c"
		}
		/* END OF ACTION: make-copyright */
	    }
	    goto ZL2;
	  ZL3:;
	    {
		/* BEGINNING OF ACTION: E_nonglobalzonecopyright */
		{
#line 915 "syntax.act"

    error( ERROR_SERIOUS, "Syntax error: A copyright file may only be specified in the global zone") ;
#line 2850 "tmp.syntax.c"
		}
		/* END OF ACTION: E_nonglobalzonecopyright */
	    }
	  ZL2:;
	}
	/* END OF INLINE: 129 */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRcommand(zoneP ZIz)
{
    switch (CURRENT_TERMINAL) {
      case 7:
	{
	    ADVANCE_LEXER;
	    ZR233 (&ZIz);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 16:
	{
	    ADVANCE_LEXER;
	    ZRcommand_Hlist (ZIz);
	    switch (CURRENT_TERMINAL) {
	      case 17:
		break;
	      case 42:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	}
	break;
      case 22:
	{
	    ADVANCE_LEXER;
	}
	break;
      case 10:
	{
	    ADVANCE_LEXER;
	    ZR234 (&ZIz);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 38:
	{
	    ZRaction_Hdecl (ZIz);
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 6:
	{
	    ZRcopyright_Hstmt (ZIz);
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 8:
	{
	    ZRkeyword_Hdefn (ZIz);
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 9:
	{
	    ZRtrigraph_Hdefn (ZIz);
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 41:
	{
	    ZRtype_Hdefn (ZIz);
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 13:
	{
	    ZRzone_Hdefn (ZIz);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 42:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZRnon_Hempty_Htuple_Hargs(args_listP *ZOl)
{
    args_listP ZIl;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	argP ZIa;

	ZRsingle_Harg (&ZIa);
	ZR279 (&ZIa, &ZIl);
	if ((CURRENT_TERMINAL) == 42) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOl = ZIl;
}

static void
ZR231(zoneP ZI225, instructions_listP ZI228, zoneP *ZO229, instructions_listP *ZO230)
{
    zoneP ZI229;
    instructions_listP ZI230;

  ZL2_231:;
    switch (CURRENT_TERMINAL) {
      case 28:
	{
	    instructions_listP ZIinstl;
	    instructionP ZIinst;

	    ZIinstl = ZI228;
	    ADVANCE_LEXER;
	    ZRinstruction (ZI225, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: add-inst-to-list */
	    {
#line 471 "syntax.act"

	if((ZIinst)!=NULL) { /* if (ZIinst) == NULL, an error has already been issued.*/
		LocalNamesT* locals = instructionslist_localnames((ZIinstl));
/*		if(((ZIinstl)->head !=NULL) && ((ZIinst)->type==return_terminal || (ZIinst)->type==do_nothing)) {
			error(ERROR_SERIOUS, "A $sid-identifier or a $$ can only appear at the end of an instruction-list"); Does not work anymore since we append and do not prepend anymore. No pb as this will be unecessary due to the upcoming removal of direct function calls.
		}*/
		if((ZIinstl)->nb_return_terminal>0 && (ZIinst)->type!=do_nothing)
			error(ERROR_SERIOUS, "No instruction may follow an instruction that returns a terminal");
		if((ZIinst)->type == return_terminal) {
			++((ZIinstl)->nb_return_terminal);
		}
		if((ZIinst)->type == terminal_apply_function) {
			++((ZIinstl)->nb_return_terminal);
		}
		if((ZIinst)->type == action_call) {
			(ZIinstl)->nb_return_terminal+=(ZIinst)->u.act.lhs->nb_return_terminal;
			if((ZIinstl)->nb_return_terminal>1)
				error(ERROR_SERIOUS, "Only one terminal may be returned per token");
			EntryT* entryaction = (ZIinst)->u.act.called_act;
			ActionT* action = entry_get_action(entryaction);
			args_list* rhs = (ZIinst)->u.act.rhs;
			args_list* lhs = (ZIinst)->u.act.lhs;

			arg* p;
			TypeTupleEntryT* q;

			/* CHECKING RHS COMPATIBILITY */ 
			for ( p = rhs->head, q = action->inputs.head; p!=NULL && q!=NULL; p=p->next, q=q->next) {
			      	EntryT* entrytype = NULL;
				NStringT str;
			      	switch (p->type) {
				case arg_identifier: 
				     	nstring_copy_cstring(&str, p->u.litteral);
					entrytype=localnames_get_type(locals, &str);
					nstring_destroy(&str);
					if(!entrytype) {
						EntryT* tableentry = table_get_entry((ZI225)->top_level->table, &str);
						if(!tableentry) {
							error(ERROR_SERIOUS, "local name %s has not been defined yet", p->u.litteral);
							entrytype = NULL;
						} else if (entry_is_localname(tableentry)) {
							error(ERROR_SERIOUS, "local name %s has been defined but not in this scope", p->u.litteral);
							entrytype = NULL;
						} else if (entry_is_action(tableentry)) {
							error(ERROR_SERIOUS, "%s is not a local name but an action which is not allowed", p->u.litteral);
							entrytype = NULL;
						} else if (entry_is_type(tableentry)) {
							error(ERROR_SERIOUS, "%s is not a local name but a type which is not allowed", p->u.litteral);
							entrytype = NULL;
						} else {
							; /* TODO assert(0) this should be unreachable*/
						}
					}
					break;
				case arg_charP:
					/* TODO assert(lexer_string_type(top_level)) */
					entrytype = lexer_string_type((ZI225)->top_level);
		 			break;
				case arg_char_nb:
					/* TODO assert(lexer_char_type(top_level)) */
					entrytype = lexer_char_type((ZI225)->top_level);
			 		break;
				case arg_terminal:
					/* TODO assert(lexer_terminal_type(top_level)) */
					entrytype = lexer_terminal_type((ZI225)->top_level);
					break;
				case arg_nb_of_chars:
					/* TODO assert(lexer_terminal_type(top_level)) */
					entrytype = lexer_int_type((ZI225)->top_level);
		 			break;
				case arg_none:
					break; //Error already detected, do nothing and leave p->lexitype = NULL
				case arg_litteral:
				case arg_chars_list:
				case arg_ignore:
				case arg_return_terminal:
					/* TODO assert(0): we should never reach this place */
				break;
			default:
				break;
				/* TODO assert(0): we should never reach this place either, doubly so*/
			}
			if(entrytype) {
				if( q->type!=entrytype || p->is_reference!=q->is_reference) {
						char* s1 = nstring_to_cstring(entry_key(entryaction));
						char* s2 = nstring_to_cstring(entry_key(entrytype));
						char* s3 = p->is_reference ? "&" : "";
						char* s4 = nstring_to_cstring(entry_key(q->type));
						char* s5 = q->is_reference ? "&" : "";
						error(ERROR_SERIOUS, "In call to action %s, argument \'%s\' has type \'%s%s\' when it should have type %s", s1, p->u.litteral, s2, s3, s4, s5);
						DEALLOCATE(s1);
						DEALLOCATE(s2);
						DEALLOCATE(s4);
					}
				}
			}
			if(p!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, too many arguments", s);
				DEALLOCATE(s);
			}
			if(q!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, not enough arguments", s);
				DEALLOCATE(s);
			}

			for ( p = lhs->head, q = action->outputs.head; p!=NULL && q!=NULL; p=p->next, q=q->next) {
			      	EntryT* entrytype;
				switch (p->type) {
				case arg_identifier: 
					{
						NStringT str;
						EntryT* entry; 
						nstring_copy_cstring(&str, p->u.litteral);
						entrytype = localnames_get_type(locals, &str);
						if(!entrytype) {
							EntryT* entry = table_get_entry((ZI225)->top_level->table, &str);
							localnames_add_nstring(locals, &str, q->type);
							if(entry) {
								nstring_destroy(&str);
								if (entry_is_action(entry)) {
									error(ERROR_SERIOUS, "In action lhs. Name %s is an action. Hiding globals by local names is not allowed", p->u.litteral);
								} else if (entry_is_type(entry)) {
									error(ERROR_SERIOUS, "In action lhs. Name %s is a type. Hiding globals by local names is not allowed", p->u.litteral);									
								}
							} else {
								table_add_local_name((ZI225)->top_level->table, &str);
							}
							if(p->is_reference) {
								char* s = nstring_to_cstring(entry_key(entryaction));
								error(ERROR_SERIOUS, "In action call %s, you can only use references %s for preexisting variables", s, p->u.litteral);
								DEALLOCATE(s);
							} 
						} else {
							nstring_destroy(&str);
							if(!p->is_reference) {
								char* s = nstring_to_cstring(entry_key(entryaction));
								error(ERROR_SERIOUS, "In action call %s, name %s already declared. Use references to change the value of an already existing variable", s, p->u.litteral);
								entrytype=q->type; /* To avoid outputting that error more than once*/
								DEALLOCATE(s);
							}
						}
					}
					break;
				case arg_return_terminal:
					entrytype = lexer_terminal_type((ZI225)->top_level);
					q->is_reference = false;
					/* TODO assert(q->is_reference == false) */
					break;
				case arg_ignore:
					/*always acceptable */
					entrytype=q->type;
					p->is_reference=q->is_reference;
					break;
				case arg_none:
					break;
					/* TODO asserting errored is already set */
					/* Error has already been detected */
				case arg_charP:
				case arg_char_nb:
				case arg_chars_list:
				case arg_terminal:
				case arg_nb_of_chars:
					break; /* UNREACHABLE */
				default:
					break; /* UNREACHABLE */
				}
				if(p->is_reference != q->is_reference) {
					/* XXX: state which action */
					if(p->is_reference)
						error(ERROR_SERIOUS, "In call to action, %s should not be a reference", p->u.litteral);
					else
						error(ERROR_SERIOUS, "In call to action, %s should not be a reference", p->u.litteral);
				}
			}
			if(p!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, too many results", s);
				DEALLOCATE(s);
			}
			if(q!=NULL) {
				char* s = nstring_to_cstring(entry_key(entryaction));
				error(ERROR_SERIOUS, "In call to action %s, not enough results", s);
				DEALLOCATE(s);
			}
		}
		/* TODO only append if no error */
		*(ZIinstl)->tail=(ZIinst);
		(ZIinstl)->tail=&(ZIinst)->next;
		++((ZIinstl)->size);
	}
#line 3220 "tmp.syntax.c"
	    }
	    /* END OF ACTION: add-inst-to-list */
	    /* BEGINNING OF INLINE: 231 */
	    ZI228 = ZIinstl;
	    goto ZL2_231;
	    /* END OF INLINE: 231 */
	}
	/*UNREACHED*/
      default:
	{
	    ZI229 = ZI225;
	    ZI230 = ZI228;
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZO229 = ZI229;
    *ZO230 = ZI230;
}

static void
ZRtype_Htuple_C_Ctype_Htuple1(zoneP ZIz, TypeTupleT *ZIa)
{
    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
  ZL2_type_Htuple_C_Ctype_Htuple1:;
    {
	ZRtype_Htuple_C_Ctype_Hname (ZIz, ZIa);
	/* BEGINNING OF INLINE: 284 */
	{
	    switch (CURRENT_TERMINAL) {
	      case 28:
		{
		    ADVANCE_LEXER;
		    /* BEGINNING OF INLINE: type-tuple::type-tuple1 */
		    goto ZL2_type_Htuple_C_Ctype_Htuple1;
		    /* END OF INLINE: type-tuple::type-tuple1 */
		}
		/*UNREACHED*/
	      case 42:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		break;
	    }
	}
	/* END OF INLINE: 284 */
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZR233(zoneP *ZIz)
{
    switch (CURRENT_TERMINAL) {
      case 0:
	{
	    SID_STRING ZIi;
	    SID_CHARS ZIs;

	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 3296 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    ADVANCE_LEXER;
	    ZR134 ();
	    ZRchars (*ZIz, &ZIs);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: make-group */
	    {
#line 346 "syntax.act"

    make_group ( (*ZIz), (ZIi), (ZIs) ) ;
#line 3311 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-group */
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 11:
	{
	    SID_CHARS ZIs;

	    ADVANCE_LEXER;
	    ZR134 ();
	    ZRchars (*ZIz, &ZIs);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: make-white */
	    {
#line 332 "syntax.act"

    if ( (*ZIz)->white_space) {
	error ( ERROR_SERIOUS, "White space group already defined" ) ;
    }
    (*ZIz)->white_space= make_group((*ZIz),"white",(ZIs)) ;
#line 3340 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-white */
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 42:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZR234(zoneP *ZIz)
{
    switch (CURRENT_TERMINAL) {
      case 12:
	{
	    instructions_listP ZIinst_Hlist;

	    ADVANCE_LEXER;
	    switch (CURRENT_TERMINAL) {
	      case 18:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZRinstructions_Hlist (*ZIz, &ZIinst_Hlist);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: make-default */
	    {
#line 705 "syntax.act"

    (*ZIz)->default_instructions=(ZIinst_Hlist);
#line 3387 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-default */
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 2: case 3: case 4: case 5:
	{
	    SID_CHARS ZIs;
	    instructions_listP ZIinst_Hlist;

	    ZRnon_Hempty_Hchars (*ZIz, &ZIs);
	    switch (CURRENT_TERMINAL) {
	      case 18:
		break;
	      case 42:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZRinstructions_Hlist (*ZIz, &ZIinst_Hlist);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: check-inst-list */
	    {
#line 665 "syntax.act"

	if((ZIinst_Hlist)->nb_return_terminal>1)
		error(ERROR_SERIOUS, "At most one return terminal may be specified per instruction list");
#line 3424 "tmp.syntax.c"
	    }
	    /* END OF ACTION: check-inst-list */
	    /* BEGINNING OF ACTION: make-token */
	    {
#line 686 "syntax.act"

        add_char ( (*ZIz), (*ZIz)->zone_main_pass, (ZIs), (ZIinst_Hlist), NULL) ;
	if((ZIinst_Hlist)->nb_return_terminal)
		(*ZIz)->type=typezone_general_zone;
#line 3434 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-token */
	    ZRexpected__semicolon ();
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 42:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (42);
    return;
}

static void
ZR236(zoneP *ZIz, args_listP *ZIl, instructionP *ZOinst)
{
    instructionP ZIinst;

    switch (CURRENT_TERMINAL) {
      case 31:
	{
	    argP ZI251;
	    argP ZI252;

	    /* BEGINNING OF EXTRACT: arg-char-list */
	    {
#line 265 "syntax.act"

      ZI251=add_arg(arg_chars_list,0);
#line 3471 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-list */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZI252) = add_none_arg();
#line 3480 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
	    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 3488 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_sharp_arg_in_lhs */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI252);
    (*ZIl)->tail=&(ZI252)->next;
    if((ZI252)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 3499 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 33:
	{
	    argP ZI257;
	    argP ZI258;

	    /* BEGINNING OF EXTRACT: arg-char-nb */
	    {
#line 273 "syntax.act"

      ZI257=add_arg(arg_char_nb,number_buffer);
#line 3526 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-nb */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZI258) = add_none_arg();
#line 3535 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
	    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 3543 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_sharp_arg_in_lhs */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI258);
    (*ZIl)->tail=&(ZI258)->next;
    if((ZI258)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 3554 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 32:
	{
	    argP ZI254;
	    argP ZI255;

	    /* BEGINNING OF EXTRACT: arg-char-string */
	    {
#line 269 "syntax.act"

      ZI254=add_arg(arg_charP,0);
#line 3581 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-string */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZI255) = add_none_arg();
#line 3590 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
	    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 3598 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_sharp_arg_in_lhs */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI255);
    (*ZIl)->tail=&(ZI255)->next;
    if((ZI255)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 3609 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 36:
	{
	    argP ZI274;

	    /* BEGINNING OF EXTRACT: arg-ignore */
	    {
#line 285 "syntax.act"

      ZI274=add_arg(arg_ignore,0);
#line 3635 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-ignore */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI274);
    (*ZIl)->tail=&(ZI274)->next;
    if((ZI274)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 3647 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 34:
	{
	    argP ZI260;
	    argP ZI261;

	    /* BEGINNING OF EXTRACT: arg-nb-of-chars */
	    {
#line 277 "syntax.act"

      ZI260=add_arg(arg_nb_of_chars,0);
#line 3674 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-nb-of-chars */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZI261) = add_none_arg();
#line 3683 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_sharp_arg_in_lhs */
	    {
#line 982 "syntax.act"

	error(ERROR_SERIOUS, "Argument of style # are rvalues and should not appear on a left handside");
#line 3691 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_sharp_arg_in_lhs */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI261);
    (*ZIl)->tail=&(ZI261)->next;
    if((ZI261)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 3702 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 35:
	{
	    argP ZI272;

	    /* BEGINNING OF EXTRACT: arg-return-terminal */
	    {
#line 281 "syntax.act"

      ZI272=add_arg(arg_return_terminal,0);
#line 3728 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-return-terminal */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI272);
    (*ZIl)->tail=&(ZI272)->next;
    if((ZI272)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 3740 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 39:
	{
	    SID_STRING ZIi;
	    args_listP ZIr;

	    ADVANCE_LEXER;
	    switch (CURRENT_TERMINAL) {
	      case 0:
		/* BEGINNING OF EXTRACT: identifier */
		{
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 3770 "tmp.syntax.c"
		}
		/* END OF EXTRACT: identifier */
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: check-args-list */
	    {
#line 437 "syntax.act"

    if((*ZIl)->nb_return_terminal>1)
	error(ERROR_SERIOUS, "There can only be one return terminal argument per action lhs");
#line 3784 "tmp.syntax.c"
	    }
	    /* END OF ACTION: check-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 40:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR187 (&ZIr);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: make-action-inst */
	    {
#line 383 "syntax.act"

	NStringT key;
	nstring_copy_cstring(&key, (ZIi));
	EntryT* entry = table_get_entry((*ZIz)->top_level->table, &key);
	if(entry) {
		if(entry_is_action(entry)) {
			/* TODO: Inefficient code follows: */
			/* Checking that a name does not appear twice in an lhs*/
			arg* p, *q;
			for(p=(*ZIl)->head;p!=NULL;p=p->next) {
				if(p->type==arg_identifier) {
					for(q=p->next; q!=NULL;q=q->next) {
						if(q->type==arg_identifier && !strcmp(p->u.litteral, q->u.litteral)) {
							char* s = nstring_to_cstring(entry_key(entry));
							error(ERROR_SERIOUS, "In call to action %s, the left hand side contain multiple reference to %s",s, p->u.litteral);
							break;		   
						}
					}
				}
			}
			(ZIinst)=add_instruction_action(entry,(*ZIl),(ZIr));
		 /* END Inefficient code*/
		} else {
			(ZIinst)=NULL;
			error(ERROR_SERIOUS, "Name %s is not an action", (ZIi));
		}
	} else {
		(ZIinst)=NULL;
		error(ERROR_SERIOUS, "Unknown action %s", (ZIi));
	}
	xfree((ZIi));
#line 3833 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-action-inst */
	}
	break;
      case 0:
	{
	    SID_STRING ZI248;

	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZI248 = xstrcpy ( token_buff ) ;
#line 3847 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    ADVANCE_LEXER;
	    ZR249 (ZIz, ZIl, &ZI248, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 29:
	{
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make-donothing-inst */
	    {
#line 378 "syntax.act"

	(ZIinst)=add_instruction_donothing();
#line 3866 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-donothing-inst */
	}
	break;
      case 14:
	{
	    ADVANCE_LEXER;
	    ZRfunction_Haction_Hcall_C_Clhs_Htuple1 (*ZIl);
	    switch (CURRENT_TERMINAL) {
	      case 15:
		break;
	      case 42:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 24:
	{
	    SID_STRING ZI266;
	    argP ZI267;

	    ADVANCE_LEXER;
	    switch (CURRENT_TERMINAL) {
	      case 0:
		/* BEGINNING OF EXTRACT: identifier */
		{
#line 202 "syntax.act"

    ZI266 = xstrcpy ( token_buff ) ;
#line 3912 "tmp.syntax.c"
		}
		/* END OF EXTRACT: identifier */
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_from_reference */
	    {
#line 799 "syntax.act"

	(ZI267) = add_reference_arg ((ZI266));
#line 3925 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_from_reference */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI267);
    (*ZIl)->tail=&(ZI267)->next;
    if((ZI267)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 3936 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 1:
	{
	    SID_STRING ZI276;

	    /* BEGINNING OF EXTRACT: sid-identifier */
	    {
#line 235 "syntax.act"

    int n ;
    char *s ;
    char buff [1000] ;
    strcpy ( buff, token_prefix ) ;
    n = ( int ) strlen ( buff ) ;
    for ( s = token_buff ; *s ; s++ ) {
	if ( *s == '-' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = 'H' ;
	} else if ( *s == '_' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = '_' ;
	} else {
	    buff [ n++ ] = *s ;
	}
	if ( n >= 900 ) {
	    error ( ERROR_SERIOUS, "Identifier too long" ) ;
	    break ;
	}
    }
    buff [n] = 0 ;
    ZI276 = xstrcpy ( buff ) ;
#line 3983 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: sid-identifier */
	    ADVANCE_LEXER;
	    ZR277 (ZIz, ZIl, &ZI276, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 2:
	{
	    SID_STRING ZI263;
	    argP ZI264;

	    /* BEGINNING OF EXTRACT: string */
	    {
#line 247 "syntax.act"

    ZI263 = xstrcpy ( token_buff ) ;
#line 4004 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: string */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZI264) = add_none_arg();
#line 4013 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_string_arg_in_lhs */
	    {
#line 986 "syntax.act"

	error(ERROR_SERIOUS, "Argument of type "" are rvalues and should not appear on a left handside");
#line 4021 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_string_arg_in_lhs */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI264);
    (*ZIl)->tail=&(ZI264)->next;
    if((ZI264)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 4032 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 20:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 42:
	return;
      default:
	goto ZL1;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOinst = ZIinst;
}

static void
ZRnon_Hempty_Hchars(zoneP ZIz, SID_CHARS *ZOc)
{
    SID_CHARS ZIc;

    if ((CURRENT_TERMINAL) == 42) {
	return;
    }
    {
	ZRchars (ZIz, &ZIc);
	/* BEGINNING OF INLINE: 127 */
	{
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		/* BEGINNING OF ACTION: is-non-empty */
		{
#line 692 "syntax.act"

    (ZI0)=((ZIc)[0]!=(ZIz)->top_level->last_letter_code);
#line 4084 "tmp.syntax.c"
		}
		/* END OF ACTION: is-non-empty */
		if (!ZI0)
		    goto ZL3;
	    }
	    goto ZL2;
	  ZL3:;
	    {
		/* BEGINNING OF ACTION: E_empty_character_string */
		{
#line 697 "syntax.act"

        error(ERROR_SERIOUS, "Empty character string is not allowed here, try using DEFAULT instead");	
#line 4098 "tmp.syntax.c"
		}
		/* END OF ACTION: E_empty_character_string */
	    }
	  ZL2:;
	}
	/* END OF INLINE: 127 */
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOc = ZIc;
}

static void
ZRsingle_Harg(argP *ZOa)
{
    argP ZIa;

    switch (CURRENT_TERMINAL) {
      case 31:
	{
	    /* BEGINNING OF EXTRACT: arg-char-list */
	    {
#line 265 "syntax.act"

      ZIa=add_arg(arg_chars_list,0);
#line 4127 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-list */
	    ADVANCE_LEXER;
	}
	break;
      case 33:
	{
	    /* BEGINNING OF EXTRACT: arg-char-nb */
	    {
#line 273 "syntax.act"

      ZIa=add_arg(arg_char_nb,number_buffer);
#line 4140 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-nb */
	    ADVANCE_LEXER;
	}
	break;
      case 32:
	{
	    /* BEGINNING OF EXTRACT: arg-char-string */
	    {
#line 269 "syntax.act"

      ZIa=add_arg(arg_charP,0);
#line 4153 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-char-string */
	    ADVANCE_LEXER;
	}
	break;
      case 36:
	{
	    /* BEGINNING OF EXTRACT: arg-ignore */
	    {
#line 285 "syntax.act"

      ZIa=add_arg(arg_ignore,0);
#line 4166 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-ignore */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: E_ignore_in_rhs */
	    {
#line 1014 "syntax.act"

	error(ERROR_SERIOUS, "Ignore argument in right handside");
#line 4175 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_ignore_in_rhs */
	}
	break;
      case 34:
	{
	    /* BEGINNING OF EXTRACT: arg-nb-of-chars */
	    {
#line 277 "syntax.act"

      ZIa=add_arg(arg_nb_of_chars,0);
#line 4187 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-nb-of-chars */
	    ADVANCE_LEXER;
	}
	break;
      case 35:
	{
	    argP ZIb;

	    /* BEGINNING OF EXTRACT: arg-return-terminal */
	    {
#line 281 "syntax.act"

      ZIb=add_arg(arg_return_terminal,0);
#line 4202 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: arg-return-terminal */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 4211 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_return_terminal_in_rhs */
	    {
#line 990 "syntax.act"

	error(ERROR_SERIOUS, "Return terminal argument in right handside");
#line 4219 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_return_terminal_in_rhs */
	}
	break;
      case 0:
	{
	    SID_STRING ZIi;

	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 4233 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 4242 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_localname_in_function_rhs */
	    {
#line 1003 "syntax.act"

	error(ERROR_SERIOUS, "Local names in function rhs not implemented yet ");
#line 4250 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_localname_in_function_rhs */
	}
	break;
      case 24:
	{
	    SID_STRING ZIi;

	    ADVANCE_LEXER;
	    switch (CURRENT_TERMINAL) {
	      case 0:
		/* BEGINNING OF EXTRACT: identifier */
		{
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 4267 "tmp.syntax.c"
		}
		/* END OF EXTRACT: identifier */
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_from_reference */
	    {
#line 799 "syntax.act"

	(ZIa) = add_reference_arg ((ZIi));
#line 4280 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_from_reference */
	}
	break;
      case 1:
	{
	    SID_STRING ZIb;

	    /* BEGINNING OF EXTRACT: sid-identifier */
	    {
#line 235 "syntax.act"

    int n ;
    char *s ;
    char buff [1000] ;
    strcpy ( buff, token_prefix ) ;
    n = ( int ) strlen ( buff ) ;
    for ( s = token_buff ; *s ; s++ ) {
	if ( *s == '-' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = 'H' ;
	} else if ( *s == '_' ) {
	    buff [ n++ ] = '_' ;
	    buff [ n++ ] = '_' ;
	} else {
	    buff [ n++ ] = *s ;
	}
	if ( n >= 900 ) {
	    error ( ERROR_SERIOUS, "Identifier too long" ) ;
	    break ;
	}
    }
    buff [n] = 0 ;
    ZIb = xstrcpy ( buff ) ;
#line 4315 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: sid-identifier */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_none */
	    {
#line 808 "syntax.act"

	(ZIa) = add_none_arg();
#line 4324 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_none */
	    /* BEGINNING OF ACTION: E_terminal_in_function_rhs */
	    {
#line 999 "syntax.act"

	error(ERROR_SERIOUS, "Terminals in function rhs not implemented yet ");
#line 4332 "tmp.syntax.c"
	    }
	    /* END OF ACTION: E_terminal_in_function_rhs */
	}
	break;
      case 2:
	{
	    SID_STRING ZIb;

	    /* BEGINNING OF EXTRACT: string */
	    {
#line 247 "syntax.act"

    ZIb = xstrcpy ( token_buff ) ;
#line 4346 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: string */
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: make_arg_from_string */
	    {
#line 791 "syntax.act"

	(ZIa) = add_litteral_arg ((ZIb));
#line 4355 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_from_string */
	}
	break;
      case 42:
	return;
      default:
	goto ZL1;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOa = ZIa;
}

static void
ZR249(zoneP *ZIz, args_listP *ZIl, SID_STRING *ZI248, instructionP *ZOinst)
{
    instructionP ZIinst;

    switch (CURRENT_TERMINAL) {
      default:
	{
	    args_listP ZIa;
	    int ZIb;

	    ZRargs (&ZIa);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: check-lhs-args-function */
	    {
#line 442 "syntax.act"

	if((*ZIl)->head==NULL)
		(ZIb)=false;
	else {
		(ZIb)=true;
		if((*ZIl)->head->next!=NULL || (*ZIl)->head->type != arg_return_terminal)
			error(ERROR_SERIOUS,"For direct function calls, at most one return value, of type TERMINAL '$=', may be specified");
	}
	
#line 4401 "tmp.syntax.c"
	    }
	    /* END OF ACTION: check-lhs-args-function */
	    /* BEGINNING OF ACTION: make-inst */
	    {
#line 366 "syntax.act"

    if((ZIa)) {
    	if((ZIb))
	    (ZIinst)=add_instruction_terminalfunction((*ZI248),(ZIa));
	else
	    (ZIinst)=add_instruction_purefunction((*ZI248),(ZIa));
    } 
    else {
        (ZIinst)=add_instruction_return_terminal((*ZI248));
    }
#line 4417 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-inst */
	}
	break;
      case 20:
	{
	    argP ZI280;

	    /* BEGINNING OF ACTION: make_arg_from_identifier */
	    {
#line 795 "syntax.act"

	(ZI280) = add_identifier_arg ((*ZI248));
#line 4431 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make_arg_from_identifier */
	    /* BEGINNING OF ACTION: append-arg-args-list */
	    {
#line 423 "syntax.act"

    *(*ZIl)->tail=(ZI280);
    (*ZIl)->tail=&(ZI280)->next;
    if((ZI280)->type==arg_return_terminal)
	(*ZIl)->nb_return_terminal++;
#line 4442 "tmp.syntax.c"
	    }
	    /* END OF ACTION: append-arg-args-list */
	    ADVANCE_LEXER;
	    ZR253 (ZIz, ZIl, &ZIinst);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 42:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOinst = ZIinst;
}

static void
ZR253(zoneP *ZIz, args_listP *ZIl, instructionP *ZOinst)
{
    instructionP ZIinst;

    switch (CURRENT_TERMINAL) {
      case 39:
	{
	    SID_STRING ZIi;
	    args_listP ZIr;

	    ADVANCE_LEXER;
	    switch (CURRENT_TERMINAL) {
	      case 0:
		/* BEGINNING OF EXTRACT: identifier */
		{
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 4483 "tmp.syntax.c"
		}
		/* END OF EXTRACT: identifier */
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    /* BEGINNING OF ACTION: check-args-list */
	    {
#line 437 "syntax.act"

    if((*ZIl)->nb_return_terminal>1)
	error(ERROR_SERIOUS, "There can only be one return terminal argument per action lhs");
#line 4497 "tmp.syntax.c"
	    }
	    /* END OF ACTION: check-args-list */
	    switch (CURRENT_TERMINAL) {
	      case 40:
		break;
	      default:
		goto ZL1;
	    }
	    ADVANCE_LEXER;
	    ZR187 (&ZIr);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: make-action-inst */
	    {
#line 383 "syntax.act"

	NStringT key;
	nstring_copy_cstring(&key, (ZIi));
	EntryT* entry = table_get_entry((*ZIz)->top_level->table, &key);
	if(entry) {
		if(entry_is_action(entry)) {
			/* TODO: Inefficient code follows: */
			/* Checking that a name does not appear twice in an lhs*/
			arg* p, *q;
			for(p=(*ZIl)->head;p!=NULL;p=p->next) {
				if(p->type==arg_identifier) {
					for(q=p->next; q!=NULL;q=q->next) {
						if(q->type==arg_identifier && !strcmp(p->u.litteral, q->u.litteral)) {
							char* s = nstring_to_cstring(entry_key(entry));
							error(ERROR_SERIOUS, "In call to action %s, the left hand side contain multiple reference to %s",s, p->u.litteral);
							break;		   
						}
					}
				}
			}
			(ZIinst)=add_instruction_action(entry,(*ZIl),(ZIr));
		 /* END Inefficient code*/
		} else {
			(ZIinst)=NULL;
			error(ERROR_SERIOUS, "Name %s is not an action", (ZIi));
		}
	} else {
		(ZIinst)=NULL;
		error(ERROR_SERIOUS, "Unknown action %s", (ZIi));
	}
	xfree((ZIi));
#line 4546 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-action-inst */
	}
	break;
      case 0:
	{
	    SID_STRING ZIi;
	    args_listP ZIa;
	    int ZIb;

	    /* BEGINNING OF EXTRACT: identifier */
	    {
#line 202 "syntax.act"

    ZIi = xstrcpy ( token_buff ) ;
#line 4562 "tmp.syntax.c"
	    }
	    /* END OF EXTRACT: identifier */
	    ADVANCE_LEXER;
	    ZRargs (&ZIa);
	    if ((CURRENT_TERMINAL) == 42) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    /* BEGINNING OF ACTION: check-lhs-args-function */
	    {
#line 442 "syntax.act"

	if((*ZIl)->head==NULL)
		(ZIb)=false;
	else {
		(ZIb)=true;
		if((*ZIl)->head->next!=NULL || (*ZIl)->head->type != arg_return_terminal)
			error(ERROR_SERIOUS,"For direct function calls, at most one return value, of type TERMINAL '$=', may be specified");
	}
	
#line 4583 "tmp.syntax.c"
	    }
	    /* END OF ACTION: check-lhs-args-function */
	    /* BEGINNING OF ACTION: make-inst */
	    {
#line 366 "syntax.act"

    if((ZIa)) {
    	if((ZIb))
	    (ZIinst)=add_instruction_terminalfunction((ZIi),(ZIa));
	else
	    (ZIinst)=add_instruction_purefunction((ZIi),(ZIa));
    } 
    else {
        (ZIinst)=add_instruction_return_terminal((ZIi));
    }
#line 4599 "tmp.syntax.c"
	    }
	    /* END OF ACTION: make-inst */
	}
	break;
      case 42:
	return;
      default:
	goto ZL1;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (42);
    return;
  ZL0:;
    *ZOinst = ZIinst;
}

/* BEGINNING OF TRAILER */

#line 1021 "syntax.act"

#line 4621 "tmp.syntax.c"

/* END OF FILE */
