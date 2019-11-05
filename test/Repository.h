#pragma once
#include "Organism.h"
#include <stdlib.h>
#include <vector>

using namespace std;

class Repo
{

private:
	std::vector<Organism> elems;

public:

	Repo();

	~Repo();

	/*
	Function that adds an organism to the repository
	in: o - organism
	*/
	void add_elem(Organism o);
	
	std::vector<Organism> get_elems() const;

	/*
	Function that return the number of elements from the repository
	*/
	int get_size();
};