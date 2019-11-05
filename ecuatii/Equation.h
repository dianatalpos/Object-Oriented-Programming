#pragma once
class Equation
{
private:

	double a;
	double b;
	double c;

public:
	Equation(double a, double b,double c);
	double getA() { return this->a; }
	double getB() { return this->b; }
	double getC() { return this->c; }
	Equation();
	~Equation();
};

