/*
решение задач с сайта http://cppstudio.com/cat/285/288/
*/

#include <iostream>
#include <fstream>
#include <string>
#include "../include/help.h"
#include "../include/normal.h"
#include <ctime>
#include <clocale>
#include <stack>
#include <sstream>
#include <stdexcept>

using namespace std;
#define DEBUG 1

double calculateContinuedFraction(int n);
int getIntInput(const std::string& prompt);

int runNormal () {
    string titleFile = "normal.cpp";
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

    // Задача 1: В текстовом файле, содержащем текст программы на языке Си, проверить соответствие открывающихся и закрывающихся фигурных скобок { и }. 
    // Результат проверки вывести на экран и записать в виде фразы в текстовый файл. 
    // Результат работы программы (вывод) поместить в отдельный текстовый файл (например, "out . txt " ), продублировав на экране.
    cout<< "=============================== Задача №1 ========================================="<< endl;
    std::fstream myInputFileC("./data/input/randomTextC.txt");
    std::ofstream myOutputFileC("./data/output/reportOutput.txt");
    if (!myInputFileC.is_open()) {
        writeLogError("Error: Файл с кодом на языке С не удалось открыт");
    }

    if (!myOutputFileC.is_open()) {
        writeLogError("Error: Файл для вывода не удалось открыт");
    }

    std::string line;
    std::stack<char> stackBrackets;
    int lineNumber (0);
    while(std::getline(myInputFileC, line)) {
        lineNumber++;
        for (char c : line) {
            if (c == '{') {
                stackBrackets.push('{');
            } else if (c == '}') {
                if (stackBrackets.empty()) {
                    myOutputFileC << "Лишняя закрывающая '}' скобка в строке № "<< lineNumber << endl;
                    myOutputFileC.close();
                    break;
                }
                stackBrackets.pop(); // удаляем последнюю скобку
            }
        }
    }

    // в конце мы должны получить пусток стэк
    if (!stackBrackets.empty()) {
            myOutputFileC << "Лишняя открывающая '{' скобка"<< endl;
            myOutputFileC.close();
        }

    if (myOutputFileC.is_open()) {
        myOutputFileC << "Количество открывающихся скобок '{' == соответсвует количеству закрыающихся '}' ";
        myOutputFileC.close();
    }
    cout << "Пожалуйста, посмотрите в файл в папке ./data/output" << endl;
    myInputFileC.close();



    // Задача 2: Используя показатели функции вычислить цепную дробь. Количество елементов дроби надо задавать с клавиатуры.
    cout<< "=============================== Задача №2 ========================================="<< endl;
    int n;
    n = getIntInput("Введите целое число: ");
    double result = calculateContinuedFraction(n);
    cout << "Результат цепной дроби: " << result << endl;


    // Задача 3: Нужно вычислить произведение матрицы на вектор. В полученном векторе найти макисмальный  элемент. необходимо решить данную задачу тремя способами:

            // 1. с использованием статических массивов
            // 2. использовать только динамические массивы с явным разыменованием указателя
            // 3. использовать только динамические массивы, адресацию к элементам массива выполнять с помощью индексов.
            // То есть, у вас должно получиться три отдельных исходника — три программы.


    // Задача 4: Задача на динамическое выделение памяти. Изначально есть указатель на массив с одним элементом. 
    // Пользователь вводит число. Если оно больше 0 записываем его в массив. 
    // Далее пользователь вводит второе число, тут уже,  если оно больше 0, надо пере выделять память для 2-х элементов массива и записать в массив второе число. 
    // И так далее…  для 3-х элементов, для 4-х…  пока пользователь не введет отрицательное число. 


    // Задача 5: Необходимо создать структуру, которая содержит элемент типа int и строку. 
    // Объявить указатель типа структуры (объект структуры) и выделить память для хранения данных одной структуры. 
    // Предложить пользователю внести данные и записать их в элементы объекта структуры. 
    // Далее пользователю необходимо сделать выбор: внести еще данные (создать еще один объект структуры) либо выйти из программы. 
    // Если пользователь продолжает ввод — необходимо выделить новую память для указателя на объект структуры и дописать в нее введенные пользователем новые данные. 
    // Цикл выделения новой памяти продолжается, пока пользователь не выберет выход из программы.



    // ==================== end ============================
    unsigned int endTime = clock();
    unsigned int resultTime = endTime - startTime;
    timeTime(resultTime);
    system("pause");
    return 0;
}


double calculateContinuedFraction(int n) {
    double result = 1.0;  // нач. значение дроби
    for (int i = 0; i < n - 1; i++) {
        result = 1.0 / (1.0 + result);  // Вычисление каждого элемента цепной дроби
    }
    return 1.0 + result;  // Добавление единицы в начале цепной дроби
}

int getIntInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (iss >> value && iss.eof() && value > 0) {
            return value;
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите целое положительное число.\n";
        }
    }
}
