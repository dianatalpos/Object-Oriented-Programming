#include "lab1112.h"
#include "MyGuiByHand.h"
#include "UserMode.h"
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QRadioButton>
#include <QLineEdit>

lab1112::lab1112(Controller& _ctr,MyModel* _m1, MyModel* _m2, QWidget *parent)
	: QMainWindow(parent), ctr(_ctr), m1{_m1}, m2{_m2}
{
	ui.setupUi(this);
	QObject::connect(this->ui.administratorButton, &QPushButton::clicked,this,  &lab1112::administratorMode);
	QObject::connect(this->ui.userButton, &QPushButton::clicked, this, &lab1112::userMode);
}

void lab1112::administratorMode()
{
	MyGuiByHand *w = new MyGuiByHand{ this->ctr };
	w->show();
	this->hide();
}

void lab1112::userMode()
{
	UserMode *w = new UserMode{this->ctr, this->m1, this->m2};

	UserMode *w2 = new UserMode{ this->ctr, this->m1, this->m2 };
	UserMode *w3 = new UserMode{ this->ctr, this->m1, this->m2 };
	UserMode *w4 = new UserMode{ this->ctr, this->m1, this->m2 };

	w->show();
	w2->show();
	w3->show();
	w4->show();
	this->hide();
}


