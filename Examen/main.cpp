#include "Examen.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "MyModel.h"
#include "Statistics.h"
#include <assert.h>
#include "Model.h"
void testFunction()
{
	Repository repo{};
	Controller* ctr = new Controller{ repo };
	try
	{
		ctr->addFile("", "not_revised", "", "");

	}
	catch(std::exception& e)
	{
		assert(strcmp(e.what() , "The name of the file must contain some characters!") == 0);
	}
	try
	{
		ctr->addFile("maine", "not_revised", "", "");

	}
	catch (std::exception& e)
	{
		assert(strcmp(e.what(), "This file already exists!") == 0);
	}
	int size = repo.getSize();
	ctr->addFile("blablabla", "revised", "Andrea", "Simina");
	assert(size + 1 == repo.getSize());
	
	///tests for update a file
	
	Team *p = new Team{ "Alex", 1,1 };
	ctr->reviseFile(0, "revised", p);
	assert(ctr->getFile(0).getReviewer() =="Alex");
	delete p;
}


int main(int argc, char *argv[])
{
	testFunction();
	QApplication a(argc, argv);
	Repository repo{};
	Controller* ctr = new Controller{ repo };
	MyModel* model = new MyModel{ repo };
	Model* model2 = new Model{ repo };
	Statistics* statistics = new Statistics{ model2 };
	statistics->show();
	for (auto i : repo.getTeam())
	{
		Examen *w = new Examen{model, ctr, i, statistics};
		w->show();
	}

	return a.exec();
}
