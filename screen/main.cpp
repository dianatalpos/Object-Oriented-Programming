#include "screen.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "MyModel.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	Controller* ctr = new Controller{ repo };
	MyModel *model = new MyModel{ repo };

	for (auto i : ctr->getWriters())
	{
		screen *w = new screen{model,ctr, i};
		w->show();
	}
	return a.exec();
}
