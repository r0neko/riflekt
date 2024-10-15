#pragma once

#include <string>
#include <string_view>
#include <functional>

struct RFMethod {
    RFMethod(std::string_view name, const std::function<void()> &func) : m_Name(name), m_Function(func) {}

    virtual ~RFMethod() = default;

    [[nodiscard]] std::string getName() const;

    void invoke();

protected:
    std::string m_Name;
    std::function<void()> m_Function;
};