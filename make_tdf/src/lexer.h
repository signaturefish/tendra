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

/*
 *  AUTOMATICALLY GENERATED BY lexi VERSION 1.2
 */


/* LOOKUP TABLE */

static unsigned char lookup_tab[257] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x000c, 0x000c, 0x000c, 0x000c, 0x000c, 0x000c, 0x000c, 0x000c,
    0x000c, 0x000c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x000a,
    0x0000, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x0000, 0x0000, 0x0000, 0x000a, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000
};

#ifndef LEX_EOF
#define LEX_EOF		256
#endif

#define lookup_char(C)	((int)lookup_tab[(C)])
#define is_white(T)	((T) & 0x0001)
#define is_alpha(T)	((T) & 0x0002)
#define is_digit(T)	((T) & 0x0004)
#define is_alphanum(T)	((T) & 0x0008)


/* MAIN PASS ANALYSER */

int
read_token(void)
{
    start: {
	int c0 = read_char(), t0;
	t0 = lookup_char(c0);
	if (is_white(t0)) goto start;
	switch (c0) {
	    case '#': {
		return(get_comment(c0));
	    }
	    case ',': {
		return(lex_comma);
	    }
	    case '[': {
		return(lex_open);
	    }
	    case ']': {
		return(lex_close);
	    }
	    case LEX_EOF: {
		return(lex_eof);
	    }
	}
	if (is_alpha(t0)) {
	    return(get_identifier(c0));
	} else if (is_digit(t0)) {
	    return(get_number(c0));
	}
	return(unknown_token(c0));
    }
}
