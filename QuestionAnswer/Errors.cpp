#include "Errors.h"



Errors::Errors()
{
}


Errors::~Errors()
{
}

const char * QuestionError::what() const noexcept
{
	return this->message.c_str();
	return nullptr;
}
