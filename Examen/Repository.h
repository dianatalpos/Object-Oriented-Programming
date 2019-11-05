#pragma once
#include <vector>
#include <string>
#include "Team.h"
#include "SourceFile.h"
#include <fstream>
#include "Errors.h"

class Repository
{
private:
	std::vector<Team*> programmers;
	std::vector<SourceFile> files;
	void readAllFromFile();
	void sort();
public:
	int getSize() { return this->files.size(); }
	SourceFile getFile(int row) { return this->files[row]; }
	std::vector<Team*> getTeam() { return this->programmers; }
	void addFile(SourceFile file);
	void setFile(int index,std::string status, Team* programmer);
 	Repository();
	~Repository();
};

