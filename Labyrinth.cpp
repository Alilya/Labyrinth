//#include <iostream>
//#include <math.h>
//#include <cmath>
//#include <string>
//#include <ctime>
//#include <windows.h> 
//#include <stdio.h>
//#include <vector>
//
//#include "Input.h"
//
//
//
//using namespace std;
//
//int main() {
//	const string WALL = "|";;
//
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
//	setlocale(0, "rus");
//	srand(time(nullptr));
//
//	//string maze[100];// choice = "p";
//	vector<string> maze(1000);
//
//	int path = 1, c[100], c1 = 2, n, k = 0, height = 0, width = 0, enter = 0;
//
//	do {
//		cout << "Для выхода нажмите 0, " << endl;
//		cout << "Для продолжения работы нажмите цифру 1 ";
//		enter = getInt();
//
//		if (enter == 1) {
//
//			while (height % 2 == 0 || width % 2 == 0 || height < 5 || width < 5 || width>70 || (height + 2) * (width + 2) >= 1000) {//вынести в функию bool   
//				cout << "Введите нечетную высоту,ширину, рекомендовано 15 27." << endl;
//				cin >> height >> width;
//			
//				if (height < 5) cout << "Маленькая высота!!!" << endl;
//				if (width < 5) cout << "Маленькая ширина!!!" << endl;
//				if ((height + 2) * (width + 2) >= 1000) cout << "Слишком большой лабиринт" << endl;
//				if (width > 70)cout << "Слишком большая ширина" << endl;
//				if (width % 2 == 0 || height % 2 == 0)cout << "Числа должны быть нечетными!!" << endl;
//			}
//
//			height += 2;
//			width += 2;
//
//			for (int x = 0; x < height * width; x++) {
//				maze[x] = " ";
//				if (x < width) maze[x] = WALL;//если точка меньше ширины то там стена.. первая строка
//				if (x > height * width - width - 1) maze[x] = WALL;//если точка больше высоты* ширину -  ширина -1 то там стена? ... последняя строка
//				if (x % width == 0) maze[x] = WALL;//если точка нечетная то там стена ... левая сторона
//				if (x % width == width - 1) maze[x] = WALL;//если точка ... правая сторона
//			}
//
//			//генерация внутреннего лабиринта
//
//			while (path% 2 == 1) {
//				path= rand() % (width - 4) + width * height - width + 2;
//			}
//
//			maze[path] = ".";
//			maze[path- width] = ".";
//			path= 1;
//
//			while (path% 2 == 1) {
//				path= rand() % (width - 4) + 2;
//			}
//
//			maze[path] = ".";
//			maze[path+ width] = ".";
//			path+= width * 2;
//
//			while (c1 > 1) {
//				int a1 = path;
//				if (k < 15) {
//					c[c1] = path;
//					c1++;
//				}
//				maze[path] = ".";
//				k = 0;
//				while (a1 == path&& k < 15) {
//					n = rand() % 4 + 1;
//					if (n == 1 && maze[path+ 2] == " ")path++;
//					if (n == 2 && maze[path+ width * 2] == " ")path+= width;
//					if (n == 3 && maze[path- width * 2] == " ")path-= width;
//					if (n == 4 && maze[path- 2] == " ")path--;
//					k++;
//				}
//				if (k == 15) {
//					c[c1 - 1] = 0;
//					c1 -= 2;
//					path= c[c1];
//					c1++;
//				}
//				if (path> 0)
//					maze[path] = ".";
//				if (path< 0)
//					c1 = 0;
//				if (k < 15) {
//					if (n == 1)path++;
//					if (n == 2)path+= width;
//					if (n == 3)path-= width;
//					if (n == 4)path--;
//					maze[path] = ".";
//				}
//			}
//			maze[width * 2] = WALL;
//			for (int x = 0; x < width * height; x++) {
//				if (maze[x] == WALL)maze[x] = "";
//				if (maze[x] == " ")maze[x] = WALL;
//				if (x > width * 2 || x < width)
//					if (maze[x] == ".")maze[x] = " ";
//			}
//			system("CLS");
//			for (int x = 0; x < width * height; x++) {
//				cout << maze[x];
//				if (x % width == width - 1)
//					cout << endl;
//			}
//		}
//		////Прохождение
//			//int a1 = 0, a2 = 0, m[1000], j, h = 0;
//			//c1 = 0;
//			//cout << "Хотите следить за прохождением лабиринта? ";
//			//while (h == 0) {
//			//	cin >> t;
//			//	if (choice == "yes") {
//			//		h = 1;
//			//		j = 0;
//			//	}
//			//	if (choice == "no") {
//			//		h = 1;
//			//		j = 1;
//			//	}
//			//}
//			//k = j;
//			//for (int x = 0; x < width; x++) {
//			//	for (int y = 0; y < width * height; y++)
//			//		maze[y] = maze[y + 1];
//			//}
//			//for (int x = 0; x < width;x++)
//			//	if (maze[x] == ".")
//			//		path= x;
//			//for (int x = width * (height - 3) - 1; x < width * (height - 2); x++)
//			//	if (maze[x] == " ")
//			//		a1 = x;
//			//for (int x = 0; x < 1000; x++)
//			//	c[x] = 0;
//			//maze[a] = ".";
//			//while (path!= a1) {
//			//	if (k == 0) {
//			//		system("CLS");
//			//		for (int x = 0; x < width * height; x++) {
//			//			cout << maze[x];
//			//			if (x % width == width - 1)
//			//				cout << endl;
//			//		}
//			//		Sleep(150);
//			//	}
//			//	n = 0;
//			//	a2 = a;
//			//	while (a2 == a) {
//			//		n++;
//			//		k = j;
//			//		if (n == 1 && maze[path- width] == " " && path- width > 0 && m[path- width] != 666)path-= width;
//			//		if (n == 2 && maze[path- 1] == " " && m[path- 1] != 666)a--;
//			//		if (n == 3 && maze[path+ 1] == " " && m[path+ 1] != 666)a++;
//			//		if (n == 4 && maze[path+ width] == " " && m[path+ width] != 666)path+= width;
//			//		if (n == 5) {
//			//			k = 1;
//			//			n = 0;
//			//			c1--;
//			//			maze[a] = " ";
//			//			m[a] = 666;
//			//			c1--;
//			//			path= c[c1];
//			//			c1++;
//			//		}
//			//	}
//			//	maze[a] = ".";
//			//	c[c1] = a;
//			//	c1++;
//			//}
//			//system("CLS");
//			//for (int x = 0; x < width * height; x++) {
//			//	if (maze[x] == ".")
//			//		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
//			//	cout << maze[x];
//			//	if (x % width == width - 1)
//			//		cout << endl;
//			//	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
//			//}
//
//	} while (enter);
//
//	return 0;
//}

// maze.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <iostream>
#include "windows.h"
#include <cstdlib>
#include <ctime>
#include <queue>
#include <conio.h>
#include <vector>
#include <cmath>
//#include "console.cpp"
using namespace std;


//функция установки символа С в любое место консоли X,Y без перерисовывания всего экрана
void WriteCharToXY(int X, int Y, char C) {
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	_CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
	GetConsoleScreenBufferInfo(StdOut, &BufferInfo);
	_COORD OldPos = BufferInfo.dwCursorPosition;
	_COORD NewPos;
	NewPos.X = X;
	NewPos.Y = Y;
	SetConsoleCursorPosition(StdOut, NewPos);
	DWORD NumWritten;
	WriteConsoleA(StdOut, &C, 1, &NumWritten, NULL);
	SetConsoleCursorPosition(StdOut, OldPos);
}

//хотел использовать для поиска пути к выходу, но пока не реализовано
/*class Point {
	int x, y;
	Point* pred;
	bool visited;
public:
	Point() {
		visited = false;
	}
	void setvis(bool b) {
		visited = b;
	}
	void setPred(Point *p) {
		pred = p;
	}
};*/

//управление обзором, перемещение курсора
//class Camera {
//	int x, y;
//public:
//	Camera() {
//		x = 0; y = 0; setCam();
//	}
//	void moveUp() { y -= 5; setCam(); }
//	void moveDown() { y += 5; setCam(); }
//
//	//установка курсора в нужные координаты, так же как и в функции WriteCharToXY, только проще
//	void setCam() {
//		HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//		_COORD NewPos;
//		NewPos.X = x;
//		NewPos.Y = y;
//		SetConsoleCursorPosition(StdOut, NewPos);
//	}
//};

//класс персонажа с координатами, методы для движения в 4 стороны, отрисовки и стирания в текущих координатах
//class Player {
//	int x, y;
//public:
//	Player() {
//		x = 1; y = 1;
//	}
//
//	int getx() { return x; }
//	int gety() { return y; }
//
//	void reset() { x = 1; y = 1; }//для перезапуска
//	void moveUp() { y -= 1; }
//	void moveDown() { y += 1; }
//	void moveLeft() { x -= 1; }
//	void moveRigth() { x += 1; }
//	void clear() { WriteCharToXY(x, y, ' '); }
//	void draw() { WriteCharToXY(x, y, '@'); }
//};


//класс лабиринта и все с ним связанное, все здесь
class Maze {
	//сам лабиринт на плоскости, если элемент= 0-стена, если =1-проход(двумерный массив, сделал динамическим чтобы при запуске можно было задавать размеры)
	int** maz;
	int cons_x, cons_y;//переменные для размера лабиринта, чем больше тем дольше генерируется

	vector<int> points_x;//глупое решение, но первое что пришло в голову, хранить в 2х массивах координаты тех точек лабиринта, которые уже вырублены, т.е вершины   
	vector<int> points_y;//чтобы из них потом продолжать строить ответвления, рандомно выбирая точки из этих массивов и рандомное направление прокладки пути 
	int number;//собственно, переменная, чтобы знать насколько заполнены предыдущие массивы, и выбирать из них случайный

	//Player player;//символ игрока
	//Camera camera;//для управления камерой

	int end_x, end_y;//координаты выхода


public:	Maze(int y = 25, int x = 80) {
		//В конструкторе инициализация динамического массива лабиринта и его размеров
		cons_x = x, cons_y = y;
		maz = new int* [cons_y];
		for (int i = 0; i < cons_y; i++) {
			maz[i] = new int[cons_x];
		}
		end_x = cons_x - 2, end_y = cons_y - 2;
	}

	//функция возврата любой клетки лабиринта по координатам
	int getMaze(int y, int x) {
		return maz[y][x];
	}

	//подготовка лабиринта, его очистка и заполнение всего стенами
	void prepare() {
		for (int i = 0; i < cons_y; i++) {
			for (int i1 = 0; i1 < cons_x; i1++) { maz[i][i1] = 0; }
		}
		number = 1;//1 начальная вершина
		maz[1][1] = 1;
		points_x.push_back(1);//добавление в массивы элемента 1,1-начальная точка, от которой рисуем лабиринт
		points_y.push_back(1);
	}

	//функция чтобы узнать можно ли вырубить клетку x,y в лабиринте
	//проверка того что эта клетка находится внутри лабиринта, еще не вырублена и что вокруг нее нет в любом направлении нет 3х
	//уже ощищенных клеток лабиринта(иначе бы вообще стен не было нигде, были 2*2 пустые места)
	bool testXY(int y, int x) {
		if (x == end_x && y == end_y) { return true; }//чтобы в конце всегда было разрешено строить, иначе при некоторых размерах там получался тупик
		else if (x<1 || y<1 || x>end_x || y>end_y || maz[y][x] == 1) { return false; }
		else if (maz[y - 1][x - 1] + maz[y - 1][x] + maz[y][x - 1] >= 3) { return false; }//направление влево вверх 3 клетки
		else if (maz[y - 1][x] + maz[y - 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//вправо вверх 3 кл
		else if (maz[y + 1][x - 1] + maz[y + 1][x] + maz[y][x - 1] >= 3) { return false; }//влево вниз 3 кл
		else if (maz[y + 1][x] + maz[y + 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//вправо вниз 3 кл
		else { return true; }
	}

	//прорубание пути в лабиринте-массиве maz(который по сути проскость с x и y)
	void generateTree() {
		//сначала чистим
		prepare();

		int rep = 0;//количество повторений
		int point = rand() % number;//выбор случайной точки из массивов points_x и points_x, чтобы от нее продолжить лабиринт
		while (maz[end_y][end_x] != 1) {//пока не дойдем до конца
			point = rand() % number;//каждый раз генерим случайный номер клетки, из которой будем строить путь

			switch (rand() % 4)//рандомное направление постройки прохода
			{
				//0-вверх: если в верхней клетке можно сделать проход в соответствии с методом testXY(), и если она и так не пустая, то делаем проход
			case 0: if (testXY(points_y[point] - 1, points_x[point]) && maz[points_y[point] - 2][points_x[point]] != 1) {
				maz[points_y[point] - 1][points_x[point]] = 1;//проход
				//и сразу же пытаемся пробурить еще одну клетку,потому что если бурить по одной лабиринт будет не красивым,
				//и строить пути мы будем только из клеток с нечетными координатами, тоже по этой причине, иначе не лабиринт а дуршлаг получается
				if (testXY(points_y[point] - 2, points_x[point])) {
					maz[points_y[point] - 2][points_x[point]] = 1;//проход
					//запоминаем координаты x и y этой клетки в массивы points, чтобы добавить ее в список клеток, из которых рандомно строятся пути
					points_x.push_back(points_x[point]);
					points_y.push_back(points_y[point] - 2);
					number++;//теперь на 1 такую клетку больше
				}
			}	break;
				//аналогично для всех остальных 3х сторон
			case 1: if (testXY(points_y[point], points_x[point] + 1) && maz[points_y[point]][points_x[point] + 2] != 1) {
				maz[points_y[point]][points_x[point] + 1] = 1;
				if (testXY(points_y[point], points_x[point] + 2)) {
					maz[points_y[point]][points_x[point] + 2] = 1;
					points_x.push_back(points_x[point] + 2);
					points_y.push_back(points_y[point]);
					number++;
				}
			}	break;
			case 2: if (testXY(points_y[point] + 1, points_x[point]) && maz[points_y[point] + 2][points_x[point]] != 1) {
				maz[points_y[point] + 1][points_x[point]] = 1;
				if (testXY(points_y[point] + 2, points_x[point])) {
					maz[points_y[point] + 2][points_x[point]] = 1;
					points_x.push_back(points_x[point]);
					points_y.push_back(points_y[point] + 2);
					number++;
				}
			}	break;
			case 3: if (testXY(points_y[point], points_x[point] - 1) && maz[points_y[point]][points_x[point] - 2] != 1) {
				maz[points_y[point]][points_x[point] - 1] = 1;
				if (testXY(points_y[point], points_x[point] - 2)) {
					maz[points_y[point]][points_x[point] - 2] = 1;
					points_x.push_back(points_x[point] - 2);
					points_y.push_back(points_y[point]);
					number++;
				}
			}	break;
			default:
				break;
			}
			rep++;

			//вызов функциии для оптимизации
			testforDEADEND(point);

			/*if (rep % 30000 == 0) {
				draw();
				cout << endl;
				//system("pause");
			}*/
			//system("pause");
		}
	}


	//функция для проверки вершин, если из текущей вершины невозможно ни в одну сторону прорубить проход, то эта вершина удаляется из списка points, чтобы рандом больше ее не выбирал
	//по тестам ускоряет генерацию лабиринта для больших размеров в 10 и более раз
	void testforDEADEND(int num) {
		if (!testXY(points_y[num] - 2, points_x[num])) {
			if (!testXY(points_y[num] + 2, points_x[num])) {
				if (!testXY(points_y[num], points_x[num] - 2)) {
					if (!testXY(points_y[num], points_x[num] + 2)) {
						near_finish(num);//проверка на то что мы возле финиша, чтобы не было проблем с дорисовкой выхода
						if (number > 1) {
							auto iter = points_x.cbegin();//немного запутано, это итератор-указатель на начало vectorа, иначе не нашел возможности удалить по номеру элемента 
							points_x.erase(iter + num);//метод удаления у vector
							auto iter2 = points_y.cbegin();
							points_y.erase(iter2 + num);
							number--;
						}
					}
				}
			}
		}
	}

	//если лабиринт с нечетными размерами сторон, то не всегда найдется выход сам по себе,
	//поэтому если рядом вручную его очищаем
	void near_finish(int num) {
		if (abs(points_y[num] - end_y) <= 2 && abs(points_x[num] - end_x) <= 2) {
			for (int y = end_y - 1; y <= end_y;y++) {
				for (int x = end_x - 1; x <= end_x; x++) {
					maz[y][x] = 1;
				}
			}
		}
	}



	void draw() {//отрисовка лабиринта и персонажа
		for (int y = 0; y < cons_y; y++) {
			for (int x = 0; x < cons_x; x++) {
				if ((y == end_y && x == end_x)) { 
					cout << ' '; 
				}//выход
				else if ((y == 0 && x == 0)) { 
					cout << ' '; 
				}//вход
				else if (maz[y][x] == 0 && !(y == end_y && x == end_x+1) && !(y == 0 && x == 1)) {
					cout << '|'; 
				}//стены
				else{
					cout << ' '; }//проходы
			}
			cout << endl;
		}
		//player.draw();
	}

	//void control() { //метод для управления всем лабиринтом
	//	camera.setCam();

	//	while (player.getx() != end_x || player.gety() != end_y) {//пока не дошел до выхода
	//		if (_kbhit()) {
	//			int button = _getch();
	//			//управление камерой
	//			if (button == 119) {
	//				camera.moveUp();
	//			}
	//			else if (button == 115) {
	//				camera.moveDown();
	//			}

	//			//управление персонажем
	//			else {
	//				int button2 = _getch();
	//				if (button == 224) { //при нажатии стрелочек движение в нужную сторону, если свободна клетка лабиринта, в которую надо перейти(т.е. в ячейке массива 1)
	//					switch (button2)
	//					{
	//					case 72:if (maz[player.gety() - 1][player.getx()] == 1) { player.clear(); player.moveUp(); player.draw(); }//сначала очистка, потом движение и снова отрисовка
	//								 break;
	//					case 80:if (maz[player.gety() + 1][player.getx()] == 1) { player.clear();  player.moveDown(); player.draw(); }
	//								 break;
	//					case 75:if (maz[player.gety()][player.getx() - 1] == 1) { player.clear();  player.moveLeft(); player.draw(); }
	//								 break;
	//					case 77:if (maz[player.gety()][player.getx() + 1] == 1) { player.clear();  player.moveRigth(); player.draw(); }
	//								 break;
	//					default:
	//						break;
	//					}
	//				}
	//			}
	//		}
	//		Sleep(10);
	//	}
	//	cout << "\n\n\n\n\n\n\n" << "YOU WIN!";
	//	system("pause");
	//}

	/*void findPath() {
		for (int i = 0; i < cons_y; i++) {
			for (int i1 = 0; i1 < cons_x; i1++) {
				if (maz[i][i1] == 0) {
					masp[i][i1].setvis(true);
				}
			}
		}

	}*/

};

int main()
{
	srand(time(0));
	setlocale(0, "");
	int x, y;
	cout << "Управление стрелочками , чтобы двигать камеру клавиши W и S\n";
	cout << "Введите размеры лабиринта y и x(x<=119, иначе не вместится): ";
	cin >> y >> x;
	Maze ma(y, x);
	unsigned int start_time = clock();
	ma.generateTree();
	unsigned int end_time = clock();
	system("cls");
	ma.draw();
	cout << "Время генерации: " << end_time - start_time << "миллисекунд \n";
	//ma.control();
}
