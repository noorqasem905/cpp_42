/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:13:10 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/19 18:51:41 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"
#include <iostream>

Contact::Contact() : first_name(""), last_name(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::Contact(const std::string& fname, const std::string& lname, const std::string& nick, 
        const std::string& phone, const std::string& secret) 
    : first_name(fname), last_name(lname), nickname(nick), phoneNumber(phone), darkestSecret(secret) {}

int Contact::addContact()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
	if (first_name.empty() || last_name.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "All fields must be filled!" << std::endl;
		return (-1);
	}
	return (0);
}

void Contact::displayContacts()
{
	if (first_name.length() > 10)
        std::cout << std::setw(10) << std::right << (first_name.substr(0, 9) + ".") << "|";
    else
        std::cout << std::setw(10) << std::right << first_name << "|";
	
    if (last_name.length() > 10) 
        std::cout << std::setw(10) << std::right << (last_name.substr(0, 9) + ".") << "|";
    else 
        std::cout << std::setw(10) << std::right << last_name << "|";
    
    if (nickname.length() > 10)
        std::cout << std::setw(10) << std::right << (nickname.substr(0, 9) + ".") << "|";
    else 
        std::cout << std::setw(10) << std::right << nickname << "|";
}

void Contact::searchContact() const{
    std::cout << "Fisrt Name: " <<  ": " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
