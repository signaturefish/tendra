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
#include <stdarg.h>
#include <ctype.h>
#include "calculus.h"
#include "common.h"
#include "cstring.h"
#include "lex.h"
#include "msgcat.h"
#include "output.h"
#include "ostream.h"
#include "suffix.h"
#include "tenapp.h"
#include "type_ops.h"


/*
 *    FIND BINARY LOG OF A NUMBER
 *
 *    This routine calculates the binary log of n (i.e. the smallest number
 *    r such that n <= 2**r).
 */

number
log_2(number n)
{
    number r;
    number m;
    for (r = 0, m = 1; n > m && m; r++, m *= 2) /* empty */;
    return (r);
}


/*
 *    LOOP VARIABLES
 *
 *    These are the counter variables used in the LOOP macros defined in
 *    output.h.
 */

LIST (ECONST_P) crt_ec = NULL_list (ECONST_P);
LIST (ENUM_P) crt_en = NULL_list (ENUM_P);
LIST (IDENTITY_P) crt_id = NULL_list (IDENTITY_P);
LIST (PRIMITIVE_P) crt_prim = NULL_list (PRIMITIVE_P);
LIST (STRUCTURE_P) crt_str = NULL_list (STRUCTURE_P);
LIST (UNION_P) crt_union = NULL_list (UNION_P);
LIST (COMPONENT_P) crt_cmp = NULL_list (COMPONENT_P);
LIST (FIELD_P) crt_fld = NULL_list (FIELD_P);
LIST (MAP_P) crt_map = NULL_list (MAP_P);
LIST (ARGUMENT_P) crt_arg = NULL_list (ARGUMENT_P);
LIST (TYPE_P) crt_type = NULL_list (TYPE_P);
int unique = 0;


/*
 *    CURRENT OUTPUT FILE
 *
 *    This gives the file which is currently being used for output.
 */

OStreamT *output_file = NULL;
static OStreamT *output_file_old = NULL;
BoolT verbose_output = TRUE;
BoolT const_tokens = TRUE;
int have_varargs = 1;

#define	out	output_file

/*
 *    PRINT A CHARACTER
 *
 *    This routine prints the single character c.
 */

static void
output_char(int c)
{
    write_char(output_file, c);
    return;
}


/*
 *    PRINT A STRING
 *
 *    This routine prints the string s.
 */

static void
output_string(const char *s)
{
    write_cstring(output_file, s);
    return;
}


/*
 *    FLUSH OUTPUT FILE
 *
 *    This routine flushes the output file buffer by printing a newline
 *    character.
 */

void
flush_output(void)
{
    if (output_file)
	ostream_flush (output_file);
    return;
}


/*
 *    PRINT A TYPE
 *
 *    This routine prints the type t.
 */

void
output_type(TYPE_P t)
{
    TYPE t0 = DEREF_type (t);
    switch (TAG_type (t0)) {
	case type_vec_tag : {
	    TYPE_P_P s = type_vec_sub (t0);
	    output_string ("VEC (");
	    output_type (DEREF_ptr (s));
	    output_string (")");
	    break;
	}
	case type_ptr_tag : {
	    TYPE_P_P s = type_ptr_sub (t0);
	    output_string ("PTR (");
	    output_type (DEREF_ptr (s));
	    output_string (")");
	    break;
	}
	case type_list_tag : {
	    TYPE_P_P s = type_list_sub (t0);
	    output_string ("LIST (");
	    output_type (DEREF_ptr (s));
	    output_string (")");
	    break;
	}
	case type_stack_tag : {
	    TYPE_P_P s = type_stack_sub (t0);
	    output_string ("STACK (");
	    output_type (DEREF_ptr (s));
	    output_string (")");
	    break;
	}
	case type_vec_ptr_tag : {
	    TYPE_P_P s = type_vec_ptr_sub (t0);
	    output_string ("VEC_PTR (");
	    output_type (DEREF_ptr (s));
	    output_string (")");
	    break;
	}
	default : {
	    output_string (name_type (t));
	    break;
	}
    }
    return;
}


/*
 *    PRINT A TYPE IDENTIFIER
 *
 *    This routine prints an identifier derived from the type t.  depth
 *    determines the depth to which identities are to be expanded.
 */

static void
output_type_id(TYPE_P t, int depth)
{
    TYPE t0 = DEREF_type (t);
    switch (TAG_type (t0)) {
	case type_vec_tag : {
	    TYPE_P_P s = type_vec_sub (t0);
	    output_string ("vec_");
	    output_type_id (DEREF_ptr (s), depth);
	    break;
	}
	case type_ptr_tag : {
	    TYPE_P_P s = type_ptr_sub (t0);
	    output_string ("ptr_");
	    output_type_id (DEREF_ptr (s), depth);
	    break;
	}
	case type_list_tag : {
	    TYPE_P_P s = type_list_sub (t0);
	    output_string ("list_");
	    output_type_id (DEREF_ptr (s), depth);
	    break;
	}
	case type_stack_tag : {
	    TYPE_P_P s = type_stack_sub (t0);
	    output_string ("stack_");
	    output_type_id (DEREF_ptr (s), depth);
	    break;
	}
	case type_vec_ptr_tag : {
	    TYPE_P_P s = type_vec_ptr_sub (t0);
	    output_string ("vptr_");
	    output_type_id (DEREF_ptr (s), depth);
	    break;
	}
	case type_ident_tag : {
	    IDENTITY_P id = DEREF_ptr (type_ident_id (t0));
	    if (depth) {
			TYPE_P_P s = ident_defn (id);
			output_type_id (DEREF_ptr (s), depth - 1);
	    } else {
			CLASS_ID_P nm = DEREF_ptr (ident_id (id));
			output_string (DEREF_string (cid_name (nm)));
	    }
	    break;
	}
	default : {
	    output_string (name_aux_type (t));
	    break;
	}
    }
    return;
}


/*
 *    PRINT A TYPE SIZE
 *
 *    This routine print the size of the type t.
 */

static void
output_type_size(TYPE_P t)
{
    TYPE t0 = DEREF_type (t);
    switch (TAG_type (t0)) {
	case type_vec_tag : {
	    TYPE_P_P s = type_vec_sub (t0);
	    output ("SIZE_vec (%TT)", DEREF_ptr (s));
	    break;
	}
	case type_ptr_tag : {
	    TYPE_P_P s = type_ptr_sub (t0);
	    output ("SIZE_ptr (%TT)", DEREF_ptr (s));
	    break;
	}
	case type_list_tag : {
	    TYPE_P_P s = type_list_sub (t0);
	    output ("SIZE_list (%TT)", DEREF_ptr (s));
	    break;
	}
	case type_stack_tag : {
	    TYPE_P_P s = type_stack_sub (t0);
	    output ("SIZE_stack (%TT)", DEREF_ptr (s));
	    break;
	}
	case type_vec_ptr_tag : {
	    TYPE_P_P s = type_vec_ptr_sub (t0);
	    output ("SIZE_vec_ptr (%TT)", DEREF_ptr (s));
	    break;
	}
	case type_ident_tag : {
	    IDENTITY_P id = DEREF_ptr (type_ident_id (t0));
	    output_type_size (DEREF_ptr (ident_defn (id)));
	    break;
	}
	default : {
	    output_string ("SIZE_");
	    output_string (name_aux_type (t));
	    break;
	}
    }
    return;
}


/*
 *    PRINT A FORMAT STRING
 *
 *    This routine prints the string s, taking any formatting characters
 *    into account.  These formatting characters have the form %X or %XY
 *    for characters X and Y.  Each is commented within the body of the
 *    procedure in the form "%XY -> ....".
 */

void
output(char *s, ...)
    /*VARARGS*/
{
    char c;
    va_list args;

    va_start (args, s);

    while (c = *(s++), c != 0) {
		if (c == '%') {
			char *s0 = s;
			c = *(s++);
			switch (c) {

			case 'A' : {
				/* Arguments */
				c = *(s++);
				if (c == 'N') {
					/* %AN -> argument name */
					if (HAVE_ARGUMENT) {
						string_P ps = arg_name (CRT_ARGUMENT);
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'T') {
					/* %AT -> argument type */
					if (HAVE_ARGUMENT) {
						TYPE_P_P pt = arg_type (CRT_ARGUMENT);
						output_type (DEREF_ptr (pt));
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'C' : {
				/* Components */
				c = *(s++);
				if (c == 'N') {
					/* %CN -> component name */
					if (HAVE_COMPONENT) {
						string_P ps = cmp_name (CRT_COMPONENT);
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'T') {
					/* %CT -> component type */
					if (HAVE_COMPONENT) {
						TYPE_P_P pt = cmp_type (CRT_COMPONENT);
						output_type (DEREF_ptr (pt));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'U') {
					/* %CU -> short component type */
					if (HAVE_COMPONENT) {
						TYPE_P_P pt = cmp_type (CRT_COMPONENT);
						TYPE_P ta = DEREF_ptr (pt);
						char *tn = name_aux_type (ta);
						output_string (tn);
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'V') {
					/* %CV -> component default value */
					if (HAVE_COMPONENT) {
						string_P ps = cmp_name (CRT_COMPONENT);
						string s1 = DEREF_string (ps);
						if (s1) output_string (s1);
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'E' : {
				/* Enumerations */
				c = *(s++);
				if (c == 'N') {
					/* %EN -> enumeration name */
					if (HAVE_ENUM) {
						CLASS_ID_P_P pi = en_id (CRT_ENUM);
						string_P ps = cid_name (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'M') {
					/* %EM -> short enumeration name */
					if (HAVE_ENUM) {
						CLASS_ID_P_P pi = en_id (CRT_ENUM);
						string_P ps = cid_name_aux (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'O') {
					/* %EO -> enumeration order */
					if (HAVE_ENUM) {
						number_P pn = en_order (CRT_ENUM);
						number n = DEREF_number (pn);
						if (*s == '2') {
							n = log_2 (n);
							s++;
						}
						write_fmt(out, "%lu", n);
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'S') {
					/* %ES -> enumerator name */
					if (HAVE_ECONST) {
						string_P ps = ec_name (CRT_ECONST);
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'V') {
					/* %EV -> enumerator value */
					if (HAVE_ECONST) {
						number_P pn = ec_value (CRT_ECONST);
						number n = DEREF_number (pn);
						write_fmt(out, "%lu", n);
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'F' : {
				/* Fields */
				c = *(s++);
				if (c == 'N') {
					/* %FN -> field name */
					if (HAVE_FIELD) {
						string_P ps = fld_name (CRT_FIELD);
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == ',') {
					/* %F, -> ',' (if not the last field) */
					if (HAVE_FIELD) {
						LIST (FIELD_P) nf = TAIL_list (crt_fld);
						if (!IS_NULL_list (nf)) output_string (",");
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'I' : {
				/* Identities */
				c = *(s++);
				if (c == 'N') {
					/* %IN -> identity name */
					if (HAVE_IDENTITY) {
						CLASS_ID_P_P pi = ident_id (CRT_IDENTITY);
						string_P ps = cid_name (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'M') {
					/* %IM -> short identity name */
					if (HAVE_IDENTITY) {
						CLASS_ID_P_P pi = ident_id (CRT_IDENTITY);
						string_P ps = cid_name_aux (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'T') {
					/* %IT -> identity type definition */
					if (HAVE_IDENTITY) {
						TYPE_P_P pt = ident_defn (CRT_IDENTITY);
						output_type (DEREF_ptr (pt));
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'M' : {
				/* Maps */
				c = *(s++);
				if (c == 'N') {
					/* %MN -> map name */
					if (HAVE_MAP) {
						string_P ps = map_name (CRT_MAP);
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'R') {
					/* %MR -> map return type */
					if (HAVE_MAP) {
						TYPE_P_P pt = map_ret_type (CRT_MAP);
						output_type (DEREF_ptr (pt));
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'P' : {
				/* Primitives */
				c = *(s++);
				if (c == 'N') {
					/* %PN -> primitive name */
					if (HAVE_PRIMITIVE) {
						CLASS_ID_P_P pi = prim_id (CRT_PRIMITIVE);
						string_P ps = cid_name (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'M') {
					/* %PM -> short primitive name */
					if (HAVE_PRIMITIVE) {
						CLASS_ID_P_P pi = prim_id (CRT_PRIMITIVE);
						string_P ps = cid_name_aux (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'D') {
					/* %PD -> primitive definition */
					if (HAVE_PRIMITIVE) {
						string_P ps = prim_defn (CRT_PRIMITIVE);
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'S' : {
				/* Structures */
				c = *(s++);
				if (c == 'N') {
					/* %SN -> structure name */
					if (HAVE_STRUCTURE) {
						CLASS_ID_P_P pi = str_id (CRT_STRUCTURE);
						string_P ps = cid_name (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'M') {
					/* %SM -> short structure name */
					if (HAVE_STRUCTURE) {
						CLASS_ID_P_P pi = str_id (CRT_STRUCTURE);
						string_P ps = cid_name_aux (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'T' : {
				/* Types */
				c = *(s++);
				if (have_varargs) {
					TYPE_P ta = va_arg (args, TYPE_P);
					if (c == 'N') {
						/* %TN -> type name */
						char *tn = name_type (ta);
						output_string (tn);
					} else if (c == 'M') {
						/* %TM -> short type name */
						char *tn = name_aux_type (ta);
						output_string (tn);
					} else if (c == 'I') {
						/* %TI -> type identifier */
						output_type_id (ta, 0);
					} else if (c == 'J') {
						/* %TJ -> type identifier */
						output_type_id (ta, 1);
					} else if (c == 'S') {
						/* %TS -> type size */
						output_type_size (ta);
					} else if (c == 'T') {
						/* %TT -> type definition */
						output_type (ta);
					} else {
						goto bad_format;
					}
					break;
				}
				goto bad_format;
			}

			case 'U' : {
				/* Unions */
				c = *(s++);
				if (c == 'N') {
					/* %UN -> union name */
					if (HAVE_UNION) {
						CLASS_ID_P_P pi = un_id (CRT_UNION);
						string_P ps = cid_name (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'M') {
					/* %UM -> short union name */
					if (HAVE_UNION) {
						CLASS_ID_P_P pi = un_id (CRT_UNION);
						string_P ps = cid_name_aux (DEREF_ptr (pi));
						output_string (DEREF_string (ps));
					} else {
						goto misplaced_arg;
					}
				} else if (c == 'O') {
					/* %UO -> union order */
					if (HAVE_UNION) {
						int_P pi = un_no_fields (CRT_UNION);
						number n = (number) DEREF_int (pi);
						c = *s;
						if (c == '2') {
							n = log_2 (n);
							s++;
						} else if (c == '3') {
							n = log_2 (n + 1);
							s++;
						}
						write_fmt(out, "%lu", n);
					} else {
						goto misplaced_arg;
					}
				} else {
					goto bad_format;
				}
				break;
			}

			case 'V' : {
				/* %V -> overall version */
				int v1 = algebra->major_no;
				int v2 = algebra->minor_no;
				write_fmt(out, "%d.%d", v1, v2);
				break;
			}

			case 'X' : {
				/* %X -> overall name */
				output_string (algebra->name);
				break;
			}

			case 'Z' : {
				c = *(s++);
				if (c == 'V') {
					/* %ZV -> program version */
					output_string (progvers);
				} else if (c == 'X') {
					/* %ZX -> program name */
					output_string (progname);
				} else {
					goto bad_format;
				}
				break;
			}

			case 'b' : {
				/* %b -> backspace */
				ostream_unput(output_file, 1);
				break;
			}

			case 'd' : {
				/* %d -> integer (extra argument) */
				if (have_varargs) {
					int da = va_arg (args, int);
					write_fmt(out, "%d", da);
					break;
				}
				goto bad_format;
			}

			case 'e' : {
				/* %e -> evaluated string (extra argument) */
				if (have_varargs) {
					char *ea = va_arg (args, char *);
					if (ea) output (ea);
					break;
				}
				goto bad_format;
			}

			case 'n' : {
				/* %n -> number (extra argument) */
				if (have_varargs) {
					number na = va_arg (args, number);
					write_fmt(out, "%lu", na);
					break;
				}
				goto bad_format;
			}

			case 'p' : {
				/* Pragmas */
				c = *(s++);
				if (c == 't') {
					/* %pt -> '#pragma token' */
					output_string ("#pragma token");
				} else if (c == 'i') {
					/* %pi -> '#pragma interface' */
					output_string ("#pragma interface");
				} else {
					goto bad_format;
				}
				break;
			}

			case 's' : {
				/* %s -> string (extra argument) */
				if (have_varargs) {
					char *sa = va_arg (args, char *);
					if (sa) output_string (sa);
					break;
				}
				goto bad_format;
			}

			case 't' : {
				/* %t[0-9]* -> tab */
				unsigned t = 0;
				while (c = *s, (c >= '0' && c <= '9')) {
					t = 10 * t + (c - '0');
					s++;
				}
				while (out->column < t) output_char ('\t');
				break;
			}

			case 'u' : {
				/* %u -> unique */
				write_fmt(out, "%d", unique);
				break;
			}

			case 'x' : {
				/* Expression tokens */
				c = *(s++);
				if (c == 'r') {
					/* %xr -> 'EXP rvalue' */
					output_string ("EXP");
				} else if (c == 'l') {
					/* %xl -> 'EXP lvalue' */
					output_string ("EXP lvalue");
				} else if (c == 'c') {
					/* %xc -> 'EXP const' */
					output_string ("EXP");
					if (const_tokens) output_string (" const");
				} else {
					goto bad_format;
				}
				break;
			}

			case '0' : {
				/* %0 -> x<unique>_ */
				write_fmt(out, "x%d_", unique);
				break;
			}

			case '%' : {
				/* %% -> '%' */
				output_string ("%");
				break;
			}

			case '@' : {
				/* %@ -> '@' */
				output_string ("@");
				break;
			}

			case '\n' : {
				/* %\n -> ignored newline */
				break;
			}

				misplaced_arg : {
					MSG_misplaced_formatting_string (s0);
					break;
				}

			default :
				bad_format : {
					MSG_unknown_formatting_string (s0);
					s = s0;
					break;
				}
			}
		} else {
			output_char (c);
		}
    }
    va_end (args);
    return;
}


/*
 *    PRINT INITIAL COMMENT
 *
 *    This comment is printed at the start of each output file to indicate
 *    that it is automatically generated.
 */

static void
print_comment(void)
{
    if (first_comment) {
		/* Print copyright comment, if present */
		output ("%s\n\n", first_comment);
    }
    output ("/*\n");
    output (" *    AUTOMATICALLY GENERATED FROM ALGEBRA %X (VERSION %V)\n");
    output (" *    BY %ZX (VERSION %ZV)\n");
    output (" */\n\n");
    return;
}


/*
 *    C CODE FLAG
 *
 *    This flag is true if C code is being output.
 */

int output_c_code = 1;


/*
 *    OPEN AN OUTPUT FILE
 *
 *    This routine opens the output file formed by concatenating nm and suff.
 *    Two files can be open at once.
 */

void
open_file(char *dir, char *nm, char *suff)
{
    char *fname, *p;
    char buff [1000];

    flush_output ();
    (void)sprintf (buff, "%s%c%s%s", dir, FS_PATH_SEP, nm, suff);
    fname = string_copy(buff);
    output_file_old = output_file;
    output_file = ostream_new();
    if (!ostream_open(output_file, fname)) {
		MSG_cant_open_output_file (fname);
    }
    if (verbose_output) {
		MSG_creating (fname);
    }

    if (output_c_code) {
		/* Set up protection macro */
		char *tok = "";
		if (output_c_code == 2) tok = "_TOK";
		(void)sprintf (buff, "%s%s%s_INCLUDED", nm, suff, tok);
		for (p = buff; *p; p++) {
			char c = *p;
			if (isalpha (c)) {
				if (islower (c)) c = (char) toupper (c);
			} else if (!isdigit (c)) {
				c = '_';
			}
			*p = c;
		}

		/* Print file header */
		print_comment ();
		output ("#ifndef %s\n", buff);
		output ("#define\t%s\n\n", buff);
    }
    return;
}


/*
 *    CLOSE AN OUTPUT FILE
 *
 *    This routine closes the current output file.
 */

void
close_file(void)
{
    if (output_c_code) output ("#endif\n");
    flush_output ();
    ostream_close (output_file);
    ostream_free (output_file);
    output_file = output_file_old;
    output_file_old = NULL;
    output_c_code = 1;
    return;
}