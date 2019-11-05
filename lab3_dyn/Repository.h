#pragma once
#include "Offer.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* offers;
}RepoOffers;

DynamicArray* getAll(RepoOffers* r);

int getLenght(RepoOffers* r);

/*
Function that creates a repository
*/
RepoOffers* createRepo();

/*
Function that adds an offer to the repository
*/
void addOffer(RepoOffers*, Offer*);


/*
Function that deletes an offer from the repository
*/
void deleteOffer(RepoOffers*, Offer*);


/*
Function that destroys the repository
*/
void destroyRepo(RepoOffers*);



Offer* search(RepoOffers* r, char* address);


void updateOffer(RepoOffers* r, Offer* o);