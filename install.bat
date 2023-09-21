@echo off
set ROOT="%cd%"
set CONAN=--profile %ROOT%/.conan/windows.conf --build missing -s compiler.version=13

:: Dependencies
echo [+] Dependencies
conan create deps/minhook %CONAN%

:: Build
echo [+] Build
mkdir build
cd build
conan install .. %CONAN%
cmake .. -A Win32
cmake --build .

:: Binary
copy /v bin\IW3SR.dll "%COD4%\miles\mssIW3SR.asi"
