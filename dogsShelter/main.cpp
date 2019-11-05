#include "lab1112.h"
#include <QtWidgets/QApplication>
#include "MyGuiByHand.h"
#include "Repository.h"
#include "Controller.h"
#include "Validator.h"
#include "MyModel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository* repo = new FileRepository("dogs.txt");
	Repository* adoption = new FileRepository("adoption.txt");
	DogValidator valid{};

	MyModel *mRepo = new MyModel{ repo };
	MyModel *mAdopt = new MyModel{ adoption };

	Controller ctr{ repo,adoption, valid };

	//MyGuiByHand w{ ctr };
	//w.show();

	lab1112 w1{ctr, mRepo, mAdopt};
	w1.show();


	return a.exec();
}
