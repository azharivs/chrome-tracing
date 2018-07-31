/*
 * hello-tp.c
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */


#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include "chrome-sch-worker-tp.h"

void trpoint_function(int tid, char *str){
    tracepoint(chrome, function, tid, str);
}

void trpoint_worker_start(int tid, bool exit, bool handle){
    tracepoint(chrome, worker_start, tid, exit, handle);
}

void trpoint_worker_wakeup(int tid){
    tracepoint(chrome, worker_wakeup, tid);
}

void trpoint_run_worker(int tid, int seq_id){
    tracepoint(chrome, run_worker, tid, seq_id);
}


void trpoint_jsontolttng(char* phase, char* category_group_enabled, char* name, char* scope, unsigned long long id, int num_args, char* arg_types, const unsigned long long arg_values, unsigned int flags) {

<<<<<<< HEAD
    tracepoint(chrome, jsontolttng, phase, category_group_enabled, name, scope, id, num_args, arg_types, arg_values, flags);
=======
	if (strcmp(name, "Agent_StartTracing_ProxyToResponder::Run") == 0 )
		tracepoint(chrome, Agent_StartTracing_ProxyToResponder_Run, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);
	
	else if (strcmp(name, "SequenceManagerImpl::TakeTask") == 0 )
		tracepoint(chrome, SequenceManagerImpl_TakeTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskCompleted") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskCompleted, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::CreateWithOpener") == 0 )
		tracepoint(chrome, WebContentsImpl_CreateWithOpener, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::CreateWithOpener_END") == 0 )
		tracepoint(chrome, WebContentsImpl_CreateWithOpener_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "NavigationControllerImpl::LoadURLWithParams") == 0 )
		tracepoint(chrome, NavigationControllerImpl_LoadURLWithParams, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "NavigationControllerImpl::LoadURLWithParams_END") == 0 )
		tracepoint(chrome, NavigationControllerImpl_LoadURLWithParams_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "CoordinatorProxy::StopAndFlush") == 0 )
		tracepoint(chrome, CoordinatorProxy_StopAndFlush, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else
	    tracepoint(chrome, jsontolttng, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);
>>>>>>> 2eabd7e... Making first XML view
}
