#pragma once
#include "Repository.h"


class Controller
{
private:
	Repo repo;

public:
	Controller(Repo);
	~Controller();

	/*
	fUNCTION THAT PRINTS THE LIST SORTED
	*/
	void print_Sort();


	/*
	Function that print the list;
	*/
	void print_list();

	/*
	 Function that adds an organism to the repository
	*/
	void add(std::string, int, bool);
};