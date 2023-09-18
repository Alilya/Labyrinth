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
	cout << "������� ������������ ������ ��� ������" << endl;
	countX = getInt();
	cout << "������� ������������ ������ ��� �����" << endl;
	countY = getInt();

	while (countX <= 0 || countY<=0) {
		cout << "����� ������ ���� ������ 0 " << endl;
		cout << "���������� ��� ��� " << endl;
		countX = getInt();
	}
	x = rand() % countX;
	y = rand() % countY;
	

	cout << endl;
	cout << "��������������� ������� ���������: " << x <<"x" << y << endl;
	cout << endl;
}

void keyboardInput::createNum(int& x, int& y) {
	cout << "������� ������� ���������: " << endl;
	cin >> x >> y;
}

bool checkEnter(string enterfile) {
	try {
		static_cast<void>(filesystem::is_regular_file(enterfile));
	}
	catch (...) {
		cout << "������ ����������, ������������ ����������������� ���������" << endl;
		return true;
	}
	return false;
}

void fileInput::createNum(int& x, int& y) {
	string enterfile;
	cout << "������� ������ ���� ����� " << endl;
	cin >> enterfile;

	while (checkEnter(enterfile)) {
		cout << "������� ������ ���� ����� " << endl;
		cin >> enterfile;
	}

	ifstream filereading;
	filereading.open(enterfile);
	string save1, save2;
	while (!filereading.is_open() || checkEnter(enterfile)) {
		cout << "������, ������� ����������/������������ ����� �����" << endl;
		cout << "������� ������ ���� ����� " << endl;
		cin >> enterfile;
		filereading.close();
		filereading.open(enterfile);
	}

	if (filereading.eof()) {
		cout << "������ ������������ " << endl;
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
