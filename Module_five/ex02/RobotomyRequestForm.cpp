/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:28:42 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 15:18:57 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
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
        
    std::cout << "* drilling noises *" << std::endl;
    srand(static_cast<unsigned int>(time(NULL))); // Changed from nullptr to NULL
    if (rand() % 2 == 0)
    {
        std::cout << "Bzzzz... " << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}