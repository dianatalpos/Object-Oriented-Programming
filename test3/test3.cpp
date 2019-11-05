#include "test3.h"


test3::test3(Controller& _ctr, QWidget *parent)
	: QMainWindow(parent), ctr{_ctr}
{
	ui.setupUi(this);
	this->populate();
	QObject::connect(ui.symptomButton, &QPushButton::clicked, this, &test3::showSymptoms);
}

void test3::populate()
{
	this->ui.disordersList->clear();
	for (auto x : this->ctr.getAll())
	{
		char name[100];
		strcpy(name, x.getName());
		char category[50];
		strcpy(category, x.getCategory());
		char symptoms[200];
		strcpy(symptoms, x.getSymptoms());

		std::string all = "";
		all += category;
		all += " | ";
		all += name;
		all += " | ";
		all += symptoms;
		this->ui.disordersList->addItem(QString::fromStdString(all));
	}
}

void test3::showSymptoms()
{
	std::string symptom ="";
	//QString a = 
	symptom = (this->ui.lineEdit->text()).toStdString();
	//symptom += QString::toStdString(a);
	Symptoms *w = new Symptoms{this->ctr, symptom};
	(*w).show();

	this->hide();
}
