/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:49:21 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 17:38:58 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

FragTrap::FragTrap(): ClapTrap(100, 100, 30)
{
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "\e[0;32mFragTrap " << getName() << " is requesting a high five!\e[0m" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
        setHitPoints(getHitPoints() + 1);
        return;
    }
    else if (getHitPoints() <= 0)
    {
        std::cout << "\e[0;31mFragTrap " << getName() << " is out of hitpoints and cannot request a high five!\e[0m" << std::endl;
        return;
    }
    else if (getEnergyPoints() <= 0)
    {
        std::cout << "\e[0;31mFragTrap " << getName() << " is out of energy and cannot request a high five!\e[0m" << std::endl;
        return;
    }
    else{
        std::cout << "\e[0;32mFragTrap " << getName() << " has enough energy and hitpoints to request a high five!\e[0m" << std::endl;
    }
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}