/*
 * chrome-sch-worker-tp.cc
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


void trpoint_jsontolttng(int thread_id, char* phase, char* category_group_enabled, char* name, char* scope, unsigned long long id, unsigned long long bind_id, int num_args, char* arg_types, const unsigned long long arg_values) {

	if (strcmp(name, "Agent_StartTracing_ProxyToResponder::Run") == 0 )
		tracepoint(chrome, Agent_StartTracing_ProxyToResponder_Run, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "LayerTreeImpl::PushPropertyTreesTo") == 0 )
		tracepoint(chrome, LayerTreeImpl_PushPropertyTreesTo, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);
	
	else if (strcmp(name, "SequenceManagerImpl::TakeTask") == 0 )
		tracepoint(chrome, SequenceManagerImpl_TakeTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_control_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_control_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_default_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_default_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_unthrottled_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_unthrottled_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_frame_loading_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_frame_loading_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_frame_throttleable_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_frame_throttleable_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_frame_deferrable_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_frame_deferrable_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_frame_pausable_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_frame_pausable_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_frame_unpausable_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_frame_unpausable_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_compositor_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_compositor_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_idle_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_idle_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_test_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_test_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_frame_loading_control_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_frame_loading_control_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_v8_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_v8_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_ipc_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_ipc_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_input_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_input_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_detached_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_detached_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_cleanup_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_cleanup_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_other_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_other_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_subthread_default_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_subthread_default_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskStarted_subthread_control_tq") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskStarted_subthread_control_tq, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueueImpl::OnTaskCompleted") == 0 )
		tracepoint(chrome, TaskQueueImpl_OnTaskCompleted, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::CreateWithOpener") == 0 )
		tracepoint(chrome, WebContentsImpl_CreateWithOpener, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::opener_rfh->frame_tree_node") == 0 )
		tracepoint(chrome, WebContentsImpl_opener_rfh_frame_tree_node, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::opener_rfh->frame_tree_node_END") == 0 )
		tracepoint(chrome, WebContentsImpl_opener_rfh_frame_tree_node_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_contents->SetOpenerForNewContents") == 0 )
		tracepoint(chrome, WebContentsImpl_new_contents_SetOpenerForNewContents, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_contents->SetOpenerForNewContents_END") == 0 )
		tracepoint(chrome, WebContentsImpl_new_contents_SetOpenerForNewContents_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_contents->GetFrameTree()->root") == 0 )
		tracepoint(chrome, WebContentsImpl_new_contents_GetFrameTree_root, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_contents->GetFrameTree()->root_END") == 0 )
		tracepoint(chrome, WebContentsImpl_new_contents_GetFrameTree_root_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::opener_rfh->active_sandbox_flags") == 0 )
		tracepoint(chrome, WebContentsImpl_opener_rfh_active_sandbox_flags, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::opener_rfh->active_sandbox_flags_END") == 0 )
		tracepoint(chrome, WebContentsImpl_opener_rfh_active_sandbox_flags_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_root->SetPendingFramePolicy") == 0 )
		tracepoint(chrome, WebContentsImpl_new_root_SetPendingFramePolicy, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_root->SetPendingFramePolicy_END") == 0 )
		tracepoint(chrome, WebContentsImpl_new_root_SetPendingFramePolicy_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::pending_frame_policy") == 0 )
		tracepoint(chrome, WebContentsImpl_pending_frame_policy, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::pending_frame_policy_END") == 0 )
		tracepoint(chrome, WebContentsImpl_pending_frame_policy_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_root->CommitPendingFramePolicy") == 0 )
		tracepoint(chrome, WebContentsImpl_new_root_CommitPendingFramePolicy, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_root->CommitPendingFramePolicy_END") == 0 )
		tracepoint(chrome, WebContentsImpl_new_root_CommitPendingFramePolicy_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::BrowserPluginGuest::Create") == 0 )
		tracepoint(chrome, WebContentsImpl_BrowserPluginGuest_Create, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::BrowserPluginGuest::Create_END") == 0 )
		tracepoint(chrome, WebContentsImpl_BrowserPluginGuest_Create_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::new_contents->Init") == 0 )
		tracepoint(chrome, WebContentsImpl_new_contents_Init, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SiteInstance::Create") == 0 )
		tracepoint(chrome, SiteInstance_Create, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SiteInstance::Create_END") == 0 )
		tracepoint(chrome, SiteInstance_Create_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PreventAssociationWithSpareProcess") == 0 )
		tracepoint(chrome, PreventAssociationWithSpareProcess, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PreventAssociationWithSpareProcess_END") == 0 )
		tracepoint(chrome, PreventAssociationWithSpareProcess_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "site_instance::GetProcess::GetNextRoutingID") == 0 )
		tracepoint(chrome, site_instance_GetProcess_GetNextRoutingID, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "site_instance::GetProcess::GetNextRoutingID_END") == 0 )
		tracepoint(chrome, site_instance_GetProcess_GetNextRoutingID_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "GetRenderManager::Init") == 0 )
		tracepoint(chrome, GetRenderManager_Init, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "GetRenderManager::Init_END") == 0 )
		tracepoint(chrome, GetRenderManager_Init_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "frame_tree_root::SetFrameName") == 0 )
		tracepoint(chrome, frame_tree_root_SetFrameName, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "frame_tree_root::SetFrameName_END") == 0 )
		tracepoint(chrome, frame_tree_root_SetFrameName_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "GetContentClient::browser::GetWebContentsViewDelegate") == 0 )
		tracepoint(chrome, GetContentClient_browser_GetWebContentsViewDelegate, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "GetContentClient::browser::GetWebContentsViewDelegate_END") == 0 )
		tracepoint(chrome, GetContentClient_browser_GetWebContentsViewDelegate_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "view_reset::WebContentsViewChildFrame") == 0 )
		tracepoint(chrome, view_reset_WebContentsViewChildFrame, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "view_reset::WebContentsViewChildFrame_END") == 0 )
		tracepoint(chrome, view_reset_WebContentsViewChildFrame_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "view_reset::CreateWebContentsView") == 0 )
		tracepoint(chrome, view_reset_CreateWebContentsView, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "view_reset::CreateWebContentsView_END") == 0 )
		tracepoint(chrome, view_reset_CreateWebContentsView_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "view::CreateView") == 0 )
		tracepoint(chrome, view_CreateView, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "view::CreateView_END") == 0 )
		tracepoint(chrome, view_CreateView_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "NotificationRegistrar::Add") == 0 )
		tracepoint(chrome, NotificationRegistrar_Add, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "NotificationRegistrar::Add_END") == 0 )
		tracepoint(chrome, NotificationRegistrar_Add_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WebContentsImpl::CreateWithOpener_END") == 0 )
		tracepoint(chrome, WebContentsImpl_CreateWithOpener_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "NavigationControllerImpl::LoadURLWithParams") == 0 )
		tracepoint(chrome, NavigationControllerImpl_LoadURLWithParams, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "NavigationControllerImpl::LoadURLWithParams_END") == 0 )
		tracepoint(chrome, NavigationControllerImpl_LoadURLWithParams_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "MouseCursorOverlayController::OnMouseClicked") == 0 )
		tracepoint(chrome, MouseCursorOverlayController_OnMouseClicked, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "MouseCursorOverlayController::OnMouseClicked_END") == 0 )
		tracepoint(chrome, MouseCursorOverlayController_OnMouseClicked_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostImpl::ForwardMouseEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostImpl_ForwardMouseEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);
	
	else if (strcmp(name, "RenderWidgetHostImpl::ForwardMouseEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostImpl_ForwardMouseEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostImpl::ForwardWheelEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostImpl_ForwardWheelEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);
	
	else if (strcmp(name, "RenderWidgetHostImpl::ForwardWheelEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostImpl_ForwardWheelEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostImpl::ForwardKeyboardEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostImpl_ForwardKeyboardEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);
	
	else if (strcmp(name, "RenderWidgetHostImpl::ForwardKeyboardEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostImpl_ForwardKeyboardEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnKeyEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnKeyEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnMouseEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnMouseEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnScrollEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnScrollEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnTouchEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnTouchEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnGestureEvent") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnGestureEvent, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnKeyEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnKeyEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnMouseEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnMouseEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnScrollEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnScrollEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnTouchEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnTouchEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "RenderWidgetHostViewBase::OnGestureEvent_END") == 0 )
		tracepoint(chrome, RenderWidgetHostViewBase_OnGestureEvent_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "LayerTreeHostImpl::BeginCommit") == 0 )
		tracepoint(chrome, LayerTreeHostImpl_BeginCommit, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "LayerTreeHostImpl::CommitComplete") == 0 )
		tracepoint(chrome, LayerTreeHostImpl_CommitComplete, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);






	else if (strcmp(name, "WorkQueue::GetFrontTask") == 0 )
		tracepoint(chrome, WorkQueue_GetFrontTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::GetFrontTask_END") == 0 )
		tracepoint(chrome, WorkQueue_GetFrontTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::GetBackTask") == 0 )
		tracepoint(chrome, WorkQueue_GetBackTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::GetBackTask_END") == 0 )
		tracepoint(chrome, WorkQueue_GetBackTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::BlockedByFence") == 0 )
		tracepoint(chrome, WorkQueue_BlockedByFence, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::BlockedByFence_END") == 0 )
		tracepoint(chrome, WorkQueue_BlockedByFence_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::GetFrontTaskEnqueueOrder") == 0 )
		tracepoint(chrome, WorkQueue_GetFrontTaskEnqueueOrder, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::GetFrontTaskEnqueueOrder_END") == 0 )
		tracepoint(chrome, WorkQueue_GetFrontTaskEnqueueOrder_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::Push") == 0 )
		tracepoint(chrome, WorkQueue_Push, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::Push_END") == 0 )
		tracepoint(chrome, WorkQueue_Push_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::PushNonNestableTaskToFront") == 0 )
		tracepoint(chrome, WorkQueue_PushNonNestableTaskToFront, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::PushNonNestableTaskToFront_END") == 0 )
		tracepoint(chrome, WorkQueue_PushNonNestableTaskToFront_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::ReloadEmptyImmediateQueue") == 0 )
		tracepoint(chrome, WorkQueue_ReloadEmptyImmediateQueue, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::ReloadEmptyImmediateQueue_END") == 0 )
		tracepoint(chrome, WorkQueue_ReloadEmptyImmediateQueue_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::TakeTaskFromWorkQueue") == 0 )
		tracepoint(chrome, WorkQueue_TakeTaskFromWorkQueue, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::TakeTaskFromWorkQueue_END") == 0 )
		tracepoint(chrome, WorkQueue_TakeTaskFromWorkQueue_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::RemoveAllCanceledTasksFromFront") == 0 )
		tracepoint(chrome, WorkQueue_RemoveAllCanceledTasksFromFront, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::RemoveAllCanceledTasksFromFront_END") == 0 )
		tracepoint(chrome, WorkQueue_RemoveAllCanceledTasksFromFront_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::AssignToWorkQueueSets") == 0 )
		tracepoint(chrome, WorkQueue_AssignToWorkQueueSets, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::AssignToWorkQueueSets_END") == 0 )
		tracepoint(chrome, WorkQueue_AssignToWorkQueueSets_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::AssignSetIndex") == 0 )
		tracepoint(chrome, WorkQueue_AssignSetIndex, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::AssignSetIndex_END") == 0 )
		tracepoint(chrome, WorkQueue_AssignSetIndex_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::InsertFenceImpl") == 0 )
		tracepoint(chrome, WorkQueue_InsertFenceImpl, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::InsertFenceImpl_END") == 0 )
		tracepoint(chrome, WorkQueue_InsertFenceImpl_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::InsertFenceSilently") == 0 )
		tracepoint(chrome, WorkQueue_InsertFenceSilently, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::InsertFenceSilently_END") == 0 )
		tracepoint(chrome, WorkQueue_InsertFenceSilently_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::InsertFence") == 0 )
		tracepoint(chrome, WorkQueue_InsertFence, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::InsertFence_END") == 0 )
		tracepoint(chrome, WorkQueue_InsertFence_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::RemoveFence") == 0 )
		tracepoint(chrome, WorkQueue_RemoveFence, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::RemoveFence_END") == 0 )
		tracepoint(chrome, WorkQueue_RemoveFence_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::ShouldRunBefore") == 0 )
		tracepoint(chrome, WorkQueue_ShouldRunBefore, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::ShouldRunBefore_END") == 0 )
		tracepoint(chrome, WorkQueue_ShouldRunBefore_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::PopTaskForTesting") == 0 )
		tracepoint(chrome, WorkQueue_PopTaskForTesting, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueue::PopTaskForTesting_END") == 0 )
		tracepoint(chrome, WorkQueue_PopTaskForTesting_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::AddQueue") == 0 )
		tracepoint(chrome, WorkQueueSets_AddQueue, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::AddQueue_END") == 0 )
		tracepoint(chrome, WorkQueueSets_AddQueue_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::RemoveQueue") == 0 )
		tracepoint(chrome, WorkQueueSets_RemoveQueue, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::RemoveQueue_END") == 0 )
		tracepoint(chrome, WorkQueueSets_RemoveQueue_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::ChangeSetIndex") == 0 )
		tracepoint(chrome, WorkQueueSets_ChangeSetIndex, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::ChangeSetIndex_END") == 0 )
		tracepoint(chrome, WorkQueueSets_ChangeSetIndex_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnFrontTaskChanged") == 0 )
		tracepoint(chrome, WorkQueueSets_OnFrontTaskChanged, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnFrontTaskChanged_END") == 0 )
		tracepoint(chrome, WorkQueueSets_OnFrontTaskChanged_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnTaskPushedToEmptyQueue") == 0 )
		tracepoint(chrome, WorkQueueSets_OnTaskPushedToEmptyQueue, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnTaskPushedToEmptyQueue_END") == 0 )
		tracepoint(chrome, WorkQueueSets_OnTaskPushedToEmptyQueue_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnPopQueue") == 0 )
		tracepoint(chrome, WorkQueueSets_OnPopQueue, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnPopQueue_END") == 0 )
		tracepoint(chrome, WorkQueueSets_OnPopQueue_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnQueueBlocked") == 0 )
		tracepoint(chrome, WorkQueueSets_OnQueueBlocked, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::OnQueueBlocked_END") == 0 )
		tracepoint(chrome, WorkQueueSets_OnQueueBlocked_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::GetOldestQueueInSet") == 0 )
		tracepoint(chrome, WorkQueueSets_GetOldestQueueInSet, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::GetOldestQueueInSet_END") == 0 )
		tracepoint(chrome, WorkQueueSets_GetOldestQueueInSet_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::GetOldestQueueAndEnqueueOrderInSet") == 0 )
		tracepoint(chrome, WorkQueueSets_GetOldestQueueAndEnqueueOrderInSet, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::GetOldestQueueAndEnqueueOrderInSet_END") == 0 )
		tracepoint(chrome, WorkQueueSets_GetOldestQueueAndEnqueueOrderInSet_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::IsSetEmpty") == 0 )
		tracepoint(chrome, WorkQueueSets_IsSetEmpty, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::IsSetEmpty_END") == 0 )
		tracepoint(chrome, WorkQueueSets_IsSetEmpty_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::ContainsWorkQueueForTest") == 0 )
		tracepoint(chrome, WorkQueueSets_ContainsWorkQueueForTest, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "WorkQueueSets::ContainsWorkQueueForTest_END") == 0 )
		tracepoint(chrome, WorkQueueSets_ContainsWorkQueueForTest_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetSequencedTaskSource") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetSequencedTaskSource, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetSequencedTaskSource_END") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetSequencedTaskSource_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetTimerSlack") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetTimerSlack, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetTimerSlack_END") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetTimerSlack_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::ScheduleWork") == 0 )
		tracepoint(chrome, ThreadControllerImpl_ScheduleWork, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::ScheduleWork_END") == 0 )
		tracepoint(chrome, ThreadControllerImpl_ScheduleWork_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetNextDelayedDoWork") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetNextDelayedDoWork, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetNextDelayedDoWork_END") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetNextDelayedDoWork_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::RunsTasksInCurrentSequence") == 0 )
		tracepoint(chrome, ThreadControllerImpl_RunsTasksInCurrentSequence, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::RunsTasksInCurrentSequence_END") == 0 )
		tracepoint(chrome, ThreadControllerImpl_RunsTasksInCurrentSequence_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetDefaultTaskRunner") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetDefaultTaskRunner, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "ThreadControllerImpl::SetDefaultTaskRunner_END") == 0 )
		tracepoint(chrome, ThreadControllerImpl_SetDefaultTaskRunner_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::TaskTiming::RecordTaskStart") == 0 )
		tracepoint(chrome, TaskQueue_TaskTiming_RecordTaskStart, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::TaskTiming::RecordTaskStart_END") == 0 )
		tracepoint(chrome, TaskQueue_TaskTiming_RecordTaskStart_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::TaskTiming::RecordTaskEnd") == 0 )
		tracepoint(chrome, TaskQueue_TaskTiming_RecordTaskEnd, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::TaskTiming::RecordTaskEnd_END") == 0 )
		tracepoint(chrome, TaskQueue_TaskTiming_RecordTaskEnd_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::ShutdownTaskQueue") == 0 )
		tracepoint(chrome, TaskQueue_ShutdownTaskQueue, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::ShutdownTaskQueue_END") == 0 )
		tracepoint(chrome, TaskQueue_ShutdownTaskQueue_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::RunsTasksInCurrentSequence") == 0 )
		tracepoint(chrome, TaskQueue_RunsTasksInCurrentSequence, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::RunsTasksInCurrentSequence_END") == 0 )
		tracepoint(chrome, TaskQueue_RunsTasksInCurrentSequence_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::PostDelayedTask") == 0 )
		tracepoint(chrome, TaskQueue_PostDelayedTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::PostDelayedTask_END") == 0 )
		tracepoint(chrome, TaskQueue_PostDelayedTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::PostNonNestableDelayedTask") == 0 )
		tracepoint(chrome, TaskQueue_PostNonNestableDelayedTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::PostNonNestableDelayedTask_END") == 0 )
		tracepoint(chrome, TaskQueue_PostNonNestableDelayedTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::PostTaskWithMetadata") == 0 )
		tracepoint(chrome, TaskQueue_PostTaskWithMetadata, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::PostTaskWithMetadata_END") == 0 )
		tracepoint(chrome, TaskQueue_PostTaskWithMetadata_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::IsQueueEnabled") == 0 )
		tracepoint(chrome, TaskQueue_IsQueueEnabled, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::IsQueueEnabled_END") == 0 )
		tracepoint(chrome, TaskQueue_IsQueueEnabled_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::GetNumberOfPendingTasks") == 0 )
		tracepoint(chrome, TaskQueue_GetNumberOfPendingTasks, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::GetNumberOfPendingTasks_END") == 0 )
		tracepoint(chrome, TaskQueue_GetNumberOfPendingTasks_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::IsOnMainThread") == 0 )
		tracepoint(chrome, TaskQueue_IsOnMainThread, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskQueue::IsOnMainThread_END") == 0 )
		tracepoint(chrome, TaskQueue_IsOnMainThread_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::PushTask") == 0 )
		tracepoint(chrome, Sequence_PushTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::PushTask_END") == 0 )
		tracepoint(chrome, Sequence_PushTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::TakeTask") == 0 )
		tracepoint(chrome, Sequence_TakeTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::TakeTask_END") == 0 )
		tracepoint(chrome, Sequence_TakeTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::Pop") == 0 )
		tracepoint(chrome, Sequence_Pop, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::Pop_END") == 0 )
		tracepoint(chrome, Sequence_Pop_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::GetSortKey") == 0 )
		tracepoint(chrome, Sequence_GetSortKey, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "Sequence::GetSortKey_END") == 0 )
		tracepoint(chrome, Sequence_GetSortKey_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::Delegate::WaitForWork") == 0 )
		tracepoint(chrome, SchedulerWorker_Delegate_WaitForWork, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::Delegate::WaitForWork_END") == 0 )
		tracepoint(chrome, SchedulerWorker_Delegate_WaitForWork_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::Start") == 0 )
		tracepoint(chrome, SchedulerWorker_Start, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::Start_END") == 0 )
		tracepoint(chrome, SchedulerWorker_Start_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::WakeUp") == 0 )
		tracepoint(chrome, SchedulerWorker_WakeUp, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::WakeUp_END") == 0 )
		tracepoint(chrome, SchedulerWorker_WakeUp_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::JoinForTesting") == 0 )
		tracepoint(chrome, SchedulerWorker_JoinForTesting, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::JoinForTesting_END") == 0 )
		tracepoint(chrome, SchedulerWorker_JoinForTesting_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::ThreadAliveForTesting") == 0 )
		tracepoint(chrome, SchedulerWorker_ThreadAliveForTesting, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::ThreadAliveForTesting_END") == 0 )
		tracepoint(chrome, SchedulerWorker_ThreadAliveForTesting_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);


	else if (strcmp(name, "SchedulerWorker::Cleanup") == 0 )
		tracepoint(chrome, SchedulerWorker_Cleanup, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::Cleanup_END") == 0 )
		tracepoint(chrome, SchedulerWorker_Cleanup_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::BeginUnusedPeriod") == 0 )
		tracepoint(chrome, SchedulerWorker_BeginUnusedPeriod, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::BeginUnusedPeriod_END") == 0 )
		tracepoint(chrome, SchedulerWorker_BeginUnusedPeriod_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);


	else if (strcmp(name, "SchedulerWorker::EndUnusedPeriod") == 0 )
		tracepoint(chrome, SchedulerWorker_EndUnusedPeriod, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::EndUnusedPeriod_END") == 0 )
		tracepoint(chrome, SchedulerWorker_EndUnusedPeriod_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::GetLastUsedTime") == 0 )
		tracepoint(chrome, SchedulerWorker_GetLastUsedTime, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SchedulerWorker::GetLastUsedTime_END") == 0 )
		tracepoint(chrome, SchedulerWorker_GetLastUsedTime_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::Push") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_Push, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::Push_END") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_Push_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);


	else if (strcmp(name, "PriorityQueue::Transaction::PeekSortKey") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_PeekSortKey, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::PeekSortKey_END") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_PeekSortKey_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::PopSequence") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_PopSequence, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::PopSequence_END") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_PopSequence_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::IsEmpty") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_IsEmpty, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::IsEmpty_END") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_IsEmpty_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::Size") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_Size, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "PriorityQueue::Transaction::Size_END") == 0 )
		tracepoint(chrome, PriorityQueue_Transaction_Size_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::BindToCurrentThread") == 0 )
		tracepoint(chrome, SequenceManagerImpl_BindToCurrentThread, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::BindToCurrentThread_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_BindToCurrentThread_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::CompleteInitializationOnBoundThread") == 0 )
		tracepoint(chrome, SequenceManagerImpl_CompleteInitializationOnBoundThread, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::CompleteInitializationOnBoundThread_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_CompleteInitializationOnBoundThread_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);


	else if (strcmp(name, "SequenceManagerImpl::AddToIncomingImmediateWorkList") == 0 )
		tracepoint(chrome, SequenceManagerImpl_AddToIncomingImmediateWorkList, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::AddToIncomingImmediateWorkList_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_AddToIncomingImmediateWorkList_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);


	else if (strcmp(name, "SequenceManagerImpl::RemoveFromIncomingImmediateWorkList") == 0 )
		tracepoint(chrome, SequenceManagerImpl_RemoveFromIncomingImmediateWorkList, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::RemoveFromIncomingImmediateWorkList_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_RemoveFromIncomingImmediateWorkList_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::OnBeginNestedRunLoop") == 0 )
		tracepoint(chrome, SequenceManagerImpl_OnBeginNestedRunLoop, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::OnBeginNestedRunLoop_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_OnBeginNestedRunLoop_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::OnExitNestedRunLoop") == 0 )
		tracepoint(chrome, SequenceManagerImpl_OnExitNestedRunLoop, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::OnExitNestedRunLoop_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_OnExitNestedRunLoop_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::OnQueueHasIncomingImmediateWork") == 0 )
		tracepoint(chrome, SequenceManagerImpl_OnQueueHasIncomingImmediateWork, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::OnQueueHasIncomingImmediateWork_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_OnQueueHasIncomingImmediateWork_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::MaybeScheduleImmediateWork") == 0 )
		tracepoint(chrome, SequenceManagerImpl_MaybeScheduleImmediateWork, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "SequenceManagerImpl::MaybeScheduleImmediateWork_END") == 0 )
		tracepoint(chrome, SequenceManagerImpl_MaybeScheduleImmediateWork_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::WillPostTask") == 0 )
		tracepoint(chrome, TaskTracker_WillPostTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::WillPostTask_END") == 0 )
		tracepoint(chrome, TaskTracker_WillPostTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::RunAndPopNextTask") == 0 )
		tracepoint(chrome, TaskTracker_RunAndPopNextTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::RunAndPopNextTask_END") == 0 )
		tracepoint(chrome, TaskTracker_RunAndPopNextTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::BeforeRunTask") == 0 )
		tracepoint(chrome, TaskTracker_BeforeRunTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::BeforeRunTask_END") == 0 )
		tracepoint(chrome, TaskTracker_BeforeRunTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::AfterRunTask") == 0 )
		tracepoint(chrome, TaskTracker_AfterRunTask, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);

	else if (strcmp(name, "TaskTracker::AfterRunTask_END") == 0 )
		tracepoint(chrome, TaskTracker_AfterRunTask_END, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);


	else if (strcmp(name, "CoordinatorProxy::StopAndFlush") == 0 )
		tracepoint(chrome, CoordinatorProxy_StopAndFlush, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);


	else
	    tracepoint(chrome, jsontolttng, thread_id, phase, category_group_enabled, name, scope, id, bind_id, num_args, arg_types, arg_values);
}
