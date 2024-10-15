#pragma once

#include <string>
#include <string_view>

struct RFProperty {
    enum PropertyType {
        PROPERTY_TYPE_UNKNOWN,
        PROPERTY_TYPE_INT,
        PROPERTY_TYPE_FLOAT,
        PROPERTY_TYPE_BOOL,
        PROPERTY_TYPE_STRING,
        PROPERTY_TYPE_OBJECT
    };

    RFProperty(std::string_view name) : m_Name(name) {}

    virtual ~RFProperty() = default;

    [[nodiscard]] std::string getName() const {
        return m_Name;
    }

    [[nodiscard]] virtual PropertyType getType() const = 0;

protected:
    std::string m_Name;
};