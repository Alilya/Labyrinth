//#include <iostream>
//#include <cstdlib>
//#include <time.h>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//enum CellState { Close, Open };
//
//class Cell
//{
//public:
//  int x;
//  int y;
//  CellState Left;
//  CellState Right;
//  CellState Top;
//  CellState Bottom;
//  bool Visited;
//};
//
//int main(int argc, char** argv)
//{
//  const int width = 5,
//    height = 5;
//
//  Cell labyrinth[width][height];
//
//  //��������� ��������� ������ ��� �����
//  for (int y = 0; y < height; y++)
//    for (int x = 0; x < width; x++)
//    {
//      labyrinth[x][y].x = x;
//      labyrinth[x][y].y = y;
//      labyrinth[x][y].Visited = false;
//    }
//
//  //�������� ������ ������ ������ ������ ��������
//  srand(time(NULL));
//  int startX = rand() % width;
//  int startY = rand() % height;
//
//  labyrinth[startX][startY].Visited = true;
//
//  //������� ���� ������ � path � �������� ������� ����
//  stack<Cell> path;
//  path.push(labyrinth[startX][startY]);
//
//  while (!path.empty())
//  {
//    Cell _cell = path.top();
//
//    //������� ��������, � ����� ������� ����� �����
//    vector<Cell> nextStep;
//    if (_cell.x > 0 && (labyrinth[_cell.x - 1][_cell.y].Visited == false))
//      nextStep.push_back(labyrinth[_cell.x - 1][_cell.y]);
//    if (_cell.x < width - 1 && (labyrinth[_cell.x + 1][_cell.y].Visited == false))
//      nextStep.push_back(labyrinth[_cell.x + 1][_cell.y]);
//    if (_cell.y > 0 && (labyrinth[_cell.x][_cell.y - 1].Visited == false))
//      nextStep.push_back(labyrinth[_cell.x][_cell.y - 1]);
//    if (_cell.y < height - 1 && (labyrinth[_cell.x][_cell.y + 1].Visited == false))
//      nextStep.push_back(labyrinth[_cell.x][_cell.y + 1]);
//
//    if (!nextStep.empty())
//    {
//      //�������� ������� �� ��������� ���������
//      Cell next = nextStep[rand() % nextStep.size()];
//
//      //��������� �������, � ������� ����� �� �������
//      if (next.x != _cell.x)
//      {
//        if (_cell.x - next.x > 0)
//        {
//          labyrinth[_cell.x][_cell.y].Left = Open;
//          labyrinth[next.x][next.y].Right = Open;
//        }
//        else
//        {
//          labyrinth[_cell.x][_cell.y].Right = Open;
//          labyrinth[next.x][next.y].Left = Open;
//        }
//      }
//      if (next.y != _cell.y)
//      {
//        if (_cell.y - next.y > 0)
//        {
//          labyrinth[_cell.x][_cell.y].Top = Open;
//          labyrinth[next.x][next.y].Bottom = Open;
//        }
//        else
//        {
//          labyrinth[_cell.x][_cell.y].Bottom = Open;
//          labyrinth[next.x][next.y].Top = Open;
//        }
//      }
//
//      labyrinth[next.x][next.y].Visited = true;
//      path.push(next);
//
//    }
//    else
//    {
//      //���� ����� ������ ������, ������������ � ����������� ����
//      path.pop();
//    }
//  }
//
//  //... ���-�� ��� ������������� labyrinth...
//  for (int y = 0; y < height; y++){
//    for (int x = 0; x < width; x++){
//      cout << labyrinth[x][y].x;
//      cout << labyrinth[x][y].y << endl;
//     
//    }
//  }
//
//  return 0;
//}
//
