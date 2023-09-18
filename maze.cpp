#include "Maze.h"

//сам лабиринт на плоскости, если элемент= 0-стена, если =1-проход(двумерный массив, сделал динамическим чтобы при запуске можно было задавать размеры)
int** maz;
int cons_x, cons_y;//переменные для размера лабиринта, чем больше тем дольше генерируется
vector<int> points_x;//глупое решение, но первое что пришло в голову, хранить в 2х массивах координаты тех точек лабиринта, которые уже вырублены, т.е вершины   
vector<int> points_y;//чтобы из них потом продолжать строить ответвления, рандомно выбирая точки из этих массивов и рандомное направление прокладки пути 
int number;//собственно, переменная, чтобы знать насколько заполнены предыдущие массивы, и выбирать из них случайный
int end_x, end_y;//координаты выхода

Maze::Maze(int y = 25, int x = 80) {
	//В конструкторе инициализация динамического массива лабиринта и его размеров
	cons_x = x, cons_y = y;
	maz = new int* [cons_y];
	for (int i = 0; i < cons_y; i++) {
		maz[i] = new int[cons_x];
	}
	end_x = cons_x - 2, end_y = cons_y - 2;
}

//функция возврата любой клетки лабиринта по координатам
int Maze::getMaze(int y, int x) {
	return maz[y][x];
}

//подготовка лабиринта, его очистка и заполнение всего стенами
void Maze::prepare() {
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
bool Maze::testXY(int y, int x) {
	if (x == end_x && y == end_y) { return true; }//чтобы в конце всегда было разрешено строить, иначе при некоторых размерах там получался тупик
	else if (x<1 || y<1 || x>end_x || y>end_y || maz[y][x] == 1) { return false; }
	else if (maz[y - 1][x - 1] + maz[y - 1][x] + maz[y][x - 1] >= 3) { return false; }//направление влево вверх 3 клетки
	else if (maz[y - 1][x] + maz[y - 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//вправо вверх 3 кл
	else if (maz[y + 1][x - 1] + maz[y + 1][x] + maz[y][x - 1] >= 3) { return false; }//влево вниз 3 кл
	else if (maz[y + 1][x] + maz[y + 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//вправо вниз 3 кл
	else { return true; }
}

//прорубание пути в лабиринте-массиве maz(который по сути проскость с x и y)
void Maze::generateTree() {
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
	}
}


//функция для проверки вершин, если из текущей вершины невозможно ни в одну сторону прорубить проход, то эта вершина удаляется из списка points, чтобы рандом больше ее не выбирал
//по тестам ускоряет генерацию лабиринта для больших размеров в 10 и более раз
void Maze::testforDEADEND(int num) {
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
void Maze::near_finish(int num) {
	if (abs(points_y[num] - end_y) <= 2 && abs(points_x[num] - end_x) <= 2) {
		for (int y = end_y - 1; y <= end_y;y++) {
			for (int x = end_x - 1; x <= end_x; x++) {
				maz[y][x] = 1;
			}
		}
	}
}



void Maze::draw() {//отрисовка лабиринта и персонажа
	for (int y = 0; y < cons_y; y++) {
		for (int x = 0; x < cons_x; x++) {
			if ((y == end_y && x == end_x)) {
				cout << ' ';
			}//выход
			else if ((y == 0 && x == 0)) {
				cout << ' ';
			}//вход
			else if (maz[y][x] == 0 && !(y == end_y && x == end_x + 1) && !(y == 0 && x == 1)) {
				cout << '|';
			}//стены
			else {
				cout << ' ';
			}//проходы
		}
		cout << endl;
	}
}
