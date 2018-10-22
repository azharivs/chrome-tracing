/*
 * chrome-sch-worker-tp.h
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER chrome6

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./chrome-sch-worker-tp_gpu.h"

#if !defined(_CHROME_SCH_WORKER_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CHROME_SCH_WORKER_TP_H

#include <lttng/tracepoint.h>

//used to simply say which function is being executed
TRACEPOINT_EVENT(
    chrome6,
    GpuChannelHost_Send_StartWrapUnique,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    BelongsToCurrentThread,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    message_set_unblock,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    message_is_sync,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    io_thread_PostTask,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    io_thread_PostTask_END,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    Startbase_WaitableEvent_done_event,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    IPC_PendingSyncMsg_pending_sync,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    io_thread_PostTask2,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    pending_sync_done_event_Wait,
    TP_ARGS(
        char*, GpuChannelHost_Send
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send)
    )
)

TRACEPOINT_EVENT(
    chrome6,
    GpuChannelHost_Send_END_pending_sync_done_event_Wait_END,
    TP_ARGS(
        char*, GpuChannelHost_Send_END
    ),
    TP_FIELDS(
        ctf_string(arg, GpuChannelHost_Send_END)
    )
)

#endif /* _CHROME_SCH_WORKER_TP_H */

#include <lttng/tracepoint-event.h>
