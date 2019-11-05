#include "SourceFile.h"



SourceFile::SourceFile(std::string name, std::string status, std::string creator, std::string reviewer)
{
	this->name = name;
	this->status = status;
	this->creator = creator;
	this->reviewer = reviewer;
}


SourceFile::~SourceFile()
{
}
