#pragma once
#include <string>

class Idea
{
private:
	std::string description;
	std::string status;
	std::string name;
	int act;
public:
	Idea() {}
	Idea(std::string description,std::string status,std::string name,int act);
	int getAct() { return this->act; }
	std::string getName() { return this->name; }
	std::string getStatus() { return this->status; }
	std::string getDescription() { return this->description; }
	void setStatus(std::string status) { this->status = status; }
	~Idea();
};

