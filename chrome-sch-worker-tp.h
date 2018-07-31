/*
 * chrome-sch-worker-tp.h
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

//worker is taking up tasks from sequence of slots to run 
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


TRACEPOINT_EVENT(
    chrome,
    jsontolttng,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    Agent_StartTracing_ProxyToResponder_Run,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    SequenceManagerImpl_TakeTask,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    TaskQueueImpl_OnTaskStarted,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    TaskQueueImpl_OnTaskCompleted,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    WebContentsImpl_CreateWithOpener,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    WebContentsImpl_CreateWithOpener_END,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    NavigationControllerImpl_LoadURLWithParams,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

TRACEPOINT_EVENT(
    chrome,
    NavigationControllerImpl_LoadURLWithParams_END,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)



TRACEPOINT_EVENT(
    chrome,
    CoordinatorProxy_StopAndFlush,
    TP_ARGS(
	int, thread_id,
	char*, phase,
	char*, category_group_enabled,
        char*, name,
        char*, scope,
	unsigned long long, id,
	unsigned long long, bind_id,
	int, num_args,
	char*, arg_types,
	const unsigned long long, arg_values
    	),
    TP_FIELDS(
        ctf_integer(int, thread_id, thread_id)
        ctf_string(phase, phase)
        ctf_string(category_group_enabled, category_group_enabled)
        ctf_string(name, name)
        ctf_string(scope, scope)
        ctf_integer(unsigned long long, id, id)
        ctf_integer(unsigned long long, bind_id, bind_id)
        ctf_integer(int, num_args, num_args)
        ctf_string(arg_types, arg_types)
        ctf_integer(const unsigned long long, arg_values, arg_values)
    )
)

#endif /* _CHROME_SCH_WORKER_TP_H */

#include <lttng/tracepoint-event.h>
