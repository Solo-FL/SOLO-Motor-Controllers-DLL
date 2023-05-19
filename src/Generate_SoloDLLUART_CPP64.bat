Del "..\release\UART\x64\SoloDLLUART_CPP64.dll"
Del "..\release\UART\x64\SoloDLLUART_CPP64.h"
g++ -c -o SOLOMotorControllersSerial.o SOLOMotorControllersSerial.cpp  -D SOLOLIBRARY_EXPORTS
g++ -o ../release/UART/x64/SoloDLLUART_CPP64.dll SOLOMotorControllersSerial.o -I ..\inc -I ..\src -s -shared SOLOMotorControllersUtils.cpp -Wl,--subsystem,windows
copy SOLOMotorControllersSerial.h ..\release\UART\x64\SoloDLLUART_CPP64.h