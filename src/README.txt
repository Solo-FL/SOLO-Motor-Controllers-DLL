SoloDLL_CPP.h <- C/C++ source code used for generate the DLL
SoloDLL_CPP.c <- C/C++ source code used for generate the DLL
build32.bat <- run it for generate SoloDLL_CPP32.dll
build64.bat <- run it for generate SoloDLL_CPP.dll
SoloDLL_CPP.o <- temp file generate from the bat file (no user usage)
SoloDLL_CPP.dll <- 64bit C/C++ DLL
SoloDLL_CPP32.dll <- 32bit C/C++ DLL

NOTE CONFIGURATION
- Need Mingw-w64 for run bat file, they call: g++. More info here: https://code.visualstudio.com/docs/cpp/config-mingw
- For generate 32 bit and 64 bit version we use MinGW-W64 GCC-8.1.0 . Find it here: https://sourceforge.net/projects/mingw-w64/files/