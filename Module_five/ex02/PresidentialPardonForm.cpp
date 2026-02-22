/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:29:46 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 15:11:05 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("PresidentialPardonForm", 25, 5), target(target)  // Changed from Form
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
AForm(other), target(other.target)  // Changed from Form
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);  // Changed from Form
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (this->getIsSigned() == false)
        throw std::runtime_error("Form is not signed.");
    if (executor.getGrade() > this->getExecGrade())
        throw std::runtime_error("Bureaucrat grade too low to execute the form.");
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}