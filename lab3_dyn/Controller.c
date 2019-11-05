#include "Controller.h"
#include "Operation.h"
#include <stdlib.h>
#include <string.h>

ControllerOffers* createController(RepoOffers* repository)
{
	ControllerOffers* c = (ControllerOffers*)malloc(sizeof(ControllerOffers));
	c->repo = repository;
	c->undo = create(2);
	c->index = 0;
	return c;
}

void addCtr(ControllerOffers* c, char* type, char* address, double surface, double price)
{
	Offer* o = createOffer(type, address, surface, price);
	//Offer* o_undo = createOffer(type, address, surface, price);
	Offer* o_redo = createOffer(type, address, surface, price);
	addOffer(c->repo, o);
	Operation* operation;
	char* name = (char*)malloc(sizeof(char) * 10);
	strcpy(name, "add");
	operation = createOperation(name, o, o_redo);
	add(c->undo, operation);
	c->index += 1;
	free(name);
}

void updateCtr(ControllerOffers* c, char* type, char* address, double surface, double price)
{
	Offer* o = createOffer(type, address, surface, price);
	Offer* o_1 = search(c->repo, address);
	Offer* o_undo = createOffer(o_1->type, address, o_1->surface, o_1->price);
	//Offer* o_redo = createOffer(type, address, surface, price);
	updateOffer(c->repo, o);
	//destroyOffer(o);
	Operation* operation;
	char* name = (char*)malloc(sizeof(char) * 10);
	strcpy(name, "update");
	operation = createOperation(name, o_undo, o);
	add(c->undo, operation);
	c->index += 1;
	free(name);
}

void removeCtr(ControllerOffers* c, char* address)
{
	Offer* o = search(c->repo, address);
	//Offer* o_undo = search(c->repo, address);
	Offer* o_redo = search(c->repo, address);
	deleteOffer(c->repo, o);
	Operation* operation;
	char* name = (char*)malloc(sizeof(char) * 10);
	strcpy(name, "remove");
	operation = createOperation(name, o, o_redo);
	add(c->undo, operation);
	c->index += 1;
	free(name);
}


void perform_undo(ControllerOffers* c)
{
	if (c->index == 0)
	{
		printf("You can't perform any undo!\n");
		return;
	}
	char* name;
	Offer* o;
	//o = c->undo->elements[c->index-1]->offer_undo;
	name = get_name(getElem(c->undo, c->index-1));
	Offer* offer;
	offer = get_offer_undo(getElem(c->undo, c->index-1 ));
	if (strcmp(name, "add") == NULL)
	{
		deleteOffer(c->repo, offer);
	}
	else
		if (strcmp(name, "update") == NULL)
		{
			updateOffer(c->repo, offer);
		}
		else
			addOffer(c->repo, offer);
		
	c->index -= 1;

}

void perform_redo(ControllerOffers* c)
{
	if (c->index == c->undo->size)
	{
		printf("You can't perform any redo!\n");
		return;
	}
	char* name;
	Offer* o;
	//o = c->undo->elements[c->index-1]->offer_undo;
	name = get_name(getElem(c->undo, c->index));
	Offer* offer;
	offer = get_offer_redo(getElem(c->undo, c->index));
	if (strcmp(name, "remove") == NULL)
	{
		deleteOffer(c->repo, offer);
	}
	else
		if (strcmp(name, "update") == NULL)
		{
			updateOffer(c->repo, offer);
		}
		else
			addOffer(c->repo, offer);

	c->index += 1;

}



void  sort_asc(Offer* o[100], int dim)
{
	int i, j;
	for (i = 0; i < dim - 1; i++)
		for (j = i + 1; j < dim; j++)
			if (o[i]->price > o[j]->price)
			{
				Offer* aux = NULL;
				aux = o[i];
				o[i] = o[j];
				o[j] = aux;
			}

}

void  sort_asc_address(Offer* o[100], int dim)
{
	int i, j;
	for (i = 0; i < dim - 1; i++)
		for (j = i + 1; j < dim; j++)
			if (strcmp(o[i]->address, o[j]->address) < 0)
			{
				Offer* aux = NULL;
				aux = o[i];
				o[i] = o[j];
				o[j] = aux;
			}

}


void  sort_desc(Offer* o[100], int dim)
{
	int i, j;
	for (i = 0; i < dim - 1; i++)
		for (j = i + 1; j < dim; j++)
			if (o[i]->price < o[j]->price)
			{
				Offer* aux = NULL;
				aux = o[i];
				o[i] = o[j];
				o[j] = aux;
			}

}

void asc_string(ControllerOffers* c, char* s)
{
	Offer* o[100];
	int dim = 0;

	if (s[0] != '\n')
	//if (!(strcmp(s, "/n") == 0))
	{
		int lenght = getLenght(c->repo);
		int i = 0;
		char* address;
		s[strlen(s) - 1] = NULL;
		for (i = 0; i < lenght; i++)
		{
			address = getAddress(c->repo->offers->elements[i]);
			if (strstr(address, s) != NULL)
			{
				o[dim++] = c->repo->offers->elements[i];
			}
		}
		address = NULL;
	}
	else
	{
		int lenght = getLenght(c->repo);
		int i = 0;
		for (i = 0; i < lenght; i++)
		{
			o[dim++] = c->repo->offers->elements[i];
		}
	}
	int i, j;
	sort_asc(o, dim);
	for (i = 0; i < dim; i++)
	{
		char* p;
		p = toString(o[i]);
		printf("%s\n", p);
		free(p);
		
	}
}


void asc_price(ControllerOffers* c, double price)
{
	Offer* o[100];
	int dim = 0;

	int lenght = getLenght(c->repo);
	int i = 0;
	double pric;

	for (i = 0; i < lenght; i++)
	{
		pric = getPrice(c->repo->offers->elements[i]);
		if (pric == price)
		{
			o[dim++] = c->repo->offers->elements[i];
		}
	}
 
	sort_asc_address(o, dim);
	for (i = 0; i < dim; i++)
	{
		char* p;
		p = toString(o[i]);
		printf("%s\n", p);
		free(p);

	}
}

void asc_surface(ControllerOffers* c, double surface)
{

	Offer* o[100];
	int dim = 0;

	int lenght = getLenght(c->repo);		
	int i = 0;
	double surf;
		
	for (i = 0; i < lenght; i++)
	{
		surf = getSurface(c->repo->offers->elements[i]);
		if (surf == surface)
		{
			o[dim++] = c->repo->offers->elements[i];
		}
	}

	sort_asc(o, dim);
	for (i = 0; i < dim; i++)
	{
		char* p;
		p = toString(o[i]);
		printf("%s\n", p);
		free(p);

	}
}



void type_surface(ControllerOffers* c, char* type, double surface, int order)
{

	Offer* o[100];
	int dim = 0;

	int lenght = getLenght(c->repo);
	int i = 0;
	double surf;
	char* typ;

	for (i = 0; i < lenght; i++)
	{
		typ = getType(c->repo->offers->elements[i]);
		surf = getSurface(c->repo->offers->elements[i]);
		if (surf >= surface && strcmp(typ, type) == NULL)
		{
			o[dim++] = c->repo->offers->elements[i];
		}
	}
	if (order == 1)
		sort_asc(o, dim);
	else
		sort_desc(o, dim);
	
	for (i = 0; i < dim; i++)
	{
		char* p;
		p = toString(o[i]);
		printf("%s\n", p);
		free(p);

	}
}

void destroyController(ControllerOffers* c)
{
	destroyRepo(c->repo);
	int i;
	for(i = 0; i < c->undo->size; i++)
		destroyOperation(c->undo->elements[i]);
	destroy(c->undo);
	free(c);
}