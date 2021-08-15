<h1 align="center"> Ray N Vader </h1>
<p align="center">
  <img src="https://img.shields.io/badge/Made%20With%20-C%2B%2B%2FQt-%2323005A">
</p>

**Ray N Vader** is a game written in C++ using Raylib.

## Build and Run

Download raylib using vcpkg -
```
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg integrate install
vcpkg install raylib:x64-windows
```
Clone the repo and run -
```
md build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE="path_to_vcpkg.cmake" -DVCPKG_TARGET_TRIPLET=x64-windows
mingw32-make
```

This will generate the binary executable as `build\Ray-n-vader.exe`.
