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
    cout << 1<< " ";
    }
    // конструктор по умолчанию
    A(): a(0), b(0) {};
    // конструктор для принятия одного аргумента
    explicit A (int a) {
    this -> a = a;
    b = a;
    cout << 2<< " ";
    }

    // перегрузка оператора присваивания
    A &operator=(const A &obj) {
        if (this != &obj) {
            a = obj.a;
            b = obj.b;
    }
    cout << 4<< endl;
    return *this;
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

// 1.4
class A4 {
    int x;

    public:

        // запретив неявное объявление объекта, чтобы избежать копирования
        explicit A4 (int x) {
            this->x = x;
        }
        // конструктор копирования
        A4 (const A4& obj) {
            this->x = obj.x;
        }
        // перегрузка оператора *= с использованием локальных переменных
        A4 &operator *= (const int value) {
            x *= value;
            return *this; // возвращаем ссылку на текущий объект
        }
        // перегрузка оператора *= с использованием объекта
        A4 &operator *= (const A4& obj) {
            x *= obj.x;
            return *this; // возвращаем ссылку на текущий объект
        } 
        int get() const {
            return x;
        }

};

// 1.5
class B5 {
    int s;
    public:
    // конструктор по умолчанию
    B5 () {
        s = 10;
    }

    // конструктор копирования
    B5 (const B5 &s ) {
        this->s = s.s;
    }
    int get () {
        return s;
    }
};

// 1.6
class C {
    int value;
    public:

    // конструктор по умолчанию
    C() {
        value = 0;
    }

    C (int val): value(val) {};

    // конструктор копирования
    C (const C &obj) {
        value = obj.value;
    } 

    // перегрузка оператора сложения
    C operator+(const C &obj) const{
        return C(value + obj.value);
    }

    int get () const{
        return value;
    }


};

// 1.7
class A7 {
    int value;
    public:

    // конструткор с дефолтным значением (единсвенно явно описанный коснтруктор)
    explicit A7 (int val = 7) {
        value =val; // запрещаю неявное создание объекта, чтобы избежат ькопирования
    }



    // перегрузка оператора *=
    // в данной задаче lдве перегрузки: числом int и коснтантным объектом
    A7 &operator*= (int val) {
        value *= val;
        return *this; // обязательно возвращаем ссылку на текущий объект
    } 
    // перегрузка оператора *= константным объектом
    A7 &operator*= (const A7 &obj) {
        value *= obj.value;
        return *this; // обязательно возвращаем ссылку на текущий объект
    } 
    int get () const{
        return value;
    }
};
// 1.8
class B8 {
    int value;
    public:

    // единственный явно описанный коснтруктор (с дефолтным значением)
    B8(int x = 0, int y=0) {
        this->value = (x + y);
    }

    // конструктор копирования 
    B8(const B8& object) {
        value = object.value;
    }

    // перегрузка оператора +=
    B8  &operator+=(const B8& object) {
        value += object.value;
        return *this; // обязательно возврщаем ссылку на текущий объект
    }

    int get() const{
        return value;
    }

    void setValue() {
        cout << "Enter a number: ";
        cin >> value;
    }

    // Напишем деструктор
    ~B8() { 
        cout << "Объект, находящийся по адресу " << this << ", удален." << endl;
    }

};

//1.9
class C9 {
    int value;
    public:
    // конструктор с дефолтным значением
    // запрещаю неявное объявление класса, чтобы избежать лишнего копирования
    explicit C9(int value = 7) {
        this->value = value;
    }

    //  оператор +
    C9 operator+(const C9 &obj) const{
        return C9(value + obj.value);
    }
    int get() const{
        return value;
    }

    // Напишем деструктор 
    ~C9() {
        cout << "Объект, находящийся поадресу " << this << ", удален." << endl;
    }

};

//1.13
// Запрещаем передавать структуру с помощью delete
struct mystr {
    int a, b;
    mystr(const mystr& object) = delete;  // Запрещаем копирование при попытке передать объект структуры mystr
};

int i = sizeof(mystr);

// int f(mystr s) {  // Ошибка: нельзя передавать структуру по значению
//     return 0;
// }

// 1.14


int runMSUTasks1 () {
    string titleFile = "msuTasks1.cpp";
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    unsigned int startTime = clock();
    if (DEBUG) {
        writeLog(titleFile);
    } 
    // ==================== start ==========================

    // 1.1
    cout << "=================== Задача 1.1 =======================" << endl;
    A x (1); // явный вызов конструктора
    A y;
    A z = A (2.5, 4);
    // A s = 6; // неявный вызов конструктора запрещен, чтобы не возникало копирования
    A w = z;
    x = z = w;

    //1.2
    cout << "=================== Задача 1.2 ======================" << endl;
    UniversalClassA ua1 ("hello", 4, 3);
    UniversalClassA ua2 (5, 3, '7', 3); 
    UniversalClassA ua3 (4.3, 6.3, "world");

    // 1.4
    cout << "=================== Задача 1.4 ==================" << endl;
    A4 a1 (5), a2 (3); // a2 = 3 - запрещено делать
    a1 *= 10;
    a2 *= a1 *= 2;
    cout << a1.get() << " " << a2.get() << " "  << endl;

    // 1.5
    cout << "=================== Задача 1.5 ==================" << endl;
    B5 b1, b2 = b1, b3 (b2);
    cout << b1.get() << " " << b2.get() <<  " " << b3.get () << endl;

    // 1.6
    cout << "=================== Задача 1.6 ==================" << endl;
    C c1 (7), c2 = 5, c3 (c1 + c2);
    cout << c1.get()<< " " << c2.get() << " " << c3.get () << endl;

    // 1.7
    cout << "=================== Задача 1.7 ==================" << endl;
    A7 a1_7(5), a2_7 (4), a3_7; // нельзя a2 = 4
    a2_7 *= a1_7 *= 3;
    cout << a1_7.get( ) << ' ' << a2_7.get() << ' ' << a3_7.get( ) << endl;

    // 1.8
    cout << "=================== Задача 1.8 ==================" << endl;
    B8 *b1_8 = new B8(); // инициализируем объект в динамической памяти с помощью конструктора по умолчанию
    cout << "Введите значение для b1_8, чтобы его записать в динамическую память: ";
    b1_8->setValue();
    B8 b2_8(2,3); // статический объект
    B8 *b3_8 = new B8(*b1_8); // инициализируем объект в динамической памяти с помощью другого объекта (который тоже в динамич. памяти)
    *b1_8 += b2_8 += *b3_8;
    cout << b1_8->get() << ' ' << b2_8.get() << ' ' << b3_8->get() << endl;
    delete b1_8;
    delete b3_8; // обязательно удаляем динамические объекты


    // 1.9
    cout << "=================== Задача 1.9 ==================" << endl;
    { 
        C9 c1_9(7), c2_9 (5), c3_9(c1_9 + c1_9);
        cout << c1_9.get ( ) << ' ' << c3_9.get ( ) << endl;
    }




    // ==================== end ============================
    unsigned int endTime = clock();
    unsigned int resultTime = endTime - startTime;
    timeTime(resultTime);
    system("pause");
    return 0;
}