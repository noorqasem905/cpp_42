/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:44:43 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 17:25:49 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    std::cout << "\e[0;34mScavTrap " << getName() << " is now in Gate keeper mode.\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name,  100, 50, 20)
{
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap(100, 50, 20)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void  ScavTrap::attack(const std::string& target)
{
    if (getEnergyPoints() > 0)
    {
        std::cout << "\e[0;32mScavTrap " << getName() 
        << " attacks " << target << "!\e[0m" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else
    {
        std::cout << "\e[0;31mScavTrap " 
        << getName() << 
        " is out of energy!\e[0m" << std::endl;
    }
}

// ScavTrap::ScanvTrap(const S)
// {
//     std::cout << "ScavTrap Copy constructor called" << std::endl;
// }