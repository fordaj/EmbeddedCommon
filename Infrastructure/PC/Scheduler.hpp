#pragma once
#include <chrono>
#include <thread>
#include "iScheduler.hpp"

namespace Platform
{

  inline Tick Now()
  {
    using clock         = std::chrono::steady_clock;
    static const auto start = clock::now();
    auto now            = clock::now();
    auto ms             = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
    return static_cast<Tick>(ms.count());
  }

  inline void Idle()
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

} // namespace Platform
