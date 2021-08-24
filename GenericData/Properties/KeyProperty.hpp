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

};

template <class T>
class ImmutableKeyProperty : public ImmutableProperty<T>, 
							 public _key_property_base_class::_Key_Base_<T> {

};

template <class T>
class ConstantKeyProperty : public ConstantProperty<T>, 
							public _key_property_base_class::_Key_Base_<T> {

};

