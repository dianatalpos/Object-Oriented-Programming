#include "Controller.h"
#include "Dog.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Controller::~Controller()
{

}

void Controller::open_file_dogs()
{
	this->list->play();
}

void Controller::open_file_adoption()
{
	this->adoption->play();
}



void Controller::add_adoption(Dog d)
{
	this->adoption->addDog(d);
}

void Controller::sort_dogs_name()
{
	ComparatorAscendingName* comp = new ComparatorAscendingName;
	std::vector<Dog> vct = this->list->getAll();
 	this->sort(comp, vct);
	auto it = vct.begin();
	for (; it < vct.end()-1; it++)
	{
		Dog d = *it;
		//cout << d <<'\n';
		cout << (*it).getBreed() << " " << (*it).getName() << " " << (*it).getAge() << " " << (*it).getPhoto()<<'\n';

	}
	//std::cout << *it;
	delete comp;
}

void Controller::get_dogs(std::string breed, int age, std::vector<Dog>& dogs)
{
	vector<Dog> allDogs = this->list->getAll();

	if (breed == "")
	{
		/*
		for (size_t i = 0; i < this->get_size(0); i++) {
			Dog d = this->get_elem(i, 0);
			if (d.getAge() < age)
				dogs.push_back(d);
		}*/
		copy_if(allDogs.begin(), allDogs.end(), dogs.begin(), 
			[&](Dog d) { 
			return d.getAge() < age; 
		});
	}
	else {
		/*for (size_t i = 0; i < this->get_size(0); i++) {
			Dog d = this->get_elem(i, 0);
			if (this->list.search_breed(breed, d) == 1 && d.getAge() < age)
				dogs.push_back(d);
		}*/

		copy_if(allDogs.begin(), allDogs.end(), dogs.begin(), 
			[&](Dog d) {
			return d.getAge() < age && d.getBreed() == breed; 
		});
	}
	
}

Dog Controller::get_elem(int i, bool t)
{
	if (t == 0)
		return this->list->get_elem(i);
	return this->adoption->get_elem(i);
}

int Controller::get_size(bool t)
{
	if (t==0)
		return this->list->get_size();
	return this->adoption->get_size();
}

void Controller::add_dog(std::string& breed, std::string& name, int age, std::string& photo)
{
	Dog d{ breed, name, age, photo };
	this->valid.validate(d);
	this->list->addDog(d);
}

void Controller::remove_dog(std::string& name)
{
	Dog d{ "",name, 0,"" };
	this->list->removeDog(d);
}

void Controller::update_dog(std::string& breed, std::string& name, int age, std::string& photo)
{
	Dog d{ breed, name, age, photo };
	this->list->updateDog(d);
}

void Controller::sort(Comparator<Dog>* compare, std::vector<Dog>& dogs)
{
	for(auto it = dogs.begin(); it< dogs.end()-1; it++)
		for (auto j = it; j < dogs.end(); j++)
			if( compare->compare(*it, *j) == 0 )
			{
				Dog aux;
				aux = *it;
				*it = *j;
				*j = aux;
			}
}