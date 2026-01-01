/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 13:49:23 by nqasem            #+#    #+#             */
/*   Updated: 2026/01/01 13:50:08 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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
		// Copy assignment logic (if needed)
	}
	return *this;
}

Intern::~Intern()
{
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	else
		throw std::invalid_argument("Unknown form type");
}
