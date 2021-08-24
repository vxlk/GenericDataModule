#include "Property.hpp"

// A mutable property is subject to referential changes
// Not thread safe
template <class T>
class MutableProperty : public Property<T> {
public:
	// todo: ... make others inherit these from Property
	MutableProperty() noexcept = default;
	MutableProperty(std::string name) {
		m_name = move(name);
	}
	MutableProperty(T t) noexcept {
		m_dataType = std::move(t);
	}
	MutableProperty(std::string name, T t) {
		m_name = move(name);
		m_dataType = std::move(t);
	}
	MutableProperty(T t, std::string name) {
		m_name = move(name);
		m_dataType = std::move(t);
	}

	~MutableProperty() noexcept = default;

	MutableProperty(const MutableProperty& p) {
		// this is always safe even if the incoming p is const,
		// we only ever exchange and never directly mutate the object
		m_dataType.swap(const_cast<std::variant<T>&>(p.m_dataType));
		m_name = p.m_name;
	}
	MutableProperty(MutableProperty&& p) {
		m_dataType.swap(std::move(p.m_dataType));
		m_name = std::move(p.m_name);
	}

	T operator=(const T& t) {
		if (t == this->data())
			return t;
		m_dataType = t;
		return std::move(this->data());
	}
	T operator=(T&& t) {
		if (t == this->data())
			return t;
		m_dataType = std::move(t);
		return std::move(this->data());
	}

	MutableProperty<T> operator=(const MutableProperty& p) {
		if (p == *this)
			return *this;
		m_dataType.swap(p.m_dataType);
		m_name = p.m_name;
		return *this;
	}
	MutableProperty<T> operator=(MutableProperty&& p) {
		if (p == *this)
			return *this;
		m_dataType.swap(std::move(p.m_dataType));
		m_name = std::move(p.m_name);
		return *this;
	}

	bool isMutable() const override   { return true; }
	bool isChangeable() const override { return true; }

	void setName(std::string new_name) { m_name = std::move(new_name); }
	void setName(const char* new_name) { m_name = new_name; }
	void setName(std::string& new_name) { m_name = new_name; }

	void setVal(const T& t) { m_dataType = t; }
	void setVal(T&& t) { m_dataType = std::move(t); }
};