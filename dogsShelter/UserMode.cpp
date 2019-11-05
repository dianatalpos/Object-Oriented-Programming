#include "UserMode.h"
#include <QMessageBox>

UserMode::UserMode(Controller& _ctr, MyModel *mrepo, MyModel* madopt,QWidget *parent)
	: QWidget(parent), ctr{_ctr}, mRepo{mrepo}, mAdopt{madopt}
{
	ui.setupUi(this);
	this->ui.dogsList->setModel(mRepo);
	this->ui.adoptionList->setModel(mAdopt);
	this->ui.dogsList->setSelectionMode(QAbstractItemView::SingleSelection);
	//this->populateDogs();
	//this->populateAdoption();
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &UserMode::addTo);
}

UserMode::~UserMode()
{
}


void UserMode::populateDogs()
{
/*	this->ui.dogsList->clear();

	for (auto& s : this->ctr.getAlldogs())
	{
		std::string age = std::to_string(s.getAge());
		this->ui.dogsList->addItem(QString::fromStdString(s.getBreed() + ", " + s.getName() + ", " + age ));
	}
*/
}

void UserMode::populateAdoption()
{
/*
	this->ui.adoptionList->clear();

	for (auto& s : this->ctr.getAllAdoption())
	{
		std::string age = std::to_string(s.getAge());
		this->ui.adoptionList->addItem(QString::fromStdString(s.getBreed() + ", " + s.getName() + ", " + age ));
	}
*/
}


void UserMode::addTo()
{

	QModelIndex index = this->ui.dogsList->currentIndex();
	Dog d = this->mRepo->adopt(index);
	this->mRepo->removeRow(index.row());
	this->mAdopt->addto(d);
	this->mAdopt->insertRow(this->ctr.get_size(1));
	
	/*
	int row = this->ui.dogsList->currentRow();
	QListWidgetItem *t = this->ui.dogsList->takeItem(row);
	this->ui.adoptionList->addItem(t);
	std::string info;
	info = ((*t).text()).toStdString();
	std::string name;
	std::size_t found = info.find_first_of(",");
	std::size_t found2 = info.find_first_of(",", found+1);
	name.assign(info, found+2, found2-found-2 );
	Dog d = this->ctr.search_dog(name);
	try
	{
		this->ctr.add_adoption(d);
	}
	catch (std::exception &e)
	{
		QMessageBox* addDog = new QMessageBox();
		addDog->setText(e.what());
		addDog->exec();
	}
	*/
	
}

void UserMode::exit_function()
{

}


