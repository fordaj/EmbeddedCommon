#pragma once

// #include "I2C.hpp"
#include "Logger.hpp"
#include "Units.hpp"

#include <Arduino.h>

class ArduinoLogger : public Logger
{
public:
  void logf(const char* fmt, ...) override
  {
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    Serial.print(buffer);
  }
};

// Usage
ArduinoLogger logger;

namespace Platform
{

  inline Time NowMicroseconds()
  {
    return Time::Microseconds(micros());
  }

} // namespace Platform
