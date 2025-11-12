/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:27:32 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 18:58:23 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "\e[0;33mAnimal constructor called\e[0m" << std::endl;
    type = "Animal";
}

Animal::~Animal()
{
    std::cout << "\e[0;31mAnimal destructor called\e[0m" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "\e[0;33mAnimal sound!\e[0m" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}