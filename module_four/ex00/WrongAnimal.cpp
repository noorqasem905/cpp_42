/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:48:37 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 21:26:45 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "\e[0;33mWrongAnimal constructor called\e[0m" << std::endl;
    type = "WrongAnimal";
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "\e[0;31mWrongAnimal destructor called\e[0m" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return type;
}
void WrongAnimal::makeSound() const
{
    std::cout << "\e[0;33mWrongAnimal sound!\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "\e[0;33mWrongAnimal copy constructor called\e[0m" << std::endl;
    type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "\e[0;33mWrongAnimal copy assignment operator called\e[0m" << std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}
