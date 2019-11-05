#pragma once

#include <vector>
#include "Disorder.h"

class Controller
{
	std::vector<Disorder> elems;

public:
	std::vector<Disorder> getAll() { return this->elems; }
	Controller();
	~Controller();
	std::string searchByName(std::string);

private:

	//Function that reads all disorders from the file 
	void readAllFromFile();
};

