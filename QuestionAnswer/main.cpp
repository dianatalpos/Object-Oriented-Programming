#include "QuestionAnswer.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "MyModel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Repository repo{};
	Controller* ctr = new Controller{ repo };
	MyModel* model = new MyModel{repo};
	
	for (auto i : ctr->getUsers())
	{
		QuestionAnswer *w = new QuestionAnswer(model,ctr, i);
		w->show();
	}
	/*QuestionAnswer w;
	w.show();
	*/

	return a.exec();
}
