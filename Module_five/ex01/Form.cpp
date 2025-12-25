/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:18:20 by nqasem            #+#    #+#             */
/*   Updated: 2025/12/25 17:42:11 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade)
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	isSigned = true;
}

const std::string &Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecGrade() const
{
	return execGrade;
}

Form::~Form()
{
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: " << form.getExecGrade();
	return out;
}

