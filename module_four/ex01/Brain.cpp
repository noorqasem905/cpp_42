/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:37:15 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 17:17:52 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\e[0;33mBrain constructor called\e[0m" << std::endl;
}
Brain::~Brain()
{
    std::cout << "\e[0;31mBrain destructor called\e[0m" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "\e[0;33mBrain copy constructor called\e[0m" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "\e[0;33mBrain assignment operator called\e[0m" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

void Brain::setIdeas(const std::string& idea, int index)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

void Brain::getIdeas() const
{
    for (int i = 0; i < 100; i++)
    {
        if (!ideas[i].empty())
            std::cout << "Idea " << i << ": " << ideas[i] << std::endl;
    }
}