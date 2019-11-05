#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chat.h"
#include "Observer.h"
#include <string>
#include "ChatSession.h"

class chat : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	chat(ChatSession& session, std::string name,QWidget *parent = Q_NULLPTR);
	void update() override;
private:
	ChatSession& session;
	Ui::chatClass ui;
	std::string user;
	void send_message();
};
