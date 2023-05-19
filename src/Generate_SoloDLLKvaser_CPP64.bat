Del "..\release\Kvaser\x64\SoloDLLKvaser_CPP64.dll"
Del "..\release\Kvaser\x64\SoloDLLKvaser_CPP64.h"
g++ -c -o SOLOMotorControllersKvaser.o SOLOMotorControllersKvaser.cpp -I ..\inc -I ..\src  -D SOLOLIBRARY_EXPORTS
g++ -o ../release/Kvaser/x64/SoloDLLKvaser_CPP64.dll -I ..\inc -I ..\src -s -shared SOLOMotorControllersKvaser.cpp SOLOMotorControllersUtils.cpp Kvaser.cpp -L ../lib -lcanlib32 -Wl,--subsystem,windows
copy SoloMotorControllersKvaser.h ..\release\Kvaser\x64\SoloDLLKvaser_CPP64.h