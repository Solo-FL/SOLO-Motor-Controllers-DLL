SoloMotorControllers.h <- C/C++ source code used for generate the DLL
SoloMotorControllers.cpp <- C/C++ source code used for generate the DLL
Generate_SoloDLL_CPP32.bat <- run it for generate SoloDLL_CPP32.dll in relase folder
Generate_SoloDLL_CPP64.bat <- run it for generate SoloDLL_CPP.dll in relase folder


NOTE CONFIGURATION
- Need Mingw-w64 for run bat file, they call: g++. More info here: https://code.visualstudio.com/docs/cpp/config-mingw
- For generate 32 bit and 64 bit version we use MinGW-W64 GCC-8.1.0 . Find it here: https://sourceforge.net/projects/mingw-w64/files/