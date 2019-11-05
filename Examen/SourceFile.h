#pragma once
#include <string>

class SourceFile
{

private:
	std::string name;
	std::string status;
	std::string creator;
	std::string reviewer;

public:
	int changed = 0;
	SourceFile() {}
	SourceFile(std::string name,std::string status,std::string creator,std::string reviewer);
	std::string getName() { return this->name;}
	std::string getStatus() { return this->status;}
	std::string getCreator() { return this->creator; }
	std::string getReviewer() { return this->reviewer; }
	void setStatus(std::string status) { this->status = status; this->changed = 1; }
	void setReviewer(std::string review) { this->reviewer = review; }
	
	~SourceFile();
};

