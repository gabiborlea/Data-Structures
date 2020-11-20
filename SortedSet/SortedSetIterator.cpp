#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//TODO - Implementation
	this->s = {};
	this->first();
}


void SortedSetIterator::first() {
	//TODO - Implementation
	SortedSet::BSTNode* node = this->multime.root;
	this->s = {};
	while (node != NULL)
	{
		this->s.push(node);
		node = node->left;
	}
	if (!this->s.empty())
	{
		this->current_node = s.top();
	}
	else
		this->current_node = NULL;

}


void SortedSetIterator::next() {
	//TODO - Implementation
	if (this->current_node == NULL)
		throw exception{};
	SortedSet::BSTNode* node = this->s.top();
	s.pop();
	if (node->right != NULL)
	{
		node = node->right;
		while (node != NULL)
		{
			this->s.push(node);
			node = node->left;
		}
	}
	if (!this->s.empty())
	{
		this->current_node = s.top();
	}
	else
		this->current_node = NULL;
}


TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
	if (this->current_node == NULL)
		throw exception{};

	return this->current_node->info;
}

bool SortedSetIterator::valid() const {
	//TODO - Implementation
	if (this->current_node == NULL)
		return false;
	else
		return true;
}

