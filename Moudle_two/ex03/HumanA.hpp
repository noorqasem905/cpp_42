/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:29:54 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/29 16:14:07 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
class HumanA
{
	public:
		void attack() const;
		HumanA(const std::string& name, Weapon& weapon);
	private:
		std::string name;
		Weapon* weapon;
};

