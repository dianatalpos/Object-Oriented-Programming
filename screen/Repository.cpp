#include "Repository.h"
#include <fstream>


void Repository::readAllFromFile()
{
	std::ifstream w("writers.txt");
	std::ifstream i("ideas.txt");
	std::string name;
	std::string expertise;
	while (w >> name >> expertise)
	{
		Writer w{ name, expertise };
		this->writers.push_back(w);
	}
	int act;
	std::string description;
	std::string status;
	while (i >> description >> status >> name >> act)
	{
		Idea ide{ description,status, name, act };
		this->ideas.push_back(ide);
	}
}

void Repository::sort()
{
	for (auto it = this->ideas.begin(); it < this->ideas.end()-1; it++)
	{
		for (auto ij = it + 1; ij < this->ideas.end(); ij++)
		{
			if ((*it).getAct() > (*ij).getAct())
			{
				Idea a;
				a = (*it);
				(*it) = (*ij);
				(*ij) = a;
			}
		}
	}
}

Repository::Repository()
{
	this->readAllFromFile();
	this->sort();
}



void Repository::addIdea(Idea i)
{
	if (!(i.getAct() == 1 || i.getAct() == 2 || i.getAct() == 3))
		throw IdeaError("The act is invalid!");
	if (i.getDescription().size() == 0)
		throw IdeaError("The description is empty!");
	
	
	for (auto idea : this->ideas)
	{
		if (idea.getDescription() == i.getDescription())
		{
			throw IdeaError{"This idea already exists!" };
		}
	}
	this->ideas.push_back(i);
	this->sort();
}

Repository::~Repository()
{
}
