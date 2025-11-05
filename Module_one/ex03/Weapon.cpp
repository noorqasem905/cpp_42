/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:14:56 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/05 13:50:31 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon()
{
}

Weapon::Weapon(const std::string& type) : type(type)
{
}
const std::string& Weapon::getType() const	
{
	return (type);
}
void Weapon::setType(const std::string type)
{
	this->type = type;
}

