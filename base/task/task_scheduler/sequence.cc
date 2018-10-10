// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/task/task_scheduler/sequence.h"
#include "base/trace_event/trace_event.h"
#include <utility>

#include "base/logging.h"
#include "base/time/time.h"

namespace base {
namespace internal {

Sequence::Sequence() = default;

bool Sequence::PushTask(Task task) {
  TRACE_EVENT0("dorsal", "Sequence::PushTask");
  // Use CHECK instead of DCHECK to crash earlier. See http://crbug.com/711167
  // for details.
  CHECK(task.task);
  DCHECK(task.sequenced_time.is_null());
  task.sequenced_time = base::TimeTicks::Now();

  AutoSchedulerLock auto_lock(lock_);
  ++num_tasks_per_priority_[static_cast<int>(task.traits.priority())];
  queue_.push(std::move(task));

  // Return true if the sequence was empty before the push.
  TRACE_EVENT0("dorsal", "Sequence::PushTask_END");
  return queue_.size() == 1;
}

Optional<Task> Sequence::TakeTask() {
  TRACE_EVENT0("dorsal", "Sequence::TakeTask");
  AutoSchedulerLock auto_lock(lock_);
  DCHECK(!queue_.empty());
  DCHECK(queue_.front().task);

  const int priority_index = static_cast<int>(queue_.front().traits.priority());
  DCHECK_GT(num_tasks_per_priority_[priority_index], 0U);
  --num_tasks_per_priority_[priority_index];
  TRACE_EVENT0("dorsal", "Sequence::TakeTask_END");
  return std::move(queue_.front());
}

bool Sequence::Pop() {
  TRACE_EVENT0("dorsal", "Sequence::Pop");
  AutoSchedulerLock auto_lock(lock_);
  DCHECK(!queue_.empty());
  DCHECK(!queue_.front().task);
  queue_.pop();
  TRACE_EVENT0("dorsal", "Sequence::Pop_END");
  return queue_.empty();
}

SequenceSortKey Sequence::GetSortKey() const {
  TRACE_EVENT0("dorsal", "Sequence::GetSortKey");
  TaskPriority priority = TaskPriority::LOWEST;
  base::TimeTicks next_task_sequenced_time;

  {
    AutoSchedulerLock auto_lock(lock_);
    DCHECK(!queue_.empty());

    // Find the highest task priority in the sequence.
    const int highest_priority_index = static_cast<int>(TaskPriority::HIGHEST);
    const int lowest_priority_index = static_cast<int>(TaskPriority::LOWEST);
    for (int i = highest_priority_index; i > lowest_priority_index; --i) {
      if (num_tasks_per_priority_[i] > 0) {
        priority = static_cast<TaskPriority>(i);
        break;
      }
    }

    // Save the sequenced time of the next task in the sequence.
    next_task_sequenced_time = queue_.front().sequenced_time;
  }
  TRACE_EVENT0("dorsal", "Sequence::GetSortKey_END");
  return SequenceSortKey(priority, next_task_sequenced_time);
  TRACE_EVENT0("dorsal", "Sequence::GetSortKey_END");
}

Sequence::~Sequence() = default;

}  // namespace internal
}  // namespace base
