#include <iostream>
#include "windows.h"
#include <cstdlib>
#include <ctime>
#include <queue>
#include <conio.h>
#include <cmath>
#include "Input.h"
#include "Maze.h"
#include "Common.h"
#include "Save.h"

using namespace std;

int main() {
	srand(time(nullptr));
	setlocale(0, "");

	cout << "Добро пожаловать!" << endl;
	cout << "|||Колесникова Алина ||| 8 вариант " << endl << "||| 404 группа       ||| 2 лабораторная " << endl << endl;
	cout << "Программа, которая по исходным данным m и n строит прямоугольный лабиринт m x n " << endl << endl;
	int enter = 0;
	//if (test()) {
	do {
		cout << "Введите 1, чтобы сгенерировать данные случайным образом" << endl;
		cout << "Введите 2, чтобы ввести с клавиатуры" << endl;
		cout << "Введите 3, чтобы использовать файл" << endl;
		cout << "Введите 0, чтобы закончить" << endl;
		enter = getInt();
		if (enter == random || enter == keyboard || enter == file) {
			int x, y;

			auto metod = makeChoiceInput(enter);
			metod->createNum(y, x);

			Maze maze(y, x);
			maze.generateTree();
			system("cls");
			maze.draw();

			if (enter == random || enter == keyboard) {
				cout << endl;
				cout << "Введите 1, чтобы сохранить исходные данные" << endl;
				cout << "Введите 2, чтобы не сохранить" << endl;
				enter = getInt();
				while (enter != save && enter != notSave) {
					cout << endl;
					cout << "Введите 1, чтобы сохранить исходные данные" << endl;
					cout << "Введите 2, чтобы не сохранить" << endl;
					enter = getInt();
				}
				if (enter == save) {
					string strX = to_string(x);
					string strY = to_string(y);

					saveData(strX, strY);
				}

			}
			cout << endl;

			/*	cout << "Введите 1, чтобы сохранить результат" << endl;
				cout << "Введите 2, чтобы не сохранить" << endl;
				enter = getInt();
				while (enter != save && enter != notSave) {
					cout << endl;
					cout << "Введите 1, чтобы сохранить  сохранить результат" << endl;
					cout << "Введите 2, чтобы не сохранить" << endl;
					enter = getInt();
				}
				if (enter == save) {
					saveResult(str);
					return true;
				}*/
		}

	} while (enter);
	//}
	return 0;
}
