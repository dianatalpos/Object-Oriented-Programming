#include "Repository.h"
#include <iostream>

Repo::Repo()
{

}


Repo::~Repo()
{

}

int Repo::get_size()
{
	return this->elems.size();
}


std::vector<Organism> Repo::get_elems() const
{
	return this->elems;
}

void Repo::add_elem(Organism o)
{
	int i; 
	int n = this->elems.size();
	std::string type = o.getType();
	for (i = 0; i < n; i++)
	{
		if (type == this->elems[i].getType())
		{
			this->elems[i].setNumber(o.getNumber());
			cout << "The population has been added!\n";
			return;
		}
	}
	this->elems.push_back(o);
	cout << "The population has been added!\n";
}