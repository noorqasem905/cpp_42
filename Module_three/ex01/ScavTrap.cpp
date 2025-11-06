/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:44:43 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/05 21:11:58 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    std::cout << "\e[0;34mScavTrap " << getName() << " is now in Gate keeper mode.\e[0m" << std::endl;
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name,  100, 50, 20)
{
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap(100, 50, 20)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void  ScavTrap::attack(const std::string& target)
{
    std::cout << "\e[0;32mScavTrap " << getName() << " attacks " << target << "!\e[0m" << std::endl;
}

// ScavTrap::ScanvTrap(const S)
// {
//     std::cout << "ScavTrap Copy constructor called" << std::endl;
// }