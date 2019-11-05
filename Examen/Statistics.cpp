#include "Statistics.h"

Statistics::Statistics(Model* model,QWidget *parent)
	: QWidget(parent), model {model}
{
	ui.setupUi(this);
	this->ui.tableView->setModel(model);
	this->model->layoutChanged();
	
}

Statistics::~Statistics()
{
}
