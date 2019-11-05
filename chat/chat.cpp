#include "chat.h"

chat::chat(ChatSession& session, std::string name, QWidget *parent)
	: QMainWindow(parent) , session{session}, user{name}
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &chat::send_message);

}

void chat::update()
{
	this->ui.listWidget->clear();
	for (auto x : this->session.getMessages())
	{
		QListWidgetItem* lwi = new QListWidgetItem{ QString::fromStdString(x) };
		if (x.find(user) == 0)
		{
			this->ui.listWidget->addItem(lwi);
			lwi->setTextAlignment(Qt::AlignRight);
		}
		this->ui.listWidget->addItem(lwi);
	}
}

void chat::send_message()
{
	std::string text = this->ui.lineEdit->text().toStdString();
	this->session.addMessage(this->user, text);
	this->session.notify();
}
