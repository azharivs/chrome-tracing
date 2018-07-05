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


void trpoint_jsontolttng(char* phase
    /*const char *name,
    const char *scope,
    unsigned long long id,
    int num_args,
    unsigned int flags*/) {

    tracepoint(chrome, jsontolttng, phase/*, name, scope, id, num_args, flags*/);
}
