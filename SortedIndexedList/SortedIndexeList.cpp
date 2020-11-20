#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <exception>
using namespace std;


int SortedIndexedList::allocte()
{
	int new_element = this->first_empty;
	if (new_element != -1)
	{
		this->first_empty = this->nodes[first_empty].next;
		if (this->first_empty != -1)
			this->nodes[this->first_empty].prev = -1;

		this->nodes[new_element].next = -1;
		this->nodes[new_element].prev = -1;
	}
	return new_element;
}

void SortedIndexedList::free(int position)
{
	this->nodes[position].next = this->first_empty;
	this->nodes[position].prev = -1;

	if (this->first_empty != -1)
		this->nodes[first_empty].prev = position;

	this->first_empty = position;
}


void SortedIndexedList::resize()
{
	this->capacity *= 2;
	DLLANode* aux_nodes = new DLLANode[this->capacity];


	for (int i = this->lsize + 1; i < this->capacity; i++)
	{
		aux_nodes[i].next = i + 1;
		aux_nodes[i].prev = i - 1;
	}
	aux_nodes[1].next = 2;
	aux_nodes[1].prev = -1;
	aux_nodes[this->capacity].next = -1;
	aux_nodes[this->capacity].prev = this->capacity - 1;


	for (int i = 0; i < this->capacity; i++)
		aux_nodes[i] = this->nodes[i];

	delete[] this->nodes;
	this->nodes = aux_nodes;
	this->first_empty = this->lsize + 1;
}

SortedIndexedList::SortedIndexedList(Relation r) {
	//TODO - Implementation
	this->capacity = 10;
	this->nodes = new DLLANode[this->capacity];
	this->head = -1;
	this->tail = -1;
	this->lsize = 0;
	this->relation = r;

	for (int i = 1; i < this->capacity; i++)
	{
		this->nodes[i].next = i + 1;
		this->nodes[i].prev = i - 1;
	}
	this->nodes[0].next = 1;
	this->nodes[0].prev = -1;
	this->nodes[this->capacity].next = -1;
	this->nodes[this->capacity].prev = this->capacity - 1;
	this->first_empty = 0;
}

int SortedIndexedList::size() const {
	//TODO - Implementation
	return this->lsize;
}

bool SortedIndexedList::isEmpty() const {
	//TODO - Implementation

	if (this->lsize)
		return false;

	return true;
}

TComp SortedIndexedList::getElement(int i) const{
	//TODO - Implementation

	if (i < 0 && i >= this->lsize)
		return NULL_TCOMP;

	int current = head;
	while (current != i && current != -1)
	{
		current = this->nodes[current].next;
	}
	if (current == -1)
		return NULL_TCOMP;
	return this->nodes[current].info;
}

TComp SortedIndexedList::remove(int i) {
	//TODO - Implementation
	if ( i < 0 && i >= this->lsize)
		return NULL_TCOMP;

	int current = head;
	while (current != i && current != -1)
	{
		current = this->nodes[current].next;
	}

	if (current == -1)
		return NULL_TCOMP;

	this->nodes[current - 1].next = this->nodes[current].next;
	this->nodes[current + 1].prev = this->nodes[current].prev;
	auto number = this->nodes[current].info;
	this->free(current);
	this->lsize--;
	return number;

}

int SortedIndexedList::search(TComp e) const {
	//TODO - Implementation
	int current = head;
	while (this->nodes[current].info != e && current != -1)
	{
		current = this->nodes[current].next;
	}
	return current;
}

void SortedIndexedList::add(TComp e) {
	//TODO - Implementation

	this->lsize++;
	int current = head;

	int position = 0;
	int node_previous = -1;
	while (this->relation(this->nodes[current].info, e) && current != -1)
	{
		node_previous = current;
		current = this->nodes[current].next;
		position++;
	}


	int new_element = this->allocte();
	if (new_element == -1)
	{
		this->resize();
		new_element = this->allocte();
	}
	this->nodes[new_element].info = e;


	if (position == 0)
	{
		if (this->head == -1)
		{
			this->head = new_element;
			this->tail = new_element;
		}
		else
		{
			this->nodes[new_element].next = this->head;
			this->nodes[this->head].prev = new_element;
			this->head = new_element;
		}
	}
	else
	{

		if (node_previous != -1)
		{
			int node_next = this->nodes[node_previous].next;
			this->nodes[new_element].next = node_next;
			this->nodes[new_element].prev = node_previous;
			this->nodes[node_previous].next = new_element;

			if (node_next == -1)
				this->tail = new_element;
			else
				this->nodes[node_next].prev = new_element;
		}
	}



}

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	//TODO - Implementation
}
