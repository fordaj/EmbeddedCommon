

#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct Illuminance : UnitBase<Illuminance>
  {
    using UnitBase::UnitBase;

    constexpr double Lux() const
    {
      return value;
    }
    constexpr double KiloLux() const
    {
      return value / 1000.0;
    }

    enum class Unit
    {
      lx,
      klx
    };

    static constexpr const char* Units(Unit u = Unit::lx)
    {
      return (u == Unit::lx) ? "lx" : "klx";
    }
  };

  constexpr Illuminance operator""_lux(long double v)
  {
    return Illuminance(static_cast<double>(v));
  }
  constexpr Illuminance operator""_lux(unsigned long long v)
  {
    return Illuminance(static_cast<double>(v));
  }
  constexpr Illuminance operator""_k_lux(long double v)
  {
    return Illuminance(static_cast<double>(v * 1000.0));
  }
  constexpr Illuminance operator""_k_lux(unsigned long long v)
  {
    return Illuminance(static_cast<double>(v * 1000.0));
  }

} // namespace Units
