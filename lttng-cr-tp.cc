/*
 * lttng-cr-tp.cc
 *
 *  Created on: Dec 3, 2018
 *      Author: azhari
 *      The instrumented application dlopens tracepoint provider package shared object at runtime.
 */


#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE

#include "lttng-cr-tp.h"

void generic0(const char* name, const char *phase){
    tracepoint(chrome, generic0, name, phase);
}

void generic1(const char* name, const char *phase, const char *arg1, const char *val1 ){
    tracepoint(chrome, generic1, name, phase, arg1, val1);
}

void generic2(const char* name, const char *phase, const char *arg1, const char *val1, const char *arg2, const char *val2){
    tracepoint(chrome, generic2, name, phase, arg1, val1, arg2, val2);
}

void generic3(const char* name, const char *phase, const char *arg1, const char *val1, const char *arg2, const char *val2, const char *arg3, const char *val3){
    tracepoint(chrome, generic3, name, phase, arg1, val1, arg2, val2, arg3, val3);
}
/*
void trpoint_jsontolttng(char* phase,
    const unsigned char category_group_enabled,
    const char* name,
    const char* scope,
    unsigned long long id,
    int num_args,
    const char* const arg_names,
    const unsigned char arg_types,
    const unsigned long long arg_values,
    unsigned int flags) {

    tracepoint(chrome, jsontolttng, phase, category_group_enabled, name, scope, id, num_args, arg_names, arg_types, arg_values, flags);
}
*/
