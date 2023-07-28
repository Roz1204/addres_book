#include "address_book.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int Address_Book::search(std::string& name)
{
    for(int i = 0; i < contacts.size(); ++i)
    {
        if(contacts[i]->get_name() == name)
        {
            std::cout << "Name: " << contacts[i]->get_name() << "\n";
            std::cout << "Phone Number: " << contacts[i]->get_phone() << "\n";
            std::cout << "Email: " << contacts[i]->get_email() << "\n\n";
            break;
        }
    }
    std::cout << "Do you want to continue the process?" << std::endl;
    std::cout << "1. yes" << std::endl;
    std::cout << "2. no" << std::endl;
    int x;
    std::cin >> x;
    return x;
}

int Address_Book::display_contacts() 
{
    std::cout << "Contact List:\n";
    for (int i = 0; i < contacts.size(); ++i) 
    {
        std::cout << "Name: " << contacts[i]->get_name() << "\n";
        std::cout << "Phone Number: " << contacts[i]->get_phone() << "\n";
        std::cout << "Email: " << contacts[i]->get_email() << "\n\n";
    } 
    std::cout << "Do you want to continue the process?" << std::endl;
    std::cout << "1. yes" << std::endl;
    std::cout << "2. no" << std::endl;
    int x;
    std::cin >> x;
    return x;
}


void ofstream_data(const std::vector<Contact*>& contacts)
{
    std::ofstream out("data.txt");
    if(out.is_open())
    {
        for (int i = 0; i < contacts.size(); ++i) 
        { 
            out << contacts[i]->get_name() << "\n";
            out << contacts[i]->get_phone() << "\n";
            out << contacts[i]->get_email() << "\n\n";
        }
    } else {
        std::cout << "Failed to open file 'data.txt'\n";
    }
    out.close();
}

int Address_Book::remove_contact(const std::string& name) 
{
    for (int i = 0; i < contacts.size(); ++i) 
    {
        if (contacts[i]->get_name() == name) 
        {
            contacts.erase(contacts.begin() + i);
            std::cout << "Contact removed successfully!\n";
            ofstream_data(contacts);
            std::cout << "Do you want to continue the process?" << std::endl;
            std::cout << "1. yes" << std::endl;
            std::cout << "2. no" << std::endl;
            int x;
            std::cin >> x;
            return x;
        }
    }
    std::cout << "Contact not found!\n";

    return -1;
}

int Address_Book::update_contact(const std::string& name)
{
    for(int i = 0; i < contacts.size(); ++i)
    {
        if(contacts[i]->get_name() == name)
        {            
            std::string phone_number;
            bool b = true;
            do
            {
                std::cout << "Enter the contact phone number: ";
                std::cin >> phone_number;

                for(int i = 4; i < phone_number.size(); ++i)
                {
                    if(phoneNumber[i] < '0' && phone_number[i] > '9')
                    {
                        b = false;
                    }
                }
            } while (phone_number.substr(0, 4) != "+374" || phone_number.size() != 12 || !b );
        
            contacts[i]->set_phone(phone_number);
            std::string new_email;
            do
            {
                std::cout << "Enter a new email: ";
                std::cin >> new_email;
            } while (new_email.substr(new_email.size() - 10) != "@gmail.com" || new_email.size() < 10);
            contacts[i]->set_email(new_email);

            std::cout << "Contact updated successfully!\n\n";
            ofstream_data(contacts);
            
            std::cout << "Do you want to continue the process?" << std::endl;
            std::cout << "1. yes" << std::endl;
            std::cout << "2. no" << std::endl;
            int x;
            std::cin >> x;
            return x;
        }
    }
    std::cout << "Contact not found!\n";
    return -1;
}

int  Address_Book::add_contact() 
{
    Contact new_contact;
    std::cout << "Enter a contact name: ";
    std::string name;
    std::cin >> name;
    new_contact.set_name(name);

    std::string phone_number;
    bool b = true;
    do
    {
        std::cout << "Enter the contact phone number: ";
        std::cin >> phone_number;

        for(int i = 4; i < phone_number.size(); ++i)
        {
            if(phone_number[i] < '0' && phone_number[i] > '9')
            {
                b = false;
            }
        }
    } while (phone_number.substr(0, 4) != "+374" || phone_number.size() != 12 || !b );
 
    new_contact.set_phone(phone_number);
        
    std::string new_email;
    do
    {
        std::cout << "Enter new email: ";
        std::cin >> new_email;
    } while (new_email.substr(new_email.size() - 10) != "@gmail.com" || new_email.size() < 10);
    new_contact.set_email(new_email);

    contacts.push_back(&new_contact);
    std::cout << "Contact added successfully!\n\n";
    ofstream_data(contacts);

    std::cout << "Do you want to continue the process?" << std::endl;
    std::cout << "1. yes" << std::endl;
    std::cout << "2. no" << std::endl;
    int x;
    std::cin >> x;
    return x;
}


void Address_Book::init()
{
    std::ifstream in("data.txt");

    if(in.is_open())
    {
        std::string name = "";
        std::string phone = "";
        std::string email = "";
        while(in >> name >> phone >> email)
        {
            Contact* obj = new Contact();
            obj->set_name(name);
            obj->set_phone(phone);
            obj->set_email(email);
            contacts.push_back(obj);
        }
        
        int number = 0;
        do
        { 
            system("clear");
            std::cout << "Select the action by selecting the number: \n";
            std::cout << "1. displayContact\n";
            std::cout << "2. search\n";
            std::cout << "3. removeContacn\n";
            std::cout << "4. updateContact\n";
            std::cout << "5. addContact \n";
            std::cout << "6. exit \n";
            std::cin >> number;
        
            system("clear");

            if(number == 1)
            {
                int x = displayContacts();
                if(x == 2) {
                    number = 6;
                }
            }
            else if(number == 2)
            {
                std::string name = "";
                std::cout << "Enter the searcher's name: ";
                std::cin >> name;
                int x = search(name);
                if(x == 2) {
                    number = 6;
                }
            }
            else if(number == 3)
            {
                std::string name = "";
                std::cout << "Enter the name of the person to be removed: ";
                std::cin >> name;
                int x = remove_contact(name);
                if(x == 2) {
                    number = 6;
                } else if(x == -1) {
                    std::cout << "Do you want to continue the process?" << std::endl;
                    std::cout << "1. yes" << std::endl;
                    std::cout << "2. no" << std::endl;
                    int x;
                    std::cin >> x;
                    if(x == 2) {
                        number = 6;
                    }
                }
            }
            else if(number == 4)
            {
                std::string name = "";
                std::cout << "Enter the name of the person to be update: ";
                std::cin >> name;
                int x = update_contact(name);
                if(x == 2) {
                    number = 6;
                } else if(x == -1) {
                    std::cout << "Do you want to continue the process?" << std::endl;
                    std::cout << "1. yes" << std::endl;
                    std::cout << "2. no" << std::endl;
                    int x;
                    std::cin >> x;
                    if(x == 2) {
                        number = 6;
                    }
                }
            }
            else if(number == 5)
            {
                int x = add_contact();
                if(x == 2) {
                    number = 6;
                }
            }
        } while(number != 6);
        std::cout << "The process is complete, thank you for using our program." << std::endl;
    }
    else
    {
        std::cout << "Failed to open file 'data.txt'!\n";
    }

    in.close();
}
