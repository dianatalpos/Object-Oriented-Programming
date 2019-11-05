#pragma once
#include "Repository.h"
#include <QtWidgets/QMainWindow>
#include "ui_ecuatii.h"

class ecuatii : public QMainWindow
{
	Q_OBJECT

private:
	Repository& repo;

public:
	ecuatii(Repository& _repo, QWidget *parent = Q_NULLPTR);

private:
	Ui::ecuatiiClass ui;
	void populate();
	void computeValues();
	void editFct();
	void edita();
	void editb();
	void editc();
};
