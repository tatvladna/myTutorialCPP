/*
решение задач с https://al.cs.msu.ru/files/cpp.tasks.2013.pdf
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../include/help.h"
#include "../include/msuTasks1.h"
#include <cmath>
#include <ctime>
#include <clocale>
#include <Windows.h>
#include <variant>
#include <sstream>

using namespace std;
#define DEBUG 1

// 1.1
// 1.2
class A {
    int a, b;
    public:
    // конструктор копирования должен принимать ссылку на константный объект
    A (const A & x) {
    a = x.a;
    b = x.b;
    cout << 1;
    }
    // конструктор по умолчанию
    A(): a(0), b(0) {};
    // конструктор для принятия одного аргумента
    explicit A (int a) {
    this -> a = a;
    b = a;
    cout << 2;
    }

    // ======= можно вообще запретить копировать ============
    // A(const A&) = delete;  // передаем константный объект и удаляем
    // A& operator=(const A&) = delete; // Запрет оператора присваивания

    // конструктор для принятия 2х аргументов
    // используем this, т.к аргументы и имена цленов класа совпадают
    A (double a, double b) {
        this->a = static_cast<int>(a);
        this->b = static_cast<int>(b);
    }
    };
    void f () {
    A x (1); // явный вызов конструктора
    A y;
    A z = A (2.5, 4);
    // A s = 6; // неявный вызов конструктора запрещен, чтобы не возникало копирования
    A w = z;
    x = z = w;
    }

// 1.2. Напишем универсальный класс

class UniversalClassA {
private:
    std::vector<std::variant<int, double, string, char>> data; // контейнер для хранения аргументов

public:
    template <typename... Args>
    explicit UniversalClassA(Args... args) {
        // сохраняем все переданные аргументы в контейнер
        (data.emplace_back(args), ...);

        std::cout << "Конструктор со следующими данными: ";
        printArgs(args...);
        std::cout << "\n";
    }

    template <typename... Args>
    void printArgs(Args... args) {
        ((std::cout << args << " "), ...);
    }
};

// 1.3
class A3 {
    int x;

    public:

        A3 (int x) {
            this->x = x;
        }
        // конструктор копирования
        A3 (const A3& obj) {
            this->x = obj.x;
        }
        // перегрузка оператора *= с использованием локальных переменных
        A3 &operator *= (const int value) {
            x *= value;
            return *this; // возвращаем ссылку на текущий объект
        }
        // перегрузка оператора *= с использованием объекта
        A3 &operator *= (const A3& obj) {
            x *= obj.x;
            return *this; // возвращаем ссылку на текущий объект
        } 
        int get() const {
            return x;
        }

};
int main () {
    A3 a1 (5), a2 = 3;
    a1 *= 10;
    a2 *= a1 *= 2;
    cout << a1.get() << a2.get() << endl;
    return 0;
}



int runMSUTasks1 () {
        string titleFile = "msuTasks1.cpp";
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    unsigned int startTime = clock();
    if (DEBUG) {
        writeLog(titleFile);
    } 
    // ==================== start ==========================

    //1.2
    UniversalClassA ua1 ("hello", 4, 3);
    UniversalClassA ua2 (5, 3, '7', 3); 
    UniversalClassA ua3 (4.3, 6.3, "world");



    // ==================== end ============================
    unsigned int endTime = clock();
    unsigned int resultTime = endTime - startTime;
    timeTime(resultTime);
    system("pause");
    return 0;
}