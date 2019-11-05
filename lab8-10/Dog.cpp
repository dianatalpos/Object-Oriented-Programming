#include "Dog.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

Dog::Dog(std::string breed, std::string name, int age, std::string photo)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photo = photo;

}

void Dog::setPhoto(std::string photo) 
{
	this->photo = photo;
}

void Dog::setBreed(std::string breed)
{
	this->breed = breed;
}

Dog::Dog()
{
	this->breed = "";
	this->name = "";
	this->age = 0;
	this->photo = "";
}


void Dog::setAge(int age)
{
	this->age = age;
}

void Dog::setName(std::string name)
{
	this->name = name;
}

Dog::~Dog()
{
}

std::ofstream& operator<<(std::ofstream& f, const Dog& dog)
{
	f << dog.getBreed() << " " << dog.getName() << " " << dog.getAge() << " " << dog.getPhoto();
	return f;
}

Dog Dog::operator=(const Dog& dog)
{
	this->setPhoto(dog.getPhoto());
	this->setAge(dog.getAge());
	this->setName(dog.getName());
	this->setBreed(dog.getBreed());
	return *this;
}

std::ifstream& operator >>(std::ifstream& f, Dog& dog)
{
	std::string breed;
	std::string name;
	int age;
	std::string photo;
	std::string line;
	std::getline(f, breed, ' ');
	std::getline(f, name, ' ');
	f >> age;
	std::getline(f, photo, '\n');
	dog.setBreed(breed);
	dog.setAge(age);
	dog.setName(name);
	dog.setPhoto(photo);
	return f;
}
