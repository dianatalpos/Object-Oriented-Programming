#include "Repository.h"



void Repository::readAllFromFile()
{
	std::ifstream u("users.txt");
	std::ifstream a("answers.txt");
	std::ifstream q("questions.txt");


	std::string name;
	while (u >> name)
	{
		this->users.push_back(name);
	}

	int id;
	std::string text;
	while (!q.eof())
	{
		char p;
		q >> id;
		q >> p;
		std::getline(q, text, ',');
		std::getline(q, name, '\n');
		Question x{ text, id, name };
		this->questions.push_back(x);
	}

	int idq;
	int votes;
	while (!a.eof())
	{
		char p;
		a >> id;
		a >> p;
		a >> idq;
		a >> p;
		std::getline(a, name, ',');
		std::getline(a, text, ',');
		a >> votes;
		Answer ans{ id, idq,name, text, votes };
		this->answers.push_back(ans);
		for (auto it = this->questions.begin(); it < this->questions.end(); it++)
		{
			if ((*it).getId() == id)
				(*it).setNumber();
		}
	}


}

void Repository::sortQuestion()
{
	for(auto i = this->questions.begin();i<this->questions.end()-1;i++)
		for (auto j = i + 1; j < this->questions.end(); j++)
		{
			if ((*j).getNumber() > (*i).getNumber())
			{
				Question aux;
				aux = (*i);
				(*i) = (*j);
				(*j) = aux;
			}
		}
}

Repository::Repository()
{
	this->readAllFromFile();
}


void Repository::addQuestion(Question q)
{
	if (q.getText() == "")
		throw QuestionError("You must add a question!\n");
	this->questions.push_back(q);
}

Repository::~Repository()
{
}
