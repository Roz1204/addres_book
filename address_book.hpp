#ifndef ADDRES_BOOK
#define ADDRES_BOOK

#include <vector>
#include "contact.hpp"

class Address_Book {
private:
    std::vector<Contact*> contacts;
public:
    int search(std::string& name);
    int displayContacts();
    int removeContact(const std::string& name);
    int updateContact(const std::string& name);
    int addContact();
    void init();
};

#endif
