#pragma once

#include <string>

// Interface to a property
class IProperty {
public:
	virtual ~IProperty() noexcept = default;

	static constexpr auto key = "Property Interface";

	virtual [[nodiscard]] const std::string& name() const noexcept = 0;
	virtual [[nodiscard]] std::string typeName() const noexcept = 0;

	// I maybe don't like these
	virtual bool isMutable() const = 0;
	virtual bool isChangeable() const = 0;
};
