#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation

	this->current_position = 0;
}//Theta(1)


void SetIterator::first() {
	//TODO - Implementation
	this->current_position = 0;
}//Theta(1)


void SetIterator::next() {
	//TODO - Implementation
	this->current_position++;
}//Theta(1)


TElem SetIterator::getCurrent()
{

	//TODO - Implementation
	if (this->current_position < set.set_size)
		return set.array[this->current_position];
	
	return NULL_TELEM;
}//Theta(1)

bool SetIterator::valid() const {
	//TODO - Implementation
	if (this->current_position >= set.set_size)
		return false;
	return true;
}//Theta(1)



