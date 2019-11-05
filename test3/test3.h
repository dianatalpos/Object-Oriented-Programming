#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test3.h"
#include "Controller.h"
#include "Symptoms.h"

class test3 : public QMainWindow
{
	Q_OBJECT

private:
	Controller& ctr;
public:
	test3(Controller& ctr, QWidget *parent = Q_NULLPTR);

private:
	//Function that populates the list with the current disoders
	void populate();
	Ui::test3Class ui;
	void showSymptoms();
};
