#pragma once

#include <string>
#include <functional>
#include <string_view>
#include <vector>
#include <unordered_map>

#include <rift/reflection/rf_object_macros.hpp>
#include <rift/reflection/rf_type_info.hpp>
#include <rift/reflection/rf_property.hpp>
#include <rift/reflection/rf_method.hpp>

struct RFObject {
    explicit RFObject(RFObject *parent = nullptr) : m_Parent(parent) {}

    static RFObject *createInstance(std::string_view name);

    static RFTypeInfo *getType(std::string_view name);

    RFObject *createChild(std::string_view name);

    [[nodiscard]] std::vector<RFProperty *> getProperties() const;

    [[nodiscard]] std::vector<RFMethod *> getMethods() const;

    RFProperty *getProperty(std::string_view name);

    template<typename T>
    T *getPropertyType(std::string_view name) {
        return static_cast<T *>(getProperty(name));
    }

    RFMethod *getMethod(std::string_view name);

protected:
    // Parent RFObject that owns the current RFObject
    RFObject *m_Parent;

    // Children instances of RFObject
    std::vector<RFObject *> m_Children;

    // Properties
    std::vector<RFProperty *> m_Properties;

    // Methods
    std::vector<RFMethod *> m_Methods;

    static std::unordered_map<std::string, RFTypeInfo *> &getRegistry();

RF_ABS_OBJECT_PROTO(RFObject)
};