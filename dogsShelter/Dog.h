#pragma once
#include <iostream>

class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string photo;

public:
	Dog(std::string, std::string, int, std::string);
	Dog(const Dog& d);
	Dog();

	void setAge(int);
	void setPhoto(std::string);
	void setName(std::string);
	void setBreed(std::string);
	std::string getName() const { return this->name; }
	std::string getBreed() const { return this->breed; }
	int getAge() const { return this->age; }
	std::string getPhoto() const { return this->photo; }
	Dog operator=(const Dog& dog);

	friend std::ofstream& operator <<(std::ofstream& f, const Dog& dog);
	friend std::ifstream& operator >>(std::ifstream& f, Dog& dog);
	~Dog();
};