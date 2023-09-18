#include "Common.h"
#include <clocale>
#include <fstream>
#include <vector>

using namespace std;

int getInt() {
	int input = 0;
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка, введите число: ";
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}



using namespace std;

stringC::stringC() {
	result = "";
}


void stringC::setStr(string& newStr) {
	result += newStr;
}


