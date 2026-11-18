#pragma once

#include "BaseUnits.hpp"

namespace Units
{

  struct dB : UnitBase<dB>
  {
    using UnitBase::UnitBase;

    constexpr double Decibels() const
    {
      return value;
    }

    enum class Unit
    {
      dB
    };

    static constexpr const char* Units(Unit u = Unit::dB)
    {
      return "dB";
    }
  };

  constexpr dB operator""_dB(long double v)
  {
    return dB(static_cast<double>(v));
  }
  constexpr dB operator""_dB(unsigned long long v)
  {
    return dB(static_cast<double>(v));
  }

} // namespace Units
