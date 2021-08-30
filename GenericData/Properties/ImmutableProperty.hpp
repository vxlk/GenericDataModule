#include "Property.hpp"

// An Immutable Property is an implementation of a "Property"
// in which carries immutability.
//
// This cancels out the ability to directly assign and instead
// requires "swaps" and "exchanges"
template <class T>
class ImmutableProperty : public Property<T> {
	static constexpr auto key = "Immutable Property";
	virtual [[nodiscard]] std::string typeName() const noexcept override { return ImmutableProperty::key; }
	bool isMutable() const override   { return false; }
	bool isChangable() const override { return true; }
};