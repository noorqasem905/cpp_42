/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:54 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 18:58:45 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"  

Cat::Cat()
{
    std::cout << "\e[0;33mCat constructor called\e[0m" <<  std::endl;
    type = "Cat";
}

Cat::~Cat()
{
    std::cout << "\e[0;31mCat destructor called\e[0m" <<  std::endl;
}

void Cat::makeSound() const
{
    std::cout << "\e[0;33mMeow Meow!\e[0m" << std::endl;
}