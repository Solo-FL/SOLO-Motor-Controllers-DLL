Del "../release/SoloDLL_CPP64.dll"
Del "../release/SoloDLL_CPP64.h"
g++ -o ../release/SoloDLL_CPP64.dll -s -shared SoloMotorControllers.cpp -Wl,--subsystem,windows
copy SoloMotorControllers.h ..\release\SoloDLL_CPP64.h