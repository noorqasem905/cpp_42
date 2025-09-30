/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:05:05 by nqasem            #+#    #+#             */
/*   Updated: 2025/09/30 15:16:28 by nqasem           ###   ########.fr       */
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
        Contact contacts[8];
        int myNum;
		int contactCount;

};

#endif