#pragma once
#include "Logger.hpp"
#include "Units.hpp"
#include <chrono>
#include <iostream>
#include <cstdarg>
#include <cstdio>

class PCLogger : public Logger
{
public:
  void logf(const char* fmt, ...) override
  {
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    std::vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    std::cout << buffer;
  }
};

PCLogger logger;

namespace Platform
{

  inline Time NowMicroseconds()
  {
    using namespace std::chrono;
    return Time::Microseconds(duration_cast<microseconds>(steady_clock::now().time_since_epoch()).count());
  }

} // namespace Platform
