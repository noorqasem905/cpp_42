/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:56 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 21:26:20 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "\e[0;33mDog constructor called\e[0m" <<  std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "\e[0;31mDog destructor called\e[0m" <<  std::endl;
}

void Dog::makeSound() const
{
    std::cout << "\e[0;33mWoof Woof!\e[0m" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "\e[0;33mDog copy constructor called\e[0m" <<  std::endl;
    type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "\e[0;33mDog copy assignment operator called\e[0m" <<  std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}