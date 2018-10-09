/*
 * chrome-sch-worker-tp.h
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER chrome5

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./chrome-sch-worker-tp_taketask.h"

#if !defined(_CHROME_SCH_WORKER_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CHROME_SCH_WORKER_TP_H

#include <lttng/tracepoint.h>


TRACEPOINT_EVENT(
    chrome5,
    TaskTracker_WillPostTask,
    TP_ARGS(
        long int, taskid,
       /* char*, TaskName,
	int, task_type,*/
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        /*ctf_string(TaskName, TaskName)
        ctf_integer(int, task_type, task_type)*/
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)

TRACEPOINT_EVENT(
    chrome5,
    TaskTracker_WillScheduleSequence,
    TP_ARGS(
        long int, taskid,
       /* char*, TaskName,
	int, task_type,*/
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        /*ctf_string(TaskName, TaskName)
        ctf_integer(int, task_type, task_type)*/
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)

TRACEPOINT_EVENT(
    chrome5,
    TaskTracker_RunAndPopNextTask,
    TP_ARGS(
        long int, taskid,
        /*char*, TaskName,
	int, task_type,*/
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        /*ctf_string(TaskName, TaskName)
        ctf_integer(int, task_type, task_type)*/
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)

TRACEPOINT_EVENT(
    chrome5,
    TaskTracker_WillRun,
    TP_ARGS(
        long int, taskid,
        /*char*, TaskName,
	int, task_type,*/
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        /*ctf_string(TaskName, TaskName)
        ctf_integer(int, task_type, task_type)*/
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)

TRACEPOINT_EVENT(
    chrome5,
    TaskTracker_WillSkip,
    TP_ARGS(
        long int, taskid,
        /*char*, TaskName,
	int, task_type,*/
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        /*ctf_string(TaskName, TaskName)
        ctf_integer(int, task_type, task_type)*/
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)

TRACEPOINT_EVENT(
    chrome5,
    TaskTracker_RunOrSkipTask,
    TP_ARGS(
        long int, taskid,
        /*char*, TaskName,
	int, task_type,*/
        char*, function_name,
        char*, file_name,
	int, line_number
    ),
    TP_FIELDS(
        ctf_integer(long int, TaskID, taskid)
        /*ctf_string(TaskName, TaskName)
        ctf_integer(int, task_type, task_type)*/
        ctf_string(function_name, function_name)
        ctf_string(file_name, file_name)
        ctf_integer(int, line_number, line_number)
    )
)

#endif /* _CHROME_SCH_WORKER_TP_H */

#include <lttng/tracepoint-event.h>
