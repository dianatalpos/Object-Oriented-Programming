#include "Controller.h"


Controller::Controller(Repository& repo): repo{repo}
{
}

void Controller::addFile(std::string name, std::string status, std::string creator, std::string reviewer)
{
	SourceFile s{ name, status, creator, reviewer };
	this->repo.addFile(s);
}


void Controller::reviseFile(int position, std::string status, Team* programmer)
{
	this->repo.setFile(position, status, programmer);
}

Controller::~Controller()
{
}
