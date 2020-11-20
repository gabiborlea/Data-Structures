#include <assert.h>
#include "Matrix.h"
#include <iostream>
using namespace std;

void testAll() { 

	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);

	Matrix test(5, 5);
	test.modify(4, 4, 1);
	test.modify(4, 3, 1);
	test.modify(1, 2, 4);
	assert(test.element(4, 4) == 1);
	assert(test.element(4, 3) == 1);
	assert(test.element(1, 2) == 4);
	test.resize(3, 3);
	/*
	assert(test.element(4, 4) == NULL_TELEM);
	assert(test.element(4, 3) == NULL_TELEM);
	assert(test.element(1, 2) == 4);
	*/

	try
	{
		test.element(4, 4);
		assert(false);
	}
	catch (exception& e)
	{
		assert(true);
	}
	test.resize(8, 8);
	assert(test.element(7, 7) == NULL_TELEM);

}