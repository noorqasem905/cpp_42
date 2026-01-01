/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:28:42 by nqasem            #+#    #+#             */
/*   Updated: 2026/01/01 13:32:35 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
Form("RobotomyRequestForm", 72, 45), target(target)
{
	// Constructor body (if needed)
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
Form(other), target(other.target)
{
	// Copy constructor body (if needed)
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		Form::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw std::runtime_error("Form is not signed.");
	if (executor.getGrade() > this->getExecGrade())
		throw std::runtime_error("Bureaucrat grade too low to execute the form.");
		std::cout << "Robotomy failed on " << target << "." << std::endl;
	srand(static_cast<unsigned int>(time(nullptr)));
	if (rand() % 2 == 0)
	{
		std::cout << "Bzzzz... " << target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed on " << target << "." << std::endl;
	}
}