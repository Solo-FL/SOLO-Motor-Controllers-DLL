g++ -c -o SoloDLL_CPP.o SoloDLL_CPP.cpp  -D SOLOLIBRARY_EXPORTS
g++ -o SoloDLL_CPP.dll SoloDLL_CPP.o -s -shared -Wl,--subsystem,windows