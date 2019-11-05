#include "Examen.h"

Examen::Examen(MyModel* model, Controller* ctr, Team* prog, Statistics* statistics, QWidget *parent)
	: QMainWindow(parent), model {model}, ctr{ctr}, programmer{prog}, statistics{statistics}
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->programmer->getName()));
	this->ui.filesView->setModel(model);
	this->ui.haveTo->setText(QString::number(this->programmer->getFiles()));
	this->ui.revisedValue->setText(QString::number(this->programmer->getRevised()));


	QObject::connect(ui.filesView, &QListView::clicked, [this]()
	{
		SourceFile file = this->ctr->getFile(this->ui.filesView->currentIndex().row());
		if (file.getStatus() == "not_revised")
		{
			if( this->programmer->getName() != file.getCreator() )
				this->ui.revisedButton->setEnabled(true);
			else
				this->ui.revisedButton->setEnabled(false);
		}
		else
		{
			this->ui.revisedButton->setEnabled(false);
		}
	});
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &Examen::addFile);
	QObject::connect(ui.revisedButton, &QPushButton::clicked, this, &Examen::reviseFile);
}

void Examen::addFile()
{
	std::string name = this->ui.nameEdit->text().toStdString();
	try
	{
		this->ctr->addFile(name, "not_revised", this->programmer->getName(), "None");
		this->model->layoutChanged();
	}
	catch (std::exception& e)
	{
		QMessageBox* m = new QMessageBox{};
		m->setText(e.what());
		m->exec();
	}

}

void Examen::reviseFile()
{
	if (this->programmer->getRevised() != 0)
	{
		int index = this->ui.filesView->currentIndex().row();
		this->ctr->reviseFile(index, "revised", this->programmer);
		this->model->dataChanged(this->ui.filesView->currentIndex(), this->ui.filesView->currentIndex());
		this->ui.haveTo->setText(QString::number(this->programmer->getFiles()));
		this->ui.revisedValue->setText(QString::number(this->programmer->getRevised()));
	}

	if (this->programmer->getFiles() == 0)
	{
		this->statistics->model->notify();
		QMessageBox* m = new QMessageBox{};
		m->setText("Congratulations!");
		m->exec();
	}

}
