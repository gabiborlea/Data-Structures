#include "ShortTest.h"
#include <assert.h>
#include "Map.h"
#include "MapIterator.h"


void testAll() { //call each function to see if it is implemented
	Map m;
	assert(m.isEmpty() == true);
	assert(m.size() == 0); //add elements
	assert(m.add(5,5)==NULL_TVALUE);

	assert(m.add(1,111)==NULL_TVALUE);
	assert(m.add(10,110)==NULL_TVALUE);
	assert(m.add(7,7)==NULL_TVALUE);
	assert(m.add(1,1)==111);
	assert(m.add(10,10)==110);
	assert(m.add(-3,-3)==NULL_TVALUE);
	assert(m.size() == 5);
	assert(m.search(10) == 10);
	assert(m.search(16) == NULL_TVALUE);
	assert(m.remove(1) == 1);
	assert(m.remove(6) == NULL_TVALUE);
	assert(m.size() == 4);


	TElem e;
	MapIterator id = m.iterator();
	id.first();
	int s1 = 0, s2 = 0;

	while (id.valid()) {
		e = id.getCurrent();
		s1 += e.first;
		s2 += e.second;
		id.next();
	}
	assert(s1 == 19);
	assert(s2 == 19);


	Map test;
	assert(test.add(1, 1) == NULL_TVALUE);
	assert(test.add(2, 2) == NULL_TVALUE);
	assert(test.add(3, 3) == NULL_TVALUE);
	assert(test.add(4, 4) == NULL_TVALUE);
	assert(test.add(5, 5) == NULL_TVALUE);
	MapIterator it = test.iterator();

	int sum1 = 0, sum2 = 0;
	TElem current = it.getCurrent();


	it.first();
	while (it.valid()) {
		current = it.getCurrent();
		sum1 += current.first;
		sum2 += current.second;
		it.next();
	}

	assert(sum1 == 15);
	assert(sum2 == 15);


	
	it.first(); //current (1,1)
	it.next(); //current (2,2)
	it.next();//current (3,3)
	current = it.getCurrent();
	assert(it.remove() == current); //(3,3) is deleted
	TElem next_current = it.getCurrent();
	assert(current != next_current);

	sum1 = 0;
	sum2 = 0;
	it.first();
	while (it.valid()) {
		current = it.getCurrent();
		sum1 += current.first;
		sum2 += current.second;
		it.next();
	}

	assert(sum1 == 12);
	assert(sum2 == 12);

}


