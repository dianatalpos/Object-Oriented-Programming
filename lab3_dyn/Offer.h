#pragma once


typedef struct
{
	char* type;
	char* address;
	double surface;
	double price;

}Offer;



char* toString(Offer* o);

/*
Function that creates an offer
in: offerType - char which represents the type of the house that is in the offer
	offerAddress - char which represents the address of the house that is in the offer
	offerSurface - double which represents the surface of the house that isin the offer
	offerPrice - whici represents the price of the house that is in the offer

out: p which is an Offer
*/
Offer* createOffer(char* offerType, char* offerAddress, double offerSurface, double offerPrice);


/*
Function that returns the address from an Offer
*/
char* getAddress(Offer*);


/*
Function that sets the type for the offer
*/
void setType(Offer*, char*);

char* getType(Offer* o);


/*
Function that sets the price for an offer
*/
void setPrice(Offer* o, double price);

double getPrice(Offer*);


/*
Function that sets the surface for an offer
*/
void setSurface(Offer*, double surface);

double getSurface(Offer*);


/*
Function that destroyes an Offer */
void destroyOffer(Offer*);