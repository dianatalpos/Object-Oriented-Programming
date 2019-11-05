#pragma once
#include "Controller.h"

typedef struct
{
	ControllerOffers* ctr;
}Ui;

/*
Function that creates an ui
*/
Ui* createUi(ControllerOffers* ctr);



/*
Function which runs the aplication
*/
void run(Ui*);

void destroyUi(Ui*);
