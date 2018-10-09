/*
 * chrome-sch-worker-tp.cc
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */


#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include "chrome-sch-worker-tp_pendingtasks.h"

void TaskQueueImpl_OnTaskStarted(long int taskid, char* TaskName, int task_type, char* function_name, char* file_name, int line_number){
    tracepoint(chrome3, TaskQueueImpl_OnTaskStarted, taskid, TaskName, task_type, function_name, file_name, line_number);
}

void TaskQueueImpl_OnTaskCompleted(long int taskid, char* TaskName, int task_type, char* function_name, char* file_name, int line_number){
    tracepoint(chrome3, TaskQueueImpl_OnTaskCompleted, taskid, TaskName, task_type, function_name, file_name, line_number);
}
