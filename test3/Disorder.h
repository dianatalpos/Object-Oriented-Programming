#pragma once

#include <string>

class Disorder
{

private:
	char category[50];
	char name[100];
	char symptoms[200];

public:
	Disorder(char* category,char* name,char* symptoms);
	char* getCategory() { return this->category; }
	char* getName() { return this->name; }
	char* getSymptoms() { return this->symptoms; }
	
	~Disorder();
};

