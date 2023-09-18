#include "Maze.h"

//��� �������� �� ���������, ���� �������= 0-�����, ���� =1-������(��������� ������, ������ ������������ ����� ��� ������� ����� ���� �������� �������)
int** maz;
int cons_x, cons_y;//���������� ��� ������� ���������, ��� ������ ��� ������ ������������
vector<int> points_x;//������ �������, �� ������ ��� ������ � ������, ������� � 2� �������� ���������� ��� ����� ���������, ������� ��� ���������, �.� �������   
vector<int> points_y;//����� �� ��� ����� ���������� ������� �����������, �������� ������� ����� �� ���� �������� � ��������� ����������� ��������� ���� 
int number;//����������, ����������, ����� ����� ��������� ��������� ���������� �������, � �������� �� ��� ���������
int end_x, end_y;//���������� ������

Maze::Maze(int y = 25, int x = 80) {
	//� ������������ ������������� ������������� ������� ��������� � ��� ��������
	cons_x = x, cons_y = y;
	maz = new int* [cons_y];
	for (int i = 0; i < cons_y; i++) {
		maz[i] = new int[cons_x];
	}
	end_x = cons_x - 2, end_y = cons_y - 2;
}

//������� �������� ����� ������ ��������� �� �����������
int Maze::getMaze(int y, int x) {
	return maz[y][x];
}

//���������� ���������, ��� ������� � ���������� ����� �������
void Maze::prepare() {
	for (int i = 0; i < cons_y; i++) {
		for (int i1 = 0; i1 < cons_x; i1++) { maz[i][i1] = 0; }
	}
	number = 1;//1 ��������� �������
	maz[1][1] = 1;
	points_x.push_back(1);//���������� � ������� �������� 1,1-��������� �����, �� ������� ������ ��������
	points_y.push_back(1);
}

//������� ����� ������ ����� �� �������� ������ x,y � ���������
//�������� ���� ��� ��� ������ ��������� ������ ���������, ��� �� ��������� � ��� ������ ��� ��� � ����� ����������� ��� 3�
//��� ��������� ������ ���������(����� �� ������ ���� �� ���� �����, ���� 2*2 ������ �����)
bool Maze::testXY(int y, int x) {
	if (x == end_x && y == end_y) { return true; }//����� � ����� ������ ���� ��������� �������, ����� ��� ��������� �������� ��� ��������� �����
	else if (x<1 || y<1 || x>end_x || y>end_y || maz[y][x] == 1) { return false; }
	else if (maz[y - 1][x - 1] + maz[y - 1][x] + maz[y][x - 1] >= 3) { return false; }//����������� ����� ����� 3 ������
	else if (maz[y - 1][x] + maz[y - 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//������ ����� 3 ��
	else if (maz[y + 1][x - 1] + maz[y + 1][x] + maz[y][x - 1] >= 3) { return false; }//����� ���� 3 ��
	else if (maz[y + 1][x] + maz[y + 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//������ ���� 3 ��
	else { return true; }
}

//���������� ���� � ���������-������� maz(������� �� ���� ��������� � x � y)
void Maze::generateTree() {
	//������� ������
	prepare();

	int rep = 0;//���������� ����������
	int point = rand() % number;//����� ��������� ����� �� �������� points_x � points_x, ����� �� ��� ���������� ��������
	while (maz[end_y][end_x] != 1) {//���� �� ������ �� �����
		point = rand() % number;//������ ��� ������� ��������� ����� ������, �� ������� ����� ������� ����

		switch (rand() % 4)//��������� ����������� ��������� �������
		{
			//0-�����: ���� � ������� ������ ����� ������� ������ � ������������ � ������� testXY(), � ���� ��� � ��� �� ������, �� ������ ������
		case 0: if (testXY(points_y[point] - 1, points_x[point]) && maz[points_y[point] - 2][points_x[point]] != 1) {
			maz[points_y[point] - 1][points_x[point]] = 1;//������
			//� ����� �� �������� ��������� ��� ���� ������,������ ��� ���� ������ �� ����� �������� ����� �� ��������,
			//� ������� ���� �� ����� ������ �� ������ � ��������� ������������, ���� �� ���� �������, ����� �� �������� � ������� ����������
			if (testXY(points_y[point] - 2, points_x[point])) {
				maz[points_y[point] - 2][points_x[point]] = 1;//������
				//���������� ���������� x � y ���� ������ � ������� points, ����� �������� �� � ������ ������, �� ������� �������� �������� ����
				points_x.push_back(points_x[point]);
				points_y.push_back(points_y[point] - 2);
				number++;//������ �� 1 ����� ������ ������
			}
		}	break;
			//���������� ��� ���� ��������� 3� ������
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

		//����� �������� ��� �����������
		testforDEADEND(point);
	}
}


//������� ��� �������� ������, ���� �� ������� ������� ���������� �� � ���� ������� ��������� ������, �� ��� ������� ��������� �� ������ points, ����� ������ ������ �� �� �������
//�� ������ �������� ��������� ��������� ��� ������� �������� � 10 � ����� ���
void Maze::testforDEADEND(int num) {
	if (!testXY(points_y[num] - 2, points_x[num])) {
		if (!testXY(points_y[num] + 2, points_x[num])) {
			if (!testXY(points_y[num], points_x[num] - 2)) {
				if (!testXY(points_y[num], points_x[num] + 2)) {
					near_finish(num);//�������� �� �� ��� �� ����� ������, ����� �� ���� ������� � ���������� ������
					if (number > 1) {
						auto iter = points_x.cbegin();//������� ��������, ��� ��������-��������� �� ������ vector�, ����� �� ����� ����������� ������� �� ������ �������� 
						points_x.erase(iter + num);//����� �������� � vector
						auto iter2 = points_y.cbegin();
						points_y.erase(iter2 + num);
						number--;
					}
				}
			}
		}
	}
}

//���� �������� � ��������� ��������� ������, �� �� ������ �������� ����� ��� �� ����,
//������� ���� ����� ������� ��� �������
void Maze::near_finish(int num) {
	if (abs(points_y[num] - end_y) <= 2 && abs(points_x[num] - end_x) <= 2) {
		for (int y = end_y - 1; y <= end_y;y++) {
			for (int x = end_x - 1; x <= end_x; x++) {
				maz[y][x] = 1;
			}
		}
	}
}



void Maze::draw() {//��������� ��������� � ���������
	for (int y = 0; y < cons_y; y++) {
		for (int x = 0; x < cons_x; x++) {
			if ((y == end_y && x == end_x)) {
				cout << ' ';
			}//�����
			else if ((y == 0 && x == 0)) {
				cout << ' ';
			}//����
			else if (maz[y][x] == 0 && !(y == end_y && x == end_x + 1) && !(y == 0 && x == 1)) {
				cout << '|';
			}//�����
			else {
				cout << ' ';
			}//�������
		}
		cout << endl;
	}
}
