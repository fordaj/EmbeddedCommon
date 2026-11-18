#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct Temperature : UnitBase<Temperature>
  {
    enum class Unit
    {
      Celsius,
      Kelvin,
      Fahrenheit
    };
    using UnitBase::UnitBase;

    constexpr double Celsius() const
    {
      return value;
    }
    constexpr double Fahrenheit() const
    {
      return value * 9.0 / 5.0 + 32.0;
    }
    constexpr double Kelvin() const
    {
      return value + 273.15;
    }

    constexpr Temperature Celsius(const double& _value) const
    {
      return Temperature(_value);
    }
    constexpr Temperature Fahrenheit(const double& _value) const
    {
      return Temperature((_value - 32.0) * 5.0 / 9.0);
    }

    static constexpr const char* Units(Unit u = Unit::Celsius)
    {
      return (u == Unit::Kelvin) ? "K" : (u == Unit::Fahrenheit) ? "°F" : "°C";
    }
  };

  constexpr Temperature operator""_celsius(long double v)
  {
    return Temperature(static_cast<double>(v));
  }
  constexpr Temperature operator""_celsius(unsigned long long v)
  {
    return Temperature(static_cast<double>(v));
  }
  constexpr Temperature operator""_fahrenheit(long double v)
  {
    return Temperature((static_cast<double>(v) - 32.0) * 5.0 / 9.0);
  }
  constexpr Temperature operator""_fahrenheit(unsigned long long v)
  {
    return Temperature((static_cast<double>(v) - 32.0) * 5.0 / 9.0);
  }
  constexpr Temperature operator""_kelvin(long double v)
  {
    return Temperature(static_cast<double>(v) - 273.15);
  }
  constexpr Temperature operator""_kelvin(unsigned long long v)
  {
    return Temperature(static_cast<double>(v) - 273.15);
  }

} // namespace Units
