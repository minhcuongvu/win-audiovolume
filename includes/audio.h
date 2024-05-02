#pragma once

#include <iostream>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <comdef.h>
#include <windows.h>

class Audio
{
public:
  static void SetSystemVolume(float volume);
};
