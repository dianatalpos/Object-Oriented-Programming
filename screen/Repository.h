#pragma once
#include <vector>
#include <string>
#include "Idea.h"
#include "Writer.h"
#include "Errors.h"

class Repository
{
private:
	std::vector<Idea> ideas;
	std::vector<Writer> writers;
	void readAllFromFile();
	void sort();
public:
	Repository();
	std::vector<Writer> getWriters() { return this->writers; }
	std::vector<Idea>& getIdeas() { return this->ideas; }
	void addIdea(Idea i);
	~Repository();
};

