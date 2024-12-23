#include <iostream>

void hello() {
    std::cout << "Hello, World!" << std::endl;
}

void goodbye() {
    std::cout << "Goodbye, World!" << std::endl;
}


int main() {
    const short number = 1;
    if (number == 0) {
        hello();
    } else {
        goodbye();
    }
    return 0;
}