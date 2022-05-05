g++ -c -o SoloDLL_CPP.o SoloDLL_CPP.cpp  -D SOLOLIBRARY_EXPORTS -m32
g++ -o SoloDLL_CPP32.dll SoloDLL_CPP.o -s -shared -Wl,--subsystem,windows -m32