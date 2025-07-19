/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:05:01 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/19 19:02:05 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact{

	public:
		Contact();
		Contact(const std::string& fname, const std::string& lname, const std::string& nick, 
				const std::string& phone, const std::string& secret);
		void	displayContacts();
		void	searchContact() const;
    	int		addContact();
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
};


#endif