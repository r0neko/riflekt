#pragma once

#include <rift/reflection/rf_property.hpp>

// forward definition of object class to prevent looped includes
struct RFObject;

// Reflected typed pointer property
template<typename T>
struct RFTypePtrProperty : public RFProperty {
    explicit RFTypePtrProperty(std::string_view name) : RFProperty(name) { m_Reference = new T; }

    RFTypePtrProperty(std::string_view name, T *reference) : RFProperty(name) {
        m_Reference = reference;
    }

    // value setter
    void setValue(T v) {
        *m_Reference = v;
    };

    // value getter
    T getValue() {
        return *m_Reference;
    };

    [[nodiscard]] PropertyType getType() const override;

protected:
    T *m_Reference;
};

typedef RFTypePtrProperty<bool> RFBoolPtrProperty;
typedef RFTypePtrProperty<int> RFIntPtrProperty;
typedef RFTypePtrProperty<float> RFFloatPtrProperty;
typedef RFTypePtrProperty<std::string> RFStringPtrProperty;
typedef RFTypePtrProperty<RFObject *> RFObjectPtrProperty;

