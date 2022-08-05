Del "../release/SoloDLL_CPP32.dll"
Del "../release/SoloDLL_CPP32.h"
g++ -o ../release/SoloDLL_CPP32.dll -s -shared SoloMotorControllers.cpp -Wl,--subsystem,windows -m32
copy SoloMotorControllers.h ..\release\SoloDLL_CPP32.h