#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	//TODO - Implementation
	this->current_element = list.head;

}

void ListIterator::first(){
	//TODO - Implementation
	this->current_element = list.head;
}

void ListIterator::next(){
	//TODO - Implementation
	if (this->current_element == -1)
		throw exception();

	this->current_element = this->list.nodes[this->current_element].next;
}

bool ListIterator::valid() const{
	//TODO - Implementation
	if (this->current_element == -1)
		return false;

	return true;
}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
	if (this->current_element == -1)
		throw exception();
	return this->list.nodes[this->current_element].info;
}


