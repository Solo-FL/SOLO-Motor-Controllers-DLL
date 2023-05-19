Del "..\release\UART\x86\SoloDLLUART_CPP32.dll"
Del "..\release\UART\x86\SoloDLLUART_CPP32.h"
g++ -c -o SOLOMotorControllersSerial.o SOLOMotorControllersSerial.cpp  -D SOLOLIBRARY_EXPORTS -m32
g++ -o ../release/UART/x86/SoloDLLUART_CPP32.dll SOLOMotorControllersSerial.o -I ..\inc -I ..\src -s -shared SOLOMotorControllersUtils.cpp -Wl,--subsystem,windows -m32
copy SOLOMotorControllersSerial.h ..\release\UART\x86\SoloDLLUART_CPP32.h