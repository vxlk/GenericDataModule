// GenericData.cpp : Defines the entry point for the application.
//

#include "MutableProperty.hpp"
#include "PropertyContainer.hpp"
#include <assert.h>

using namespace std;

int main()
{	
	struct EZ {};
	// assignment from T
	MutableProperty<int> i = 0;
	assert(i == 0);
	
	// initialization lists
	MutableProperty<int> d = { "name", i.data() };
	MutableProperty<int> r = { i.data(), "name" };


	// assignment to T
	int j = i.data();
	assert(j == i.data());

	// string only ctor
	auto t = MutableProperty<int>("gets assigned a number later, also copied");
	
	// assignment after string only ctor
	t = 1;
	assert(t == 1);

	// ctor tests
	auto raw_ctor = MutableProperty<int>(100);
	auto raw_ctor_with_name = MutableProperty<int>("name and value", 100);
	
	// copy test
	auto copy = t;
	assert(copy == t);

	// operator() as get() test
	auto opParenth = copy();
	assert(opParenth == copy.data());

	return 0;
}
