#pragma once
#include "Repository.h"


class Controller
{
private:
	Repository& repo;
public:
	Controller( Repository& repo);
	std::vector<Writer> getWriters() { return this->repo.getWriters(); }
	std::vector<Idea>& getIdeas() { return this->repo.getIdeas(); }

	void addIdea(std::string description, std::string name, std::string status, int act);
	~Controller();
};

