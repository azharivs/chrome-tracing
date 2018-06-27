/*
 * hello-tp.h
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER chrome

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./chrome-sch-worker-tp.h"

#if !defined(_CHROME_SCH_WORKER_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CHROME_SCH_WORKER_TP_H

#include <lttng/tracepoint.h>

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome,
    function,
    TP_ARGS(
        int, tid,
        char*, func_name
    ),
    TP_FIELDS(
        ctf_string(func, func_name)
        ctf_integer(int, tid, tid)
    )
)

//indicate start of a scheduler worker
TRACEPOINT_EVENT(
    chrome,
    worker_start,
    TP_ARGS(
        int, tid,
        bool, should_exit,
        bool, null_thread_handle
    ),
    TP_FIELDS(
        ctf_integer(int, exit, should_exit == true)
        ctf_integer(int, thread_handle_is_null, null_thread_handle == true)
        ctf_integer(int, tid, tid)
    )
)

//indicate wakeup of a scheduler worker
TRACEPOINT_EVENT(
    chrome,
    worker_wakeup,
    TP_ARGS(
        int, tid
    ),
    TP_FIELDS(
        ctf_integer(int, tid, tid)
    )
)

//indicate wakeup of a scheduler worker
TRACEPOINT_EVENT(
    chrome,
    run_worker,
    TP_ARGS(
        int, tid,
        int, seq_id
    ),
    TP_FIELDS(
        ctf_integer(int, task_sequence_id, seq_id)
        ctf_integer(int, tid, tid)
    )
)

#endif /* _CHROME_SCH_WORKER_TP_H */

#include <lttng/tracepoint-event.h>
