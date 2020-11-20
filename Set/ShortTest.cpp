#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

void testAll() { 
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0); 
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);


	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}

	assert(sum == 19);

	Set s1;
	Set s2;
	s1.add(1);
	s1.add(2);
	s1.add(3);
	s1.add(4);

	s2.add(2);
	s2.add(4);
	s1.intersection(s2);

	SetIterator it1 = s1.iterator();
	it1.first();
	int sum1 = 0;
	while (it1.valid()) {

		TElem e1 = it1.getCurrent();
		sum1 += e1;
		it1.next();
	}

	assert(sum1 == 6);

}

