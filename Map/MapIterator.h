#pragma once
#include "Map.h"
class MapIterator
{
	//DO NOT CHANGE THIS PART
	friend class Map;
private:
	Map& map;
	Map::DLLNode* current_element;

	MapIterator(Map& m);
public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
	TElem remove();
};


