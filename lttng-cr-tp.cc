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

void generic(const char* name, const char *phase){
    tracepoint(chrome, generic, name, phase);
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
