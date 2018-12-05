/*
 * lttng-cr-tp.h
 *
 *  Created on: Dec 3, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER chrome

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./lttng-cr-tp.h"

#if !defined(_LTTNG_CR_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _LTTNG_CR_TP_H

#include <lttng/tracepoint.h>

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome,
    generic0,
    TP_ARGS(
        const char*, name,
        const char*, phase
    ),
    TP_FIELDS(
        ctf_string(name, name)
        ctf_string(phase, phase)
    )
)

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome,
    generic1,
    TP_ARGS(
        const char*, name,
        const char*, phase,
        const char*, arg1,
        const char*, val1
    ),
    TP_FIELDS(
        ctf_string(name, name)
        ctf_string(phase, phase)
        ctf_string(arg1, arg1)
        ctf_string(val1, val1)
    )
)

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome,
    generic2,
    TP_ARGS(
        const char*, name,
        const char*, phase,
        const char*, arg1,
        const char*, val1,
        const char*, arg2,
        const char*, val2
    ),
    TP_FIELDS(
        ctf_string(name, name)
        ctf_string(phase, phase)
        ctf_string(arg1, arg1)
        ctf_string(val1, val1)
        ctf_string(arg2, arg2)
        ctf_string(val2, val2)
    )
)

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome,
    generic3,
    TP_ARGS(
        const char*, name,
        const char*, phase,
        const char*, arg1,
        const char*, val1,
        const char*, arg2,
        const char*, val2,
        const char*, arg3,
        const char*, val3
    ),
    TP_FIELDS(
        ctf_string(name, name)
        ctf_string(phase, phase)
        ctf_string(arg1, arg1)
        ctf_string(val1, val1)
        ctf_string(arg2, arg2)
        ctf_string(val2, val2)
        ctf_string(arg3, arg3)
        ctf_string(val3, val3)
    )
)

#endif /* _LTTNG_CR_TP_H */

#include <lttng/tracepoint-event.h>

