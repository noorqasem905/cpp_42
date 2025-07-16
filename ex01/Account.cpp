/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:08:36 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/16 19:09:07 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Contact {
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        
        // Constructor
        Contact() : first_name(""), last_name(""), nickname(""), phoneNumber(""), darkestSecret("") {}
        
        // Constructor with parameters
        Contact(const std::string& fname, const std::string& lname, const std::string& nick, 
                const std::string& phone, const std::string& secret) 
            : first_name(fname), last_name(lname), nickname(nick), phoneNumber(phone), darkestSecret(secret) {}
};

class PhoneBook {
    private:
        Contact contacts[8];
        int myNum;
        
    public:
        PhoneBook() : myNum(0) {}
        
        void addContact() 
        {
            std::string name, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::getline(std::cin, name);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);
            if (myNum < 8)
            {
                contacts[myNum] = Contact(name, lastName, nickname, phoneNumber, darkestSecret);
                myNum++;
            } else 
            {
                contacts[0] = Contact(name, lastName, nickname, phoneNumber, darkestSecret);
                myNum = 1;
            }
        }
        
        void displayContacts() const 
        {
            for (int i = 0; i < myNum; ++i)
            {
                    std::cout << "Index|"<<"first name"<<"|last name"<<"|nickname"<<"|phone number"<<"|darkest secret" << std::endl;
                    std::cout << contacts[i].first_name;
                    std::cout << contacts[i].last_name;
                    std::cout << contacts[i].nickname;
                    std::cout << contacts[i].phoneNumber;
                    std::cout << contacts[i].darkestSecret << std::endl;  
            }
        }
        
        void searchContact(int index) const {
            if (index < 0 || index >= myNum) {
                std::cout << "Invalid index!" << std::endl;
                return;
            }
            std::cout << "Contact " << index + 1 << ": " << contacts[index].first_name << std::endl;

        }
};



int main()
{
    PhoneBook phoneBook;
    while (1)
    {
        std::string command;
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        
        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            int index;
            phoneBook.displayContacts();
            std::cout << "Enter contact index to search: ";
            std::cin >> index;
            std::cin.ignore();
            phoneBook.searchContact(index - 1);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid Command, command accepted (ADD, SEARCH, EXIT)" << std::endl;
        }
    }
    return (0);
}