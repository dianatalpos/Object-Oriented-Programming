#pragma once
#include <string>
#include "Engine.h"

using namespace std;

class Car
{
private:
	std::string bodyStyle;
	Engine* engine;

public:
	Car(std::string _bodyStyle, Engine* e): bodyStyle{_bodyStyle}, engine{e} {}
	double computePrice();
};