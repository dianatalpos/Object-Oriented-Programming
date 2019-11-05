#include "Controller.h"
#include <fstream>
#include <iostream>
#include "Disorder.h"
#include <string>

Controller::Controller()
{
	this->readAllFromFile();
}


Controller::~Controller()
{
}

//Function that searches by name the symptomps for that disorder
std::string Controller::searchByName(std::string name)
{
	for (auto x : this->elems)
	{
		char* a = x.getName();
		std::string nameo = "";
		nameo += a;
		if (name == nameo)
		{
			std::string sym = x.getSymptoms();
			return sym;
		}
	}
	return "";
}

void Controller::readAllFromFile()
{
	std::ifstream f("disorder.txt");
	while(!f.eof())
	{	
		char category[50];
		char name[100];
		char symptoms[200];
		f.getline(category, 50, '|');
		f.getline(name, 100, '|');
		f.getline(symptoms, 200, '\n');
		Disorder d{ category, name, symptoms };
		this->elems.push_back(d);
	}
}
