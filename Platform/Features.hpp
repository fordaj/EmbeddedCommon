#pragma once

// ─────────────────────────────────────────────────────────────
// EmbeddedCommon compile-time feature flags.
//
// Every flag defaults to 0 (off). Opt in per environment via
// `build_flags` in platformio.ini (e.g. -DAIRFRAME_ENABLE_WIFI=1).
// Flags that are compiled out are guaranteed to drag in neither
// their headers nor their libraries: nothing is included, declared
// or constructed unless the corresponding flag is enabled.
//
// Runtime on/off toggles (`Configuration.is*Enabled`) only exist
// for features that are compiled in. A toggle for a feature that
// is not compiled does not exist.
//
// These flags are the shared contract for all projects consuming
// EmbeddedCommon (AirFrame, smart-string-lights, ...).
//
//   AIRFRAME_ENABLE_HOMESPAN  ESP32 HomeKit/HomeSpan service (Arduino only)
//   AIRFRAME_ENABLE_WIFI      ESP32 WiFi service + WiFiManager portal (Arduino only)
//   AIRFRAME_ENABLE_MDNS      mDNS responder for the WiFi service (Arduino only,
//                             requires AIRFRAME_ENABLE_WIFI)
//   AIRFRAME_ENABLE_WEBSERVER Web server: ESP32 WebServer on Arduino, static
//                             assets on the host
//   AIRFRAME_ENABLE_REST      REST API (`/api/sensors` JSON endpoint) and the
//                             RESTParameters serializer (host only). The host web
//                             server itself is served over the REST transport, so
//                             the static site is available without the REST API.
//   AIRFRAME_ENABLE_TELEPLOT  TelePlot serial output of parameter values
//   AIRFRAME_ENABLE_I2C       I2C bus init + device scan at boot (Arduino only).
//                             Requires an I2CUtil header on the include path
//                             and a `Board` header with I2C0_SDA/I2C0_SCL.
// ─────────────────────────────────────────────────────────────

#if !defined(AIRFRAME_ENABLE_HOMESPAN)
#define AIRFRAME_ENABLE_HOMESPAN 0
#endif

#if !defined(AIRFRAME_ENABLE_WIFI)
#define AIRFRAME_ENABLE_WIFI 0
#endif

#if !defined(AIRFRAME_ENABLE_MDNS)
#define AIRFRAME_ENABLE_MDNS 0
#endif

#if !defined(AIRFRAME_ENABLE_WEBSERVER)
#define AIRFRAME_ENABLE_WEBSERVER 0
#endif

#if !defined(AIRFRAME_ENABLE_REST)
#define AIRFRAME_ENABLE_REST 0
#endif

#if !defined(AIRFRAME_ENABLE_TELEPLOT)
#define AIRFRAME_ENABLE_TELEPLOT 0
#endif

#if !defined(AIRFRAME_ENABLE_I2C)
#define AIRFRAME_ENABLE_I2C 0
#endif
