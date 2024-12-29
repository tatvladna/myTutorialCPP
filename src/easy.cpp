/*
решение задач с сайта http://cppstudio.com/cat/285/287/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../include/help.h"
#include "../include/easy.h"
#include <cmath>
#include <ctime>
#include <clocale>
#include <Windows.h>

using namespace std;
#define DEBUG 1


int runEasy () {
    string titleFile = "easy.cpp";
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    unsigned int startTime = clock();
    if (DEBUG) {
        writeLog(titleFile);
    } 
    // перехватываем mode из main.cpp
    string *inputDelete = new string();
    getline(std::cin, *inputDelete);
    delete inputDelete;
    // ==================== start ==========================

    // Задача 1: Организовать ввод двухзначного натурального числа с клавиатуры. 
    // Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.


    // ==================== end ============================
    unsigned int endTime = clock();
    unsigned int resultTime = endTime - startTime;
    timeTime(resultTime);
    system("pause");
    return 0;
}