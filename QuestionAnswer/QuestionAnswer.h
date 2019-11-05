#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QuestionAnswer.h"
#include "Controller.h"
#include <string>
#include "MyModel.h"
#include <QMessageBox>

class QuestionAnswer : public QMainWindow
{
	Q_OBJECT

public:
	QuestionAnswer(MyModel* mdoel,Controller* ctr, std::string name, QWidget *parent = Q_NULLPTR);

private:
	Controller* ctr;
	std::string name;
	MyModel* model;
	void addQuestion();
	void displayAnswer();
	Ui::QuestionAnswerClass ui;
};
