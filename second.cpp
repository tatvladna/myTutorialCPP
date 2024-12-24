#include <iostream>
#define DEBUG 100
#include <cassert>
#include <fstream>
#include <cstdio>

int main() {
    #ifdef DEBUG 
        std::cout << "DEBUG mode is ON" << std::endl;
    #endif

    #ifdef __cplusplus 
        std::cout << "Hello, C++!" << std::endl;
    #endif

    std::cout << ":)" << std::endl; 

    const short number = 0;
    std::ofstream logFile("errors.log", std::ios::app);
    if (number == 0) {
        logFile << "Erorr: number = 0" << std::endl;
    }
    logFile.close();
    // assert(number != 0);
    return 0;

}