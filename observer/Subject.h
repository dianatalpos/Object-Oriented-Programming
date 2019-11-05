#pragma once
#include "observer.h"
#include <vector>


class Subject
{
	std::vector<Observer*> elems;

public:
	void registerObserver(Observer* obs);
	void unregisterObserver(Observer* obs);
	void notify();
	Subject();
	~Subject();
};

