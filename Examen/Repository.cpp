#include "Repository.h"



void Repository::readAllFromFile()
{
	std::ifstream p("team.txt");
	std::ifstream f("files.txt");
	std::string name;
	int revised;
	int haveTo;
	while (p >> name >> revised >> haveTo)
	{
		Team *progammer = new Team{ name, revised, haveTo };
		this->programmers.push_back(progammer);
	}
	std::string creator;
	std::string reviewer;
	std::string status;
	while (f >> name >> status >> creator >> reviewer)
	{
		SourceFile file{ name, status, creator, reviewer };
		this->files.push_back(file);
	}
	this->sort();
}

void Repository::sort()
{
	for(auto it =this->files.begin(); it< this->files.end() - 1; it++)
		for (auto ij = it + 1;ij< this->files.end(); ij++)
			if((*it).getName()>(*ij).getName())
			{
				SourceFile aux;
				aux = (*it);
				(*it) = (*ij);
				(*ij) = aux;
			}
}



/*
Function that adds a new source file
in: file which is a Source File
throw exception:
	-the name of the file is empty
	-this file already exists
out:-
*/
void Repository::addFile(SourceFile file)
{
	if (file.getName() == "")
		throw FileError("The name of the file must contain some characters!");
	for (auto i : this->files)
	{
		if (i.getName() == file.getName())
			throw FileError("This file already exists!");
	}
	this->files.push_back(file);
	this->sort();
}


/*
This function updates the status of a file and updates the revised files for a programmer
int: index - position where it found the element that has to be updated
	status - a new status for a file
	programmer - the programmer that revised the file
out: -
*/
void Repository::setFile(int index,std::string status, Team* programmer)
{
	this->files[index].setStatus(status);
	this->files[index].setReviewer(programmer->getName());
	for (auto i : this->programmers)
	{
		if ((*i).getName() == programmer->getName())
		{
			(*i).setFiles(-1);
			(*i).setRevised(1);
			break;
		}
	}
}

Repository::Repository()
{
	this->readAllFromFile();
}


Repository::~Repository()
{
}
