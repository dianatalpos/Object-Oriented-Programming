#include "Equation.h"



Equation::Equation()
{
	a = 0;
	b = 0;
	c = 0;
}


Equation::Equation(double _a, double _b, double _c)
{
	this->a = _a;
	this->b = _b;
	this->c = _c;
}

Equation::~Equation()
{
}
