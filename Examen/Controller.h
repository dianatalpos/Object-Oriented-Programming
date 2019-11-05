#pragma once
#include "Repository.h"


class Controller
{

private:
	Repository& repo;
public:
	Controller(Repository& repo);
	void addFile(std::string name, std::string status, std::string creator, std::string reviewer);
	SourceFile getFile(int pos) { return this->repo.getFile(pos); }
	void reviseFile(int position, std::string status, Team *programmer);
	~Controller();
};

