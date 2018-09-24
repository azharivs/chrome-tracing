/*
 * chrome-sch-worker-tp.cc
 *
 *  Created on: Jun 7, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */


#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include "chrome-sch-worker-tp_posttask.h"

void PostTask(char *function_name, char *file_name, int line_number){
    tracepoint(chrome2, PostTask, function_name, file_name, line_number);
}

void PostDelayedTask(char *function_name, char *file_name, int line_number, long int delayInNanoseconds){
    tracepoint(chrome2, PostDelayedTask, function_name, file_name, line_number, delayInNanoseconds);
}


void PostTaskAndReply(char *function_name, char *file_name, int line_number){
    tracepoint(chrome2, PostTaskAndReply, function_name, file_name, line_number);
}

void PostTaskWithTraits(char *function_name, char *file_name, int line_number, char *priority){
    tracepoint(chrome2, PostTaskWithTraits, function_name, file_name, line_number, priority);
}

void PostDelayedTaskWithTraits(char *function_name, char *file_name, int line_number, char *priority, long int delayInNanoseconds){
    tracepoint(chrome2, PostDelayedTaskWithTraits, function_name, file_name, line_number, priority, delayInNanoseconds);
}

void PostTaskWithTraitsAndReply(char *function_name, char *file_name, int line_number, char *priority){
    tracepoint(chrome2, PostTaskWithTraitsAndReply, function_name, file_name, line_number, priority);
}

void CreateTaskRunnerWithTraits(char *priority){
    tracepoint(chrome2, CreateTaskRunnerWithTraits, priority);
}

void CreateSequencedTaskRunnerWithTraits(char *priority){
    tracepoint(chrome2, CreateSequencedTaskRunnerWithTraits, priority);
}

void CreateSingleThreadTaskRunnerWithTraits(char *priority){
    tracepoint(chrome2, CreateSingleThreadTaskRunnerWithTraits, priority);
}

void CreateCOMSTATaskRunnerWithTraits(char *priority){
    tracepoint(chrome2, CreateCOMSTATaskRunnerWithTraits, priority);
}
