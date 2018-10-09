/*
 * chrome-sch-worker-tp.cc
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */


#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include "chrome-sch-worker-tp_taketask.h"

void TaskTracker_WillPostTask(long int taskid, /*char* TaskName, int task_type,*/ char* function_name, char* file_name, int line_number){
    tracepoint(chrome5, TaskTracker_WillPostTask, taskid, /*TaskName, task_type,*/ function_name, file_name, line_number);
}

void TaskTracker_WillScheduleSequence(long int taskid, /*char* TaskName, int task_type,*/ char* function_name, char* file_name, int line_number){
    tracepoint(chrome5, TaskTracker_WillScheduleSequence, taskid, /*TaskName, task_type,*/ function_name, file_name, line_number);
}


void TaskTracker_RunAndPopNextTask(long int taskid, /*char* TaskName, int task_type,*/ char* function_name, char* file_name, int line_number){
    tracepoint(chrome5, TaskTracker_RunAndPopNextTask, taskid, /*TaskName, task_type,*/ function_name, file_name, line_number);
}

void TaskTracker_WillRun(long int taskid, /*char* TaskName, int task_type,*/ char* function_name, char* file_name, int line_number){
    tracepoint(chrome5, TaskTracker_WillRun, taskid, /*TaskName, task_type,*/ function_name, file_name, line_number);
}

void TaskTracker_WillSkip(long int taskid, /*char* TaskName, int task_type,*/ char* function_name, char* file_name, int line_number){
    tracepoint(chrome5, TaskTracker_WillSkip, taskid, /*TaskName, task_type,*/ function_name, file_name, line_number);
}

void TaskTracker_RunOrSkipTask(long int taskid, /*char* TaskName, int task_type,*/ char* function_name, char* file_name, int line_number){
    tracepoint(chrome5, TaskTracker_RunOrSkipTask, taskid, /*TaskName, task_type,*/ function_name, file_name, line_number);
}
