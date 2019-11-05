#include "ChatSession.h"



void ChatSession::addMessage(std::string user, std::string message)
{
	this->messages.push_back(user + ": " + message);
}

ChatSession::ChatSession()
{
}


ChatSession::~ChatSession()
{
}
