#include "MutableProperty.hpp"
#include "ImmutableProperty.hpp"
#include "ConstantProperty.hpp"

namespace _key_property_base_class {
template <class T>
class _Key_Base_ { 
};
}

template <class T>
class MutableKeyProperty : public MutableProperty<T>, 
						   public _key_property_base_class::_Key_Base_<T> {
	static constexpr auto key = "Mutable Key Property";
	virtual [[nodiscard]] std::string typeName() const noexcept override { return MutableKeyProperty::key; }
};

template <class T>
class ImmutableKeyProperty : public ImmutableProperty<T>, 
							 public _key_property_base_class::_Key_Base_<T> {
	static constexpr auto key = "Immutable Key Property";
	virtual [[nodiscard]] std::string typeName() const noexcept override { return ImmutableKeyProperty::key; }
};

template <class T>
class ConstantKeyProperty : public ConstantProperty<T>, 
							public _key_property_base_class::_Key_Base_<T> {
	static constexpr auto key = "Constant Key Property";
	virtual [[nodiscard]] std::string typeName() const noexcept override { return ConstantKeyProperty::key; }
};

