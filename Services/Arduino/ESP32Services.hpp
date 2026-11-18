#pragma once
#include "Features.hpp"
#include "iServices.hpp"
#if AIRFRAME_ENABLE_I2C
#include "I2CUtil.hpp"
#endif
#include "Platform.hpp"
#include "Configuration.hpp"
#if AIRFRAME_ENABLE_WIFI
#include "ESP32WiFi.hpp"
#endif
#if AIRFRAME_ENABLE_HOMESPAN
#include "ESP32Homespan.hpp"
#endif
#if AIRFRAME_ENABLE_WEBSERVER
#include "ESP32WebServer.hpp"
#endif

class ESP32Services : public iServices
{
public:
  void Init(void) override
  {
    ResetReason resetReason;
    resetReason.print();
#if AIRFRAME_ENABLE_I2C
    Common::I2CUtil::Init();
    Common::I2CUtil::Scan();
#endif
#if AIRFRAME_ENABLE_WIFI
    if (Configuration.isWiFiEnabled)
    {
      esp32WiFi.setup();
    }
#endif
#if AIRFRAME_ENABLE_HOMESPAN
    if (Configuration.isHomeSpanEnabled)
    {
      homespan.Init();
    }
#endif
#if AIRFRAME_ENABLE_WEBSERVER
    if (Configuration.isWebServerEnabled)
    {
      esp32WebServer.Init();
    }
#endif
    isInitialized = true;
  }

  void Poll(void) override
  {
#if AIRFRAME_ENABLE_WIFI
    if (Configuration.isWiFiEnabled)
    {
      esp32WiFi.run();
    }
#endif
#if AIRFRAME_ENABLE_HOMESPAN
    if (Configuration.isHomeSpanEnabled)
    {
      homespan.Poll();
    }
#endif
#if AIRFRAME_ENABLE_WEBSERVER
    if (Configuration.isWebServerEnabled)
    {
      esp32WebServer.Poll();
    }
#endif
  }

private:
#if AIRFRAME_ENABLE_WIFI
  ESP32WiFi esp32WiFi = ESP32WiFi();
#endif
#if AIRFRAME_ENABLE_HOMESPAN
  ESP32HomeSpan homespan = ESP32HomeSpan();
#endif
#if AIRFRAME_ENABLE_WEBSERVER
  ESP32WebServer esp32WebServer = ESP32WebServer();
#endif
};
