#pragma once
#include <exception>
#include <string>

class Errors
{
public:
	Errors();
	~Errors();
};


class QuestionError : public std::exception
{
private:
	std::string message;
public:
	QuestionError(std::string msg): message{msg} {}
	const char* what() const noexcept;
	~QuestionError() {};
};

