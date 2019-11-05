#include "chat.h"
#include <QtWidgets/QApplication>
#include <string>
#include "ChatSession.h"
#include "Observer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	ChatSession cht{};
	chat w3{cht, "Paul"};
	chat w2{ cht, "fdsf" };
	chat w1{ cht, "fds" };


	cht.registerObserver(&w1);
	cht.registerObserver(&w2);
	cht.registerObserver(&w3);

	w1.show();
	w2.show();
	w3.show();

	return a.exec();
}
