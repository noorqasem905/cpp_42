/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:08:36 by nqasem            #+#    #+#             */
/*   Updated: 2025/08/06 18:39:04 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contacts.hpp"

int stringToInt(const std::string& str) {
    if (str.empty())
        return -1;
    int start = 0;
    while (start < (int)str.length() && std::isspace(str[start]))
        start++;
    if (start < (int)str.length() && (str[start] == '+' || str[start] == '-'))
        start++;    
    if (start >= (int)str.length())
        return -1;
    for (int i = start; i < (int)str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return -1;
        }
    }
    return std::atoi(str.c_str());
}

int main()
{
    PhoneBook phoneBook;
    while (1)
    {
		std::string indexStr;
        std::string command;
	
        std::cout << "Enter command: ";
        std::getline(std::cin, command);    
        if (std::cin.eof())
            return(1);
        if (command == "ADD")
            phoneBook.addBook();
        else if (command == "SEARCH")
		{
            phoneBook.displayContacts();
            std::cout << "Enter contact index to search: ";
            std::getline(std::cin, indexStr);
            if (std::cin.eof())
                return(1);
            int index = stringToInt(indexStr);
            if (index == -1) {
                std::cout << "Invalid input! Please enter a number." << std::endl;
            } else {
                phoneBook.searchContact(index);
            }
        }
		else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid Command, command accepted (ADD, SEARCH, EXIT)" << std::endl;
    }
    return (0);
}