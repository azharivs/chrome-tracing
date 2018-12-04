// Copyright 2018 Seyed Vahid Azhari, 
// Ecole Polytechnique de Montreal, DORSAL.  All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file contains the exporting to LTTng.
#ifndef BASE_TRACE_EVENT_TRACE_EVENT_LTTNG_EXPORT_H_
#define BASE_TRACE_EVENT_TRACE_EVENT_LTTNG_EXPORT_H_

#include <stdint.h>

#include <map>

#include "base/base_export.h"
#include "base/macros.h"
#include "base/strings/string_piece.h"
#include "base/trace_event/trace_event_impl.h"

namespace base {

template <typename Type>
struct StaticMemorySingletonTraits;

namespace trace_event {

class BASE_EXPORT TraceEventLttngExport {
 public:
  ~TraceEventLttngExport();

  // Retrieves the singleton.
  // Note that this may return NULL post-AtExit processing.
  //TODO static TraceEventETWExport* GetInstance();

  // Enables/disables exporting of events to ETW. If disabled,
  // AddEvent and AddCustomEvent will simply return when called.
  //TODO for now always enabled static void EnableETWExport();
  //TODO static void DisableETWExport();

  // Returns true if Lttng export is enabled. For now, this is true if the command line
  // flag is specified.
  //TODO for now always true
  static bool IsLttngExportEnabled();

  // Exports an event to Lttng. This is mainly used in
  // TraceLog::AddTraceEventWithThreadIdAndTimestamp to export internal events.
  static void AddLttngEvent(
      char phase,
      const unsigned char* category_group_enabled,
      const char* name,
      unsigned long long id,
      int num_args,
      const char* const* arg_names,
      const unsigned char* arg_types,
      const unsigned long long* arg_values,
      const std::unique_ptr<ConvertableToTraceFormat>* convertable_values);

  // Exports an Lttng event that marks the end of a complete event.
  //TODO not implemented 
  static void AddLttngCompleteEndEvent(const char* name);

  // Returns true if any category in the group is enabled.
  //TODO for now always returns true
  static bool IsCategoryGroupEnabled(StringPiece category_group_name);

 private:
  // Ensure only the provider can construct us.
  //TODO friend struct StaticMemorySingletonTraits<TraceEventLttngExport>;
  // To have access to UpdateKeyword().
  //TODO class LttngKeywordUpdateThread;
  TraceEventLttngExport();

  // Updates the list of enabled categories by consulting the Lttng keyword.
  // Returns true if there was a change, false otherwise.
  //TODO not implemented yet bool UpdateEnabledCategories();

  // Returns true if the category is enabled.
  //TODO for now always true
  bool IsCategoryEnabled(StringPiece category_name) const;

  // Called back by the update thread to check for potential changes to the
  // keyword.
  //TODO static void UpdateLttngKeyword();

  // True if Lttng is enabled. Allows hiding the exporting behind a flag.
  //TODO bool lttng_export_enabled_;

  // Maps category names to their status (enabled/disabled).
  //TODO std::map<StringPiece, bool> categories_status_;

  // Local copy of the Lttng keyword.
  //TODO uint64_t lttng_match_any_keyword_;

  // Background thread that monitors changes to the Lttng keyword and updates
  // the enabled categories when a change occurs.
  //TODO std::unique_ptr<ETWKeywordUpdateThread> keyword_update_thread_;
  //TODO PlatformThreadHandle keyword_update_thread_handle_;

  DISALLOW_COPY_AND_ASSIGN(TraceEventLttngExport);
};

}  // namespace trace_event
}  // namespace base

#endif  // BASE_TRACE_EVENT_TRACE_EVENT_LTTNG_EXPORT_H_
