#pragma once
#include <string>

class Team
{
private:
	std::string name;
	int revisedFiles;
	int files;
public:
	Team(std::string name,int revisedFiles,int files);
	std::string getName() { return this->name; }
	int getRevised() { return this->revisedFiles;}
	int getFiles() { return this->files; }
	void setRevised(int value) { this->revisedFiles += value; }
	void setFiles(int value) { this->files += value; }
	~Team();
};

