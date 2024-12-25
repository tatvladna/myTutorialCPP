#include "../header/help.h"
#include <fstream>
#include <iostream>
using namespace std;

void writeLog (const std::string& messages) {
    ofstream logFile("logger.log", ios::app);
    if (!logFile.is_open()) {
        cerr << "Error: "<< messages << endl;
        return;
    }
    logFile << messages << endl;

}