#pragma once
#include <stdlib.h>;
#include <string>;

class Organism
{
private:
	std::string type;
	int number;
	bool isImmune;

public:
	Organism(std::string, int, bool);

	~Organism();
	
	std::string getType() const { return this->type; }
	int getNumber() const { return this->number; }
	bool getIsImmune() const { return this->isImmune; }

	void setNumber(int);
};