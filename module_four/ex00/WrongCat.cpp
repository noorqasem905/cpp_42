/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:48:33 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 19:08:42 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat()
{
    std::cout << "\e[0;33mWrongCat constructor called\e[0m" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "\e[0;31mWrongCat destructor called\e[0m" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "\e[0;33mWrongCat sound!\e[0m" << std::endl;
}