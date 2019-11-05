#pragma once
#include "Offer.h"

typedef struct
{
	char* name;
	Offer* offer_undo;
	Offer* offer_redo;
}Operation;


Operation* createOperation(char*, Offer*, Offer*);


/*
Get the name of the operation
*/
char* get_name(Operation*);


/*
Get the offer to perform the operation
*/
Offer* get_offer_undo(Operation*);

Offer* get_offer_redo(Operation* op);



void destroyOperation(Operation*);
