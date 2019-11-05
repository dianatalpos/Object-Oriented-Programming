#pragma once

typedef void* TElem;
//typedef (*fct)() functie;
typedef struct
{
	TElem* elements;
	int size;
	int capacity;

}DynamicArray;

/*
Function that creates a dynamical array
in: capacity - the initial capacity of the array
	function - is a function with can destroy the elements from the array;
out: p - dynamical array;
*/
DynamicArray* create(int capacity);

/*
Function that destroyes a dynamical array
in: p - dynamical array
*/
void destroy(DynamicArray*);

/*
Function that adds an element to the array
*/
void add(DynamicArray*, TElem);

/*
Function that returns the element from a position
*/
void* getElem(DynamicArray* p, int position);

/*
Function that removes an element from a position
*/
void removeElem(DynamicArray* p, int position);


int getSize(DynamicArray*);