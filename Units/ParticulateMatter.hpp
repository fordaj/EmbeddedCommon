#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct ParticulateMatter : UnitBase<ParticulateMatter>
  {
    using UnitBase::UnitBase;

    constexpr double MicrogramsPerCubicMeter() const
    {
      return value;
    }
    constexpr double MilligramsPerCubicMeter() const
    {
      return value / 1000.0;
    }

    enum class Unit
    {
      ug_m3,
      mg_m3
    };

    static constexpr const char* Units(Unit u = Unit::ug_m3)
    {
      return (u == Unit::ug_m3) ? "µg/m³" : "mg/m³";
    }
  };

  constexpr ParticulateMatter operator""_ug_per_m3(long double v)
  {
    return ParticulateMatter(static_cast<double>(v));
  }
  constexpr ParticulateMatter operator""_ug_per_m3(unsigned long long v)
  {
    return ParticulateMatter(static_cast<double>(v));
  }
  constexpr ParticulateMatter operator""_mg_per_m3(long double v)
  {
    return ParticulateMatter(static_cast<double>(v * 1000.0));
  }
  constexpr ParticulateMatter operator""_mg_per_m3(unsigned long long v)
  {
    return ParticulateMatter(static_cast<double>(v * 1000.0));
  }

} // namespace Units
