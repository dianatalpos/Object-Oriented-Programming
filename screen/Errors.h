#pragma once
#include "string"
class Errors
{
public:
	Errors();
	~Errors();
};


class IdeaError: public std::exception
{
private:
	std::string message;
public:
	IdeaError(std::string name): message {name} {}
	~IdeaError() {}
	virtual const char* what() const noexcept
	{
		return this->message.c_str();
	}

};
