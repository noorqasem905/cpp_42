/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:34:19 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/09 15:52:18 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombiee.hpp"

Zombie::Zombie(std::string name) : name(name) {}
Zombie::Zombie() : name("Unnamed Zombie") {}
void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}