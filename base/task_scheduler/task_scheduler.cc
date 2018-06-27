// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/*sva begin*/
#define TRACEPOINT_DEFINE
#define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#include "task-scheduler-tp.h"
//#include <dlfcn.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
/*sva end*/

#include "base/task_scheduler/task_scheduler.h"

#include <algorithm>
#include <iostream>

#include "base/logging.h"
#include "base/memory/ptr_util.h"
#include "base/sys_info.h"
#include "base/task_scheduler/scheduler_worker_pool_params.h"
#include "base/task_scheduler/task_scheduler_impl.h"
#include "base/threading/platform_thread.h"
#include "base/time/time.h"

static void * tppHandle = NULL;//sva
static int soLoaded = 0;//sva

namespace base {

namespace {

// |g_task_scheduler| is intentionally leaked on shutdown.
TaskScheduler* g_task_scheduler = nullptr;

}  // namespace

TaskScheduler::InitParams::InitParams(
    const SchedulerWorkerPoolParams& background_worker_pool_params_in,
    const SchedulerWorkerPoolParams& background_blocking_worker_pool_params_in,
    const SchedulerWorkerPoolParams& foreground_worker_pool_params_in,
    const SchedulerWorkerPoolParams& foreground_blocking_worker_pool_params_in,
    SharedWorkerPoolEnvironment shared_worker_pool_environment_in)
    : background_worker_pool_params(background_worker_pool_params_in),
      background_blocking_worker_pool_params(
          background_blocking_worker_pool_params_in),
      foreground_worker_pool_params(foreground_worker_pool_params_in),
      foreground_blocking_worker_pool_params(
          foreground_blocking_worker_pool_params_in),
      shared_worker_pool_environment(shared_worker_pool_environment_in) {
/*sva begin*/

        void (*tp_ptr)(int,char *);
        char *error;

        if (!soLoaded){
            tppHandle = dlopen("/home/iustack/libtask-scheduler-tp.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle) {
                 fprintf(stderr, "0: Upon dlopen: %s\n", dlerror());
            }
            else {     
                //printf("--- 0: TRACEPOINT REGISTERED\n");
                //getchar();
                soLoaded = 1;
            }
        }

        dlerror();   

        *(void **) (&tp_ptr) = dlsym(tppHandle, "_Z17trpoint_function1iPc");
    
        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "0: Upon dlsym: %s\n", error);
        }
	
	//pid_t pid = getpid();
	pid_t tid = syscall(SYS_gettid);
        (*tp_ptr)((int) tid, (char *) "TaskScheduler::InitParams::InitParams.");
        //std::cout << "....." << (int) tid << ": dlsym\n";


//        tracepoint(hello_world, my_first_tracepoint, 0, (char *) "TaskScheduler::InitParams::InitParams.");
/*sva end*/      
    }

TaskScheduler::InitParams::~InitParams() = default;

#if !defined(OS_NACL)
// static
void TaskScheduler::CreateAndStartWithDefaultParams(StringPiece name) {
/*sva begin*/
    void (*tp_ptr)(int,char *);
    char *error;
    
    if (!soLoaded){
        tppHandle = dlopen("/home/iustack/libtask-scheduler-tp.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
        if (!tppHandle) {
             fprintf(stderr, "1: Upon dlopen: %s\n", dlerror());
        }
        else {     
            //printf("--- 1: TRACEPOINT REGISTERED\n");
            //getchar();
            soLoaded = 1;
        }
    }

    //std::cout << "..... 1: dlsym\n";
    dlerror();   

    *(void **) (&tp_ptr) = dlsym(tppHandle, "_Z17trpoint_function1iPc");

    if ((error = dlerror()) != NULL)  {
         fprintf(stderr, "1: Upon dlsym: %s\n", error);
    }

    pid_t tid = syscall(SYS_gettid);
    (*tp_ptr)((int) tid, (char *) "TaskScheduler::CreateAndStartWithDefaultParams.");
    
//        tracepoint(hello_world, my_first_tracepoint, 1, (char *) "TaskScheduler::CreateAndStartWithDefaultParams.");    
/*sva end*/
  Create(name);
  GetInstance()->StartWithDefaultParams();
}

void TaskScheduler::StartWithDefaultParams() {
  // Values were chosen so that:
  // * There are few background threads.
  // * Background threads never outnumber foreground threads.
  // * The system is utilized maximally by foreground threads.
  // * The main thread is assumed to be busy, cap foreground workers at
  //   |num_cores - 1|.
  const int num_cores = SysInfo::NumberOfProcessors();
  constexpr int kBackgroundMaxThreads = 1;
  constexpr int kBackgroundBlockingMaxThreads = 2;
  const int kForegroundMaxThreads = std::max(1, num_cores - 1);
  const int kForegroundBlockingMaxThreads = std::max(2, num_cores - 1);

  constexpr TimeDelta kSuggestedReclaimTime = TimeDelta::FromSeconds(30);

  Start({{kBackgroundMaxThreads, kSuggestedReclaimTime},
         {kBackgroundBlockingMaxThreads, kSuggestedReclaimTime},
         {kForegroundMaxThreads, kSuggestedReclaimTime},
         {kForegroundBlockingMaxThreads, kSuggestedReclaimTime}});
/*sva begin*/
    void (*tp_ptr)(int,char *);
    char *error;
    
    if (!soLoaded){
        tppHandle = dlopen("/home/iustack/libtask-scheduler-tp.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
        if (!tppHandle) {
             fprintf(stderr, "2: Upon dlopen: %s\n", dlerror());
        }
        else {     
            //printf("--- 2: TRACEPOINT REGISTERED\n");
            //getchar();
            soLoaded = 1;
        }
    }

    //std::cout << "..... 2: dlsym\n";
    dlerror();   

    *(void **) (&tp_ptr) = dlsym(tppHandle, "_Z17trpoint_function1iPc");

    if ((error = dlerror()) != NULL)  {
         fprintf(stderr, "2: Upon dlsym: %s\n", error);
    }

    pid_t tid = syscall(SYS_gettid);
    (*tp_ptr)((int) tid, (char *) "TaskScheduler::StartWithDefaultParams.");
    
    //    tracepoint(hello_world, my_first_tracepoint, 2, (char *) "TaskScheduler::StartWithDefaultParams.");        
/*sva end*/
         
}
#endif  // !defined(OS_NACL)

void TaskScheduler::Create(StringPiece name) {
  SetInstance(std::make_unique<internal::TaskSchedulerImpl>(name));
/*sva begin*/
    void (*tp_ptr)(int,char *);
    char *error;
    
    if (!soLoaded){
        tppHandle = dlopen("/home/iustack/libtask-scheduler-tp.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
        if (!tppHandle) {
             fprintf(stderr, "3: Upon dlopen: %s\n", dlerror());
        }
        else {     
            //printf("--- 3: TRACEPOINT REGISTERED\n");
            //getchar();
            soLoaded = 1;
        }
    }

    //std::cout << "..... 3: dlsym\n";
    dlerror();   

    *(void **) (&tp_ptr) = dlsym(tppHandle, "_Z17trpoint_function1iPc");

    if ((error = dlerror()) != NULL)  {
         fprintf(stderr, "3: Upon dlsym: %s\n", error);
    }

    dlerror();   
    

    char cstr[100]="";
    name.copy(cstr, 100, 0); 
    pid_t tid = syscall(SYS_gettid);
    (*tp_ptr)((int) tid, (char *) cstr);

//        tracepoint(hello_world, my_first_tracepoint, 3, (char *) "TaskScheduler::Create.");        
/*sva end*/
  
}

// static
void TaskScheduler::SetInstance(std::unique_ptr<TaskScheduler> task_scheduler) {
  delete g_task_scheduler;
  g_task_scheduler = task_scheduler.release();
}

// static
TaskScheduler* TaskScheduler::GetInstance() {
  return g_task_scheduler;
}

}  // namespace base
