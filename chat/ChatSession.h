#pragma once
#include <vector>
#include "Subject.h"

class ChatSession: public Subject
{

private:
	std::vector<std::string> messages;

public:
	void addMessage(std::string user, std::string message);
	std::vector<std::string> getMessages() { return this->messages; }
	ChatSession();
	~ChatSession();
};

