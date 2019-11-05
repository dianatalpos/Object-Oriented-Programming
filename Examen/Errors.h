#pragma once
#include <string>
#include <exception>

class Errors
{
public:
	Errors();
	~Errors();
};

class FileError : public std::exception
{
private:
	std::string message;
public:
	FileError(std::string message): message{message}{}
	const char* what() const noexcept;
};
