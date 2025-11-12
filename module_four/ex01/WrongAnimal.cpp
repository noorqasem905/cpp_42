/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:48:37 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 18:59:02 by nqasem           ###   ########.fr       */
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