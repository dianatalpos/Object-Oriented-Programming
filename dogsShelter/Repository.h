#pragma once
#include "Dog.h"
#include <stdlib.h>
#include <vector>

using namespace std;

class Repository {
protected:
	std::vector<Dog> dogs;

public:
	//default constructor
	Repository();
	/*void writeAllToFile(std::string file);
	void readAllFromFile(std::string file);
	*/
	//function to get the size
	int get_size();

	//function to get an element from the given position
	Dog get_elem(int i);

	//function to get the elements
	std::vector<Dog> getAll() const { return dogs; }

	//function to search for an element by a given name
	Dog search(std::string name);

	//function to add an element
	virtual void addDog(Dog d);

	//function to remove an element
	virtual void removeDog(Dog d);

	//function to update an element
	virtual void updateDog(Dog d);

	void shuffle();
	void sorted();
	int search_name(std::string name);
	bool is_empty(std::ifstream& pFile);
	bool search_breed(std::string breed, Dog d);

	virtual void play() = 0;
	//destructor
	~Repository();
};

class FileRepository : public Repository
{
private:
	std::string file;
public:
	FileRepository(std::string file);

	void writeAllToFile(std::string file);
	void readAllFromFile(std::string file);
	void addDog(Dog d) override;
	void removeDog(Dog d) override;
	void updateDog(Dog d)override;
	void play() override;
};

class CSVRepository : public Repository
{

private:
	std::string file;
public:
	CSVRepository(std::string file);

	void writeAllToFile(std::string file);
	void readAllFromFile(std::string file);
	void addDog(Dog d) override;
	void removeDog(Dog d) override;
	void updateDog(Dog d)override;
	void play() override;
};


class HTMLRepository : public Repository
{

private:
	std::string file;
public:
	HTMLRepository(std::string file);

	void writeAllToFile(std::string file);
	void readAllFromFile(std::string file);
	void addDog(Dog d) override;
	void removeDog(Dog d) override;
	void updateDog(Dog d)override;
	void play() override;
};
