/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:56 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 15:27:16 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

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