#include "Symptoms.h"
#include <string>

Symptoms::Symptoms(Controller& ctr, std::string sym, QWidget *parent)
	: QWidget(parent), ctr {ctr}
{
	this->symptoms = sym;
	ui.setupUi(this);
	this->populate();
}

Symptoms::~Symptoms()
{
}

void Symptoms::populate()
{
	this->ui.listWidget->clear();
	std::string sympt = this->ctr.searchByName(this->symptoms);
	size_t n = sympt.find_first_of(',');
	this->ui.listWidget->addItem(QString::fromStdString(sympt));
}

