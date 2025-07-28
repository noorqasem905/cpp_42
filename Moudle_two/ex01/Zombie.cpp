/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:34:19 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/26 18:29:04 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombiee.hpp"

Zombie::Zombie(std::string name) : name(name) {}
Zombie::Zombie() : name("Unnamed Zombie") {}
void Zombie::announce() const {
	std::cout << name << std::endl;
}