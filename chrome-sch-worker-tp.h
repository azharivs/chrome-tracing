/*
 * chrome-sch-worker-tp.h
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER chrome2

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./chrome-sch-worker-tp_posttask.h"

#if !defined(_CHROME_SCH_WORKER_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CHROME_SCH_WORKER_TP_H

#include <lttng/tracepoint.h>


TRACEPOINT_EVENT(
    chrome2,
    PostTask,
    TP_ARGS(
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)


TRACEPOINT_EVENT(
    chrome2,
    PostDelayedTask,
    TP_ARGS(
        char*, function_name,
        char*, file_name,
	int, line_number,
	long int, delayInNanoseconds
    ),
    TP_FIELDS(
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
        ctf_integer(long int, delayInNanoseconds, delayInNanoseconds)
    )
)

TRACEPOINT_EVENT(
    chrome2,
    PostTaskAndReply,
    TP_ARGS(
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)

TRACEPOINT_EVENT(
    chrome2,
    PostTaskWithTraits,
    TP_ARGS(
        char*, function_name,
        char*, file_name,
	int, line_number,
	char*, priority
    ),
    TP_FIELDS(
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
        ctf_string(priority, priority)
    )
)

TRACEPOINT_EVENT(
    chrome2,
    PostDelayedTaskWithTraits,
    TP_ARGS(
        char*, function_name,
        char*, file_name,
	int, line_number,
	char*, priority,
	long int, delayInNanoseconds
    ),
    TP_FIELDS(
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
        ctf_string(priority, priority)
        ctf_integer(long int, delayInNanoseconds, delayInNanoseconds)
    )
)

TRACEPOINT_EVENT(
    chrome2,
    PostTaskWithTraitsAndReply,
    TP_ARGS(
        char*, function_name,
        char*, file_name,
	int, line_number,
	char*, priority
    ),
    TP_FIELDS(
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
        ctf_string(priority, priority)
    )
)

TRACEPOINT_EVENT(
    chrome2,
    CreateTaskRunnerWithTraits,
    TP_ARGS(
	char*, priority
    ),
    TP_FIELDS(
        ctf_string(priority, priority)
    )
)


TRACEPOINT_EVENT(
    chrome2,
    CreateSequencedTaskRunnerWithTraits,
    TP_ARGS(
	char*, priority
    ),
    TP_FIELDS(
        ctf_string(priority, priority)
    )
)

TRACEPOINT_EVENT(
    chrome2,
    CreateSingleThreadTaskRunnerWithTraits,
    TP_ARGS(
	char*, priority
    ),
    TP_FIELDS(
        ctf_string(priority, priority)
    )
)

TRACEPOINT_EVENT(
    chrome2,
    CreateCOMSTATaskRunnerWithTraits,
    TP_ARGS(
	char*, priority
    ),
    TP_FIELDS(
        ctf_string(priority, priority)
    )
)

#endif /* _CHROME_SCH_WORKER_TP_H */

#include <lttng/tracepoint-event.h>
