#pragma once

template <typename T>

class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);

	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	void operator+(T e);
	
	void remove(T e);

	// Adds an element to the current DynamicVector.
	void add(T e);

	bool equal(T e1, T e2);

	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);

	int getSize() const;

	void set_elem(int i, T e);
private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

template<typename T>
inline DynamicVector<T>::DynamicVector(int capacity)
{

	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template<typename T>
inline DynamicVector<T>::DynamicVector(const DynamicVector & v)
{

	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template<typename T>
inline DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;

}

template<typename T>
inline bool DynamicVector<T>::equal(T e1, T e2)
{
	if (e1.getAge() == e2.getAge() && e1.getBreed() == e2.getBreed() && e1.getName() == e2.getName() && e1.getPhoto() == e2.getPhoto())
		return true;
	return false;
}


template<typename T>
inline void DynamicVector<T>::remove(T e)
{
	int i, j;
	for (size_t i = 0; i < this->size; i++)
	{
		if (equal(this->elems[i], e)) {
			for (j = i; j < this->size - 1; j++)
				this->elems[i] = this->elems[i + 1];
			this->size--;
			return;
		}
	}
}


template<typename T>
inline DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}


template<typename T>

inline void DynamicVector<T>::operator+(T e)
{
	int i, j;
	for (size_t i = 0; i < this->size; i++)
	{
		if (equal(this->elems[i], e)) {
			return;
		}
	}
	this->add(e);
}


template<typename T>
inline void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;

}

template<typename T>
inline T & DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];

}

template<typename T>
inline int DynamicVector<T>::getSize() const
{
	return this->size;

	return 0;
}

template<typename T>
inline void DynamicVector<T>::set_elem(int i, T e)
{

	this->elems[i] = e;
}

template<typename T>
inline void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	elems = els;

}
