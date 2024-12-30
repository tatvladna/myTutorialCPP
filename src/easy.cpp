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
#include <algorithm> 

using namespace std;
#define DEBUG 1

bool isTwoDigitNumber(const int &num);
bool isPalindrome(const std::string& str);

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
    cout << "=============== Задача №1 ====================" << endl;
    int num;
    do {
        std::cout << "Введите двухзначное число: ";
        std::cin >> num;
        if (isTwoDigitNumber(num)) {
            break;
        } else {
            continue;
        } 
    } while (true);
    num = std::abs(num);
    int maxDigit = num % 10 > num / 10 ? num % 10 : num / 10;
    int minDigit = num % 10 < num / 10? num % 10 : num / 10;
    cout << maxDigit << " - большая цифра" << endl;
    cout << minDigit << " - меньшая цифра" << endl;


    // Задача 2: Нужно определить является ли строка палиндромом
    cout << "=============== Задача №2 ====================" << endl;

    std::string inputString2;
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString2);
    if (isPalindrome(inputString2)) {
        std::cout << "Строка является палиндромом." << std::endl;
    } else {
        std::cout << "Строка не является палиндромом." << std::endl;
    }

    // Задача 3: Найти след матрицы,  след матрицы — сумма элементов главной диагонали. 
    // Размер матрицы вводит пользователь, матрицу заполнять случайными числами.
    cout << "=============== Задача №3 ====================" << endl;
    int n;
    do {
        std::cout << "Введите размер матрицы (n x n): ";
        std::cin >> n;
        if (n > 100) {
            std::cout << "Пожалуйста, введите число меньше 100\n";
            continue;
        } else break;
        } while (true);
    std::srand(std::time(0));
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "Сгенерированная матрица: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = std::rand() % 100;  // заполним случайным числом от 0 до 99
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int trace = 0;
    for (int i = 0; i < n; ++i) {
        trace += matrix[i][i]; 
    }
    std::cout << "След матрицы: " << trace << std::endl;

    // ==================== end ============================
    unsigned int endTime = clock();
    unsigned int resultTime = endTime - startTime;
    timeTime(resultTime);
    system("pause");
    return 0;
}

bool isTwoDigitNumber(const int &num) {
    // Проверяем, что число является двухзначным (включая отрицательные числа)
    return (num >= 10 && num <= 99) || (num <= -10 && num >= -99);
}

bool isPalindrome(const std::string& str) {
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr;
}