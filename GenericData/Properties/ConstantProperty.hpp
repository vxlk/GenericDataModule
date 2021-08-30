#include "Property.hpp"

// A constant Property is an immutable property that
// never changes through the life of the program
template <class T>
class ConstantProperty : public Property<T> {
	virtual ~ConstantProperty() = default;
	static constexpr auto key = "Constant Property";
	virtual [[nodiscard]] std::string typeName() const noexcept override { return ConstantProperty::key; }
	bool isMutable() const override   { return false; }
	bool isChangeable() const override { return false; }
};