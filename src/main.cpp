#include "audio.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <volume percentage>" << std::endl;
    return 1;
  }

  float volume = std::stof(argv[1]) / 100.0f;
  Audio::SetSystemVolume(volume);
  return 0;
}