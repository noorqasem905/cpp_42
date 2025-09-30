/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:05:01 by nqasem            #+#    #+#             */
/*   Updated: 2025/09/30 15:21:24 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact{

	public:
		void	displayContacts(int i);
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