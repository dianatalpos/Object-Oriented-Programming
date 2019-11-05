#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Examen.h"
#include "Controller.h"
#include "MyModel.h"
#include "Team.h"
#include <QMessageBox>
#include "Statistics.h"

class Examen : public QMainWindow
{
	Q_OBJECT

public:
	Examen(MyModel* model , Controller* ctr, Team* prog, Statistics* statistics, QWidget *parent = Q_NULLPTR);

private:
	Statistics* statistics;
	Controller* ctr;
	MyModel* model;
	Team* programmer;
	void addFile();
	void reviseFile();
	Ui::ExamenClass ui;
};
