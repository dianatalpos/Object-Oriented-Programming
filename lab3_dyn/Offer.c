
#include "Offer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Offer* createOffer(char* offerType, char* offerAddress, double offerSurface, double offerPrice)
{
	Offer* o = (Offer*)malloc(sizeof(Offer));
	o->address = (char*)malloc(sizeof(char*) * strlen(offerAddress));
	strcpy(o->address, offerAddress);
	o->type = (char*)malloc(sizeof(char*)*strlen(offerType));
	strcpy(o->type, offerType);
	o->surface = offerSurface;
	o->price = offerPrice;
	return o;
}

char* toString(Offer* o) {
	char *offerToString = (char*)malloc(200 * sizeof(char));
	sprintf(offerToString, "Address: %s type: %s Surface: %lf Price: %lf", o->address, o->type, o->surface, o->price);
	return offerToString;
}



char* getAddress(Offer* o)
{
	return o->address;
}

void setType(Offer* o, char* s)
{
	strcpy(o->type, s);
}

char* getType(Offer* o)
{
	return o->type;
}


void setPrice(Offer* o, double price)
{
	o->price = price;
}

double getPrice(Offer* o)
{
	return o->price;
}


void setSurface(Offer* o, double surface)
{
	o->surface = surface;
}

double getSurface(Offer* o)
{
	return o->surface;
}

void destroyOffer(Offer* o)
{
	free(o->address);
	o->address = NULL;
	free(o->type);
	o->type = NULL;
	free(o);
}