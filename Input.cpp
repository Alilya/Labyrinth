#include <iostream>
#include <clocale>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

#include "Common.h"
#include "Input.h"

using namespace std;

void randomInput::createNum(int& x, int& y) {
	int countX,countY;
	cout << "¬ведите максимальный размер дл€ ширины" << endl;
	countX = getInt();
	cout << "¬ведите максимальный размер дл€ длины" << endl;
	countY = getInt();
	
	while (x < 5) {
		x = rand() % countX;
	}
	while (y < 5) {
		y = rand() % countY;
	}
	cout << endl;
	cout << "—генерированные размеры лабиринта: " << x <<"x" << y << endl;
	cout << endl;

	std::this_thread::sleep_for(500ms);
}

void keyboardInput::createNum(int& x, int& y) {
	cout << "¬ведите размеры лабиринта: " << endl;
	cout << "ƒлина: " << endl;
	x=getInt();
	while (x < 5) {
		cout << "„исло должно быть больше 4, пропробуйте еще раз! "<< endl;
		x = getInt();
	}
	cout << "Ўирина: " << endl;
	y = getInt();
	while (y < 5) {
		cout << "„исло должно быть больше 4, пропробуйте еще раз! " << endl;
		y = getInt();
	}
	std::this_thread::sleep_for(500ms);
}

bool checkEnter(string enterfile) {
	try {
		static_cast<void>(filesystem::is_regular_file(enterfile));
	}
	catch (...) {
		cout << "запись невозможна, использовано зарезервированное выражение" << endl;
		return true;
	}
	return false;
}

void fileInput::createNum(int& x, int& y) {
	string enterfile;
	cout << "введите полный путь файла " << endl;
	cin >> enterfile;

	while (checkEnter(enterfile)) {
		cout << "введите полный путь файла " << endl;
		cin >> enterfile;
	}

	ifstream filereading;
	filereading.open(enterfile);

	while (!filereading.is_open() || checkEnter(enterfile)) {
		cout << "ошибка, введите корректный/существующий адрес файла" << endl;
		cout << "введите полный путь файла " << endl;
		cin >> enterfile;
		filereading.close();
		filereading.open(enterfile);
	}

	if (filereading.eof()) {
		cout << "данных недостаточно " << endl;
	}
	else {
		string buff;
		getline(filereading, buff, '\n');
		x = stoi(buff);
		buff = "";
		getline(filereading, buff, '\0');
		y = stoi(buff);
		buff = "";
	}
	filereading.close();
}


unique_ptr<input> makeChoiceInput(int enter) {
	if (enter == random) {
		return make_unique<randomInput>();
	}
	if (enter == keyboard) {
		return make_unique<keyboardInput>();
	}
	if (enter == file) {
		return make_unique<fileInput>();
	}
	return make_unique<keyboardInput>();
}
