#include "save.h"

using namespace std;

//namespace fs = std::filesystem;

bool askRew() {
	cout << "������������ ������������ ����?" << endl <<
		"1 - ��" << endl << "2 - ���" << endl;
	int saveAnswer;
	saveAnswer = getInt();
	while (saveAnswer != yes && saveAnswer != no) {
		cout << "������������ ������������ ����?" << endl <<
			"1 - ��" << endl << "2 - ���" << endl;
		saveAnswer = getInt();
	}
	if (saveAnswer == yes)
		return true;
	else
		return false;
}

bool check(string dir) {
	ifstream checkTest(dir);
	error_code ec;

	try {
		if (filesystem::is_regular_file(dir, ec))
			return true;
	}
	catch (...) {
		cout << "������ ����������! ������������ ����������������� ���������" << endl;
		return false;
	}

	if (!filesystem::is_regular_file(dir, ec)) {
		cout << "������ ����������! ������������ ����������������� ���������" << endl;
		return false;
	}

	if (!checkTest.is_open()) {
		checkTest.close();
		std::cout << "��������� ����� ����\n";
		return true;
	}
	else {
		cout << "���� ��� ����������!\n";
		checkTest.close();
		return askRew();
	}
}

void saveData(string x, string y) {
	string fileSaveInput = "";
	cout << "������� ���� ���������� �������� ������: ";
	cin >> fileSaveInput;
	int chars = getchar();
	while (chars != '\n') {
		fileSaveInput += char(chars);
		chars = getchar();
	}
	while (!check(fileSaveInput)) {
		cout << "������� ���� ���������� ������: ";
		fileSaveInput = "";
		chars = getchar();
		while (chars != '\n') {
			fileSaveInput += char(chars);
			chars = getchar();
		}
	}
	ofstream file(fileSaveInput);
	file << x;
	file << endl;
	file << y;
	file.close();
	cout << "�������� � ���� " << fileSaveInput << endl;
}

void saveResult(string result) {
	string fileSaveInput;
	cout << "������� ���� ���������� ����������: ";
	cin >> fileSaveInput;
	int chars = getchar();
	while (chars != '\n') {
		fileSaveInput += char(chars);
		cin >> fileSaveInput;
		chars = getchar();
	}

	while (!check(fileSaveInput)) {
		cout << "������� ���� ���������� ����������: ";
		fileSaveInput = "";
		cin >> fileSaveInput;
		chars = getchar();
		while (chars != '\n') {
			fileSaveInput += char(chars);
			cin >> fileSaveInput;
			chars = getchar();
		}
	}
	ofstream file(fileSaveInput);

	file << result;
	file << endl;

	file.close();
	cout << "�������� � ���� " << fileSaveInput << endl;
}

