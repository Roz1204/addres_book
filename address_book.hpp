#ifndef ADDRES_BOOK
#define ADDRES_BOOK

#include <vector>
#include "contact.hpp"

class Address_Book {
private:
    std::vector<Contact*> contacts;
public:
    int search(std::string& name);
    int display_contacts();
    int remove_contact(const std::string& name);
    int update_contact(const std::string& name);
    int add_contact();
    void init();
};

#endif
