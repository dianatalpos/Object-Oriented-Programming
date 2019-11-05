#pragma once

#include <QWidget>
#include "ui_Symptoms.h"
#include "Controller.h"

class Symptoms : public QWidget
{
	Q_OBJECT

private:
	std::string symptoms;
	Controller& ctr;

public:
	Symptoms(Controller& ctr, std::string sym, QWidget *parent = Q_NULLPTR);
	~Symptoms();

private:
	void populate();
	Ui::Symptoms ui;
};
