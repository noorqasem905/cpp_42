/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:42:43 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/24 09:57:26 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << _name << " is born." << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce() const{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
