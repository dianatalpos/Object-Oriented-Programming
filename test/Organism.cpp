#include "Organism.h"

Organism::Organism(std::string type, int number, bool isImmune)
{
	this->type = type;
	this->number = number;
	this->isImmune = isImmune;
}

Organism::~Organism()
{

}


void Organism::setNumber(int number)
{
	this->number += number;
}

