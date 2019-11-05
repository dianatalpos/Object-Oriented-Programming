#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
#include"Car.h"
#include "Engine.h"
#include <vector>

using namespace std;

class Controller
{
private:
	std::vector<Car> elems;
	Engine* createEngine(string engineType, string fuelType, int autonomy, double price);
public:
	Controller();
	~Controller();
	void addCar(string bodyStyle, string engineType, string fuelType, int autonomy);
};