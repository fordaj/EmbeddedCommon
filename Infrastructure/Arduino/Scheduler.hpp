#pragma once
#include <Arduino.h>
#include "iScheduler.hpp"

namespace Platform
{

  inline Tick Now()
  {
    return millis();
  }

  inline void Idle()
  {
    delay(1); // yields to ESP32 background tasks
  }

} // namespace Platform
