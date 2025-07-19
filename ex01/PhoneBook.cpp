/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:04:12 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/19 18:59:26 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : myNum(0) {}

void PhoneBook::addBook()
{
	int ret;

	ret = contacts[myNum].addContact();
	if (ret == -1)
		return;
	if (myNum < 8)
        myNum++;
	else 
        myNum = 1;
}

void PhoneBook::displayContacts() 
{
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "first name" << "|";
    std::cout << std::setw(10) << std::right << "last name" << "|";
    std::cout << std::setw(10) << std::right << "nickname" << "|" << std::endl;
    for (int i = 0; i < myNum; ++i)
    {
        std::cout << std::setw(10) << std::right << i << "|";
		contacts[i].displayContacts();
        std::cout << std::endl;
    }
}

void PhoneBook::searchContact(int index) const {
	if (index < 0 || index >= myNum) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	contacts[index].searchContact();
}
