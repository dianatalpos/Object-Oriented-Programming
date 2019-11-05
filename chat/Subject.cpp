#include "Subject.h"



void Subject::registerObserver(Observer * obs)
{
	this->elems.push_back(obs);
}

void Subject::unregisterObserver(Observer * obs)
{

}

void Subject::notify()
{
	for (auto x : this->elems)
	{
		x->update();
	}
}

Subject::Subject()
{
}


Subject::~Subject()
{
}
