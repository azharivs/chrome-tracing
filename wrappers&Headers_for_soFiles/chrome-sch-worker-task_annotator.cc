/*
 * chrome-sch-worker-tp.cc
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */


#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include "chrome-sch-worker-task_annotator.h"

void TaskAnnotator_WillQueueTask(long int taskid, char* function_name, char* file_name, int line_number, char* queue_function){
    tracepoint(chrome4, TaskAnnotator_WillQueueTask, taskid, function_name, file_name, line_number, queue_function);
}

void TaskAnnotator_RunTask(long int taskid, char* function_name, char* file_name, int line_number, char* queue_function){
    tracepoint(chrome4, TaskAnnotator_RunTask, taskid, function_name, file_name, line_number, queue_function);
}

void TaskAnnotator_Task_Completed(long int taskid, char* Task_Completed){
    tracepoint(chrome4, TaskAnnotator_Task_Completed, taskid, Task_Completed);
}
