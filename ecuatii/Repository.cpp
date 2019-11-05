#include "Repository.h"
#include <fstream>

using namespace std;
Repository::Repository(std::string _file)
{
	this->file = _file;
	readAllFromFile();
}


Repository::~Repository()
{
}

std::vector<Equation> Repository::getAll()
{
	return this->elems;
}

void Repository::readAllFromFile()
{
	ifstream f(this->file);
	char d;
	double a, b, c;
	while (f >> a >> d >> b >> d >> c)
	{
		Equation eq(a, b, c);
		this->elems.push_back(eq);
	}
}
