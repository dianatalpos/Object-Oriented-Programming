#include "ChatSession.h"



void ChatSession::addMessage(std::string m , std::string user)
{
	this->messages.push_back(user + ": " + m);
	this->notify();
}

ChatSession::ChatSession()
{
}


ChatSession::~ChatSession()
{
}
