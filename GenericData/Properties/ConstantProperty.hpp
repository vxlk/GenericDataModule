#include "Property.hpp"

// A constant Property is an immutable property that
// never changes through the life of the program
template <class T>
class ConstantProperty : public Property<T> {
	bool isMutable() const override   { return false; }
	bool isChangeable() const override { return false; }
};