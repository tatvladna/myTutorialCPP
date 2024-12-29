/*
Решение задач с сайта http://cppstudio.com/cat/285/286/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../include/help.h"
#include "../include/beginner.h"
#include <cmath>
#include <ctime>
#include <clocale>
#include <locale> // Для работы с локалью
#include <Windows.h>
#include <algorithm>
#include <map>
#include <sstream>
#include <stdexcept>
#include <cctype> // Для std::islower
using namespace std;
#define DEBUG 1

double getInput(const std::string& prompt);
bool isSingleLowercase(const std::string& input);



int runBeginner () {
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    string titleFile = "beginner.cpp";
    unsigned int startTime = clock();
    if (DEBUG) {
        writeLog(titleFile);
    } 
    // перехватываем mode из main.cpp
    string *inputDelete = new string();
    getline(std::cin, *inputDelete);
    delete inputDelete;
    
    // ==================== start ==========================

    // Задача 1: Составить программу, которая будет считывать введённое пятизначное число. 
    // После чего, каждую цифру этого числа необходимо вывести в новой строке.

    cout << "=============== Задача №1 ====================" << endl;
    string strInput1;
    do {
        cout << "Введите пятизначное число: ";
        getline(std::cin, strInput1);
        if (strInput1.size() == 5 && std::all_of(strInput1.begin(), strInput1.end(), ::isdigit)) {
            break;
        }
    } while(true);

    int newNum;
    try {
        newNum = std::stoi(strInput1);
    }
    catch (const std::invalid_argument &exp) {
        cout << "error" << endl;
        return 1;
    }

    cout << "1 number = " << newNum / 10000 << endl;
    cout << "2 number = " << newNum / 1000 % 10 << endl;
    cout << "3 number = " << newNum / 100 % 10  << endl;
    cout << "4 number = " << newNum / 10 % 10 << endl;
    cout << "5 number = " << newNum % 10 << endl;


    cout << "========================= Задача №2 ==============================" << endl;
    // Задача 2: Запрограммировать следующее выражение: (а + b — f / а) + f * a * a — (a + b) Числа а, b, f вводятся с клавиатуры. 
    // Организовать пользовательский интерфейс, таким образом, чтобы было понятно, в каком порядке должны вводиться числа.

    std::map<std::string, double> myMap;
    cout << "Для решения уравнения нужно ввести числа а, b, f: ";

    do {myMap["a"] = getInput("Введите значение a: ");
        if (myMap["a"] != 0) {
            break;
        }
        else{
            std::cout << "Значение a не должно быть равно 0, так как будет деление на ноль.\n";
            continue;
        }
    } while(true);
    myMap["b"] = getInput("Введите значение b: ");
    myMap["f"] = getInput("Введите значение f: ");

    double a = myMap["a"];
    double b = myMap["b"];
    double f = myMap["f"];

    double result = (a + b - f / a) + f * a * a - (a + b);
    
    cout << "Результат вычисления (а + b — f / а) + f * a * a — (a + b): "<< result << endl;



    // Задача 3: Напишите программу, которая позволяет пользователю ввести в консоли латинскую букву нижнего регистра,  
    // переводит её в верхний регистр и результат выводит в консоль.
    cout << "========================= Задача №3 ==============================" << endl;

    string inputLowercase;
    do {
        cout << "Введите букву нижнего регистра: ";
        getline(cin, inputLowercase);
        if (isSingleLowercase(inputLowercase)) {
            break;
        } else {
            continue;
        }
        } while (true);

    char upperLetter = std::toupper(inputLowercase[0]); // берем 0-й элемент
    cout << "Буква в верхнем регистре: " << upperLetter << endl;



    // Задача 4: Программа должна переводить число, введенное с клавиатуры в метрах, в километры.

    cout << "========================= Задача №4 ==============================" << endl;

    double inputNumber4;
    inputNumber4 = getInput("Введите количество метров: ");
    string outputKM;
    int newNumber4 = std::floor(inputNumber4); // округляем в меньшую сторону
    if (newNumber4 % 10 == 1) {
        outputKM = " километр = ";
    } else if (newNumber4 % 10 == 2 || newNumber4 % 10 == 3 || newNumber4 % 10 == 4) {
        outputKM = " километра = ";
    } else {
        outputKM = " километров = ";
    }

    cout << inputNumber4 << outputKM << inputNumber4/1000 << " м." << endl;

    // Задача 5: Составьте программу, которая напечатает рисунок, используя символы из таблицы ASCII 
    cout << "========================= Задача №5 ==============================" << endl;

    // Задача 6: Программа должна нарисовать домик, как показано на рисунке 1. 
    // Строительным материалом являются: символы слэша (прямой /, обратный , вертикальный |), знак минуса, символ подчёркивания.
    cout << "========================= Задача №6 ==============================" << endl;

    // Задача 7: Используя один оператор вывода cout, программа должна напечатать прямоугольный треугольник из символов знака плюс +
    cout << "========================= Задача №7 ==============================" << endl;

    cout << "С наступающим новым 2025 годом ! :)"<< endl;
    std::cout << "    *    \n";
    std::cout << "   ***   \n";
    std::cout << "  *****  \n";
    std::cout << " ******* \n";
    std::cout << "********* \n";
    std::cout << "   | |    \n";
    std::cout << "   |_|  \n";


    cout << "========================= Задача №8 ==============================" << endl;
    // Задача 8: Напишите программу, запрашивающую имя, фамилия, отчество и номер группы студента и выводящую введённые данные в следующем виде:

                    /* ********************************
                    * Лабораторная работа № 1      *
                    * Выполнил(а): ст. гр. ЗИ-123  *
                    * Иванов Андрей Петрович       *
                    ******************************** */
    // Необходимо, чтобы программа сама определяла нужную длину рамки. 
    // Сама же длина рамки зависит от длины наибольшей строки внутри рамки. Используя циклы for легко можно выровнять стороны рамки.


    cout << "========================= Задача №9 ==============================" << endl;
    // Задача 9: Составить программу, которая требует ввести два числа. 
    // Если первое число больше второго, то программа печатает слово больше. 
    // Если первое число меньше второго, то программа печатает слово меньше. 
    // А если числа равны, программа напечатает сообщение Эти числа равны.

    double num1, num2;
    num1 = getInput("Введите первое число: ");
    num2 = getInput("Введите второе число: ");
    if (num1 > num2) {
        std::cout << "Больше" << std::endl;
    } else if (num1 < num2) {
        std::cout << "Меньше" << std::endl;
    } else {
        std::cout << "Эти числа равны" << std::endl;
    }

    cout << "========================= Задача №10 ==============================" << endl;
    // Задача 10: Составить алгоритм увеличения всех трех, введённых с клавиатуры, переменных на 5,если среди них есть хотя бы две равные. 
    // В противном случае выдать ответ «равных нет».


    double number1, number2, number3;

    number1 = getInput("Введите первое число: ");
    number2 = getInput("Введите первое число: ");
    number3 = getInput("Введите первое число: ");

    if (number1 == number2 || number1 == number3 || number2 == number3) {
        number1 += 5;
        number2 += 5;
        number3 += 5;
        std::cout << "После увеличения на 5:\n";
        std::cout << "Первое число: " << number1 << "\n";
        std::cout << "Второе число: " << number2 << "\n";
        std::cout << "Третье число: " << number3 << "\n";
    } else {
        std::cout << "Равных нет" << std::endl;
    }


    // ==================== end ============================
    unsigned int endTime = clock();
    unsigned int resultTime = endTime - startTime;
    timeTime(resultTime);
    system("pause");
    return 0;
}



double getInput(const std::string& prompt) {
    double value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (iss >> value && iss.eof()) {
            return value;
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите число.\n";
        }
    }
}

bool isSingleLowercase(const std::string& input) {
    // Проверяем, что строка состоит ровно из одного символа
    return input.length() == 1 && std::islower(input[0]);
}