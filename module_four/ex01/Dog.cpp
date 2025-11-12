/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:56 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 21:51:21 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
    brain = new Brain();
    std::cout << "\e[0;33mDog constructor called\e[0m" <<  std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "\e[0;31mDog destructor called\e[0m" <<  std::endl;
}

void Dog::makeSound() const
{
    std::cout << "\e[0;33mWoof Woof!\e[0m" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "\e[0;33mDog copy constructor called\e[0m" <<  std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "\e[0;33mDog copy assignment operator called\e[0m" <<  std::endl;
    if (this != &other)
    {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}