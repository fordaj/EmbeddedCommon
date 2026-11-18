#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct Pressure : UnitBase<Pressure>
  {
    using UnitBase::UnitBase;

    constexpr double Pascals() const
    {
      return value;
    }
    constexpr double KiloPascals() const
    {
      return value / 1000.0;
    }
    constexpr double Atmospheres() const
    {
      return value / 101325.0;
    }
    constexpr double Bar() const
    {
      return value / 100000.0;
    }
    constexpr double PSI() const
    {
      return value / 6894.757;
    }

    enum class Unit
    {
      Pa,
      kPa,
      atm,
      bar,
      psi
    };

    static constexpr const char* Units(Unit u = Unit::Pa)
    {
      return (u == Unit::Pa) ? "Pa" : (u == Unit::kPa) ? "kPa" : (u == Unit::atm) ? "atm" : (u == Unit::bar) ? "bar" : "psi";
    }
  };

  constexpr Pressure operator""_pascals(long double v)
  {
    return Pressure(static_cast<double>(v));
  }
  constexpr Pressure operator""_pascals(unsigned long long v)
  {
    return Pressure(static_cast<double>(v));
  }
  constexpr Pressure operator""_k_pascals(long double v)
  {
    return Pressure(static_cast<double>(v * 1000.0));
  }
  constexpr Pressure operator""_k_pascals(unsigned long long v)
  {
    return Pressure(static_cast<double>(v * 1000.0));
  }
  constexpr Pressure operator""_atmospheres(long double v)
  {
    return Pressure(static_cast<double>(v * 101325.0));
  }
  constexpr Pressure operator""_atmospheres(unsigned long long v)
  {
    return Pressure(static_cast<double>(v * 101325.0));
  }
  constexpr Pressure operator""_bar(long double v)
  {
    return Pressure(static_cast<double>(v * 100000.0));
  }
  constexpr Pressure operator""_bar(unsigned long long v)
  {
    return Pressure(static_cast<double>(v * 100000.0));
  }
  constexpr Pressure operator""_psi(long double v)
  {
    return Pressure(static_cast<double>(v * 6894.757));
  }
  constexpr Pressure operator""_psi(unsigned long long v)
  {
    return Pressure(static_cast<double>(v * 6894.757));
  }

} // namespace Units
