/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:26:56 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/05 13:37:04 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::~HumanA()
{
}

HumanA::HumanA(const std::string& name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}