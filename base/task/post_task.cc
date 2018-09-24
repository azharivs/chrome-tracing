// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/*sva begin*/
#define TRACEPOINT_DEFINE
#define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#include "chrome-sch-worker-tp_posttask.h"
//#include <dlfcn.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
/*sva end*/

#include "base/task/post_task.h"

#include <utility>
#include <iostream>

#include "base/logging.h"
#include "base/task/scoped_set_task_priority_for_current_thread.h"
#include "base/task/task_scheduler/task_scheduler.h"
#include "base/threading/post_task_and_reply_impl.h"
#include "base/trace_event/trace_event.h"
//#include "components/favicon/content/content_favicon_driver.h"
//#include "content/browser/frame_host/navigation_controller_impl.h"

static void * tppHandle2 = NULL;//sva
static int soLoaded2 = 0;//sva

namespace base {

namespace {

class PostTaskAndReplyWithTraitsTaskRunner
    : public internal::PostTaskAndReplyImpl {
 public:
  explicit PostTaskAndReplyWithTraitsTaskRunner(const TaskTraits& traits)
      : traits_(traits) {}


 private:
  bool PostTask(const Location& from_here, OnceClosure task) override {
    PostTaskWithTraits(from_here, traits_, std::move(task));
    return true;
  }

  const TaskTraits traits_;
};

// Returns TaskTraits based on |traits|. If TaskPriority hasn't been set
// explicitly in |traits|, the returned TaskTraits have the current
// TaskPriority.
TaskTraits GetTaskTraitsWithExplicitPriority(const TaskTraits& traits) {
  if (traits.priority_set_explicitly())
    return traits;
  return TaskTraits::Override(traits,
                              {internal::GetTaskPriorityForCurrentThread()});
}

}  // namespace

void PostTask(const Location& from_here, OnceClosure task) {

// Majid start


void (*tp_ptr)(const char*, const char*, int);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z8PostTaskPcS_i");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) from_here.function_name(), (const char*) from_here.file_name(), (int) from_here.line_number());


// Majid end
  printf("------------------------------PostTask---------------------------------\nFunction name: %s \nFile name: %s \nLine number: %d \n\n\n", from_here.function_name(), from_here.file_name(), from_here.line_number());

  TRACE_EVENT0("dorsal", "PostTask");
  PostDelayedTask(from_here, std::move(task), TimeDelta());
  TRACE_EVENT0("dorsal", "PostTask_END");
}

void PostDelayedTask(const Location& from_here,
                     OnceClosure task,
                     TimeDelta delay) {
// Majid start


void (*tp_ptr)(const char*, const char*, int, long int);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z15PostDelayedTaskPcS_il");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) from_here.function_name(), (const char*) from_here.file_name(), (int) from_here.line_number(), (long int) delay.InNanoseconds());


// Majid end

  printf("------------------------------PostDelayedTask---------------------------------\nFunction name: %s \nFile name: %s \nLine number: %d \nTime Delta: %ld \n\n\n", from_here.function_name(), from_here.file_name(), from_here.line_number(), delay.InNanoseconds());

  TRACE_EVENT0("dorsal", "PostDelayedTask");
  PostDelayedTaskWithTraits(from_here, TaskTraits(), std::move(task), delay);
  TRACE_EVENT0("dorsal", "PostDelayedTask_END");
}

void PostTaskAndReply(const Location& from_here,
                      OnceClosure task,
                      OnceClosure reply) {
// Majid start


void (*tp_ptr)(const char*, const char*, int);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z16PostTaskAndReplyPcS_i");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) from_here.function_name(), (const char*) from_here.file_name(), (int) from_here.line_number());


// Majid end

  printf("------------------------------PostTaskAndReply---------------------------------\nFunction name: %s \nFile name: %s \nLine number: %d \n\n\n", from_here.function_name(), from_here.file_name(), from_here.line_number());
  TRACE_EVENT0("dorsal", "PostTaskAndReply");
  PostTaskWithTraitsAndReply(from_here, TaskTraits(), std::move(task),
                             std::move(reply));
  TRACE_EVENT0("dorsal", "PostTaskAndReply_END");
}

void PostTaskWithTraits(const Location& from_here,
                        const TaskTraits& traits,
                        OnceClosure task) {
// Majid start


void (*tp_ptr)(const char*, const char*, int, const char*);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z18PostTaskWithTraitsPcS_iS_");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) from_here.function_name(), (const char*) from_here.file_name(), (int) from_here.line_number(), (const char*) base::TaskPriorityToString(traits.priority()));


// Majid end

  printf("------------------------------PostTaskWithTraits---------------------------------\nFunction name: %s \nFile name: %s \nLine number: %d \nTask Priority: %s \n\n\n", from_here.function_name(), from_here.file_name(), from_here.line_number(), base::TaskPriorityToString(traits.priority()));
  TRACE_EVENT0("dorsal", "PostTaskWithTraits");
  PostDelayedTaskWithTraits(from_here, traits, std::move(task), TimeDelta());
  TRACE_EVENT0("dorsal", "PostTaskWithTraits_END");
}

void PostDelayedTaskWithTraits(const Location& from_here,
                               const TaskTraits& traits,
                               OnceClosure task,
                               TimeDelta delay) {
// Majid start


void (*tp_ptr)(const char*, const char*, int, const char*, long int);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z25PostDelayedTaskWithTraitsPcS_iS_l");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) from_here.function_name(), (const char*) from_here.file_name(), (int) from_here.line_number(), (const char*) base::TaskPriorityToString(traits.priority()), (long int) delay.InNanoseconds());


// Majid end

  printf("------------------------------PostDelayedTaskWithTraits---------------------------------\nFunction name: %s \nFile name: %s \nLine number: %d \nTask Priority: %s \nTime Delta: %ld \n\n\n", from_here.function_name(), from_here.file_name(), from_here.line_number(), base::TaskPriorityToString(traits.priority()), delay.InNanoseconds());
  TRACE_EVENT0("dorsal", "PostDelayedTaskWithTraits");
  DCHECK(TaskScheduler::GetInstance())
      << "Ref. Prerequisite section of post_task.h.\n\n"
         "Hint: if this is in a unit test, you're likely merely missing a "
         "base::test::ScopedTaskEnvironment member in your fixture.\n";
  TaskScheduler::GetInstance()->PostDelayedTaskWithTraits(
      from_here, GetTaskTraitsWithExplicitPriority(traits), std::move(task),
      std::move(delay));
  TRACE_EVENT0("dorsal", "PostDelayedTaskWithTraits_END");
}

void PostTaskWithTraitsAndReply(const Location& from_here,
                                const TaskTraits& traits,
                                OnceClosure task,
                                OnceClosure reply) {
// Majid start


void (*tp_ptr)(const char*, const char*, int, const char*);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z26PostTaskWithTraitsAndReplyPcS_iS_");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) from_here.function_name(), (const char*) from_here.file_name(), (int) from_here.line_number(), (const char*) base::TaskPriorityToString(traits.priority()));


// Majid end

  printf("------------------------------PostTaskWithTraitsAndReply---------------------------------\nFunction name: %s \nFile name: %s \nLine number: %d \nTask Priority: %s \n\n\n", from_here.function_name(), from_here.file_name(), from_here.line_number(), base::TaskPriorityToString(traits.priority()));

  //TRACE_EVENT2("dorsal", "taskscheduler", "traits", (task).posted_from.file_name(), "reply", (task).posted_from.file_name()); 
  TRACE_EVENT0("dorsal", "PostTaskWithTraitsAndReply");
  PostTaskAndReplyWithTraitsTaskRunner(traits).PostTaskAndReply(
      from_here, std::move(task), std::move(reply));
  TRACE_EVENT0("dorsal", "PostTaskWithTraitsAndReply_END");
}

scoped_refptr<TaskRunner> CreateTaskRunnerWithTraits(const TaskTraits& traits) {
// Majid start


void (*tp_ptr)(const char*);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z26CreateTaskRunnerWithTraitsPc");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) base::TaskPriorityToString(traits.priority()));


// Majid end


  printf("------------------------------CreateTaskRunnerWithTraits---------------------------------\nTask Priority: %s \n\n\n", base::TaskPriorityToString(traits.priority()));
  TRACE_EVENT0("dorsal", "CreateTaskRunnerWithTraits");
  DCHECK(TaskScheduler::GetInstance())
      << "Ref. Prerequisite section of post_task.h.\n\n"
         "Hint: if this is in a unit test, you're likely merely missing a "
         "base::test::ScopedTaskEnvironment member in your fixture.\n";
  TRACE_EVENT0("dorsal", "CreateTaskRunnerWithTraits_END");
  return TaskScheduler::GetInstance()->CreateTaskRunnerWithTraits(
      GetTaskTraitsWithExplicitPriority(traits));
}

scoped_refptr<SequencedTaskRunner> CreateSequencedTaskRunnerWithTraits(
    const TaskTraits& traits) {
// Majid start


void (*tp_ptr)(const char*);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z35CreateSequencedTaskRunnerWithTraitsPc");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) base::TaskPriorityToString(traits.priority()));


// Majid end

  printf("------------------------------CreateSequencedTaskRunnerWithTraits---------------------------------\nTask Priority: %s \n\n\n", base::TaskPriorityToString(traits.priority()));
  TRACE_EVENT0("dorsal", "CreateSequencedTaskRunnerWithTraits");
  DCHECK(TaskScheduler::GetInstance())
      << "Ref. Prerequisite section of post_task.h.\n\n"
         "Hint: if this is in a unit test, you're likely merely missing a "
         "base::test::ScopedTaskEnvironment member in your fixture.\n";
  TRACE_EVENT0("dorsal", "CreateSequencedTaskRunnerWithTraits_END");
  return TaskScheduler::GetInstance()->CreateSequencedTaskRunnerWithTraits(
      GetTaskTraitsWithExplicitPriority(traits));
}

scoped_refptr<SingleThreadTaskRunner> CreateSingleThreadTaskRunnerWithTraits(
    const TaskTraits& traits,
    SingleThreadTaskRunnerThreadMode thread_mode) {
// Majid start


void (*tp_ptr)(const char*);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z38CreateSingleThreadTaskRunnerWithTraitsPc");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) base::TaskPriorityToString(traits.priority()));


// Majid end

  printf("------------------------------CreateSingleThreadTaskRunnerWithTraits---------------------------------\nTask Priority: %s \nThread_mode: %d \n\n\n", base::TaskPriorityToString(traits.priority()), thread_mode);
  TRACE_EVENT0("dorsal", "CreateSingleThreadTaskRunnerWithTraits");
  DCHECK(TaskScheduler::GetInstance())
      << "Ref. Prerequisite section of post_task.h.\n\n"
         "Hint: if this is in a unit test, you're likely merely missing a "
         "base::test::ScopedTaskEnvironment member in your fixture.\n";
  TRACE_EVENT0("dorsal", "CreateSingleThreadTaskRunnerWithTraits_END");
  return TaskScheduler::GetInstance()->CreateSingleThreadTaskRunnerWithTraits(
      GetTaskTraitsWithExplicitPriority(traits), thread_mode);
}

#if defined(OS_WIN)
scoped_refptr<SingleThreadTaskRunner> CreateCOMSTATaskRunnerWithTraits(
    const TaskTraits& traits,
    SingleThreadTaskRunnerThreadMode thread_mode) {
// Majid start


void (*tp_ptr)(const char*);
        char *error;

        if (!soLoaded2){
            tppHandle2 = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle2) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded2 = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle2, "_Z32CreateCOMSTATaskRunnerWithTraitsPc");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((const char*) base::TaskPriorityToString(traits.priority()));


// Majid end


  printf("------------------------------CreateCOMSTATaskRunnerWithTraits---------------------------------\nTask Priority: %s \nThread_mode: %d \n\n\n", base::TaskPriorityToString(traits.priority()), thread_mode);
  TRACE_EVENT0("dorsal", "CreateCOMSTATaskRunnerWithTraits");
  DCHECK(TaskScheduler::GetInstance())
      << "Ref. Prerequisite section of post_task.h.\n\n"
         "Hint: if this is in a unit test, you're likely merely missing a "
         "base::test::ScopedTaskEnvironment member in your fixture.\n";
  TRACE_EVENT0("dorsal", "CreateCOMSTATaskRunnerWithTraits_END");
  return TaskScheduler::GetInstance()->CreateCOMSTATaskRunnerWithTraits(
      GetTaskTraitsWithExplicitPriority(traits), thread_mode);
}
#endif  // defined(OS_WIN)

}  // namespace base
