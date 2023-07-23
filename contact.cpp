#include "contact.hpp"

void Contact::set_name(const std::string& name) {
    m_name = name;
}

void Contact::set_phone(const std::string& phone) {
    m_phone = phone;
}

void Contact::set_email(const std::string& email) {
    m_email = email;
}

std::string Contact::get_name() const {
    return m_name;
}

std::string Contact::get_phone() const {
    return m_phone;
}

std::string Contact::get_email() const {
    return m_email;
}
