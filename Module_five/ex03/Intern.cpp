/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 13:49:23 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/23 14:18:22 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    if (formName == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        return new PresidentialPardonForm(target);
    else
        throw std::invalid_argument("Unknown form type");
}
