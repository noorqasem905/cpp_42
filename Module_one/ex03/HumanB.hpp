/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:27:53 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/29 16:21:07 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public:
		void setWeapon(Weapon& weapon);
		void attack() const;
		HumanB(const std::string& name);
	private:
		std::string name;
		Weapon* weapon;
};

