#pragma once
#include <stdint.h>
#include "BaseUnits.hpp"

namespace Units
{

  struct TVOCIndex
  {
    explicit constexpr TVOCIndex(uint16_t v):
        value(v)
    {
    }
    uint16_t value;
  };

  struct NOxIndex
  {
    explicit constexpr NOxIndex(uint16_t v):
        value(v)
    {
    }
    uint16_t value;
  };

} // namespace Units
