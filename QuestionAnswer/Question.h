#pragma once
#include <string>


class Question
{

private:
	std::string text;
	int id;
	std::string name;
	int number;

public:
	Question() {}
	Question(std::string text, int id, std::string name);
	std::string getText() { return this->text; }
	std::string getName() { return this->name; }
	int getId() {return this->id;}
	void setNumber() { this->number++; }
	int getNumber() { return this->number; }
	~Question();
};

