# riflekt

**riflekt** is a simple object reflection system built in C++20, designed to allow introspection of object properties at runtime.

## Features
- Easy to use object reflection

## Installation

### Prerequisites
- C++20 compatible compiler
- CMake 3.14 or later

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/SpectralRift/riflekt.git
   cd riflekt
   ```
2. Add the library in your project CMakeLists.txt
   ```cmake
   add_subdirectory(third_party/riflekt)
   target_link_libraries(MyCoolApp riflekt)
   ```
3. Import the appropriate headers in your app

### Usage
#### Class creation
When you are creating a class, you must inherit from the **RFObject** type and use the `RF_OBJECT_DECLARE(className, inheritedClassName)` macro in order to initialize the methods properly. A simple example of a class implementation is given below:

```cpp
#include <rift/reflection/rf_object.hpp>

struct MyClass : public RFObject {
    RF_OBJECT_DECLARE(MyClass, RFObject)
};
```

If you want to add properties and/or methods, (as of now) you must manually register them in your class constructor. \
\
Properties are represented as pointers to a specific data type, property which is part of the class. \
An example of that can be found below:

```cpp
#include <rift/reflection/rf_object.hpp>
#include <rift/reflection/rf_type_ptr_property.hpp>

struct MyCoolClass : public RFObject {
    RF_OBJECT_DECLARE(MyCoolClass, RFObject)

    int numberProperty;
    bool boolProperty;

    MyCoolClass() : numberProperty(0), boolProperty(false) {
        // expose properties
        m_Properties.push_back(new RFIntPtrProperty("numberProperty", &numberProperty));
        m_Properties.push_back(new RFBoolPtrProperty("boolProperty", &boolProperty));

        // expose methods
        m_Methods.push_back(new RFMethod("addOne", [this] { addOne(); }));
    }

    void addOne() {
        numberProperty++;
    }
};
```

#### Reflection system

Object creation is done through the `RFObject::createInstance(name)` static method. If you want to query specific object type, you can call the `RFObject::getType(name)` static method.
```cpp
auto object = RFObject::createInstance("MyCoolClass");
```
When you have a `RFObject` instance, you have the possibility to query all exposed properties by calling `RFObject::getProperties()` or all exposed methods by calling `RFObject::getMethods()` \
\
Properties are specially typed, so you need to firstly check the property type by calling the `RFProperty::getType()` pure virtual method, which will return an enum value from `RFProperty::PropertyType`, in order to know how to cast your property to the appropriate type in order to call the getter method `getValue()` or setter method `setValue(value)`
```cpp
for(auto property : object->getProperties()) {
        printf("Property %s\n", property->getName().c_str());
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
```
If you want to get a property with casting already done, you can call the `RFObject::getPropertyType<T>(name)` method like this:
```cpp
object->getPropertyType<RFIntPtrProperty>("numberProperty")->setValue(1234);
```
Methods can be fetched by calling `RFObject::getMethod(name)`, which can be used to invoke the method accordingly:
```cpp
object->getMethod("addOne")->invoke();
```
If you want to add a children instance to this object, you can call the `RFObject::createChild(name)` method, which will create a reflected child object and handle the parent association accordingly.
```cpp
object->createChild("AnotherCoolClass");
```

### Examples
For an example application, you can check the 'sample' directory, which has a sample application ready to use featuring the reflection functionality of the library. \
\
All that's needed is for you to build it.