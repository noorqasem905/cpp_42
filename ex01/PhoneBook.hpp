/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:05:05 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/19 19:35:25 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contacts.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook 
{
	public:
		void displayContacts();
		void searchContact(int index);
		PhoneBook();
		void addBook();
	private:
        Contact contacts[2];
        int myNum;

};

#endif