#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_screen.h"
#include "Controller.h"
#include "MyModel.h"
#include <QMessageBox>

class screen : public QMainWindow
{
	Q_OBJECT

public:
	screen(MyModel* model,Controller* ctr, Writer w , QWidget *parent = Q_NULLPTR);

private:
	MyModel* model;
	Controller* ctr;
	Writer writer;
	Ui::screenClass ui;
	void addIdea();
	void setStatus();
};
