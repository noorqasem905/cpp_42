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

static bool isPrintable(const std::string &s) {
    for (std::size_t i = 0; i < s.size(); i++) {
        if (!isprint(static_cast<unsigned char>(s[i])))
            return false;
    }
    return true;
}

int Contact::addContact()
{
    std::string f_name;
    std::string l_name;
    std::string n_name;
    std::string p_number;
    std::string d_secret;

    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, f_name) || std::cin.eof() || std::cin.fail() || !isPrintable(f_name)) {
        std::cout << "Input interrupted, invalid, or contains non-printable characters!" << std::endl;
        return -1;
    }
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, l_name) || std::cin.eof() || std::cin.fail() || !isPrintable(l_name)) {
        std::cout << "Input interrupted, invalid, or contains non-printable characters!" << std::endl;
        return -1;
    }
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, n_name) || std::cin.eof() || std::cin.fail() || !isPrintable(n_name)) {
        std::cout << "Input interrupted, invalid, or contains non-printable characters!" << std::endl;
        return -1;
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, p_number) || std::cin.eof() || std::cin.fail() || !isPrintable(p_number)) {
        std::cout << "Input interrupted, invalid, or contains non-printable characters!" << std::endl;
        return -1;
    }
	if (p_number.empty() || p_number.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid phone number!" << std::endl;
		return (-1);
	}
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, d_secret) || std::cin.eof() || std::cin.fail() || !isPrintable(d_secret)) {
        std::cout << "Input interrupted, invalid, or contains non-printable characters!" << std::endl;
        return -1;
    }
	if (f_name.empty() || l_name.empty() || n_name.empty() || p_number.empty() || d_secret.empty())
	{
		std::cout << "All fields must be filled!" << std::endl;
		return (-1);
	}
    first_name = f_name;
    last_name = l_name;
    nickname = n_name;
    phoneNumber = p_number;
    darkestSecret = d_secret;
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
