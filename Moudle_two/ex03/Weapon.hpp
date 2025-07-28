/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:15:15 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/28 20:56:39 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		void attack() const;
		Weapon(const std::string& type);
		const std::string& getType() const;
		void setType(const std::string type);

};