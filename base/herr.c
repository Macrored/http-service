#include "herr.h"

#include <string.h> // for strerror

#ifdef _WIN32
#pragma warning(disable : 4996)
#endif // _WIN32

// errcode => errmsg
const char* hv_strerror(int err) {
    if (err > 0 && err <= SYS_NERR) {
        return strerror(err);
    }

    switch (err) {
#define F(errcode, name, errmsg) \
    case errcode: return errmsg;
    FOREACH_ERR(F)
#undef  F
    default:
        return "Undefined error";
    }
}
