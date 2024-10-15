#include "test_object.hpp"

int main() {
    auto object = RFObject::createInstance("TestObject");

    printf("[DEBUG] %s(base type: %s) at 0x%p\n",
           object->getTypeInfo()->getName().c_str(),
           object->getTypeInfo()->getParentTypeInfo()->getName().c_str(),
           object
           );

    object->getPropertyType<RFIntPtrProperty>("a")->setValue(1337);
    object->getPropertyType<RFBoolPtrProperty>("b")->setValue(true);

    object->getMethod("printFunc")->invoke();

    for(auto property : object->getProperties()) {
        printf("[DEBUG] Property %s\n", property->getName().c_str());
        switch(property->getType()) {
            case RFProperty::PropertyType::PROPERTY_TYPE_INT:
                printf("  Value: %i\n", ((RFIntPtrProperty*)property)->getValue());
                break;
            case RFProperty::PropertyType::PROPERTY_TYPE_FLOAT:
                printf("  Value: %f\n", ((RFFloatPtrProperty*)property)->getValue());
                break;
            case RFProperty::PropertyType::PROPERTY_TYPE_BOOL:
                printf("  Value: %s\n", ((RFBoolPtrProperty*)property)->getValue() ? "true" : "false");
                break;
            case RFProperty::PropertyType::PROPERTY_TYPE_STRING:
                printf("  Value: %s\n", ((RFStringPtrProperty*)property)->getValue().c_str());
                break;
            case RFProperty::PropertyType::PROPERTY_TYPE_OBJECT:
                printf("  Value: %s\n", ((RFObjectPtrProperty*)property)->getValue()->getTypeInfo()->getName().c_str());
                break;
            default:
            case RFProperty::PropertyType::PROPERTY_TYPE_UNKNOWN:
                break;
        }
    }

    return 0;
}