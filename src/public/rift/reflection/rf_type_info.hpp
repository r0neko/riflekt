#pragma once

#include <string>
#include <string_view>
#include <functional>

// forward definition of object class to prevent looped includes
struct RFObject;

// Reflection Base Type Information
struct RFTypeInfo {
    RFTypeInfo(std::string_view name, const std::function<RFObject*()>& createFunc, RFTypeInfo *parentType) : s_Name(name), m_CreateFunc(createFunc), t_ParentType(parentType) {}

    // name getter
    [[nodiscard]] std::string getName() const;

    // get the parent type information
    [[nodiscard]] RFTypeInfo *getParentTypeInfo() const;

    // create a new instance of this type (calls the create function)
    RFObject* createInstance();
protected:
    std::string s_Name;
    std::function<RFObject*()> m_CreateFunc;
    RFTypeInfo *t_ParentType;
};