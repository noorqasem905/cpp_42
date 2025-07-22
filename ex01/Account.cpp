/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:08:36 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/22 08:34:19 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contacts.hpp"

int main()
{
    PhoneBook phoneBook;
    while (1)
    {
		std::string indexStr;
        std::string command;
	
        std::cout << "Enter command: ";
        std::getline(std::cin, command);    
        if (command == "ADD")
            phoneBook.addBook();
        else if (command == "SEARCH")
		{
            phoneBook.displayContacts();
            std::cout << "Enter contact index to search: ";
            std::getline(std::cin, indexStr);
            try {
                int index = std::stoi(indexStr);
                phoneBook.searchContact(index);
            } catch (const std::exception& e) {
                std::cout << "Invalid input! Please enter a number." << std::endl;
            }
        }
		else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid Command, command accepted (ADD, SEARCH, EXIT)" << std::endl;
    }
    return (0);
}