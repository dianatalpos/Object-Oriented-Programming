#include "Subject.h"



void Subject::registerObserver(Observer * obs)
{
	this->elems.push_back(obs);
}

void Subject::unregisterObserver(Observer * obs)
{
	for (int i = 0; i < this->elems.size(); i++)
	{
		if (this->elems.at(i) == obs)
		{
			this->elems.erase(this->elems.begin() + i);
			return;
		}
	}
}

void Subject::notify()
{
	for (auto s : this->elems)
	{
		s->update();
	}
}

Subject::Subject()
{

}


Subject::~Subject()
{
}
