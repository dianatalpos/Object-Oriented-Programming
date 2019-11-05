#include "observer.h"
#include <QtWidgets/QApplication>
#include "ChatSession.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ChatSession s1{};
	observer w1{s1};
	observer w2{ s1 };
	observer w3{ s1 };
	observer w4{ s1 };

	s1.registerObserver(&w1);
	s1.registerObserver(&w2);
	s1.registerObserver(&w3);
	s1.registerObserver(&w4);


	w1.show();
	w2.show();
	w3.show();
	w4.show();
	return a.exec();
}
