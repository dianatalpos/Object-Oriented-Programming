#include "Controller.h"

Engine * Controller::createEngine(string engineType, string fuelType, int autonomy, double price)
{
	Engine* e;
	if (engineType == "electric")
	{
		e = new ElectricEngine{ fuelType, price, autonomy };
	}
	else
		e = new TurboEngine{ fuelType, price };
	return e;

}

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::addCar(string bodyStyle, string engineType, string fuelType, int autonomy)
{
	double price;
	if (bodyStyle == "Sedan")
		price = 8000;
	else
		price = 9000;
	Engine* e;
	e = this->createEngine(engineType, fuelType, autonomy, price);
	Car c1{ bodyStyle, e };
	this->elems.push_back(c1);
}
