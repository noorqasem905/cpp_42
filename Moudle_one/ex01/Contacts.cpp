/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:13:10 by nqasem            #+#    #+#             */
/*   Updated: 2025/08/12 18:48:22 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"
#include <iostream>

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
	if (phoneNumber.empty() || phoneNumber.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid phone number!" << std::endl;
		return (-1);
	}
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
	if (first_name.empty() || last_name.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "All fields must be filled!" << std::endl;
		return (-1);
	}
	return (0);
}

void Contact::displayContacts(int i)
{
	if (first_name.empty() && last_name.empty() && nickname.empty())
		return;
    std::cout << std::setw(10) << std::right << i << "|";
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
    std::cout << std::endl;
}

void Contact::searchContact() const{
    std::cout << "Fisrt Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
