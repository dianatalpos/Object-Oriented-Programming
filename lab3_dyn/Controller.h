#pragma once
#include "Repository.h"


typedef struct
{
	RepoOffers* repo;
	DynamicArray* undo;
	int index;
}ControllerOffers;

void perform_redo(ControllerOffers* c);


/*
Function that creates a controller for a repository
*/
ControllerOffers* createController(RepoOffers* repository);

/*
Function that prints all the offers in an asceding order that partial matches with a given string
if the string is empty all offers are printed
*/
void asc_string(ControllerOffers*, char*);


/*
Function that prints all the offers that has a given type and the surface greater than a given surface
*/
void type_surface(ControllerOffers*, char*, double, int order);



void asc_price(ControllerOffers* , double);

/*
Function that prints all the offers that has a given surface in an asceding order
*/
void asc_surface(ControllerOffers* , double);

/*
Funcion that destroys a controller
*/
void destroyController(ControllerOffers*);

/*
Function that adds an offer 
*/
void addCtr(ControllerOffers*, char* address, char* type, double surface, double price);


void perform_undo(ControllerOffers* c);



void updateCtr(ControllerOffers* c, char* address, char*type, double surface, double price);



void removeCtr(ControllerOffers* c, char* address);