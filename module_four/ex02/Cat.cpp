/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:54 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 21:56:47 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"  

Cat::Cat()
{
    brain = new Brain();
    std::cout << "\e[0;33mCat constructor called\e[0m" <<  std::endl;
    type = "Cat";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "\e[0;31mCat destructor called\e[0m" <<  std::endl;
}

void Cat::makeSound() const
{
    std::cout << "\e[0;33mMeow Meow!\e[0m" << std::endl;
}

Cat::Cat(const Cat& other):
    Animal(other)
{
    std::cout << "\e[0;33mCat copy constructor called\e[0m" <<  std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "\e[0;33mCat copy assignment operator called\e[0m" <<  std::endl;
    if (this != &other)
    {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}