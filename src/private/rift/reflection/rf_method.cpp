#include <rift/reflection/rf_method.hpp>

std::string RFMethod::getName() const {
    return m_Name;
}

void RFMethod::invoke() {
    if (m_Function) {
        m_Function();
    }
}