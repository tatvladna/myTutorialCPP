/*
решение задач с сайта http://cppstudio.com/cat/285/288/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../include/help.h"
#include "../include/normal.h"
#include <cmath>
#include <ctime>
#include <clocale>
#include <Windows.h>

using namespace std;
#define DEBUG 1


int runNormal () {
    string titleFile = "easy.cpp";
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    unsigned int startTime = clock();
    if (DEBUG) {
        writeLog(titleFile);
    } 
    // ==================== start ==========================



    // ==================== end ============================
    unsigned int endTime = clock();
    unsigned int resultTime = endTime - startTime;
    timeTime(resultTime);
    system("pause");
    return 0;
}
