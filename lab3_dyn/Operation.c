#include "Operation.h"
#include "Offer.h"
#include <string.h>

Operation* createOperation(char* name, Offer* of, Offer* of_redo)
{
	Operation* op = (Operation*)malloc(sizeof(Operation));
	op->name = (char*)malloc(sizeof(char) * 10);
	op->offer_undo = of;
	strcpy(op->name, name);
	op->offer_redo = of_redo;
	return op;
}

char* get_name(Operation* op)
{
	return op->name; 
}

Offer* get_offer_undo(Operation* op)
{
	return op->offer_undo;
}

Offer* get_offer_redo(Operation* op)
{
	return op->offer_redo;
}

void destroyOperation(Operation* op)
{
	free(op->name);
	destroyOffer(op->offer_undo);
	destroyOffer(op->offer_redo);
	free(op);
}