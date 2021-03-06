/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef PROCDECS_INCLUDED
#define PROCDECS_INCLUDED

#include <reader/exp.h>

#include <construct/installtypes.h>

#include "addr.h"

struct proc_state {
  ans procans;
  bool leaf_proc;
  baseoff mem_temp0;
  int result_label;
  long params_offset;
  long frame_size;
  long locals_offset;
  long locals_space;
  long maxargs;
  long callee_size;
};

extern int gencompat;
extern bool Has_vcallees;
extern bool Has_no_vcallers;
extern bool in_general_proc;
extern int callee_size;
extern bool May_have_callees;
extern int do_dynamic_init;

extern struct proc_state proc_state;

extern baseoff mem_temp(int);
extern makeans make_proc_tag_code(exp, space, where, int);
extern makeans make_res_tag_code(exp, space, where, int);
extern makeans make_apply_tag_code(exp, space, where, int);
extern makeans make_apply_general_tag_code(exp,space,where,int);
extern makeans make_make_callee_list_tag(exp,space,where,int);
extern makeans make_make_dynamic_callee_tag(exp,space,where,int);
extern makeans make_same_callees_tag(exp,space,where,int);
extern makeans make_tail_call_tag(exp,space,where,int);

#define PARAMS_OFFSET (16+1)*32

#endif /* PROCDECS_INCLUDED */
