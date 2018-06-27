/*
 * hello-tp.h
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER chrome1

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./task-scheduler-tp.h"

#if !defined(_TASK_SCHEDULER_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TASK_SCHEDULER_TP_H

#include <lttng/tracepoint.h>

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome1,
    function1,
    TP_ARGS(
        int, tid,
        char*, func_name
    ),
    TP_FIELDS(
        ctf_string(func, func_name)
        ctf_integer(int, tid, tid)
    )
)

#endif /* _TASK_SCHEDULER_TP_H */

#include <lttng/tracepoint-event.h>
