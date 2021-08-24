// GenericData.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <variant>
#include <string>

// A "Property" does 3 things:
// 1. Provide a <name, val> pair
// 2. Provide an interface to where an std::variant acts as its type
// 3. Provide a base class for a collection of different types of Properties <- ?
//
// These should be used in place of basic types for any aspect of the system
// that can be described as "exposed state".
// "exposed state" - A piece of data that can be changed by something outside
//					 of the subset the data was defined in.
// By using properties you open your system up to a generic key/value system
// using generic - yet powerful and strongly typed concepts.
template <class T>
class Property {
public:
	// todo: ... make others inherit these from Property
	Property() noexcept = default;
	Property(std::string name) : m_name(std::forward<std::string>(name)) {}
	Property(T t) noexcept {
		m_dataType = std::move(t);
	}
	Property(std::string name, T t) : m_name(std::forward<std::string>(name)) {
		m_dataType = std::move(t);
	}
	Property(T t, std::string name) : m_name(std::forward<std::string>(name)) {
		m_dataType = std::move(t);
	}
	
	virtual ~Property() noexcept = default;

	// By default, these operators are turned off
	// they are turned on in the  version
	Property(const Property& p) = delete;
	Property(Property&& p) = delete;
	T operator=(const T& t) = delete;
	T operator=(T&& t) = delete;
	Property<T> operator=(const Property& p) = delete;
	Property<T> operator=(Property&& p) = delete;

	const T operator()() {
		return this->data();
	}

	bool operator==(const Property& p) {
		return p.m_dataType == m_dataType && p.m_name == m_name;
	}
	bool operator==(const T& t) {
		return t == this->data();
	}

	[[nodiscard]] const std::string& name() const { return m_name; }
	[[nodiscard]] const T data() const { return std::move(std::get<T>(m_dataType)); }

	// I maybe don't like these
	virtual bool isMutable() const = 0;
	virtual bool isChangeable() const = 0;

protected:
	std::variant<T> m_dataType;
	std::string m_name;
};

using StringProperty = Property<std::string>;
using IntProperty = Property<int>;
using DoubleProperty = Property<double>;
using FloatProperty = Property<float>;