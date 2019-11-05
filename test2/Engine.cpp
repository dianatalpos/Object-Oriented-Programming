#include "Engine.h"

ElectricEngine::ElectricEngine(string _fuelType, double _basePrice, int _autonomy)
{
	fuelType = _fuelType;
	basePrice = _basePrice;
	autonomy = _autonomy;
}

ElectricEngine::~ElectricEngine()
{

}

double ElectricEngine::getPrice()
{
	return this->basePrice + this->autonomy*0.01;
}

string ElectricEngine::toString()
{
	char buff[50];
	int n;
	n = sprintf(buff, " %f ", this->basePrice);
	std::string stri = "The engine is electric ";
	stri += "the fuel type is: ";
	stri += this->fuelType;
	stri += " the base price is: ";
	stri += buff;
	stri += " the autonomy is: ";
	n = sprintf(buff, "%d", this->autonomy);
	stri += buff;
	stri += "\n";
	return stri;
}

TurboEngine::TurboEngine(string _fuelType, double _basePrice)
{
	fuelType = _fuelType;
	basePrice = _basePrice;
}

TurboEngine::~TurboEngine()
{
}

double TurboEngine::getPrice()
{
	if (this->fuelType == "gasoline")
		return this->basePrice + 0.01 * 100;
	return this->basePrice + 0.01 * 150;
}

string TurboEngine::toString()
{

	char buff[50];
	int n;
	n = sprintf(buff, " %f ", this->basePrice);
	std::string stri = "The engine is turbo ";
	stri += "the fuel type is: ";
	stri += this->fuelType;
	stri += " the base price is: ";
	stri += buff;
	stri += "\n";
	return stri;
}

Engine::Engine()
{
	this->basePrice = 3000;
}

Engine::~Engine()
{
}

double Engine::getPrice()
{
	return this->basePrice;
}
