# OCaml binding to TDF

This is an expirimental TDF bindign in OCaml.

For now the binding provides:

 * types to represent TDF 4.1 constructs
 * reader function to parse binary file with TDF capsule

Parsing of tdf bitstreams is not supported yet, so any construct uses
them (such as _apply_token, *_cond, make_tokdef, etc) are not very usable.

To compile test, run

    make a.out

To run it in OCaml interpretator. run

ocaml
#use "tdf_types.mli";;
#use "tdf_read.ml";;
read "/tmp/test.j";;
