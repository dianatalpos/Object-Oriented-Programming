#include "MyGuiByHand.h"
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <qshortcut.h>
#include <QAction>


MyGuiByHand::MyGuiByHand(Controller& _ctr): ctr {_ctr}
{
	this->my_init();
}

void MyGuiByHand::my_init()
{

	QHBoxLayout* main = new QHBoxLayout{this};
	QVBoxLayout* right = new QVBoxLayout{};
	QVBoxLayout* left = new QVBoxLayout{};

	this->dogs = new QListWidget{};
	this->populateDogs();


	QRadioButton* shuffled = new QRadioButton("Shuffled", this);
	QRadioButton* sorted = new QRadioButton("Sorted", this);

	QFormLayout *formButtons = new QFormLayout{};

	formButtons->addRow(shuffled);
	formButtons->addRow(sorted);

	main->addLayout(formButtons);
	main->addWidget(this->dogs);

	this->name = new QLineEdit();
	this->breed = new QLineEdit();
	this->age = new QLineEdit();
	this->photo = new QLineEdit();


	this->add = new QPushButton("Add");
	this->remove = new QPushButton("Remove");
	this->update = new QPushButton("Update");
	
	this->undo = new QPushButton("Undo");
	this->redo = new QPushButton("Redo");


	QFormLayout *form = new QFormLayout{};

	form->addRow("Name", this->name);
	form->addRow("Breed", this->breed);
	form->addRow("Age", this->age);
	form->addRow("Photo", this->photo);

	form->addRow(this->add);
	form->addRow(this->remove);
	form->addRow(this->update);
	form->addRow(this->undo);
	form->addRow(this->redo);
	right->addLayout(form);
	main->addLayout(right);
	//auto key = QShortcut("Ctrl+Z", t);
	/*auto keysh = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this, SLOT(MyGuiByHand::perform_undo()));
	QAction *foo = new QAction(this);
	foo->setShortcut(Qt::Key_Z | Qt::CTRL);

	QObject::connect(foo, SIGNAL(triggered()), this, SLOT(perform_undo()));
	this->addAction(foo);
	*/

	QShortcut* st = new QShortcut(QKeySequence("Ctrl+Z"), this);
	QObject::connect(st, &QShortcut::activated, this, &MyGuiByHand::perform_undo);
	QShortcut* st1 = new QShortcut(QKeySequence("Ctrl+Y"), this);
	QObject::connect(st1, &QShortcut::activated, this, &MyGuiByHand::perform_redo);


	QObject::connect(shuffled, &QPushButton::clicked, this, &MyGuiByHand::shuffledHandler);
	QObject::connect(sorted, &QPushButton::clicked, this, &MyGuiByHand::sortedHandler);
	QObject::connect(add, &QPushButton::clicked, this, &MyGuiByHand::addDog);
	QObject::connect(remove, &QPushButton::clicked, this, &MyGuiByHand::removeDog);
	QObject::connect(update, &QPushButton::clicked, this, &MyGuiByHand::updateDog);
	QObject::connect(undo, &QPushButton::clicked, this, &MyGuiByHand::perform_undo);
	QObject::connect(redo, &QPushButton::clicked, this, &MyGuiByHand::perform_redo);


}

void MyGuiByHand::populateDogs()
{
	this->dogs->clear();

	for (auto& s : this->ctr.getAlldogs())
	{
		std::string age = std::to_string(s.getAge());
		this->dogs->addItem(QString::fromStdString(s.getBreed() + ", " + s.getName() + ", " + age /*+ " - " + s.getSource()*/));
	}
}

void MyGuiByHand::sortedHandler()
{
	this->ctr.sorted();
	this->populateDogs();

}

void MyGuiByHand::shuffledHandler()
{
	this->ctr.shuffled();
	this->populateDogs();

}

void MyGuiByHand::addDog()
{
	std::string name;
	std::string breed;
	std::string photo;
	int age;
	name = this->name->text().toStdString();
	breed = this->breed->text().toStdString();
	photo = this->photo->text().toStdString();
	age = stoi(this->age->text().toStdString());
	try
	{
		this->ctr.add_dog(breed, name, age, photo);
	}
	catch (std::exception& e)
	{
		QMessageBox* addDog = new QMessageBox();
		addDog->setText(e.what());
		addDog->exec();
	}
	this->populateDogs();
}

void MyGuiByHand::removeDog()
{
	std::string name;
	name = this->name->text().toStdString();
	try
	{
		this->ctr.remove_dog(name);
	}
	catch (std::exception& e)
	{
		QMessageBox* removeDog = new QMessageBox();
		removeDog->setText(e.what());
		removeDog->exec();
	}
	this->populateDogs();

}

void MyGuiByHand::updateDog()
{
	std::string name;
	std::string breed;
	std::string photo;
	int age;
	name = this->name->text().toStdString();
	breed = this->breed->text().toStdString();
	photo = this->photo->text().toStdString();
	age = stoi(this->age->text().toStdString());
	try
	{
		this->ctr.update_dog(breed, name, age, photo);
	}
	catch (std::exception& e)
	{
		QMessageBox* updateDog = new QMessageBox();
		updateDog->setText(e.what());
		updateDog->exec();
	}
	this->populateDogs();

}

void MyGuiByHand::perform_undo()
{
	try
	{
		this->ctr.perform_undo();
		this->populateDogs();
	}
	catch (std::exception& e)
	{
		QMessageBox* undoo = new QMessageBox();
		undoo->setText(e.what());
		undoo->exec();
	}
}

void MyGuiByHand::perform_redo()
{
	try
	{
		this->ctr.perform_redo();
		this->populateDogs();
	}
	catch (std::exception& e)
	{
		QMessageBox* redoo = new QMessageBox();
		redoo->setText(e.what());
		redoo->exec();
	}
}




MyGuiByHand::~MyGuiByHand()
{
}
