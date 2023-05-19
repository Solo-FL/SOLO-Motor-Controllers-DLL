Del "..\release\Kvaser\x86\SoloDLLKvaser_CPP32.dll"
Del "..\release\Kvaser\x86\SoloDLLKvaser_CPP32.h"
g++ -o ../release/Kvaser/x86/SoloDLLKvaser_CPP32.dll -I ..\inc -I ..\src -s -shared SOLOMotorControllersKvaser.cpp SOLOMotorControllersUtils.cpp Kvaser.cpp -L ../lib -lcanlib32 -Wl,--subsystem,windows -m32
copy SoloMotorControllersKvaser.h ..\release\Kvaser\x86\SoloDLLKvaser_CPP32.h