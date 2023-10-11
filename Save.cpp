#include "save.h"

using namespace std;

//namespace fs = std::filesystem;

bool askRew() {
	cout << "Перезаписать существующий файл?" << endl <<
		"1 - Да" << endl << "2 - Нет" << endl;
	int saveAnswer;
	saveAnswer = getInt();
	while (saveAnswer != yes && saveAnswer != no) {
		cout << "Перезаписать существующий файл?" << endl <<
			"1 - Да" << endl << "2 - Нет" << endl;
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
		cout << "Запись невозможна! Использовано зарезервированное выражение" << endl;
		return false;
	}

	if (!filesystem::is_regular_file(dir, ec)) {
		cout << "Запись невозможна! Использовано зарезервированное выражение" << endl;
		return false;
	}

	if (!checkTest.is_open()) {
		checkTest.close();
		std::cout << "Создается новый фаил\n";
		return true;
	}
	else {
		cout << "Файл Уже существует!\n";
		checkTest.close();
		return askRew();
	}
}

void saveData(string x, string y) {
	string fileSaveInput = "";
	cout << "Введите путь сохранения исходных данных: ";
	cin >> fileSaveInput;
	int chars = getchar();
	while (chars != '\n') {
		fileSaveInput += char(chars);
		chars = getchar();
	}
	while (!check(fileSaveInput)) {
		cout << "Введите путь сохранения данных: ";
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
	cout << "Записано в файл " << fileSaveInput << endl;
}

void saveResult(string result) {
	string fileSaveInput;
	cout << "Введите путь сохранения результата: ";
	cin >> fileSaveInput;
	int chars = getchar();
	while (chars != '\n') {
		fileSaveInput += char(chars);
		cin >> fileSaveInput;
		chars = getchar();
	}

	while (!check(fileSaveInput)) {
		cout << "Введите путь сохранения результата: ";
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
	cout << "Записано в файл " << fileSaveInput << endl;
}

