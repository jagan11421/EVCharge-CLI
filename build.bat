
@echo off

echo Building EVChargeHub...

g++ -std=c++17 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o EVChargeHub.exe

if %errorlevel% neq 0 (
    echo Build failed!
    pause
    exit /b 1
)

echo.
echo Build successful!
echo Starting EVChargeHub...

EVChargeHub.exe

pause
