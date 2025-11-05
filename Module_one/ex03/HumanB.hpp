/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:27:53 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/05 13:36:49 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public:
		void setWeapon(Weapon& weapon);
		void attack() const;
		~HumanB();
		HumanB(const std::string& name);
	private:
		std::string name;
		Weapon* weapon;
};

