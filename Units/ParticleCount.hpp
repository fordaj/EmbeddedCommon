#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct ParticleCount : UnitBase<ParticleCount>
  {
    using UnitBase::UnitBase;

    constexpr double ParticlesPerCubicCentimeter() const
    {
      return value;
    }
    constexpr double ParticlesPerCubicMeter() const
    {
      return value * 1000000.0;
    }

    enum class Unit
    {
      particles_cm3,
      particles_m3
    };

    static constexpr const char* Units(Unit u = Unit::particles_cm3)
    {
      return (u == Unit::particles_cm3) ? "particles/cm³" : "particles/m³";
    }
  };

  constexpr ParticleCount operator""_particles_per_cm3(long double v)
  {
    return ParticleCount(static_cast<double>(v));
  }

  constexpr ParticleCount operator""_particles_per_cm3(unsigned long long v)
  {
    return ParticleCount(static_cast<double>(v));
  }

} // namespace Units