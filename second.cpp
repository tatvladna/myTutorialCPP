#include <iostream>
#define DEBUG 100

int main() {
    #ifdef DEBUG 
        std::cout << "DEBUG mode is ON" << std::endl;
    #endif

    #ifdef __cplusplus 
        std::cout << "Hello, C++!" << std::endl;
    #endif

    std::cout << ":)" << std::endl; 
    return 0;

}