// GenericData.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "IProperty.hpp"
#include "PropertyUtils.hpp"

#include <vector>
#include <unordered_set>

class PropertyContainer {
public:
	virtual ~PropertyContainer() = default;
};

class PropertySet : public PropertyContainer {
public:
	virtual ~PropertySet() = default;
private:
	std::unordered_multiset<std::string, IProperty*> m_set;
};

class PropertyList : public PropertyContainer {
public:
	virtual ~PropertyList() = default;
private:
	std::vector<IProperty*> m_list;
};