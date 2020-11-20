#include "Matrix.h"
#include <exception>
using namespace std;


int Matrix::h(int i, int j) const
{
	return (i+j) % this->m;
}
//Theta(1)

void Matrix::resize()
{
	int old_value = this->m;
	this->m *= 2;
	node** T_aux = new node * [this->m];

	for (int i = 0; i < this->m; i++)
		T_aux[i] = NULL;

	for (int idx = 0; idx < old_value; idx++)
	{
		node * cnode = T[idx];
		while (cnode != NULL)
		{
			int i = cnode->line;
			int j = cnode->col;
			TElem e = cnode->value;

			int position = this->h(i, j);
			node* current_node = T_aux[position];

			node* prev_node = NULL;

			while (current_node != NULL && (current_node->line < i || (current_node->line == i && current_node->col < j)))
			{
				prev_node = current_node;
				current_node = current_node->next;

			}
			if (prev_node == NULL)
			{

				node* next_node = T_aux[position];
				node* new_node = (node*)malloc(sizeof(node));
				new_node->next = next_node;
				new_node->line = i;
				new_node->col = j;
				new_node->value = e;

				T_aux[position] = new_node;
			}
			else
			{
				node* new_node = (node*)malloc(sizeof(node));
				new_node->next = current_node;
				new_node->line = i;
				new_node->col = j;
				new_node->value = e;

				prev_node->next = new_node;

			}
			cnode = cnode->next;
		}
	}
	delete[] this->T;
	this->T = T_aux;

}
//O(m*n) , m-the size of the hash table, the maximum number of elements in a list on a position given by the hash function 

Matrix::Matrix(int nrLines, int nrCols) {
	   
	//TODO - Implementation
	this->number_lines = nrLines;
	this->number_cols = nrCols;
	this->m = 7;
	this->size = 0;
	T = new node* [this->m];
	for (int i = 0; i < this->m; i++)
		T[i] = NULL;
}
//Theta(n)

int Matrix::nrLines() const {
	//TODO - Implementation
	return this->number_lines;
}
//Theta(1)

int Matrix::nrColumns() const {
	//TODO - Implementation
	return this->number_cols;
}
//Theta(1)

TElem Matrix::element(int i, int j) const {
	//TODO - Implementation

	if (i < 0 || i >= this->number_lines)
		throw exception{};

	if (j < 0 || j >= this->number_cols)
		throw exception{};

	int position = this->h(i,j);
	node* current_node = this->T[position];


	while (current_node != NULL && (current_node->line < i || (current_node->line == i && current_node->col < j)))
		current_node = current_node->next;
	

	if (current_node != NULL)
	{
		auto ti = current_node->line;
		auto tj = current_node->col;

		if (current_node->line == i && current_node->col == j)
			return current_node->value;
	}

	return NULL_TELEM;

}
//O(n) n- number of elements in the the list on the position given by the hash function 

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation


	if (i < 0 || i >= this->number_lines)
		throw exception{};

	if (j < 0 || j >= this->number_cols)
		throw exception{};

	float load_factor = (float)this->size / (float)this->m;
	if (load_factor > 0.7)
	{
		this->resize();
	}

	int position = this->h(i, j);
	node* current_node = this->T[position];
	node* prev_node = NULL;
	while (current_node != NULL && (current_node->line < i || (current_node->line == i && current_node->col < j)))
	{
		prev_node = current_node;
		current_node = current_node->next;
		
	}



	if (current_node != NULL)
	{
		if (current_node->line == i && current_node->col == j)
		{
			TElem prev_value = current_node->value;
			current_node->value = e;
			return prev_value;
		}
	}

	if (prev_node == NULL)
	{
		
			node* next_node = this->T[position];
			node* new_node = (node*)malloc(sizeof(node));
			new_node->next = next_node;
			new_node->line = i;
			new_node->col = j;
			new_node->value = e;

			this->T[position] = new_node;
			this->size++;
	}
	else
	{
		node* new_node = (node*)malloc(sizeof(node));
		new_node->next = current_node;
		new_node->line = i;
		new_node->col = j;
		new_node->value = e;

		prev_node->next = new_node;
		this->size++;

	}
	return NULL_TELEM;
}//O(n*m) n- number of elements in the the list on the position given by the hash function 

void Matrix::resize(int newLines, int newCol)
{
	if (newLines < 0 || newCol < 0)
		throw exception{};

	for (int idx = 0; idx < this->m; idx++)
	{
		node* current_node = T[idx];
		node* prev_node = NULL;
		while (current_node != NULL)
		{

			if (current_node->line >= newLines || current_node->col >= newCol)
			{
				if (current_node == T[idx])
				{
					T[idx] = current_node->next;
				}
				else
					prev_node->next = current_node->next;
			}
			prev_node = current_node;
			current_node = current_node->next;
		}
	}
	this->number_lines = newLines;
	this->number_cols = newCol;

}
//theta(m)

