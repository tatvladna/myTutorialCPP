#include "../include/help.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <ctime>

void writeLog (const string title) {
    ofstream logFile("logger.log", ios::app);
    if (!logFile.is_open()) {
        return;
    }
    logFile << "============= Запуск файла  " << title << " ==============="<<  endl;
    logFile << "Ваше счастливое число: " << rand() % 100 + 1 << " :)" << endl;
    srand(time(0));
    logFile << "Ваше действительно счастливое число: " << rand() << " :)" << endl;

}

void timeTime (unsigned int &t ) {
    try {
        t /= 1000.0; // перевод из млс в секунды
        ofstream logFile("logger.log", ios::app);
        if (!logFile.is_open()) {
            throw "Error opening log file";
        }
        logFile << "Время выполнения программы: " << t << " сек."<< endl;
    }
    catch (string exp) {
        cerr << exp << endl;
        return;
    }
} 