#include"Repository.h"
#include <stdlib.h>
#include <string.h>

RepoOffers* createRepo()
{
	RepoOffers* r = (RepoOffers*)malloc(sizeof(RepoOffers));
	r->offers = create(2);
	return r;
}

int getLenght(RepoOffers* r)
{
	return r->offers->size;
}

DynamicArray* getAll(RepoOffers* r)
{
	return r->offers;
}


Offer* search(RepoOffers* r, char* address)
{
	int i;
	for (i = 0; i < r->offers->size; i++)
	{
		Offer* offer = r->offers->elements[i];
		if ( strcmp( address, getAddress(offer)) == 0)
		{
			return offer;
		}
	}
}

void addOffer(RepoOffers* r, Offer* o)
{

	int i;
	for (i = 0; i < r->offers->size; i++)
	{
		Offer* offer = r->offers->elements[i];
		if (strcmp(getAddress(o), getAddress(offer)) == 0)
		{
			printf("The given address already exists!\n");
			return;
		}
	}

	add(r->offers, o);
	printf("The offer has been added!\n");
}


void deleteOffer(RepoOffers* r, Offer* o)
{
	int i;
	for (i = 0; i < r->offers->size; i++)
	{
		Offer* offer = r->offers->elements[i];
		if (strcmp(getAddress(o), getAddress(offer)) == 0)
		{
			removeElem(r->offers, i);
			printf("The offer has been deleted!\n");
			return;
		}
	}
	printf("The given address doesn't exist!\n");
}

void updateOffer(RepoOffers* r, Offer* o)
{
	int i;
	Offer* new;
	for (i = 0; i < r->offers->size; i++)
	{
		new = r->offers->elements[i];
		if (strcmp(getAddress(o), getAddress(new)) == 0)
		{
			/*setPrice(new, getPrice(o));
			setSurface(new, getSurface(o));
			setType(new, getType(o));
			*/
			r->offers->elements[i] = o;
			printf("The offer has been updated!\n");
			return;
		}
	}
	printf("The address doesn't exist! You should add it!\n");
}

void destroyRepo(RepoOffers* r)
{
	int i = 0;
	/*for (i = 0; i < r->offers->size; i++)
		destroyOffer(r->offers->elements[i]);*/
	destroy(r->offers);
	free(r);
}
