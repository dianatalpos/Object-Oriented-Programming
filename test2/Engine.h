#pragma once
#include <string>
#include <iostream>

using namespace std;

class Engine
{
protected:
	string fuelType;
	double basePrice;
public:
	Engine();
	Engine(string _fuelType, double basePrice): fuelType{_fuelType}, basePrice{basePrice} {}
	~Engine();
	virtual double getPrice();
	virtual string toString() = 0;
};

class ElectricEngine : public Engine
{
private:
	int autonomy;
public:
	ElectricEngine(string _fuelType, double _basePrice, int _autonomy);
	~ElectricEngine();
	double getPrice() override;
	string toString() override;
};


class TurboEngine : public Engine
{
public:
	TurboEngine(string _fuelType, double _basePrice);
	~TurboEngine();
	double getPrice() override;
	string toString() override;
};