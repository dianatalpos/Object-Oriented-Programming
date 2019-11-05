#include "Errors.h"



Errors::Errors()
{
}


Errors::~Errors()
{
}

const char * FileError::what() const noexcept
{
	return this->message.c_str();
}
