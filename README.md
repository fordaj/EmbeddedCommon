# EmbeddedCommon

Shared, application-agnostic C++ components for fordaj embedded projects
(AirFrame, smart-string-lights, ...). Header-only where practical; builds
on PlatformIO (`pioarduino/platform-espressif32`) for ESP32 targets and on
native (`platform = native`) for host builds and unit tests.

Projects consume this repo as a git submodule mounted at `Embedded/src/Common`.

```bash
git submodule add https://github.com/fordaj/EmbeddedCommon Embedded/src/Common
git submodule update --init --recursive
```

Then point the build at the per-directory include paths (flat includes,
same convention as the consuming projects):

```ini
build_flags =
    -IEmbedded/src/Common/Units
    -IEmbedded/src/Common/Devices
    -IEmbedded/src/Common/Infrastructure
    -IEmbedded/src/Common/Infrastructure/Arduino   # or .../PC
    -IEmbedded/src/Common/Platform
    -IEmbedded/src/Common/Services
    -IEmbedded/src/Common/Services/Arduino         # or .../PC
    -IEmbedded/src/Common/lib                      # host only (httplib.h, json.hpp)
```

Host environments must **not** add the Arduino directories to the include
path; platform selection happens in `Embedded/src/Common/Platform/Platform.hpp`
via `PLATFORM_ARDUINO` / `PLATFORM_PC`.

## Layout

| Path | Contents |
|---|---|
| `Units/` | Strong-unit types (`Temperature`, `Illuminance`, `Time`, ...) and the full `Units.hpp` umbrella. All projects get all units. |
| `Devices/` | Abstract `Logger` interface (+ per-platform implementations in `Platform/`). |
| `Infrastructure/` | `iScheduler`/`iResetReason`, platform `Scheduler` (Arduino + PC), reset-reason shims. |
| `Platform/` | `Platform.hpp` — the single platform-selection header (logger, scheduler, reset reason, `Platform::NowMicroseconds()`); `Platform/Features.hpp` — compile-time feature flags; per-platform glue. |
| `Services/` | Service plumbing: `iServices`, `iWebServer`, `iRESTServer` (+ `Response::Error`, `DELETE` routes), `RESTServer` (httplib wrapper), `PCServices`, `ESP32Services`, `ESP32WiFi`. App-specific web routes and the service composition roots stay in the consuming project's `Services/`. |
| `lib/` | Vendored third-party single headers: `httplib.h`, `json.hpp` (nlohmann). |
| `scripts/host.py` | PlatformIO extra script: `ws2_32` for cpp-httplib on Windows hosts. |

## Feature flags

See `Platform/Features.hpp`. All flags default to `0`; each project opts in
per environment in its `platformio.ini`:

```ini
build_flags =
    -DAIRFRAME_ENABLE_WIFI=1
    -DAIRFRAME_ENABLE_MDNS=1
    -DAIRFRAME_ENABLE_WEBSERVER=1
    -DAIRFRAME_ENABLE_I2C=1
```

Runtime toggles (`Configuration.is*Enabled`) exist only for compiled-in
features; each consuming project ships its own `Configuration`.

## App identity (ESP32 WiFi)

The shared `ESP32WiFi` service derives its hostname from a build-time macro:

```ini
build_flags =
    -DAIRFRAME_APP_HOSTNAME_PREFIX=\"SmartLights\"   # default: AirFrame
```

giving `<PREFIX>-XXXXXX.local` (low 24 bits of the efuse MAC). The boot
grace period before falling back to the configuration portal is
`-DAIRFRAME_WIFI_CONNECT_GRACE_MS=15000` (default 15000).

## Feature flag contract

`AIRFRAME_ENABLE_HOMESPAN`, `AIRFRAME_ENABLE_WIFI`, `AIRFRAME_ENABLE_MDNS`,
`AIRFRAME_ENABLE_WEBSERVER`, `AIRFRAME_ENABLE_REST`, `AIRFRAME_ENABLE_TELEPLOT`,
`AIRFRAME_ENABLE_I2C` — see `Platform/Features.hpp` for semantics.

## App-specific code stays in the consumer

Configuration, task tables, `main.cpp`, web routes, devices/peripherals and the
web assets are **not** here. This repo holds only what two or more projects
share, with project identity parameterized via the flags/macros above.

## License

MIT (see `LICENSE`).
