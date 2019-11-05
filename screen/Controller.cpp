#include "Controller.h"



Controller::Controller(Repository& repo): repo{repo}
{
}


void Controller::addIdea(std::string description, std::string name, std::string status, int act)
{
	Idea i{ description, status, name, act };
	this->repo.addIdea(i);
}

Controller::~Controller()
{
}
