#include "Set.h"
#include "SetITerator.h"

Set::Set() {
	//TODO - Implementation
	this->capacity = CAPACITY;
	this->set_size = 0;
	this->array = new TElem[this->capacity];
	
}//Theta(1)

void Set::resize()
{
	if (this->array == nullptr)
		return;
	this->capacity *= 2;

	TElem* aux_array = new TElem[this->capacity];

	if (aux_array == nullptr)
		return;

	for (int i = 0; i < this->set_size; i++)
		aux_array[i] = this->array[i];

	delete[] this->array;
	this->array = aux_array;
}//Theta(

bool Set::add(TElem elem) {
	//TODO - Implementation

	if (this->array == nullptr)
		return false;

	if (this->search(elem) == true)
		return false;

	if (this->capacity == this->set_size)
		resize();

	this->array[this->set_size++] = elem;

	return true;
}//O(n); n= set_size


bool Set::remove(TElem elem) {
	//TODO - Implementation
	if (this->array == nullptr)
		return false;

	int pos = -1;
	int i = 0;
	while (pos == -1 && i < this->set_size)
	{
		if (this->array[i] == elem)
			pos = i;
		i++;
	}

	if (pos == -1)
		return false;

	this->set_size--;
	for (int i = pos; i < this->set_size; i++)
		this->array[i] = this->array[i + 1];

	//delete[] & array[this->set_size];
	return true;
}//theta(n); n= set_size

bool Set::search(TElem elem) const {
	//TODO - Implementation
	if (this->array == nullptr)
		return false;
	
	int pos = -1;
	int i = 0;
	while (pos == -1 && i < this->set_size)
	{
		if (this->array[i] == elem)
			pos = i;
		i++;
	}
	if (pos == -1)
		return false;

	return true;
}//O(n); n= set_size


int Set::size() const {
	//TODO - Implementation
	if (this->array == nullptr)
		return 0;

	return this->set_size;
}
//Theta(1)

bool Set::isEmpty() const {
	//TODO - Implementation
	if (this->array == nullptr)
		return false;

	if (this->set_size == 0)
		return true;

	return false;
}//Theta(1)



Set::~Set() {
	//TODO - Implementation
	delete[] this->array;
}//Theta(1)


SetIterator Set::iterator() const {
	return SetIterator(*this);
}

void Set::intersection(const Set& s)
{
	for (int i = 0; i < this->set_size; i++)
	{
		if (s.search(this->array[i]) == false)
			this->remove(this->array[i]);
	}
}//best case = theta(n^2) - n = set_size
//worst case = theta(n^2) - n = set_size
//total complexity = O(n^3) - n = set_size


