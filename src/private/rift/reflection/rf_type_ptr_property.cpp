#include <rift/reflection/rf_type_ptr_property.hpp>

// template implementation
template<>
RFProperty::PropertyType RFTypePtrProperty<bool>::getType() const {
    return RFProperty::PropertyType::PROPERTY_TYPE_BOOL;
}

template<>
RFProperty::PropertyType RFTypePtrProperty<int>::getType() const {
    return RFProperty::PropertyType::PROPERTY_TYPE_INT;
}

template<>
RFProperty::PropertyType RFTypePtrProperty<float>::getType() const {
    return RFProperty::PropertyType::PROPERTY_TYPE_FLOAT;
}

template<>
RFProperty::PropertyType RFTypePtrProperty<std::string>::getType() const {
    return RFProperty::PropertyType::PROPERTY_TYPE_STRING;
}

template<>
RFProperty::PropertyType RFTypePtrProperty<RFObject *>::getType() const {
    return RFProperty::PropertyType::PROPERTY_TYPE_OBJECT;
}