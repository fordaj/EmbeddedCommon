#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct CircadianIlluminance : UnitBase<CircadianIlluminance>
  {
    using UnitBase::UnitBase;

    constexpr double CLA() const
    {
      return value;
    } // scaled circadian lux
    enum class Unit
    {
      CLA
    };
    static constexpr const char* Units(Unit u = Unit::CLA)
    {
      return "CLA";
    }
  };

  constexpr CircadianIlluminance operator""_cla(long double v)
  {
    return CircadianIlluminance(static_cast<double>(v));
  }
  constexpr CircadianIlluminance operator""_cla(unsigned long long v)
  {
    return CircadianIlluminance(static_cast<double>(v));
  }

  // TCS34725
  // CLA = k_red * R + k_green * G + k_blue * B
  // Constants are derived from spectral weighting curves, e.g., Rea et al. 2005.

} // namespace Units
