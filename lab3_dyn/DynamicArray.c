#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray* create(int capacity)
{
	DynamicArray* p = (DynamicArray*)malloc(sizeof(DynamicArray));
	p->size = 0;
	p->capacity = capacity;
	p->elements = (TElem*)malloc(capacity * sizeof(TElem));
	return p;
}

void destroy(DynamicArray* p)

{
	int i = 0;
	free(p->elements);
	p->elements = NULL;
	free(p);
}



void add(DynamicArray* p, TElem* e)
{
	if (p->size == p->capacity)
	{
		p->capacity = 2 * p->capacity;
		p->elements = (TElem*)realloc(p->elements, p->capacity*sizeof(TElem));
	}

	p->elements[p->size] = e;
	p->size += 1;
}

void removeElem(DynamicArray* p, int position)
{
	int i;
	for (i = position; i < p->size - 1; i++)
		p->elements[i] = p->elements[i + 1];
	p->size -= 1;
}

void* getElem(DynamicArray* p, int position)
{
	return p->elements[position];
}

int getSize(DynamicArray* p)
{
	return p->size;
}