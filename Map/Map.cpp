#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	//TODO - Implementation
	this->head = NULL;
	this->tail = NULL;
}
//Theta(1);

Map::~Map() {
	//TODO - Implementation
	DLLNode* current = this->head;
	while (current != NULL)
	{
		DLLNode* deleted = current;
		current = current->next;
		free(deleted);
	}
}

TValue Map::add(TKey c, TValue v) {
	//TODO - Implementation
	DLLNode* current = this->head;

	while (current != NULL && current->info.first != c)
	{
		current = current->next;
	}
	if (current != NULL)
	{
		TValue old_value = current->info.second;
		current->info.second = v;
		return old_value;
	}
	else
	{
		TElem pair = std::make_pair(c, v);
		DLLNode* new_node = (DLLNode*)malloc(sizeof(DLLNode));

		new_node->info = pair;
		new_node->next = NULL;
		new_node->prev = this->tail;
		
		if (this->head == NULL) //if map is empty
		{
			this->head = new_node;
			this->tail = new_node;
		}
		else
		{
			this->tail->next = new_node;
			this->tail = new_node;
		}

		return NULL_TVALUE;
	}
}
//Theta(1)

TValue Map::search(TKey c) const{
	//TODO - Implementation
	DLLNode* current = this->head;
	while (current != NULL && current->info.first != c)
	{
		current = current->next;
	}
	if (current != NULL)
		return current->info.second;
	return NULL_TVALUE;
}
//O(n) - n size dll


TValue Map::remove(TKey c){
	DLLNode* current = this->head;
	while (current != NULL && current->info.first != c)
	{
		current = current->next;
	}
	DLLNode* deleted = current;

	if (current != NULL)
	{
		if (current == this->head)
		{
			if (current == this->tail)
			{
				this->head = NULL;
				this->tail = NULL;
			}
			else
			{
				this->head = this->head->next;
				this->head->prev = NULL;
			}
		}
		else if (current == this->tail)
		{
			this->tail = this->tail->prev;
			this->tail->next = NULL;
		}
		else
		{
			current->next->prev = current->prev;
			current->prev->next = current->next;
		}
		deleted->next = NULL;
		deleted->prev = NULL;
		
		TValue deleted_value = deleted->info.second;
		free(deleted);
		return deleted_value;
	}

	return NULL_TVALUE;
}
//O(n) - n size of the dll

int Map::size() const {
	DLLNode* current = this->head;
	int size = 0;
	while (current != NULL)
	{
		current = current->next;
		size++;
	}
	return size;
}
//Theta(n) - n size of the dll

bool Map::isEmpty() const{
	if (this->head == NULL)
		return true;
	return false;
}

MapIterator Map::iterator() {
	return MapIterator(*this);
}



