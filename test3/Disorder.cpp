#include "Disorder.h"



Disorder::Disorder(char* _category, char* _name, char* _symptoms)
{
	strcpy(this->category ,_category);
	strcpy(this->name, _name);
	strcpy(this->symptoms, _symptoms);
}


Disorder::~Disorder()
{
}
