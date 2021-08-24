#include "Property.hpp"

// An Immutable Property is an implementation of a "Property"
// in which carries immutability.
//
// This cancels out the ability to directly assign and instead
// requires "swaps" and "exchanges"
template <class T>
class ImmutableProperty : public Property<T> {
	bool isMutable() const override   { return false; }
	bool isChangable() const override { return true; }
};