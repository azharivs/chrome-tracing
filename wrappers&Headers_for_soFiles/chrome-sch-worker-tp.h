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
    LayerTreeImpl_PushPropertyTreesTo,
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
    SequenceManagerImpl_TakeTask_END,
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
    TaskQueueImpl_OnTaskStarted_control_tq,
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
    TaskQueueImpl_OnTaskStarted_default_tq,
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
    TaskQueueImpl_OnTaskStarted_unthrottled_tq,
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
    TaskQueueImpl_OnTaskStarted_frame_loading_tq,
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
    TaskQueueImpl_OnTaskStarted_frame_throttleable_tq,
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
    TaskQueueImpl_OnTaskStarted_frame_deferrable_tq,
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
    TaskQueueImpl_OnTaskStarted_frame_pausable_tq,
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
    TaskQueueImpl_OnTaskStarted_frame_unpausable_tq,
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
    TaskQueueImpl_OnTaskStarted_compositor_tq,
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
    TaskQueueImpl_OnTaskStarted_idle_tq,
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
    TaskQueueImpl_OnTaskStarted_test_tq,
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
    TaskQueueImpl_OnTaskStarted_frame_loading_control_tq,
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
    TaskQueueImpl_OnTaskStarted_v8_tq,
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
    TaskQueueImpl_OnTaskStarted_ipc_tq,
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
    TaskQueueImpl_OnTaskStarted_input_tq,
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
    TaskQueueImpl_OnTaskStarted_detached_tq,
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
    TaskQueueImpl_OnTaskStarted_cleanup_tq,
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
    TaskQueueImpl_OnTaskStarted_other_tq,
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
    TaskQueueImpl_OnTaskStarted_subthread_default_tq,
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
    TaskQueueImpl_OnTaskStarted_subthread_control_tq,
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
    WebContentsImpl_opener_rfh_frame_tree_node,
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
    WebContentsImpl_opener_rfh_frame_tree_node_END,
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
    WebContentsImpl_new_contents_SetOpenerForNewContents,
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
    WebContentsImpl_new_contents_SetOpenerForNewContents_END,
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
    WebContentsImpl_new_contents_GetFrameTree_root,
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
    WebContentsImpl_new_contents_GetFrameTree_root_END,
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
    WebContentsImpl_opener_rfh_active_sandbox_flags,
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
    WebContentsImpl_opener_rfh_active_sandbox_flags_END,
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
    WebContentsImpl_new_root_SetPendingFramePolicy,
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
    WebContentsImpl_new_root_SetPendingFramePolicy_END,
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
    WebContentsImpl_pending_frame_policy,
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
    WebContentsImpl_pending_frame_policy_END,
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
    WebContentsImpl_new_root_CommitPendingFramePolicy,
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
    WebContentsImpl_new_root_CommitPendingFramePolicy_END,
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
    WebContentsImpl_BrowserPluginGuest_Create,
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
    WebContentsImpl_BrowserPluginGuest_Create_END,
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
    WebContentsImpl_new_contents_Init,
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
    SiteInstance_Create,
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
    SiteInstance_Create_END,
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
    PreventAssociationWithSpareProcess,
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
    PreventAssociationWithSpareProcess_END,
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
    site_instance_GetProcess_GetNextRoutingID,
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
    site_instance_GetProcess_GetNextRoutingID_END,
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
    GetRenderManager_Init,
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
    GetRenderManager_Init_END,
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
    frame_tree_root_SetFrameName,
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
    frame_tree_root_SetFrameName_END,
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
    GetContentClient_browser_GetWebContentsViewDelegate,
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
    GetContentClient_browser_GetWebContentsViewDelegate_END,
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
    view_reset_WebContentsViewChildFrame,
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
    view_reset_WebContentsViewChildFrame_END,
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
    view_reset_CreateWebContentsView,
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
    view_reset_CreateWebContentsView_END,
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
    view_CreateView,
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
    view_CreateView_END,
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
    NotificationRegistrar_Add,
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
    NotificationRegistrar_Add_END,
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
    ContentFaviconDriver_DidUpdateFaviconURL,
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
    MouseCursorOverlayController_OnMouseClicked,
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
    MouseCursorOverlayController_OnMouseClicked_END,
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
    RenderWidgetHostImpl_ForwardMouseEvent,
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
    RenderWidgetHostImpl_ForwardMouseEvent_END,
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
    RenderWidgetHostImpl_ForwardWheelEvent,
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
    RenderWidgetHostImpl_ForwardWheelEvent_END,
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
    RenderWidgetHostImpl_ForwardKeyboardEvent,
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
    RenderWidgetHostImpl_ForwardKeyboardEvent_END,
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
    RenderWidgetHostViewBase_OnKeyEvent,
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
    RenderWidgetHostViewBase_OnMouseEvent,
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
    RenderWidgetHostViewBase_OnScrollEvent,
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
    RenderWidgetHostViewBase_OnTouchEvent,
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
    RenderWidgetHostViewBase_OnGestureEvent,
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
    RenderWidgetHostViewBase_OnKeyEvent_END,
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
    RenderWidgetHostViewBase_OnMouseEvent_END,
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
    RenderWidgetHostViewBase_OnScrollEvent_END,
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
    RenderWidgetHostViewBase_OnTouchEvent_END,
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
    RenderWidgetHostViewBase_OnGestureEvent_END,
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
    LayerTreeHostImpl_BeginCommit,
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
    LayerTreeHostImpl_CommitComplete,
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
    WorkQueue_GetFrontTask,
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
    WorkQueue_GetFrontTask_END,
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
    WorkQueue_GetBackTask,
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
    WorkQueue_GetBackTask_END,
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
    WorkQueue_BlockedByFence,
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
    WorkQueue_BlockedByFence_END,
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
    WorkQueue_GetFrontTaskEnqueueOrder,
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
    WorkQueue_GetFrontTaskEnqueueOrder_END,
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
    WorkQueue_Push,
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
    WorkQueue_Push_END,
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
    WorkQueue_PushNonNestableTaskToFront,
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
    WorkQueue_PushNonNestableTaskToFront_END,
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
    WorkQueue_ReloadEmptyImmediateQueue,
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
    WorkQueue_ReloadEmptyImmediateQueue_END,
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
    WorkQueue_TakeTaskFromWorkQueue,
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
    WorkQueue_TakeTaskFromWorkQueue_END,
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
    WorkQueue_RemoveAllCanceledTasksFromFront,
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
    WorkQueue_RemoveAllCanceledTasksFromFront_END,
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
    WorkQueue_AssignToWorkQueueSets,
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
    WorkQueue_AssignToWorkQueueSets_END,
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
    WorkQueue_AssignSetIndex,
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
    WorkQueue_AssignSetIndex_END,
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
    WorkQueue_InsertFenceImpl,
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
    WorkQueue_InsertFenceImpl_END,
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
    WorkQueue_InsertFenceSilently,
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
    WorkQueue_InsertFenceSilently_END,
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
    WorkQueue_InsertFence,
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
    WorkQueue_InsertFence_END,
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
    WorkQueue_RemoveFence,
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
    WorkQueue_RemoveFence_END,
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
    WorkQueue_ShouldRunBefore,
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
    WorkQueue_ShouldRunBefore_END,
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
    TaskTracker_RunTask,
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
    TaskTracker_RunTask_END,
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
    WorkQueue_PopTaskForTesting,
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
    WorkQueue_PopTaskForTesting_END,
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
    WorkQueueSets_AddQueue,
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
    WorkQueueSets_AddQueue_END,
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
    WorkQueueSets_RemoveQueue,
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
    WorkQueueSets_RemoveQueue_END,
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
    WorkQueueSets_ChangeSetIndex,
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
    WorkQueueSets_ChangeSetIndex_END,
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
    WorkQueueSets_OnFrontTaskChanged,
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
    WorkQueueSets_OnFrontTaskChanged_END,
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
    WorkQueueSets_OnTaskPushedToEmptyQueue,
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
    WorkQueueSets_OnTaskPushedToEmptyQueue_END,
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
    WorkQueueSets_OnPopQueue,
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
    WorkQueueSets_OnPopQueue_END,
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
    WorkQueueSets_OnQueueBlocked,
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
    WorkQueueSets_OnQueueBlocked_END,
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
    WorkQueueSets_GetOldestQueueInSet,
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
    WorkQueueSets_GetOldestQueueInSet_END,
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
    WorkQueueSets_GetOldestQueueAndEnqueueOrderInSet,
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
    WorkQueueSets_GetOldestQueueAndEnqueueOrderInSet_END,
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
    WorkQueueSets_IsSetEmpty,
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
    WorkQueueSets_IsSetEmpty_END,
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
    WorkQueueSets_ContainsWorkQueueForTest,
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
    WorkQueueSets_ContainsWorkQueueForTest_END,
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
    ThreadControllerImpl_SetSequencedTaskSource,
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
    ThreadControllerImpl_SetSequencedTaskSource_END,
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
    ThreadControllerImpl_SetTimerSlack,
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
    ThreadControllerImpl_SetTimerSlack_END,
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
    ThreadControllerImpl_ScheduleWork,
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
    ThreadControllerImpl_ScheduleWork_END,
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
    ThreadControllerImpl_SetNextDelayedDoWork,
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
    ThreadControllerImpl_SetNextDelayedDoWork_END,
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
    ThreadControllerImpl_RunsTasksInCurrentSequence,
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
    ThreadControllerImpl_RunsTasksInCurrentSequence_END,
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
    ThreadControllerImpl_SetDefaultTaskRunner,
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
    ThreadControllerImpl_SetDefaultTaskRunner_END,
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
    TaskQueue_TaskTiming_RecordTaskStart,
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
    TaskQueue_TaskTiming_RecordTaskStart_END,
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
    TaskQueue_TaskTiming_RecordTaskEnd,
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
    TaskQueue_TaskTiming_RecordTaskEnd_END,
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
    TaskQueue_ShutdownTaskQueue,
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
    TaskQueue_ShutdownTaskQueue_END,
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
    TaskQueue_RunsTasksInCurrentSequence,
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
    TaskQueue_RunsTasksInCurrentSequence_END,
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
    TaskQueue_PostDelayedTask,
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
    TaskQueue_PostDelayedTask_END,
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
    TaskQueue_PostNonNestableDelayedTask,
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
    TaskQueue_PostNonNestableDelayedTask_END,
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
    TaskQueue_PostTaskWithMetadata,
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
    TaskQueue_PostTaskWithMetadata_END,
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
    TaskQueue_IsQueueEnabled,
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
    TaskQueue_IsQueueEnabled_END,
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
    TaskQueue_GetNumberOfPendingTasks,
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
    TaskQueue_GetNumberOfPendingTasks_END,
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
    TaskQueue_IsOnMainThread,
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
    TaskQueue_IsOnMainThread_END,
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
    Sequence_PushTask,
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
    Sequence_PushTask_END,
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
    Sequence_TakeTask,
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
    Sequence_TakeTask_END,
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
    Sequence_Pop,
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
    Sequence_Pop_END,
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
    Sequence_GetSortKey,
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
    Sequence_GetSortKey_END,
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
    SchedulerWorker_Delegate_WaitForWork,
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
    SchedulerWorker_Delegate_WaitForWork_END,
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
    SchedulerWorker_Start,
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
    SchedulerWorker_Start_END,
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
    SchedulerWorker_WakeUp,
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
    SchedulerWorker_WakeUp_END,
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
    SchedulerWorker_JoinForTesting,
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
    SchedulerWorker_JoinForTesting_END,
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
    SchedulerWorker_ThreadAliveForTesting,
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
    SchedulerWorker_ThreadAliveForTesting_END,
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
    SchedulerWorker_Cleanup,
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
    SchedulerWorker_Cleanup_END,
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
    SchedulerWorker_BeginUnusedPeriod,
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
    SchedulerWorker_BeginUnusedPeriod_END,
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
    SchedulerWorker_EndUnusedPeriod,
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
    SchedulerWorker_EndUnusedPeriod_END,
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
    SchedulerWorker_GetLastUsedTime,
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
    SchedulerWorker_GetLastUsedTime_END,
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
    PriorityQueue_Transaction_Push,
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
    PriorityQueue_Transaction_Push_END,
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
    PriorityQueue_Transaction_PeekSortKey,
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
    PriorityQueue_Transaction_PeekSortKey_END,
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
    PriorityQueue_Transaction_PopSequence,
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
    PriorityQueue_Transaction_PopSequence_END,
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
    PriorityQueue_Transaction_IsEmpty,
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
    PriorityQueue_Transaction_IsEmpty_END,
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
    PriorityQueue_Transaction_Size,
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
    PriorityQueue_Transaction_Size_END,
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
    SequenceManagerImpl_BindToCurrentThread,
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
    SequenceManagerImpl_BindToCurrentThread_END,
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
    SequenceManagerImpl_CompleteInitializationOnBoundThread,
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
    SequenceManagerImpl_CompleteInitializationOnBoundThread_END,
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
    SequenceManagerImpl_AddToIncomingImmediateWorkList,
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
    SequenceManagerImpl_AddToIncomingImmediateWorkList_END,
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
    SequenceManagerImpl_RemoveFromIncomingImmediateWorkList,
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
    SequenceManagerImpl_RemoveFromIncomingImmediateWorkList_END,
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
    SequenceManagerImpl_OnBeginNestedRunLoop,
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
    SequenceManagerImpl_OnBeginNestedRunLoop_END,
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
    SequenceManagerImpl_OnExitNestedRunLoop,
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
    SequenceManagerImpl_OnExitNestedRunLoop_END,
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
    SequenceManagerImpl_OnQueueHasIncomingImmediateWork,
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
    SequenceManagerImpl_OnQueueHasIncomingImmediateWork_END,
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
    SequenceManagerImpl_MaybeScheduleImmediateWork,
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
    SequenceManagerImpl_MaybeScheduleImmediateWork_END,
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
    TaskTracker_WillPostTask,
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
    TaskTracker_WillPostTask_END,
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
    TaskTracker_RunAndPopNextTask,
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
    TaskTracker_RunAndPopNextTask_END,
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
    TaskTracker_BeforeRunTask,
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
    TaskTracker_BeforeRunTask_END,
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
    TaskTracker_AfterRunTask,
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
    TaskTracker_AfterRunTask_END,
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
