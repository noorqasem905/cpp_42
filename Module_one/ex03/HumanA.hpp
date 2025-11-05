/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:29:54 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/05 13:37:09 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
class HumanA
{
	public:
		void attack() const;
		~HumanA();
		HumanA(const std::string& name, Weapon& weapon);
	private:
		std::string name;
		Weapon* weapon;
};

