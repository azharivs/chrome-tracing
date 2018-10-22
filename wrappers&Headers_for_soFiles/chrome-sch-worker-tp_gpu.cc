/*
 * chrome-sch-worker-tp.cc
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */


#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include "chrome-sch-worker-tp_gpu.h"

void GpuChannelHost_Send_StartWrapUnique(char *GpuChannelHost_Send){
    tracepoint(chrome6, GpuChannelHost_Send_StartWrapUnique, GpuChannelHost_Send);
}

void BelongsToCurrentThread(char *GpuChannelHost_Send){
    tracepoint(chrome6, BelongsToCurrentThread, GpuChannelHost_Send);
}

void message_set_unblock(char *GpuChannelHost_Send){
    tracepoint(chrome6, message_set_unblock, GpuChannelHost_Send);
}

void message_is_sync(char *GpuChannelHost_Send){
    tracepoint(chrome6, message_is_sync, GpuChannelHost_Send);
}

void io_thread_PostTask(char *GpuChannelHost_Send){
    tracepoint(chrome6, io_thread_PostTask, GpuChannelHost_Send);
}

void io_thread_PostTask_END(char *GpuChannelHost_Send){
    tracepoint(chrome6, io_thread_PostTask_END, GpuChannelHost_Send);
}

void Startbase_WaitableEvent_done_event(char *GpuChannelHost_Send){
    tracepoint(chrome6, Startbase_WaitableEvent_done_event, GpuChannelHost_Send);
}

void IPC_PendingSyncMsg_pending_sync(char *GpuChannelHost_Send){
    tracepoint(chrome6, IPC_PendingSyncMsg_pending_sync, GpuChannelHost_Send);
}

void io_thread_PostTask2(char *GpuChannelHost_Send){
    tracepoint(chrome6, io_thread_PostTask2, GpuChannelHost_Send);
}

void pending_sync_done_event_Wait(char *GpuChannelHost_Send){
    tracepoint(chrome6, pending_sync_done_event_Wait, GpuChannelHost_Send);
}

void GpuChannelHost_Send_END_pending_sync_done_event_Wait_END(char *GpuChannelHost_Send_END){
    tracepoint(chrome6, GpuChannelHost_Send_END_pending_sync_done_event_Wait_END, GpuChannelHost_Send_END);
}
