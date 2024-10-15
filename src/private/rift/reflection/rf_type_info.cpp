#include <rift/reflection/rf_type_info.hpp>

std::string RFTypeInfo::getName() const {
    return s_Name;
}

RFTypeInfo *RFTypeInfo::getParentTypeInfo() const {
    return t_ParentType;
}

RFObject *RFTypeInfo::createInstance() {
    printf("[REFLECTION DEBUG] Creating a new instance of type %s\n", s_Name.c_str());

    if (m_CreateFunc == nullptr) {
        printf("[REFLECTION DEBUG] Type %s has no create function\n", s_Name.c_str());
        return nullptr;
    }

    return m_CreateFunc();
}