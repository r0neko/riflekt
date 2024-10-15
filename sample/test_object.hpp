#pragma once

#include <cstdio>
#include <rift/reflection/rf_object.hpp>
#include <rift/reflection/rf_type_ptr_property.hpp>

struct TestObject : public RFObject {
    RF_OBJECT_DECLARE(TestObject, RFObject)

    int a;
    bool b;

    TestObject() : a(0), b(false) {
        printf("[DEBUG] %s created at 0x%p\n", getStaticTypeInfo()->getName().c_str(), this);

        // expose properties
        m_Properties.push_back(new RFIntPtrProperty("a", &a));
        m_Properties.push_back(new RFBoolPtrProperty("b", &b));

        // expose methods
        m_Methods.push_back(new RFMethod("printFunc", [this] { printFunc(); }));
    }

    void printFunc() {
        printf("a: %d, b: %d\n", a, b);
    }
};