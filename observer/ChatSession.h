#pragma once
#include "Subject.h"
#include "UserMessage.h"

class ChatSession: public Subject
{
	std::vector<std::string> messages;
public:
	void addMessage(std::string m, std::string user);
	std::vector<std::string> getMessages() { return this->messages; }
	ChatSession();
	~ChatSession();
};

