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
	cout << "Введите максимальный размер для ширины" << endl;
	countX = getInt();
	cout << "Введите максимальный размер для длины" << endl;
	countY = getInt();

	while (countX <= 0 || countY<=0) {
		cout << "Число должно быть больше 0 " << endl;
		cout << "Попробуйте еще раз " << endl;
		countX = getInt();
	}
	x = rand() % countX;
	y = rand() % countY;
	

	cout << endl;
	cout << "Сгенерированные размеры лабиринта: " << x <<"x" << y << endl;
	cout << endl;
}

void keyboardInput::createNum(int& x, int& y) {
	cout << "Введите размеры лабиринта: " << endl;
	cin >> x >> y;
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
	string save1, save2;
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
