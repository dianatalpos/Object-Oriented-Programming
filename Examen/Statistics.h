#pragma once

#include <QWidget>
#include "ui_Statistics.h"
#include "Model.h"

class Statistics : public QWidget
{
	Q_OBJECT

public:
	Statistics(Model* model,QWidget *parent = Q_NULLPTR);
	~Statistics();
	Model* model;
private:
	Ui::Statistics ui;
};
