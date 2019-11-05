#include "Team.h"



Team::Team(std::string name, int revisedFiles, int files)
{
	this->name = name;
	this->revisedFiles = revisedFiles;
	this->files = files;

}


Team::~Team()
{
}
