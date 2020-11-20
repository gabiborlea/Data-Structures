#pragma once
#include "SortedSet.h"
#include <stack>
//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);
	std::stack<SortedSet::BSTNode*> s;
	SortedSet::BSTNode* current_node;
	//TODO - Representation
	

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};

