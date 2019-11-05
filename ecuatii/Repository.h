#pragma once
#include <vector>
#include <string>
#include "Equation.h"
class Repository
{

private:
	std::vector<Equation> elems;
	std::string file;
public:
	Repository(std::string file);
	~Repository();

	std::vector<Equation> getAll();
private:
	void readAllFromFile();

};

