#pragma once
#include "Observer.h"
#include <vector>

class Subject
{

private:
	std::vector<Observer*> elems;

public:
	void registerObserver(Observer* obs);
	void unregisterObserver(Observer* obs);
	void notify();
	Subject();
	~Subject();
};

