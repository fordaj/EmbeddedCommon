#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct CO2 : UnitBase<CO2>
  {
    using UnitBase::UnitBase;

    // stored internally as ppm
    constexpr double PPM() const
    {
      return value;
    }
    constexpr double Percent() const
    {
      return value / 10000.0;
    } // 1% = 10,000 ppm

    enum class Unit
    {
      PPM,
      Percent
    };

    static constexpr const char* Units(Unit u = Unit::PPM)
    {
      return (u == Unit::PPM) ? "ppm" : "%";
    }
  };

  constexpr CO2 operator""_co2_ppm(long double v)
  {
    return CO2(static_cast<double>(v));
  }
  constexpr CO2 operator""_co2_ppm(unsigned long long v)
  {
    return CO2(static_cast<double>(v));
  }

  constexpr CO2 operator""_percent_co2(long double v)
  {
    return CO2(static_cast<double>(v * 10000.0));
  }
  constexpr CO2 operator""_percent_co2(unsigned long long v)
  {
    return CO2(static_cast<double>(v * 10000.0));
  }

} // namespace Units
