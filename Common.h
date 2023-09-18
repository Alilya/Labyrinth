#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int getInt();

enum inputChoice {
	random = 1,
	keyboard,
	file
};
enum saveChoice {
	save = 1,
	notSave
};
enum answer {
	yes = 1,
	no
};


struct stringC {
public:
	string result;
	void setStr(string& result);;
	stringC();
	~stringC() = default;
};

