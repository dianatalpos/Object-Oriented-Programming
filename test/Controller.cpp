#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(Repo repo) : repo{ repo }
{

}


Controller::~Controller()
{

}

void Controller::print_Sort()
{
	std::vector<Organism> vct = this->repo.get_elems();
	int n = this->repo.get_size();
	for (int i = 0; i < n-1; i++)
	{
		for(int j = i; j<n;j++)
			if (vct[i].getType() > vct[i].getType())
			{
				Organism *aux;
				aux = &vct[i];
				vct[i] = vct[j];
				vct[j] = *aux;
			}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Type: " << vct[i].getType() << "   Number of organism: " << vct[i].getNumber() << "  isImmune:  " << vct[i].getIsImmune();
		cout << endl;
	}

}

void Controller::print_list()
{
	std::vector<Organism> vct = this->repo.get_elems();
	int n= this->repo.get_size();
	for (int i = 0; i < n; i++)
	{
		cout << "Type: " << vct[i].getType()<<"   Number of organism: " << vct[i].getNumber() << "  isImmune:  "<< vct[i].getIsImmune();
		cout << endl;
	}
}

void Controller::add(std::string type, int number , bool isImmune)
{
	Organism org{ type, number, isImmune };
	this->repo.add_elem(org);
}
