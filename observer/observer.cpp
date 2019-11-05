#include "observer.h"

observer::observer(ChatSession& s, std::string name, QWidget *parent)
	: QMainWindow(parent), s{s}
{
	this->user = name;
	ui.setupUi(this);
	this->populate();
	QObject::connect(this->ui.pushButton, &QPushButton::clicked,[this]()
	{
		std::string newMessage = this->ui.lineEdit->text().toStdString();
		this->ui.lineEdit->clear();
		this->s.addMessage(newMessage, user);
		this->populate();
	});

}


Observer::Observer()
{
}


Observer::~Observer()
{
}

void observer::update()
{
	this->populate();
}

void observer::populate()
{
	this->ui.chatWindow->clear();
	for (auto s : this->s.getMessages())
	{

	}

}
