#pragma once

// ─────────────────────────────────────────────────────────────
// Single point of platform selection.
//
// Platform-specific includes and implementations are chosen here,
// once, instead of with ad-hoc #ifdefs at every call site:
//
//   - the platform logger (Arduino: Serial, PC: stdout)
//   - the scheduler implementation (millis/chrono + Scheduler)
//   - the reset reason implementation
//   - Platform::NowMicroseconds()
//
// Platforms themselves are selected with PLATFORM_ARDUINO /
// PLATFORM_PC (see platformio.ini), exactly like EMULATED is the
// model for the feature flags in Features.hpp.
// ─────────────────────────────────────────────────────────────

#include "Units.hpp"

#ifdef PLATFORM_ARDUINO
  #include "Arduino.hpp"
  #include "iScheduler.hpp"
  #include "Scheduler.hpp"
  #include "ResetReason.hpp"
using ResetReason = ESP32ResetReason;
#elif defined(PLATFORM_PC)
  #include "PC.hpp"
  #include "iScheduler.hpp"
  #include "Scheduler.hpp"
  #include "ResetReason.hpp"
using ResetReason = PCResetReason;
#endif // PLATFORM
