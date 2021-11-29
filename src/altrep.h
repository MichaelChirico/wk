
#include "Rversion.h"

#if defined(R_VERSION) && R_VERSION >= R_Version(3, 5, 0)
#define HAS_ALTREP
#endif

#if defined(HAS_ALTREP)

#if R_VERSION < R_Version(3, 6, 0)

// workaround because R's <R_ext/Altrep.h> not so conveniently uses `class`
// as a variable name, and C++ is not happy about that
//
// SEXP R_new_altrep(R_altrep_class_t class, SEXP data1, SEXP data2);
//
#define class klass

// Because functions declared in <R_ext/Altrep.h> have C linkage
#ifdef __cplusplus
extern "C" {
#endif

#include <R_ext/Altrep.h>

#ifdef __cplusplus
}
#endif

// undo the workaround
#undef class

#else
#include <R_ext/Altrep.h>
#endif

#if (defined(R_VERSION) && R_VERSION >= R_Version(3, 6, 0))

#define HAS_ALTREP_RAW

#endif

#endif

#define ALTREP_CHUNK_SIZE 1024

// uncomment to force a check without ALTREP defines
// #undef HAS_ALTREP
