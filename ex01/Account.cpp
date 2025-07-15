/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:08:36 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/15 21:10:42 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class PhoneBook {
    public:
        std::string contacts[8];
    // private:
    int myNum;
    void addContact(const std::string &name) 
    {
        if (myNum < 8)
        {
            contacts[myNum] = name;
            myNum++;
        } else 
        {
            contacts[0] = name;
            myNum = 1;
        }
    }
    void displayContacts() const 
    {
        for (int i = 0; i < myNum; ++i) {
            std::cout << i + 1 << ": " << contacts[i] << std::endl;
        }
    }
    void searchContact(int index) const {
        if (index < 0 || index >= myNum) {
            std::cout << "Invalid index!" << std::endl;
            return;
        }
        std::cout << "Contact " << index + 1 << ": " << contacts[index] << std::endl;
    }
};

class Contact {
  public:
    int myNum;
    std::string myString;
};

int main()
{
    PhoneBook phoneBook;
    phoneBook.myNum = 0;
     phoneBook.addContact("Alice");
//    phoneBook.displayContacts();
    phoneBook.addContact("Bob");
    // phoneBook.displayContacts();
    phoneBook.addContact("Charlie");
    // phoneBook.displayContacts();
    phoneBook.searchContact(0); // Should display Alice  /**/
    return 0;
}