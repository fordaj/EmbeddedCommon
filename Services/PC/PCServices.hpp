#pragma once
#include "Features.hpp"
#include "iServices.hpp"
#include "Configuration.hpp"
#if AIRFRAME_ENABLE_WEBSERVER
#include "PCWebServer.hpp"
#endif

class PCServices : public iServices
{
public:
  void Init(void) override
  {
#if AIRFRAME_ENABLE_WEBSERVER
    if (Configuration.isWebServerEnabled)
    {
      webServer.Init();
    }
#endif
    isInitialized = true;
  }

  void Poll(void) override
  {
#if AIRFRAME_ENABLE_WEBSERVER
    if (Configuration.isWebServerEnabled)
    {
      webServer.Poll();
    }
#endif
  }

private:
#if AIRFRAME_ENABLE_WEBSERVER
  PCWebServer webServer = PCWebServer();
#endif
};
