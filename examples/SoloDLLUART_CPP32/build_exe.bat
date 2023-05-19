g++ -c test1.cpp
g++ -m32 -o dllTestUART32.exe test1.o -L ../../release/UART/x86 -lSoloDLLUART_CPP32 