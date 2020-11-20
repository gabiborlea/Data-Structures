#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <stdlib.h>
#include <assert.h>

SortedSet::BSTNode* SortedSet::init_node(TElem e)
{
	BSTNode* new_node = (BSTNode*)malloc(sizeof(BSTNode));
	new_node->info = e;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

SortedSet::SortedSet(Relation r) {
	//TODO - Implementation
	this->root = NULL;
	this->relation = r;
	this->set_size = 0;
}


bool SortedSet::add(TComp elem) {
	//TODO - Implementation
	BSTNode* current_node = this->root;
	BSTNode* parent_node = this->root;

	if (this->root == NULL)
	{
		this->root = this->init_node(elem);	
	}
	else
	{
		while (current_node != NULL)
		{
			if (current_node->info == elem)
				return false;
			else if (this->relation(current_node->info, elem))
			{
				parent_node = current_node;
				current_node = current_node->right;
			}
			else
			{
				parent_node = current_node;
				current_node = current_node->left;
			}
		}
		current_node = this->init_node(elem);
		if (this->relation(parent_node->info, elem))
			parent_node->right = current_node;
		else
			parent_node->left = current_node;
	}

	this->set_size++;
	return true;
}


bool SortedSet::remove(TComp elem) {
	//TODO - Implementation
	BSTNode* current_node = this->root;
	BSTNode* parent_node = this->root;
	bool found = false;
	while (current_node != NULL && !found)
	{
		if (current_node->info == elem)
			found = true;
		else if (this->relation(current_node->info, elem))
		{
			parent_node = current_node;
			current_node = current_node->right;
		}
		else
		{
			parent_node = current_node;
			current_node = current_node->left;
		}
	}

	if (found == false)
		return false;

	//root
	if (current_node == this->root)
	{	
		if (current_node->left == NULL && current_node->right != NULL)
		{
			auto deleted = this->root;
			this->root = this->root->right;
			//free(deleted);
		}
		else if (current_node->left != NULL && current_node->right == NULL)
		{
			auto deleted = this->root;
			this->root = this->root->left;
			//free(deleted);
		}
		else if (current_node->left != NULL && current_node->right != NULL)
		{
			BSTNode* minimum_node = this->root->right;
			BSTNode* parent_minumum = this->root;
			while (minimum_node->left != NULL)
			{
				parent_minumum = minimum_node;
				minimum_node = minimum_node->left;
			}
			this->root->info = minimum_node->info;
			if (parent_minumum == this->root)
				this->root->right = NULL;
			else
				parent_minumum->left = NULL;
			//free(minimum_node);
		}
		else
		{
			this->root = NULL;
		}
	}
	else //not root
	{
		if (current_node->left == NULL && current_node->right == NULL)
		{
			if (parent_node->right == current_node)
				parent_node->right = NULL;
			else
				parent_node->left = NULL;
			//free(current_node);
		}
		else if (current_node->left == NULL && current_node->right != NULL)
		{
			parent_node->right = current_node->right;
			//free(current_node);
		}
		else if (current_node->left != NULL && current_node->right == NULL)
		{
			parent_node->left = current_node->left;
			//free(current_node);
		}
		else
		{
			BSTNode* minimum_node = current_node->right;
			BSTNode* parent_minumum = current_node;
			while (minimum_node->left != NULL)
			{
				parent_minumum = minimum_node;
				minimum_node = minimum_node->left;
			}
			current_node->info = minimum_node->info;
			parent_minumum->left = NULL;
			if (parent_minumum == current_node)
				current_node->right = NULL;
			else
				parent_minumum->left = NULL;
			//free(minimum_node);
		}
	}
	this->set_size--;
	return true;
	
}

bool SortedSet::search(TElem elem) const{
	//TODO - Implementation
	BSTNode* current_node = this->root;
	while (current_node != NULL)
	{
		if (current_node->info == elem)
			return true;
		else if (this->relation(current_node->info, elem))
			current_node = current_node->right;
		else
			current_node = current_node->left;

	}
	return false;
}


int SortedSet::size() const {
	//TODO - Implementation
	return this->set_size;
}



bool SortedSet::isEmpty() const {
	//TODO - Implementation
	if (this->set_size == 0)
		return true;
	return false;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	//TODO - Implementation
}


