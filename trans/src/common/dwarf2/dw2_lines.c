/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <string.h>
#include <stdio.h>
#include <time.h>

#include <shared/bool.h>
#include <shared/check.h>
#include <shared/string.h>

#include <local/dw2_config.h>
#include <local/al.h>

#include <main/driver.h>
#include <main/flags.h>
#include <main/print.h>

#ifdef TDF_DIAG3
#include <diag3/diagglob.h>
#endif
#ifdef TDF_DIAG4
#include <diag4/diagtypes.h>
#include <diag4/diagglob.h>
#endif

#include <dwarf2/dw2_lines.h>
#include <dwarf2/dw2_codes.h>
#include <dwarf2/dw2_basic.h>
#include <dwarf2/dw2_iface.h>


/* values used in statement program prologue */

#define n_statprog_ops 9
static short statprog_op_args[n_statprog_ops] = {
	0, 1, 1, 1, 1, 0, 0, 0, 1
};

#define default_is_stmt 0
#define opcode_base	(n_statprog_ops + 1)

/* VARIABLES */

static long current_ad_label = -1;
static long current_ad_count = -1;
static long current_file = 1;
static long current_line = 1;
static long current_col = 0;
static long current_is_stmt = 0;
static long prev_ad_label = -1;
static long prev_ad_count = -1;
static long prev_file = 1;
static long prev_line = 1;
static long prev_col = 0;
static long prev_is_stmt = default_is_stmt;


void
do_statprog_prologue(long l_start, long l_end)
{
	dg_filename f_list = all_files;
	dg_filename f_trace;
	int i;
	long prologue_end = next_dwarf_label();
	enter_section("debug_line");
	asm_comment("Statement Program Prologue");
	out_dwf_label(l_start, 1);
	out32();
	out_dwf_dist_to_label(l_end);
	asm_printf("\n");
	out16();
	asm_printf("%d\n", DWARF_MOD_VERSION);
	out32();
	out_dwf_dist_to_label(prologue_end);
	asm_printf("\n");
	out8();
	asm_printf("%d\n", min_instr_size);
	out8();
	asm_printf("%d\n", default_is_stmt);
	out8();
	asm_printf("%d\n", dw_line_base);
	out8();
	asm_printf("%d\n", dw_line_range);
	out8();
	asm_printf("%d\n", opcode_base);
	out8();
	for (i = 1 ;; i++) {
		asm_printf("%d", statprog_op_args[i-1]);
		if (i == n_statprog_ops) {
			break;
		}
		asm_printf(", ");
	}
	asm_printf("\n");
	f_list = all_files;
	i = 0;
	while (f_list) {
		/* output directories */
		f_trace = all_files;
		while (f_trace != f_list) {
			if (streq(f_list->file_path, f_trace->file_path) &&
			    streq(f_list->file_host, f_trace->file_host)) {
				break;
			}
			f_trace = f_trace->another;
		}
		if (f_trace == f_list) {
			if (f_list->file_path[0] || f_list->file_host[0]) {
				dw_out_path(f_list, 0);
				f_list->index = ++i;
			} else {
				f_list->index = 0;
			}
		} else {
			f_list->index = f_trace->index;
		}
		f_list = f_list->another;
	}
	/* end of directories */
	out_string ("");
	f_list = all_files;
	i = 0;
	while (f_list) {
		/* output file names */
		if (f_list->file_name[0]) {
			time_t t = (time_t)f_list->file_dat;
			out_string(f_list->file_name);
			out8();
			uleb128((unsigned long)f_list->index);	/* directory */
			asm_printf("\n");
			out8();
			uleb128((unsigned long)(f_list->file_dat));
			asm_comment("%s", ctime(&t));
			out8();
			uleb128((unsigned long)0);	/* unknown length */
			asm_printf("\n");
			f_list->index = ++i;
		} else {
			f_list->index = 0;
		}
		f_list = f_list->another;
	}
	/* end of file names */
	out_string ("");
	out_dwf_label(prologue_end, 1);
	exit_section();
	dw2_cie();
}


static void
ext_opcode(int op, long arg_length, long align_lab)
{
	out8();
	asm_printf("%d, ", 0);
	if (needs_debug_align && align_lab) {
		out_dwf_label(align_lab, 0);
		asm_printf(" - . - 1");		/* OK for arg_length < 127 */
	} else
		uleb128((unsigned long)arg_length + 1);
	asm_printf(", %d\n", op);
	UNUSED(align_lab);
}


static void
update_statprog(void)
{
	long lineinc = current_line - prev_line;
	long ad_inc = 0;
	long special;
	if (current_ad_label < 0)
		return;
	enter_section("debug_line");
	if (prev_ad_label < 0) {
		long align_lab = 0;
		if (needs_debug_align) {
			align_lab = next_dwarf_label();
		}
		ext_opcode(DW_LNE_set_address, (long)PTR_SZ / 8, align_lab);
		out32();
		out_dwf_label(current_ad_label, 0);
		if (current_ad_count) {
			asm_printf(" + %ld", current_ad_count * min_instr_size);
		}
		asm_printf("\n");
		if (needs_debug_align) {
			out_dwf_label(align_lab, 1);
		}
	} else if (prev_ad_label != current_ad_label) {
		out8();
		asm_printf("%d\n", DW_LNS_fixed_advance_pc);
		out16();
		out_dwf_label(current_ad_label, 0);
		asm_printf(" - ");
		out_dwf_label(prev_ad_label, 0);
		if (current_ad_count != prev_ad_count) {
			asm_printf(" + %ld", (current_ad_count - prev_ad_count) *
			     min_instr_size);
		}
		asm_printf("\n");
	} else {
		ad_inc = current_ad_count - prev_ad_count;
	}
	prev_ad_label = current_ad_label;
	prev_ad_count = current_ad_count;
	if (current_file != prev_file) {
		out8();
		asm_printf("%d, ", DW_LNS_set_file);
		uleb128((unsigned long)current_file);
		asm_printf("\n");
		prev_file = current_file;
	}
	if (current_is_stmt != prev_is_stmt) {
		out8();
		asm_printf("%d\n", DW_LNS_negate_stmt);
		prev_is_stmt = current_is_stmt;
	}
	if (current_col != prev_col) {
		out8();
		asm_printf("%d, ", DW_LNS_set_column);
		uleb128((unsigned long)current_col);
		asm_printf("\n");
		prev_col = current_col;
	}
	if (lineinc < dw_line_base ||
	    lineinc >= (dw_line_base + dw_line_range)) {
		out8();
		asm_printf("%d, ", DW_LNS_advance_line);
		sleb128(lineinc);
		asm_printf("\n");
		lineinc = 0;
	}
	special = (lineinc - dw_line_base) + (dw_line_range * ad_inc) +
	    opcode_base;
	if (special > 255) {
		out8();
		asm_printf("%d, ", DW_LNS_advance_pc);
		uleb128((unsigned long)ad_inc);
		asm_printf("\n");
		special = (lineinc - dw_line_base) + opcode_base;
	}
	out8();
	if (special == (opcode_base - dw_line_base)) {
		asm_printf("%d", DW_LNS_copy);
	} else {
		asm_printf("%ld", special);
	}
	asm_comment("Line %ld", current_line);
	prev_line = current_line;
	exit_section();
}


void
dw2_source_mark(short_sourcepos pos, int is_stmt)
{
	/* must be within text segment */
	long newlab = 0;
	if (current_ad_label < 0 || current_ad_label != last_text_label ||
	    instr_count < 0) {
		newlab = set_dw_text_label();
	}
	if (newlab || instr_count != current_ad_count ||
	    pos.file->index != current_file) {
		update_statprog();
	}
	if (newlab) {
		current_ad_label = newlab;
	}
	current_ad_count = instr_count;
	current_file = pos.file->index;
	current_line = pos.line;
	current_col = (long)pos.column;
	current_is_stmt = (long)is_stmt;
}


void
dw2_start_basic_block(void)
{
	/* must be within text segment */
	long newlab = 0;
	if (current_ad_label < 0 || current_ad_label != last_text_label ||
	    instr_count < 0) {
		newlab = set_dw_text_label();
	}
	if (newlab || instr_count) {
		update_statprog();
	}
	if (newlab) {
		current_ad_label = newlab;
	}
	current_ad_count = instr_count;
	enter_section("debug_line");
	out8();
	asm_printf("%d\n", DW_LNS_set_basic_block);
	exit_section();
}


void
close_statprog(long l_end)
{
	if (current_ad_label < 0 || current_ad_label != last_text_label ||
	    instr_count < 0) {
		current_ad_label = set_dw_text_label();
	}
	current_ad_count = instr_count;
	update_statprog();
	enter_section("debug_line");
	ext_opcode(DW_LNE_end_sequence, 0, 0);
	out_dwf_label(l_end, 1);
	exit_section();
}
