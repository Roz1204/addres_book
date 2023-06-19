#ifndef CONTACTS
#define CONTACTS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Contact
{
    std::string name = "";
    std::string phone = "";
    std::string email = "";
};

void ofstream_data(const std::vector<Contact>& contacts)
{
    std::ofstream out("data.txt");
    if(out.is_open())
    {
        for (int i = 0; i < contacts.size(); ++i) 
        { 
            out << contacts[i].name << "\n";
            out << contacts[i].phone << "\n";
            out << contacts[i].email << "\n\n";
        }
    }
    else 
    {
        std::cout << "Failed to open file 'data.txt'\n";
    }
    out.close();
}

void search(const std::vector<Contact>& contacts, std::string& name)
{
    for(int i = 0; i < contacts.size(); ++i)
    {
        if(contacts[i].name == name)
        {
            std::cout << "Name: " << contacts[i].name << "\n";
            std::cout << "Phone Number: " << contacts[i].phone << "\n";
            std::cout << "Email: " << contacts[i].email << "\n\n";
            // break;
        }
    }
}

void displayContacts(const std::vector<Contact>& contacts) 
{
    std::cout << "Contact List:\n";
    for (int i = 0; i < contacts.size(); ++i) 
    {
        std::cout << "Name: " << contacts[i].name << "\n";
        std::cout << "Phone Number: " << contacts[i].phone << "\n";
        std::cout << "Email: " << contacts[i].email << "\n\n";
    } 
}

void removeContact(std::vector<Contact>& contacts, const std::string& name) 
{
    for (auto it = contacts.begin(); it != contacts.end(); ++it) 
    {
        if (it->name == name) 
        {
            contacts.erase(it);
            std::cout << "Contact removed successfully!\n";
            ofstream_data(contacts);
            return;
        }
    }
    std::cout << "Contact not found!\n";
}

void updateContact(std::vector<Contact>& contacts, const std::string& name)
{
    for(int i = 0; i < contacts.size(); ++i)
    {
        if(contacts[i].name == name)
        {            
            std::string phoneNumber;
            bool b = true;
            do
            {
                std::cout << "Enter contact phone number: ";
                std::cin >> phoneNumber;

                for(int i = 4; i < phoneNumber.size(); ++i)
                {
                    if(phoneNumber[i] < '0' && phoneNumber[i] > '9')
                    {
                        b = false;
                    }
                }
            } while (phoneNumber.substr(0, 4) != "+374" || phoneNumber.size() != 12 || !b );
        
            contacts[i].phone = phoneNumber;

            std::string newEmail;
            do
            {
                std::cout << "Enter new email: ";
                std::cin >> newEmail;
            } while (newEmail.substr(newEmail.size() - 10) != "@gmail.com" || newEmail.size() < 10);
            contacts[i].email = newEmail;

            std::cout << "Contact updated successfully!\n\n";
            ofstream_data(contacts);
            return;
        }
    }
    std::cout << "Contact not found!\n";
}

void addContact(std::vector<Contact>& contacts) 
{
    Contact newContact;
    std::cout << "Enter contact name: ";
    std::cin >> newContact.name;

    std::string phoneNumber;
    bool b = true;
    do
    {
        std::cout << "Enter contact phone number: ";
        std::cin >> phoneNumber;

        for(int i = 4; i < phoneNumber.size(); ++i)
        {
            if(phoneNumber[i] < '0' && phoneNumber[i] > '9')
            {
                b = false;
            }
        }
    } while (phoneNumber.substr(0, 4) != "+374" || phoneNumber.size() != 12 || !b );
 
    newContact.phone = phoneNumber;
        
    std::string newEmail;
    do
    {
        std::cout << "Enter new email: ";
        std::cin >> newEmail;
    } while (newEmail.substr(newEmail.size() - 10) != "@gmail.com" || newEmail.size() < 10);
    newContact.email = newEmail;

    contacts.push_back(newContact);
    std::cout << "Contact added successfully!\n\n";
    ofstream_data(contacts);
}


void init()
{
    std::vector<Contact> contactBook;

    std::ifstream in("data.txt");

    if(in.is_open())
    {
        std::string name = "";
        std::string phone = "";
        std::string email = "";
        while(in >> name >> phone >> email)
        {
            Contact obj;
            obj.name = name;
            obj.phone = phone;
            obj.email = email;
            contactBook.push_back(obj);
        }

        std::string function = "";
        std::cout << "tame action:\n";
        std::cout << "displayContact\n";
        std::cout << "search\n";
        std::cout << "removeContacn\n";
        std::cout << "updateContact\n";
        std::cout << "addContact \n";
        std::cin >> function;

        if(function == "displayContact")
        {
            displayContacts(contactBook);
        }
        else if(function == "search")
        {
            std::string name = "";
            std::cout << "enter the searcher's name: ";
            std::cin >> name;
            search(contactBook, name);
        }
        else if(function == "removeContacn")
        {
            std::string name = "";
            std::cout << "enter the name of the person to be removed: ";
            std::cin >> name;
            removeContact(contactBook, name);
        }
        else if(function == "updateContact")
        {
            std::string name = "";
            std::cout << "enter the name of the person to be update: ";
            std::cin >> name;
            updateContact(contactBook, name);
        }
        else if(function == "addContact")
        {
            addContact(contactBook);
        }
        else
        {
            std::cout << "there is no action" << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to open file 'data.txt'\n";
    }

    in.close();
}

#endif