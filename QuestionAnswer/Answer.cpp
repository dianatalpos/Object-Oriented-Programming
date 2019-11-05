#include "Answer.h"



Answer::Answer(int id, int idq, std::string name, std::string text, int votes)
{
	this->id = id;
	this->name = name;
	this->idQuestion = idq;
	this->text = text;
	this->votes = votes;

}


Answer::~Answer()
{
}
