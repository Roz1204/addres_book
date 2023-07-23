#ifndef CONTACT 
#define CONTACT

#include <string>

class Contact
{
private:
    std::string m_name;
    std::string m_phone;
    std::string m_email;
public:
    void set_name(const std::string& name);
    void set_phone(const std::string& phone);
    void set_email(const std::string& email);

    std::string get_name() const;
    std::string get_phone() const;
    std::string get_email() const;

};

#endif
