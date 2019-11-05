#include "test3.h"
#include <QtWidgets/QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller ctr{};
	test3 w{ctr};
	w.show();
	return a.exec();
}
