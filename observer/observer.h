#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_observer.h"
#include "ChatSession.h"


class Observer
{
public:
	virtual ~Observer() {} ;
	virtual void update() = 0;
};


class observer : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	observer(ChatSession& s, std::string name, QWidget *parent = Q_NULLPTR);
	void update() override;

private:
	std::string user;
	ChatSession& s;
	void populate();
	Ui::observerClass ui;
};

