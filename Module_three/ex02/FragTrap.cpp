/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:49:21 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/06 18:21:16 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
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
    std::cout << "\e[0;35mFragTrap " << getName() << " is requesting a high five!\e[0m" << std::endl;
}

// FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
// {
//     std::cout << "FragTrap Copy constructor called" << std::endl;
// }