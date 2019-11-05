#include "screen.h"
#include "Errors.h"
#include <QModelIndex>

screen::screen(MyModel* model,Controller* ctr, Writer w ,QWidget *parent)
	: QMainWindow(parent), ctr{ctr}, writer{w}, model{model}
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->writer.getName()));
	this->ui.ideaView->setModel(model);

	QObject::connect(ui.addButton, &QPushButton::clicked, this, &screen::addIdea);
	if (w.getExpertise() != "senior")
	{
		this->ui.acceptButton->setEnabled(false);
	}
	else
		this->ui.acceptButton->setEnabled(true);
	QObject::connect(ui.ideaView, &QTableView::clicked, [this]() {
		if (this->writer.getExpertise() == "senior") {
			int row = this->ui.ideaView->currentIndex().row();
			if (this->ctr->getIdeas()[row].getStatus() == "proposed")
			{
				this->ui.acceptButton->setEnabled(true);

			}
			else
				this->ui.acceptButton->setEnabled(false);
		}

	});


	QObject::connect(ui.acceptButton, &QPushButton::clicked, this, &screen::setStatus);

}


void screen::addIdea()
{
	std::string description = this->ui.descriptionEdit->text().toStdString();
	int act = this->ui.actEdit->text().toInt();
	try
	{
		this->ctr->addIdea(description, this->writer.getName(), "proposed", act);
		this->model->layoutChanged();
	}
	catch (IdeaError& e)
	{
		QMessageBox* m = new QMessageBox{};
		m->setText(e.what());
		m->exec();
	}

}

void screen::setStatus()
{
	int row = this->ui.ideaView->currentIndex().row();
	this->ctr->getIdeas()[row].setStatus("accepted");
	//this->model->dataChanged(QModelIndex, QModelIndex(row, 1));
	this->model->layoutChanged();
}
