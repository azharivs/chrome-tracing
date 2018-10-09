/*
 * chrome-sch-worker-tp.h
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER chrome4

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./chrome-sch-worker-task_annotator.h"

#if !defined(_CHROME_SCH_WORKER_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CHROME_SCH_WORKER_TP_H

#include <lttng/tracepoint.h>

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome4,
    TaskAnnotator_WillQueueTask,
    TP_ARGS(
        long int, taskid,
        char*, function_name,
        char*, file_name,
	int, line_number,
        char*, queue_function
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
        ctf_string(queue_function, queue_function)
    )
)

TRACEPOINT_EVENT(
    chrome4,
    TaskAnnotator_RunTask,
    TP_ARGS(
        long int, taskid,
        char*, function_name,
        char*, file_name,
	int, line_number,
        char*, queue_function
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
        ctf_string(queue_function, queue_function)
    )
)

TRACEPOINT_EVENT(
    chrome4,
    TaskAnnotator_Task_Completed,
    TP_ARGS(
        long int, taskid,
        char*, Task_Completed
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        ctf_string(Task_Completed, Task_Completed)
    )
)


#endif /* _CHROME_SCH_WORKER_TP_H */

#include <lttng/tracepoint-event.h>
