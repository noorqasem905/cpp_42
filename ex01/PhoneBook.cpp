/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:04:12 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/19 19:52:47 by nqasem           ###   ########.fr       */
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
	if (myNum < 1 && ret == 0)
        myNum++;
	else if (ret == 0)
		myNum = 0;
}

void PhoneBook::displayContacts() 
{
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "first name" << "|";
    std::cout << std::setw(10) << std::right << "last name" << "|";
    std::cout << std::setw(10) << std::right << "nickname" << "|" << std::endl;
    for (int i = 0; i < 2; ++i)
    {
		contacts[i].displayContacts(i);
    }
}

void PhoneBook::searchContact(int index){
	if (index < 0 || index > myNum) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	contacts[index].searchContact();
}
