#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(Map& d) : map(d)
{
	current_element = map.head;
}
//Theta(1)

void MapIterator::first() {
	current_element = map.head;
}
//Theta(1)


void MapIterator::next() {
	if (this->current_element == NULL)
		throw exception();

	current_element = current_element->next;
}
//Theta(1)


TElem MapIterator::getCurrent(){
	if (this->current_element == NULL)
		throw exception();

	return this->current_element->info;
}
//Theta(1)


bool MapIterator::valid() const {
	if (this->current_element != NULL)
		return true;

	return false;
}
//Theta(1)

TElem MapIterator::remove()
{
	if (this->current_element == NULL)
		throw exception();

	Map::DLLNode* deleted = this->current_element;
	TElem copy_info;

	if (this->current_element == map.head)
	{
		if (this->current_element == map.tail)//if the map has one element
		{
			map.head = NULL;
			map.tail = NULL;
		}
		else // if the element is just the head
		{
			map.head = map.head->next;
			map.head->prev = NULL;
		}
	}
	else if (this->current_element == map.tail)// if the element is the tail
	{
		map.tail = map.tail->prev;
		map.tail->next = NULL;
	}
	else // if the element is neither the tail nor the head
	{
		this->current_element->next->prev = this->current_element->prev;
		this->current_element->prev->next = this->current_element->next;
	}
	this->next();
	deleted->next = NULL;
	deleted->prev = NULL;
	copy_info = deleted->info;
	free(deleted);
	return copy_info;
}
//worst case: Theta(1)
//best case: Theta(1)
//Theta(1)



