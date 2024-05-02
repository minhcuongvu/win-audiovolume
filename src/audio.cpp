#include "audio.h"

void Audio::SetSystemVolume(float volume)
{
  CoInitialize(nullptr);
  IMMDeviceEnumerator *deviceEnumerator = nullptr;
  HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_INPROC_SERVER,
                                __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);

  if (SUCCEEDED(hr))
  {
    IMMDevice *defaultDevice = nullptr;
    hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    if (SUCCEEDED(hr))
    {
      IAudioEndpointVolume *endpointVolume = nullptr;
      hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, nullptr,
                                   (LPVOID *)&endpointVolume);
      defaultDevice->Release();
      if (SUCCEEDED(hr))
      {
        // Set the volume
        hr = endpointVolume->SetMasterVolumeLevelScalar(volume, nullptr);
        if (FAILED(hr))
        {
          std::cerr << "Failed to set volume" << std::endl;
        }
        endpointVolume->Release();
      }
    }
  }
  CoUninitialize();
}
