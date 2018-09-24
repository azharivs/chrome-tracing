// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/task/sequence_manager/work_queue.h"

#include "base/task/sequence_manager/work_queue_sets.h"

namespace base {
namespace sequence_manager {
namespace internal {

WorkQueue::WorkQueue(TaskQueueImpl* task_queue,
                     const char* name,
                     QueueType queue_type)
    : task_queue_(task_queue), name_(name), queue_type_(queue_type) {}

void WorkQueue::AsValueInto(TimeTicks now,
                            trace_event::TracedValue* state) const {
  for (const TaskQueueImpl::Task& task : tasks_) {
    TaskQueueImpl::TaskAsValueInto(task, now, state);
  }
}

WorkQueue::~WorkQueue() {
  DCHECK(!work_queue_sets_) << task_queue_->GetName() << " : "
                            << work_queue_sets_->GetName() << " : " << name_;
}

const TaskQueueImpl::Task* WorkQueue::GetFrontTask() const {
  TRACE_EVENT0("dorsal", "WorkQueue::GetFrontTask");
  if (tasks_.empty()){
  TRACE_EVENT0("dorsal", "WorkQueue::GetFrontTask_END");
    return nullptr;}
  TRACE_EVENT0("dorsal", "WorkQueue::GetFrontTask_END");
  return &tasks_.front();
}

const TaskQueueImpl::Task* WorkQueue::GetBackTask() const {
  TRACE_EVENT0("dorsal", "WorkQueue::GetBackTask");
  if (tasks_.empty()){
  TRACE_EVENT0("dorsal", "WorkQueue::GetBackTask_END");
    return nullptr;}
  TRACE_EVENT0("dorsal", "WorkQueue::GetBackTask_END");
  return &tasks_.back();
}

bool WorkQueue::BlockedByFence() const {
  TRACE_EVENT0("dorsal", "WorkQueue::BlockedByFence");
  if (!fence_){
  TRACE_EVENT0("dorsal", "WorkQueue::BlockedByFence_END");
    return false;}

  // If the queue is empty then any future tasks will have a higher enqueue
  // order and will be blocked. The queue is also blocked if the head is past
  // the fence.
  TRACE_EVENT0("dorsal", "WorkQueue::BlockedByFence_END");
  return tasks_.empty() || tasks_.front().enqueue_order() >= fence_;
}

bool WorkQueue::GetFrontTaskEnqueueOrder(EnqueueOrder* enqueue_order) const {
  TRACE_EVENT0("dorsal", "WorkQueue::GetFrontTaskEnqueueOrder");
  if (tasks_.empty() || BlockedByFence()){
  TRACE_EVENT0("dorsal", "WorkQueue::GetFrontTaskEnqueueOrder_END");
    return false;}
  // Quick sanity check.
  DCHECK_LE(tasks_.front().enqueue_order(), tasks_.back().enqueue_order())
      << task_queue_->GetName() << " : " << work_queue_sets_->GetName() << " : "
      << name_;
  *enqueue_order = tasks_.front().enqueue_order();
  TRACE_EVENT0("dorsal", "WorkQueue::GetFrontTaskEnqueueOrder_END");
  return true;
}

void WorkQueue::Push(TaskQueueImpl::Task task) {
  TRACE_EVENT0("dorsal", "WorkQueue::Push");
  bool was_empty = tasks_.empty();
#ifndef NDEBUG
  DCHECK(task.enqueue_order_set());
#endif

  // Make sure the |enqueue_order()| is monotonically increasing.
  DCHECK(was_empty || tasks_.rbegin()->enqueue_order() < task.enqueue_order());

  // Amoritized O(1).
  tasks_.push_back(std::move(task));

  if (!was_empty){
  TRACE_EVENT0("dorsal", "WorkQueue::Push_END");
    return;}

  // If we hit the fence, pretend to WorkQueueSets that we're empty.
  if (work_queue_sets_ && !BlockedByFence())
    work_queue_sets_->OnTaskPushedToEmptyQueue(this);
  TRACE_EVENT0("dorsal", "WorkQueue::Push_END");
}

void WorkQueue::PushNonNestableTaskToFront(TaskQueueImpl::Task task) {
  TRACE_EVENT0("dorsal", "WorkQueue::PushNonNestableTaskToFront");
  DCHECK(task.nestable == Nestable::kNonNestable);

  bool was_empty = tasks_.empty();
  bool was_blocked = BlockedByFence();
#ifndef NDEBUG
  DCHECK(task.enqueue_order_set());
#endif

  if (!was_empty) {
    // Make sure the |enqueue_order()| is monotonically increasing.
    DCHECK_LE(task.enqueue_order(), tasks_.front().enqueue_order())
        << task_queue_->GetName() << " : " << work_queue_sets_->GetName()
        << " : " << name_;
  }

  // Amoritized O(1).
  tasks_.push_front(std::move(task));

  if (!work_queue_sets_){
  TRACE_EVENT0("dorsal", "WorkQueue::PushNonNestableTaskToFront_END");
    return;}

  // Pretend  to WorkQueueSets that nothing has changed if we're blocked.
  if (BlockedByFence()){
  TRACE_EVENT0("dorsal", "WorkQueue::PushNonNestableTaskToFront_END");
    return;}

  // Pushing task to front may unblock the fence.
  if (was_empty || was_blocked) {
    work_queue_sets_->OnTaskPushedToEmptyQueue(this);
  } else {
    work_queue_sets_->OnFrontTaskChanged(this);
  }
TRACE_EVENT0("dorsal", "WorkQueue::PushNonNestableTaskToFront_END");
}

void WorkQueue::ReloadEmptyImmediateQueue() {
  TRACE_EVENT0("dorsal", "WorkQueue::ReloadEmptyImmediateQueue");
  DCHECK(tasks_.empty());

  task_queue_->ReloadEmptyImmediateQueue(&tasks_);
  if (tasks_.empty()){
  TRACE_EVENT0("dorsal", "WorkQueue::ReloadEmptyImmediateQueue_END");
    return;}

  // If we hit the fence, pretend to WorkQueueSets that we're empty.
  if (work_queue_sets_ && !BlockedByFence())
    work_queue_sets_->OnTaskPushedToEmptyQueue(this);
  TRACE_EVENT0("dorsal", "WorkQueue::ReloadEmptyImmediateQueue_END");
}

TaskQueueImpl::Task WorkQueue::TakeTaskFromWorkQueue() {
  TRACE_EVENT0("dorsal", "WorkQueue::TakeTaskFromWorkQueue");
  printf("------------------------------TakeTaskFromWorkQueue---------------------------------\n\n");
  DCHECK(work_queue_sets_);
  DCHECK(!tasks_.empty());

  TaskQueueImpl::Task pending_task = std::move(tasks_.front());
  tasks_.pop_front();
  // NB immediate tasks have a different pipeline to delayed ones.
  if (queue_type_ == QueueType::kImmediate && tasks_.empty()) {
    // Short-circuit the queue reload so that OnPopQueue does the right thing.
    task_queue_->ReloadEmptyImmediateQueue(&tasks_);
  }

  // OnPopQueue calls GetFrontTaskEnqueueOrder which checks BlockedByFence() so
  // we don't need to here.
  work_queue_sets_->OnPopQueue(this);
  task_queue_->TraceQueueSize();
  TRACE_EVENT0("dorsal", "WorkQueue::TakeTaskFromWorkQueue_END");
  return pending_task;
}

bool WorkQueue::RemoveAllCanceledTasksFromFront() {
  TRACE_EVENT0("dorsal", "WorkQueue::RemoveAllCanceledTasksFromFront");
  printf("------------------------------RemoveAllCanceledTasksFromFront---------------------------------\n\n");
  DCHECK(work_queue_sets_);
  bool task_removed = false;
  while (!tasks_.empty() &&
         (!tasks_.front().task || tasks_.front().task.IsCancelled())) {
    tasks_.pop_front();
    task_removed = true;
  }
  if (task_removed) {
    // NB immediate tasks have a different pipeline to delayed ones.
    if (queue_type_ == QueueType::kImmediate && tasks_.empty()) {
      // Short-circuit the queue reload so that OnPopQueue does the right thing.
      task_queue_->ReloadEmptyImmediateQueue(&tasks_);
    }
    work_queue_sets_->OnPopQueue(this);
    task_queue_->TraceQueueSize();
  }
  TRACE_EVENT0("dorsal", "WorkQueue::RemoveAllCanceledTasksFromFront_END");
  return task_removed;
  TRACE_EVENT0("dorsal", "WorkQueue::RemoveAllCanceledTasksFromFront_END");
}

void WorkQueue::AssignToWorkQueueSets(WorkQueueSets* work_queue_sets) {
  TRACE_EVENT0("dorsal", "WorkQueue::AssignToWorkQueueSets");
  work_queue_sets_ = work_queue_sets;
  TRACE_EVENT0("dorsal", "WorkQueue::AssignToWorkQueueSets_END");
}

void WorkQueue::AssignSetIndex(size_t work_queue_set_index) {
  TRACE_EVENT0("dorsal", "WorkQueue::AssignSetIndex");
  work_queue_set_index_ = work_queue_set_index;
  TRACE_EVENT0("dorsal", "WorkQueue::AssignSetIndex_END");
}

bool WorkQueue::InsertFenceImpl(EnqueueOrder fence) {
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFenceImpl");
  DCHECK_NE(fence, 0u);
  DCHECK(fence >= fence_ || fence == EnqueueOrder::blocking_fence());
  bool was_blocked_by_fence = BlockedByFence();
  fence_ = fence;
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFenceImpl_END");
  return was_blocked_by_fence;
}

void WorkQueue::InsertFenceSilently(EnqueueOrder fence) {
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFenceSilently");
  // Ensure that there is no fence present or a new one blocks queue completely.
  DCHECK(!fence_ || fence_ == EnqueueOrder::blocking_fence());
  InsertFenceImpl(fence);
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFenceSilently_END");
}

bool WorkQueue::InsertFence(EnqueueOrder fence) {
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFence");
  bool was_blocked_by_fence = InsertFenceImpl(fence);

  // Moving the fence forward may unblock some tasks.
  if (work_queue_sets_ && !tasks_.empty() && was_blocked_by_fence &&
      !BlockedByFence()) {
    work_queue_sets_->OnTaskPushedToEmptyQueue(this);
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFence_END");
    return true;
  }
  // Fence insertion may have blocked all tasks in this work queue.
  if (BlockedByFence())
    work_queue_sets_->OnQueueBlocked(this);
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFence_END");
  return false;
  TRACE_EVENT0("dorsal", "WorkQueue::InsertFence_END");
}

bool WorkQueue::RemoveFence() {
  TRACE_EVENT0("dorsal", "WorkQueue::RemoveFence");
  bool was_blocked_by_fence = BlockedByFence();
  fence_ = EnqueueOrder::none();
  if (work_queue_sets_ && !tasks_.empty() && was_blocked_by_fence) {
    work_queue_sets_->OnTaskPushedToEmptyQueue(this);
  TRACE_EVENT0("dorsal", "WorkQueue::RemoveFence_END");
    return true;
  }
  TRACE_EVENT0("dorsal", "WorkQueue::RemoveFence_END");
  return false;
  TRACE_EVENT0("dorsal", "WorkQueue::RemoveFence_END");
}

bool WorkQueue::ShouldRunBefore(const WorkQueue* other_queue) const {
  TRACE_EVENT0("dorsal", "WorkQueue::ShouldRunBefore");
  DCHECK(!tasks_.empty());
  DCHECK(!other_queue->tasks_.empty());
  EnqueueOrder enqueue_order;
  EnqueueOrder other_enqueue_order;
  bool have_task = GetFrontTaskEnqueueOrder(&enqueue_order);
  bool have_other_task =
      other_queue->GetFrontTaskEnqueueOrder(&other_enqueue_order);
  DCHECK(have_task);
  DCHECK(have_other_task);
  TRACE_EVENT0("dorsal", "WorkQueue::ShouldRunBefore_END");
  return enqueue_order < other_enqueue_order;
  TRACE_EVENT0("dorsal", "WorkQueue::ShouldRunBefore_END");
}

void WorkQueue::PopTaskForTesting() {
  TRACE_EVENT0("dorsal", "WorkQueue::PopTaskForTesting");
  if (tasks_.empty()){
  TRACE_EVENT0("dorsal", "WorkQueue::PopTaskForTesting_END");
    return;}
  tasks_.pop_front();
  TRACE_EVENT0("dorsal", "WorkQueue::PopTaskForTesting_END");
}

}  // namespace internal
}  // namespace sequence_manager
}  // namespace base
