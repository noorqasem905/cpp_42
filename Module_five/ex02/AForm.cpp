/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:47:37 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 15:05:05 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecGrade() const
{
    return execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getSignGrade()
        << ", Exec Grade: " << form.getExecGrade();
    return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

