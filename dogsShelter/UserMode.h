#pragma once

#include <QWidget>
#include "ui_UserMode.h"
#include "Controller.h"
#include "MyModel.h"

class UserMode : public QWidget
{
	Q_OBJECT

public:
	UserMode(Controller& ctr, MyModel* m1, MyModel* m2, QWidget *parent = Q_NULLPTR);
	~UserMode();

private:
	Controller& ctr;
	MyModel* mRepo;
	MyModel* mAdopt;
	Ui::UserMode ui;
	void populateDogs();
	void populateAdoption();
	void addTo();
	void exit_function();
};
