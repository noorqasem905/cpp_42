/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:21:21 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 18:24:47 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <Brain.hpp>


class Animal
{
    public:
        Animal();
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const;
    protected:
        std::string type;
};

#endif