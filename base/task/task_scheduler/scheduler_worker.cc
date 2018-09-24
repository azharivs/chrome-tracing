// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


/*sva begin
#define TRACEPOINT_DEFINE
#define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#include "chrome-sch-worker-tp.h"
//#include <dlfcn.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
sva end*/



#include "base/task/task_scheduler/scheduler_worker.h"

#include <stddef.h>

#include <utility>

#include "base/compiler_specific.h"
#include "base/debug/alias.h"
#include "base/logging.h"
#include "base/task/task_scheduler/environment_config.h"
#include "base/task/task_scheduler/scheduler_worker_observer.h"
#include "base/task/task_scheduler/task_tracker.h"
#include "base/trace_event/trace_event.h"
#include "services/tracing/tracing_service.h"
#include "services/tracing/agent_registry.h"
#include "services/tracing/public/mojom/tracing.mojom.h"

#if defined(OS_MACOSX)
#include "base/mac/scoped_nsautorelease_pool.h"
#elif defined(OS_WIN)
#include "base/win/com_init_check_hook.h"
#include "base/win/scoped_com_initializer.h"
#endif

//using namespace tracing;
//using namespace mojom;
/*
static void * tppHandle = NULL;//sva
static int soLoaded = 0;//sva
*/

namespace base {
namespace internal {

//AgentRegistryRequestValidator amad;
 
//tracing amad;
//mojom amad2;

int th[50];
int insertion = 0;

void SchedulerWorker::Delegate::WaitForWork(WaitableEvent* wake_up_event) {
  TRACE_EVENT0("dorsal", "SchedulerWorker::Delegate::WaitForWork");
/*
if   {
// Majid start


void (*tp_ptr)(int, char &, const unsigned char *, const char*, const char*, unsigned long long, unsigned long long, int, char const*, const unsigned char*, unsigned long long);
        char *error;

        if (!soLoaded){
            tppHandle = dlopen("/home/majid/Documents/chromium/src/lib2.so", RTLD_NOW);// | RTLD_GLOBAL | RTLD_NODELETE);
            if (!tppHandle) {
                 fprintf(stderr, "00: Upon dlopen: %s\n", dlerror());
            }
            else {
                soLoaded = 1;
            }
        }

        dlerror();

        *(void **) (&tp_ptr) = dlsym(tppHandle, "_Z19trpoint_jsontolttngiPcS_S_S_yyiS_y");

        if ((error = dlerror()) != NULL)  {
             fprintf(stderr, "00: Upon dlsym: %s\n", error);
        }

       
        (*tp_ptr)((int) thread_id, (char &) phase, (const unsigned char*) category_group_enabled, (const char*) name, (const char*) scope, (unsigned long long) id, (unsigned long long) bind_id, (int) num_args, (char const*) arg_names, (const unsigned char*) arg_types, (unsigned long long) arg_values);


// Majid end

}
*/
/*mojo::Message msg;

	if (amad.Accept(msg)){
		//thread_id = base::SimpleThread::tid();
		int found = 0;
		for (int counter = 0 ; counter < 50 ; counter++)
		{
		    if (th[counter] == base::SimpleThread::tid()) 
		    {
			   found = 1;
			   break;
		    }
		}
		if (found == 0) {
			TRACE_EVENT0("dorsal", "StartofThread");
			th[insertion] = thread_id ;
			insertion += 1;
			}
		found = 0;
	}*/
  DCHECK(wake_up_event);
  const TimeDelta sleep_time = GetSleepTimeout();
  if (sleep_time.is_max()) {
    // Calling TimedWait with TimeDelta::Max is not recommended per
    // http://crbug.com/465948.
    wake_up_event->Wait();
  } else {
    wake_up_event->TimedWait(sleep_time);
  }
  TRACE_EVENT0("dorsal", "SchedulerWorker::Delegate::WaitForWork_END");
}

SchedulerWorker::SchedulerWorker(
    ThreadPriority priority_hint,
    std::unique_ptr<Delegate> delegate,
    TrackedRef<TaskTracker> task_tracker,
    const SchedulerLock* predecessor_lock,
    SchedulerBackwardCompatibility backward_compatibility)
    : thread_lock_(predecessor_lock),
      delegate_(std::move(delegate)),
      task_tracker_(std::move(task_tracker)),
      priority_hint_(priority_hint),
      current_thread_priority_(GetDesiredThreadPriority())
#if defined(OS_WIN) && !defined(COM_INIT_CHECK_HOOK_ENABLED)
      ,
      backward_compatibility_(backward_compatibility)
#endif
{
  DCHECK(delegate_);
  DCHECK(task_tracker_);
  DCHECK(CanUseBackgroundPriorityForSchedulerWorker() ||
         priority_hint_ != ThreadPriority::BACKGROUND);
}

bool SchedulerWorker::Start(
    SchedulerWorkerObserver* scheduler_worker_observer) {
  TRACE_EVENT0("dorsal", "SchedulerWorker::Start");
  AutoSchedulerLock auto_lock(thread_lock_);
  DCHECK(thread_handle_.is_null());

  if (should_exit_.IsSet())
    return true;

  DCHECK(!scheduler_worker_observer_);
  scheduler_worker_observer_ = scheduler_worker_observer;

  self_ = this;

  constexpr size_t kDefaultStackSize = 0;
  PlatformThread::CreateWithPriority(kDefaultStackSize, this, &thread_handle_,
                                     current_thread_priority_);

  if (thread_handle_.is_null()) {
    self_ = nullptr;
  TRACE_EVENT0("dorsal", "SchedulerWorker::Start_END");
    return false;
  }
  TRACE_EVENT0("dorsal", "SchedulerWorker::Start_END");
  return true;
  TRACE_EVENT0("dorsal", "SchedulerWorker::Start_END");
}

void SchedulerWorker::WakeUp() {
  TRACE_EVENT0("dorsal", "SchedulerWorker::WakeUp");
  // Calling WakeUp() after Cleanup() or Join() is wrong because the
  // SchedulerWorker cannot run more tasks.
  DCHECK(!join_called_for_testing_.IsSet());
  DCHECK(!should_exit_.IsSet());
  wake_up_event_.Signal();
  TRACE_EVENT0("dorsal", "SchedulerWorker::WakeUp_END");
}

void SchedulerWorker::JoinForTesting() {
  TRACE_EVENT0("dorsal", "SchedulerWorker::JoinForTesting");
  DCHECK(!join_called_for_testing_.IsSet());
  join_called_for_testing_.Set();
  wake_up_event_.Signal();

  PlatformThreadHandle thread_handle;

  {
    AutoSchedulerLock auto_lock(thread_lock_);
    DCHECK(!thread_handle_.is_null());
    thread_handle = thread_handle_;
    // Reset |thread_handle_| so it isn't joined by the destructor.
    thread_handle_ = PlatformThreadHandle();
  }

  PlatformThread::Join(thread_handle);
  TRACE_EVENT0("dorsal", "SchedulerWorker::JoinForTesting_END");
}

bool SchedulerWorker::ThreadAliveForTesting() const {
  TRACE_EVENT0("dorsal", "SchedulerWorker::ThreadAliveForTesting");
  AutoSchedulerLock auto_lock(thread_lock_);
  TRACE_EVENT0("dorsal", "SchedulerWorker::ThreadAliveForTesting_END");
  return !thread_handle_.is_null();
}

SchedulerWorker::~SchedulerWorker() {
  AutoSchedulerLock auto_lock(thread_lock_);

  // If |thread_handle_| wasn't joined, detach it.
  if (!thread_handle_.is_null()) {
    DCHECK(!join_called_for_testing_.IsSet());
    PlatformThread::Detach(thread_handle_);
  }
}

void SchedulerWorker::Cleanup() {
  TRACE_EVENT0("dorsal", "SchedulerWorker::Cleanup");
  DCHECK(!should_exit_.IsSet());
  should_exit_.Set();
  wake_up_event_.Signal();
  TRACE_EVENT0("dorsal", "SchedulerWorker::Cleanup_END");
}

void SchedulerWorker::BeginUnusedPeriod() {
  TRACE_EVENT0("dorsal", "SchedulerWorker::BeginUnusedPeriod");
  AutoSchedulerLock auto_lock(thread_lock_);
  DCHECK(last_used_time_.is_null());
  last_used_time_ = TimeTicks::Now();
  TRACE_EVENT0("dorsal", "SchedulerWorker::BeginUnusedPeriod_END");
}

void SchedulerWorker::EndUnusedPeriod() {
  TRACE_EVENT0("dorsal", "SchedulerWorker::EndUnusedPeriod");
  AutoSchedulerLock auto_lock(thread_lock_);
  DCHECK(!last_used_time_.is_null());
  last_used_time_ = TimeTicks();
  TRACE_EVENT0("dorsal", "SchedulerWorker::EndUnusedPeriod_END");
}

TimeTicks SchedulerWorker::GetLastUsedTime() const {
  TRACE_EVENT0("dorsal", "SchedulerWorker::GetLastUsedTime");
  AutoSchedulerLock auto_lock(thread_lock_);
  TRACE_EVENT0("dorsal", "SchedulerWorker::GetLastUsedTime_END");
  return last_used_time_;
}

bool SchedulerWorker::ShouldExit() const {
  // The ordering of the checks is important below. This SchedulerWorker may be
  // released and outlive |task_tracker_| in unit tests. However, when the
  // SchedulerWorker is released, |should_exit_| will be set, so check that
  // first.
  return should_exit_.IsSet() || join_called_for_testing_.IsSet() ||
         task_tracker_->IsShutdownComplete();
}

ThreadPriority SchedulerWorker::GetDesiredThreadPriority() const {
  // To avoid shutdown hangs, disallow a priority below NORMAL during shutdown
  if (task_tracker_->HasShutdownStarted())
    return ThreadPriority::NORMAL;

  return priority_hint_;
}

void SchedulerWorker::UpdateThreadPriority(
    ThreadPriority desired_thread_priority) {
  if (desired_thread_priority == current_thread_priority_)
    return;

  PlatformThread::SetCurrentThreadPriority(desired_thread_priority);
  current_thread_priority_ = desired_thread_priority;
}

void SchedulerWorker::ThreadMain() {
  if (priority_hint_ == ThreadPriority::BACKGROUND) {
    switch (delegate_->GetThreadLabel()) {
      case ThreadLabel::POOLED:
        RunBackgroundPooledWorker();
        return;
      case ThreadLabel::SHARED:
        RunBackgroundSharedWorker();
        return;
      case ThreadLabel::DEDICATED:
        RunBackgroundDedicatedWorker();
        return;
#if defined(OS_WIN)
      case ThreadLabel::SHARED_COM:
        RunBackgroundSharedCOMWorker();
        return;
      case ThreadLabel::DEDICATED_COM:
        RunBackgroundDedicatedCOMWorker();
        return;
#endif  // defined(OS_WIN)
    }
  }

  switch (delegate_->GetThreadLabel()) {
    case ThreadLabel::POOLED:
      RunPooledWorker();
      return;
    case ThreadLabel::SHARED:
      RunSharedWorker();
      return;
    case ThreadLabel::DEDICATED:
      RunDedicatedWorker();
      return;
#if defined(OS_WIN)
    case ThreadLabel::SHARED_COM:
      RunSharedCOMWorker();
      return;
    case ThreadLabel::DEDICATED_COM:
      RunDedicatedCOMWorker();
      return;
#endif  // defined(OS_WIN)
  }
}

NOINLINE void SchedulerWorker::RunPooledWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunBackgroundPooledWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunSharedWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunBackgroundSharedWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunDedicatedWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunBackgroundDedicatedWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

#if defined(OS_WIN)
NOINLINE void SchedulerWorker::RunSharedCOMWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunBackgroundSharedCOMWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunDedicatedCOMWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}

NOINLINE void SchedulerWorker::RunBackgroundDedicatedCOMWorker() {
  const int line_number = __LINE__;
  RunWorker();
  base::debug::Alias(&line_number);
}
#endif  // defined(OS_WIN)

void SchedulerWorker::RunWorker() {
  DCHECK_EQ(self_, this);
  TRACE_EVENT_BEGIN0(TRACE_DISABLED_BY_DEFAULT("task_scheduler_diagnostics"),
                     "SchedulerWorkerThread alive");
  TRACE_EVENT_BEGIN0("task_scheduler", "SchedulerWorkerThread active");

  if (scheduler_worker_observer_)
    scheduler_worker_observer_->OnSchedulerWorkerMainEntry();

  delegate_->OnMainEntry(this);

  // A SchedulerWorker starts out waiting for work.
  {
    TRACE_EVENT_END0("task_scheduler", "SchedulerWorkerThread active");
    delegate_->WaitForWork(&wake_up_event_);
    TRACE_EVENT_BEGIN0("task_scheduler", "SchedulerWorkerThread active");
  }

// When defined(COM_INIT_CHECK_HOOK_ENABLED), ignore
// SchedulerBackwardCompatibility::INIT_COM_STA to find incorrect uses of
// COM that should be running in a COM STA Task Runner.
#if defined(OS_WIN) && !defined(COM_INIT_CHECK_HOOK_ENABLED)
  std::unique_ptr<win::ScopedCOMInitializer> com_initializer;
  if (backward_compatibility_ == SchedulerBackwardCompatibility::INIT_COM_STA)
    com_initializer = std::make_unique<win::ScopedCOMInitializer>();
#endif

  while (!ShouldExit()) {
#if defined(OS_MACOSX)
    mac::ScopedNSAutoreleasePool autorelease_pool;
#endif

    UpdateThreadPriority(GetDesiredThreadPriority());

    // Get the sequence containing the next task to execute.
    scoped_refptr<Sequence> sequence = delegate_->GetWork(this);
    if (!sequence) {
      // Exit immediately if GetWork() resulted in detaching this worker.
      if (ShouldExit())
        break;

      TRACE_EVENT_END0("task_scheduler", "SchedulerWorkerThread active");
      delegate_->WaitForWork(&wake_up_event_);
      TRACE_EVENT_BEGIN0("task_scheduler", "SchedulerWorkerThread active");
      continue;
    }

    sequence =
        task_tracker_->RunAndPopNextTask(std::move(sequence), delegate_.get());

    delegate_->DidRunTask();

    // Re-enqueue |sequence| if allowed by RunNextTask().
    if (sequence)
      delegate_->ReEnqueueSequence(std::move(sequence));

    // Calling WakeUp() guarantees that this SchedulerWorker will run Tasks from
    // Sequences returned by the GetWork() method of |delegate_| until it
    // returns nullptr. Resetting |wake_up_event_| here doesn't break this
    // invariant and avoids a useless loop iteration before going to sleep if
    // WakeUp() is called while this SchedulerWorker is awake.
    wake_up_event_.Reset();
  }

  // Important: It is unsafe to access unowned state (e.g. |task_tracker_|)
  // after invoking OnMainExit().

  delegate_->OnMainExit(this);

  if (scheduler_worker_observer_)
    scheduler_worker_observer_->OnSchedulerWorkerMainExit();

  // Release the self-reference to |this|. This can result in deleting |this|
  // and as such no more member accesses should be made after this point.
  self_ = nullptr;

  TRACE_EVENT_END0("task_scheduler", "SchedulerWorkerThread active");
  TRACE_EVENT_END0(TRACE_DISABLED_BY_DEFAULT("task_scheduler_diagnostics"),
                   "SchedulerWorkerThread alive");
}

}  // namespace internal
}  // namespace base
