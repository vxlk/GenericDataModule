// GenericData.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "Property.hpp"

template <class IncomingProperty>
auto property_cast(IProperty* incomingProperty) {
	static_assert(is_property_descendant<IncomingProperty, Property>::value);
	static_assert(has_property_key<IncomingProperty>::value);
	static_assert(incomingProperty->key == IncomingProperty::key);
	return dynamic_cast<IncomingProperty*>(incomingProperty);
}