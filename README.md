# win-audiovolume

## setup

install `MSYS2` using installer from [MSYS2.org](https://www.msys2.org/)

```shell
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-make
pacman -S mingw-w64-ucrt-x86_64-cmake
pacman -S mingw-w64-ucrt-x86_64-gdb
```

## Tasks

- `CMake Configure Debug`: Configure the build system using MSYS2 g++ compiler.
- `CMake Configure Release`: Configure the build system using MSYS2 g++ compiler.
- `Build Debug`: Build in Debug mode.
  - dependsOn: `CMake Configure Debug`
- `Build Release`: Build in Release mode.
  - dependsOn: `CMake Configure Release`
- `Strip Executables`: Strip all symbols from executables in the build/bin directory.
- `Build Release & Strip`: Strip all symbols from executables in the build/bin directory.

## Usage

On windows terminal/cmdline, use `audiovolume.exe 20`.
On Linux, use `./audiovolume 20`.
