#include <rift/reflection/rf_object.hpp>
#include <stdexcept>

std::unordered_map<std::string, RFTypeInfo *> &RFObject::getRegistry() {
    static std::unordered_map<std::string, RFTypeInfo *> s_Registry;
    return s_Registry;
}

std::vector<RFProperty *> RFObject::getProperties() const {
    return m_Properties;
}

std::vector<RFMethod *> RFObject::getMethods() const {
    return m_Methods;
}

RFMethod *RFObject::getMethod(std::string_view name) {
    for (auto method: m_Methods) {
        if (method->getName() == name) {
            return method;
        }
    }

    return nullptr;
}

RFProperty *RFObject::getProperty(std::string_view name) {
    for (auto property: m_Properties) {
        if (property->getName() == name) {
            return property;
        }
    }

    return nullptr;
}

RFObject *RFObject::createInstance(std::string_view name) {
    auto type = getType(name);

    if (type) {
        return type->createInstance();
    }

    return nullptr;
}

RFObject* RFObject::createChild(std::string_view name) {
    auto itx = createInstance(name);

    if (itx) {
        itx->m_Parent = this;
        m_Children.push_back(itx);

        return itx;
    }

    return nullptr;
}

RFTypeInfo *RFObject::getType(std::string_view name) {
    const auto &registry = getRegistry();
    auto it = registry.find(std::string(name));

    if (it != registry.end()) {
        return it->second;
    }

    throw std::runtime_error("Type not found");
}