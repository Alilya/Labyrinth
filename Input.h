#pragma once

#include <string>
#include <filesystem>
#include <memory>
#include <string>

using namespace std;

class input {
public:
	virtual void createNum(int&, int&) = 0;
	virtual ~input() = default;
};

class randomInput :public input {
public:
	void createNum(int&, int&) override;
};

class keyboardInput : public input {
public:
	void createNum(int&, int &) override;
};

class fileInput : public input {
public:
	void createNum(int&, int&) override;
};

std::unique_ptr<input> makeChoiceInput(int);