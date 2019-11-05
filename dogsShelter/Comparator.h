#pragma once
#include "Dog.h"

template <typename T>
class Comparator
{
public:
	virtual bool compare(T& e1, T& e2) = 0;
	~Comparator() {};
};

class ComparatorAscendingName : public Comparator<Dog>
{
	bool compare(Dog& d1, Dog& d2) override { return d1.getName() < d2.getName(); }
	//~ComparatorAscendingName() {};
};

class ComparatorAscendingAge : public Comparator<Dog>
{
	bool compare(Dog& d1, Dog& d2) override { return d1.getAge() < d2.getAge(); }
};
