#include "ecuatii.h"
#include <QtWidgets/QApplication>
#include "Repository.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo("ecuatii.txt");
	ecuatii w{repo};
	w.show();
	return a.exec();
}
