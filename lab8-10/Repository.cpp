#include "Repository.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "Comparator.h"
#include "Validator.h"
#include <Windows.h>

using namespace std;

Repository::Repository()
{
}

int Repository::get_size()
{
	return dogs.size();
}

Dog Repository::get_elem(int i)
{
	return this->dogs[i];
}

bool Repository::is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void FileRepository::writeAllToFile(std::string file)
{
	ofstream f;
	f.open(file);
	auto it = this->dogs.begin();
	for (; it< this->dogs.end()-1; it++)
	{
		Dog d = *it;
		f << d<<"\n";

	}
	Dog d = *it;
	f << d;
	f.close();
}

void FileRepository::readAllFromFile(std::string file)
{
	ifstream f;
	f.open(file);
	std::string breed;
	std::string name;
	int age;
	std::string photo;
	std::string line;
	while (! is_empty(f))
	{
		Dog d{};
		f >> d;
		this->dogs.push_back(d);
	}
	f.close();
}

Dog Repository::search(std::string name)
{
	auto dd = find_if(this->dogs.begin(), this->dogs.end(), [&](Dog d1) { return d1.getName() == name; });
	/*if (dd == this->dogs.end())
	{
		return NULL ;
	}
	else
	{*/
		return *dd;

}

void Repository::addDog(Dog d)
{
	auto dd = find_if(this->dogs.begin(), this->dogs.end(), [&](Dog d1) { return d1.getName() == d.getName(); });
	if (dd == this->dogs.end())
	{
		this->dogs.push_back(d);
		return;
	}
	else
	{
		throw RepoError("The given dog is already in the list!\n");
	}
}

void Repository::removeDog(Dog d)
{
	auto dd = find_if(this->dogs.begin(), this->dogs.end(), [&](Dog d1) { return d1.getName() == d.getName(); });
	if (dd == this->dogs.end())
	{
		throw RepoError("The dog wasn't in the list!\n");
		return;
	}
	else
	{
		for (auto i = dd; i < this->dogs.end() - 1; i++)
			*i = *(i + 1);
		this->dogs.pop_back();
		 return;
	}
}

void Repository::updateDog(Dog d)
{
	auto dd = find_if(this->dogs.begin(), this->dogs.end(), [&](Dog d1) { return d1.getName() == d.getName(); });
	if (dd == this->dogs.end())
	{
		throw RepoError("The dog wasn't in the list!\n");
	}
	else
	{
		*dd = d;
		return;
	}
}

int Repository::search_name(std::string name)
{
	for (size_t i = 0; i < this->dogs.size(); i++)
	{
		Dog d = this->dogs[i];
		if (d.getName() == name)
			return i;
	}
	return -1;
}

bool Repository::search_breed(std::string breed, Dog d)
{
	if (d.getBreed() == breed) {
		return true;
	}
	return false;
}

Repository::~Repository()
{

}



FileRepository::FileRepository(std::string file)
{
	this->file = file;
	this->readAllFromFile(file);
}


void FileRepository::addDog(Dog d)
{
	this->Repository::addDog(d);
	this->writeAllToFile(this->file);
}


void FileRepository::removeDog(Dog d)
{
	this->Repository::removeDog(d);
	this->writeAllToFile(this->file);
}

void FileRepository::updateDog(Dog d)
{
	this->Repository::updateDog(d);
	this->writeAllToFile(this->file);
}

void FileRepository::play()
{
	;
}


//// --------------------------------CSV REPO --------------------------



CSVRepository::CSVRepository(std::string file)
{
	this->file = file;
	this->readAllFromFile(file);
}


void CSVRepository::addDog(Dog d)
{
	this->Repository::addDog(d);
	this->writeAllToFile(this->file);
}


void CSVRepository::removeDog(Dog d)
{
	this->Repository::removeDog(d);
	this->writeAllToFile(this->file);
}

void CSVRepository::updateDog(Dog d)
{
	this->Repository::updateDog(d);
	this->writeAllToFile(this->file);
}

void CSVRepository::play()
{

	ShellExecuteA(NULL, NULL, this->file.c_str() , NULL, NULL, SW_SHOWMAXIMIZED);
}

void CSVRepository::writeAllToFile(std::string file)
{
	ofstream f;
	f.open(file);
	auto it = this->dogs.begin();
	for (; it < this->dogs.end() - 1; it++)
	{
		Dog dog = *it;
		f << dog.getBreed() << "," << dog.getName() << "," << dog.getAge() << "," << dog.getPhoto();

	}
	Dog dog = *it;
	f << dog.getBreed() << "," << dog.getName() << "," << dog.getAge() << "," << dog.getPhoto();

	f.close();
}

void CSVRepository::readAllFromFile(std::string file)
{
	ifstream f;
	f.open(file);
	std::string breed;
	std::string name;
	int age;
	std::string photo;
	std::string line;
	while (!is_empty(f))
	{
		Dog dog{};

		std::string breed;
		std::string name;
		string age;
		std::string photo;
		std::string line;
		std::getline(f, breed, ',');
		std::getline(f, name, ',');
		std::getline(f, age, ',');
		std::getline(f, photo, '\n');
		int agee;
		agee = atoi(age.c_str());
		dog.setBreed(breed);
		dog.setAge(agee);
		dog.setName(name);
		dog.setPhoto(photo);

		this->dogs.push_back(dog);
	}
	f.close();
}


// ----------------------------------HTML REPO------------------------------






HTMLRepository::HTMLRepository(std::string file)
{
	this->file = file;
	this->readAllFromFile(file);
}


void HTMLRepository::addDog(Dog d)
{
	this->Repository::addDog(d);
	this->writeAllToFile(this->file);
}


void HTMLRepository::removeDog(Dog d)
{
	this->Repository::removeDog(d);
	this->writeAllToFile(this->file);
}

void HTMLRepository::updateDog(Dog d)
{
	this->Repository::updateDog(d);
	this->writeAllToFile(this->file);
}

void HTMLRepository::play()
{
	ShellExecuteA(NULL, NULL, this->file.c_str(), NULL, NULL, SW_SHOWMAXIMIZED);

}

void HTMLRepository::writeAllToFile(std::string file)
{
	ofstream f;
	f.open(file);
	auto it = this->dogs.begin();
	f << "<!DOCTYPE html>\n<html>\n<head>\n<title>List of dogs</title>\n</head>\n<body>\n<table border = \"1\">\n";
	f << "<tr>\n<td>Breed</td>\n<td>Name</td>\n<td>Age</td>\n<td>Photo link</td>\n</tr>\n";
	for (; it < this->dogs.end(); it++)
	{
		Dog dog = *it;
		//f << dog.getBreed() << "," << dog.getName() << "," << dog.getAge() << "," << dog.getPhoto();
		f << "<tr>\n<td>" << dog.getBreed() << "</td>\n";
		f << "<td>" << dog.getName() << "</td>\n";
		f << "<td>" << dog.getAge() << "</td>\n";
		f << "<td><a href =\"" << dog.getPhoto() << "\">Link</a></td>\n";
		f << "</tr>\n";
	}
	f << "</table>\n</body>\n</html>\n";
	f.close();
}

void HTMLRepository::readAllFromFile(std::string file)
{
	ifstream f;
	f.open(file);
	if (Repository::is_empty(f))
		return;
	std::string notused;
	for(int i=1;i<=13;i++)
		std::getline(f, notused, '\n');
	std::string breed;
	std::string name;
	int age;
	std::string photo;
	std::string line;
	std::string finall = "</table>";
	std::getline(f, notused, '\n');
	while (notused != finall)
	{
		cout << notused << endl;

		Dog dog{};
		std::string breed;
		std::string name;
		string age;
		std::string photo;
		std::string line;
		std::getline(f, breed, '>');
		std::getline(f, breed, '<');
		std::getline(f, notused, '\n');
		std::getline(f, name, '>');
		std::getline(f, name, '<');
		std::getline(f, notused, '\n');
		std::getline(f, age, '>');
		std::getline(f, age, '<');
		std::getline(f, notused, '\n');
		std::getline(f, photo, '\"');
		std::getline(f, photo, '\"');
		std::getline(f, notused, '\n');
		int agee;
		agee = atoi(age.c_str());
		dog.setBreed(breed);
		dog.setAge(agee);
		dog.setName(name);
		dog.setPhoto(photo);

		cout << breed << " " << name << " " << age << " " << photo << endl;

		std::getline(f, notused, '\n');
		std::getline(f, notused, '\n');

		cout << notused << endl;
		
		this->dogs.push_back(dog);
	}
	/*std::getline(f, notused, '\n');
	std::getline(f, notused, '\n');
	std::getline(f, notused, '\n');
	*/
	f.close();
}
