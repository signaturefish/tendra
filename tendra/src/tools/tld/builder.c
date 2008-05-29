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


/**** builder.c --- Front end to library construction mode of TDF linker.
 *
 ** Author: Steve Folkes <smf@hermes.mod.uk>
 *
 **** Commentary:
 *
 * This file provides the front end to the library construction mode of the
 * TDF linker.
 *
 **** Change Log:*/

/****************************************************************************/

#include "builder.h"
#include "capsule.h"
#include "debug.h"
#include "msgcat.h"
#include "library.h"
#include "shape-table.h"
#include "tenapp.h"
#include "unit-table.h"

#include "solve-cycles.h"

/*--------------------------------------------------------------------------*/

static LibraryP *
builder_read_libraries(ArgDataP arg_data, unsigned *num_libs_ref,
	unsigned *num_capsules_ref)
{
	unsigned  num_lib_files   = arg_data_num_library_files (arg_data);
	char **lib_files = arg_data_library_files (arg_data);
	LibraryP *libraries       = ALLOCATE_VECTOR (LibraryP, num_lib_files);
	unsigned  num_capsules    = 0;
	unsigned  i;

	for (i = 0; i < num_lib_files; i ++) {
		LibraryP library = library_create_stream_input (lib_files [i]);

		if (library != NIL (LibraryP)) {
			ShapeTableP lib_shapes = shape_table_create ();

			library_read (library, lib_shapes);
			library_close (library);
			libraries [i] = library;
			num_capsules += library_num_capsules (library);
			shape_table_deallocate (lib_shapes);
		} else {
			libraries [i] = NIL (LibraryP);
			MSG_cant_open_input_file (lib_files [i]);
		}
	}
	*num_libs_ref = num_lib_files;
	*num_capsules_ref = num_capsules;
	return (libraries);
}

static void
builder_read_capsule(CapsuleP capsule, CapsuleP *capsules,
	unsigned capsule_index, UnitTableP units, ShapeTableP shapes)
{
	char *name = capsule_name (capsule);
	unsigned i;

	for (i = 0; i < capsule_index; i ++) {
		if (cstring_equal (name, capsule_name (capsules [i]))) {
			MSG_duplicate_capsule_name (name);
		}
	}
	capsule_set_index (capsule, capsule_index);
	capsule_read (capsule, units, shapes);
	capsule_store_contents (capsule);
	capsule_close (capsule);
	capsules [capsule_index] = capsule;
}

static CapsuleP *
builder_read_capsules(ArgDataP arg_data, UnitTableP units,
	ShapeTableP shapes, unsigned *num_capsules_ref)
{
	unsigned  num_input_files = arg_data_get_num_files (arg_data);
	char **input_files = arg_data_get_files (arg_data);
	unsigned  capsule_index   = 0;
	unsigned  num_libraries;
	LibraryP *libraries;
	unsigned  num_capsules;
	CapsuleP *capsules;
	unsigned  i;

	libraries     = builder_read_libraries (arg_data, &num_libraries,
						&num_capsules);
	num_capsules += num_input_files;
	capsules      = ALLOCATE_VECTOR (CapsuleP, num_capsules);
	for (i = 0; i < num_libraries; i ++) {
		LibraryP library = libraries [i];

		if (library != NIL (LibraryP)) {
			unsigned num_lib_capsules = library_num_capsules (library);
			unsigned j;

			for (j = 0; j < num_lib_capsules; j ++) {
				LibCapsuleP lib_capsule = library_get_capsule (library, j);
				char *name = lib_capsule_name (lib_capsule);
				NStringP    contents    = lib_capsule_contents (lib_capsule);
				CapsuleP    capsule;

				capsule = capsule_create_string_input (name, contents);
				builder_read_capsule (capsule, capsules, capsule_index,
									  units, shapes);
				capsule_index ++;
			}
		}
	}
	DEALLOCATE (libraries);
	for (i = 0; i < num_input_files; i ++) {
		CapsuleP capsule;

		if ((capsule = capsule_create_stream_input (input_files [i])) !=
			NIL (CapsuleP)) {
			builder_read_capsule (capsule, capsules, capsule_index, units,
								  shapes);
			capsule_index ++;
		} else {
			MSG_cant_open_input_file (input_files [i]);
		}
	}
	tenapp_checkerrors(MSG_SEV_ERROR);

	*num_capsules_ref = num_capsules;
	return (capsules);
}

static void
builder_check_multi_defs(ShapeTableP shapes)
{
	shape_table_iter (shapes, shape_entry_check_multi_defs, NULL);
	tenapp_checkerrors(MSG_SEV_ERROR);
}

static void
builder_suppress_1(NStringP shape, BoolT all, NameKeyListP names,
	void *gclosure)
{
	ShapeTableP lib_shapes = (ShapeTableP) gclosure;
	ShapeEntryP entry      = shape_table_get (lib_shapes, shape);

	if (entry) {
		NameTableP        table = shape_entry_name_table (entry);
		NameKeyListEntryP name  = name_key_list_head (names);

		if (all) {
			name_table_iter (table, name_entry_builder_suppress,
							 (void *) shape);
		}
		for (; name; name = name_key_list_entry_next (name)) {
			NameKeyP   key        = name_key_list_entry_key (name);
			NameEntryP name_entry = name_table_get (table, key);

			if (name_entry) {
				debug_info_l_suppress (shape, key);
				name_entry_set_definition (name_entry, NIL (CapsuleP));
			}
		}
	}
}

static void
builder_suppress(ArgDataP arg_data, ShapeTableP lib_shapes)
{
	if (arg_data_get_suppress_mult (arg_data)) {
		shape_table_iter (lib_shapes, shape_entry_suppress_mult,
						  NULL);
	}
	shape_control_iter (arg_data_get_suppresses (arg_data), builder_suppress_1,
						(void *) lib_shapes);
	tenapp_checkerrors(MSG_SEV_ERROR);

}

static void
builder_write_library(ArgDataP arg_data, ShapeTableP shapes,
	unsigned num_capsules, CapsuleP *capsules)
{
	char *output_file = arg_data_get_output_file (arg_data);
	LibraryP library;

	if ((library = library_create_stream_output (output_file)) !=
		NIL (LibraryP)) {
		library_write (library, shapes, num_capsules, capsules);
		library_close (library);
	} else {
		MSG_cant_open_output_file (output_file);
		UNREACHED;
	}
	tenapp_checkerrors(MSG_SEV_ERROR);
}

/*--------------------------------------------------------------------------*/

void
builder_main(ArgDataP arg_data)
{
	UnitTableP  units  = unit_table_create ();
	ShapeTableP shapes = shape_table_create ();
	unsigned    num_capsules;
	CapsuleP   *capsules;

	capsules = builder_read_capsules (arg_data, units, shapes, &num_capsules);
	builder_check_multi_defs (shapes);
	builder_suppress (arg_data, shapes);
	builder_write_library (arg_data, shapes, num_capsules, capsules);
}