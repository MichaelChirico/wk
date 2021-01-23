// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"

// handle-wkt.cpp
SEXP wk_cpp_handle_wkt(SEXP wkt, SEXP xptr);
extern "C" SEXP _wk_wk_cpp_handle_wkt(SEXP wkt, SEXP xptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(wk_cpp_handle_wkt(cpp11::as_cpp<cpp11::decay_t<SEXP>>(wkt), cpp11::as_cpp<cpp11::decay_t<SEXP>>(xptr)));
  END_CPP11
}
// wkt-writer.cpp
cpp11::sexp wk_cpp_wkt_writer(int precision, bool trim);
extern "C" SEXP _wk_wk_cpp_wkt_writer(SEXP precision, SEXP trim) {
  BEGIN_CPP11
    return cpp11::as_sexp(wk_cpp_wkt_writer(cpp11::as_cpp<cpp11::decay_t<int>>(precision), cpp11::as_cpp<cpp11::decay_t<bool>>(trim)));
  END_CPP11
}
// wkt-writer.cpp
cpp11::sexp wk_cpp_wkt_formatter(int precision, bool trim, int max_coords);
extern "C" SEXP _wk_wk_cpp_wkt_formatter(SEXP precision, SEXP trim, SEXP max_coords) {
  BEGIN_CPP11
    return cpp11::as_sexp(wk_cpp_wkt_formatter(cpp11::as_cpp<cpp11::decay_t<int>>(precision), cpp11::as_cpp<cpp11::decay_t<bool>>(trim), cpp11::as_cpp<cpp11::decay_t<int>>(max_coords)));
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP _wk_wk_cpp_handle_wkt(SEXP, SEXP);
extern SEXP _wk_wk_cpp_wkt_formatter(SEXP, SEXP, SEXP);
extern SEXP _wk_wk_cpp_wkt_writer(SEXP, SEXP);
extern SEXP wk_c_handler_addr();
extern SEXP wk_c_handler_debug_new();
extern SEXP wk_c_handler_problems_new();
extern SEXP wk_c_handler_void_new();
extern SEXP wk_c_meta_handler_new();
extern SEXP wk_c_read_rct(SEXP, SEXP);
extern SEXP wk_c_read_sfc(SEXP, SEXP);
extern SEXP wk_c_read_wkb(SEXP, SEXP);
extern SEXP wk_c_read_xy(SEXP, SEXP);
extern SEXP wk_c_sfc_writer_new();
extern SEXP wk_c_vector_meta_handler_new();
extern SEXP wk_c_wkb_writer_new();
extern SEXP wk_c_xyzm_writer_new();

static const R_CallMethodDef CallEntries[] = {
    {"_wk_wk_cpp_handle_wkt",        (DL_FUNC) &_wk_wk_cpp_handle_wkt,        2},
    {"_wk_wk_cpp_wkt_formatter",     (DL_FUNC) &_wk_wk_cpp_wkt_formatter,     3},
    {"_wk_wk_cpp_wkt_writer",        (DL_FUNC) &_wk_wk_cpp_wkt_writer,        2},
    {"wk_c_handler_addr",            (DL_FUNC) &wk_c_handler_addr,            0},
    {"wk_c_handler_debug_new",       (DL_FUNC) &wk_c_handler_debug_new,       0},
    {"wk_c_handler_problems_new",    (DL_FUNC) &wk_c_handler_problems_new,    0},
    {"wk_c_handler_void_new",        (DL_FUNC) &wk_c_handler_void_new,        0},
    {"wk_c_meta_handler_new",        (DL_FUNC) &wk_c_meta_handler_new,        0},
    {"wk_c_read_rct",                (DL_FUNC) &wk_c_read_rct,                2},
    {"wk_c_read_sfc",                (DL_FUNC) &wk_c_read_sfc,                2},
    {"wk_c_read_wkb",                (DL_FUNC) &wk_c_read_wkb,                2},
    {"wk_c_read_xy",                 (DL_FUNC) &wk_c_read_xy,                 2},
    {"wk_c_sfc_writer_new",          (DL_FUNC) &wk_c_sfc_writer_new,          0},
    {"wk_c_vector_meta_handler_new", (DL_FUNC) &wk_c_vector_meta_handler_new, 0},
    {"wk_c_wkb_writer_new",          (DL_FUNC) &wk_c_wkb_writer_new,          0},
    {"wk_c_xyzm_writer_new",         (DL_FUNC) &wk_c_xyzm_writer_new,         0},
    {NULL, NULL, 0}
};
}

extern "C" void R_init_wk(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
