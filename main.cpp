#include <iostream>
#include <string>
#include <map>
using namespace std;
#include <functional>


// ==============================
#include "./include/easy.h"
#include "./include/beginner.h"
#include "./include/normal.h"
#include "./include/hard.h"
#include "./include/experienced.h"

std::map<std::string, std::function<int()>> functionMap = {
        {"beginner", runBeginner},
        {"easy", runEasy},
        {"normal", runNormal},
        {"hard", runHard},
        {"experienced", runExperienced}
    };

int main() {

    /*
    - Доступные режимы соответветсвуют названиям файлов в папке /src
    - Функция выводит на экран решение задач
    */

    std::string mode;
    std::cout << "Enter mode: " << endl ;
    std::cout<< "\t -beginner" << endl ;
    std::cout<< "\t -easy" << endl ;
    std::cout<< "\t -normal" << endl ;
    std::cout<< "\t -hard" << endl ;
    std::cout<< "\t -experienced" << endl ;
    std::cin >> mode;

    if (functionMap.find(mode) != functionMap.end()) {
        functionMap[mode](); 
    } else {
        std::cout << "Unknown mode!" << std::endl;
    }

    return 0;
}
