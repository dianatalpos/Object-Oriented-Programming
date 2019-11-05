#pragma once

#include "Controller.h"
#include <QtWidgets/QMainWindow>
#include "ui_lab1112.h"
#include "MyModel.h"

class lab1112 : public QMainWindow
{
	Q_OBJECT

public:
	lab1112( Controller& ctr, MyModel *mrepo, MyModel* madopt, QWidget *parent = Q_NULLPTR);


private:
	Controller& ctr;
	Ui::lab1112Class ui;
	MyModel *m1;
	MyModel *m2;
	void administratorMode();
	void userMode();
};
