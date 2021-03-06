// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/task/sequence_manager/task_queue_task_runner.h"

#include "base/task/sequence_manager/task_queue.h"

namespace base {
namespace sequence_manager {
namespace internal {

TaskQueueTaskRunner::TaskQueueTaskRunner(scoped_refptr<TaskQueue> task_queue,
                                         int task_type)
    : task_queue_(task_queue), task_type_(task_type) {}

TaskQueueTaskRunner::~TaskQueueTaskRunner() {}

bool TaskQueueTaskRunner::PostDelayedTask(const Location& location,
                                          OnceClosure callback,
                                          TimeDelta delay) {
  return task_queue_->PostTaskWithMetadata(TaskQueue::PostedTask(
      std::move(callback), location, delay, Nestable::kNestable, task_type_));
}

bool TaskQueueTaskRunner::PostNonNestableDelayedTask(const Location& location,
                                                     OnceClosure callback,
                                                     TimeDelta delay) {
  return task_queue_->PostTaskWithMetadata(
      TaskQueue::PostedTask(std::move(callback), location, delay,
                            Nestable::kNonNestable, task_type_));
}

bool TaskQueueTaskRunner::RunsTasksInCurrentSequence() const {
  return task_queue_->RunsTasksInCurrentSequence();
}

}  // namespace internal
}  // namespace sequence_manager
}  // namespace base
