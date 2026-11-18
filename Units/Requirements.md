# Units Library

Units is a C++ library which offers fully-compile time classes, operators, and UDLs to make units-aware arithmetic clean and accurate. It is implemented with the following requirements in mind:

1. All units, functions, classes, and operators may be used at compile time (constexpr)
   `static constexpr Temperature temperature = 5_celsius`
1. A new unit should be inferred during arithmetic operations:
   `static constexpr Velocity velocity = 5_meters / 1.2_seconds;`
1. Units should be convertible to standard types:
   `static constexpr float value = velocity.Value()`
1. Units classes shall contain functionality to convert units:
   `static constexpr float value = temperature.Fahrenheit();`
1. The implementation of the units library should be simple and easy to update. Dimensions, tags, groups of units are unnecessarily complex. Compound units, like velocity, should contain an explicitly defined operator overload for its creation arithmetically.
