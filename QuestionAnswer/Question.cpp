#include "Question.h"



Question::Question(std::string text, int id, std::string name)
{
	this->text = text;
	this -> id = id;
	this->name = name;
	this->number = 0;
}


Question::~Question()
{
}
