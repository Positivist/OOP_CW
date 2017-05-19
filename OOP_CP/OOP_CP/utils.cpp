#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;

void writeToFile(string str) {
	logFile.open("D:/log.txt", ios_base::app);
	logFile << str;
	logFile.close();
}