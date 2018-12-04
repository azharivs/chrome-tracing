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
    generic,
    TP_ARGS(
        const char*, name,
        const char*, phase
    ),
    TP_FIELDS(
        ctf_string(name, name)
        ctf_string(phase, phase)
    )
)

#endif /* _LTTNG_CR_TP_H */

#include <lttng/tracepoint-event.h>

