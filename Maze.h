#pragma once
#include <iostream>
#include "windows.h"
#include <cstdlib>
#include <ctime>
#include <queue>
#include <conio.h>
#include <cmath>
#include <vector>

using namespace std;

class Maze {
public:
	Maze(int, int);
	int getMaze(int y, int x);
	void prepare();
	bool testXY(int y, int x);
	void generateTree();
	void testforDEADEND(int num);
	void near_finish(int num);
	void draw();
};


