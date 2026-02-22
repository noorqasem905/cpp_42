/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:22:17 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 15:20:52 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"  // Changed from Form.hpp

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::signForm(AForm &form)  // Changed from Form
{
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form)  // Added this method
{
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
    {
        throw GradeTooLowException();
    }
    grade++;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (minimum grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (maximum grade is 150)";
}



// Exception in cpp in is  a mechanism to detect and manage errors runtime

// errors that occur during the execution of a program. It allows programmers to handle unexpected situations gracefully
/*
try {
    Bureaucrat bureaucrat("John", 151);
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

note 
	Instead of terminating the program abruptly 
	when an error occurs, C++ allows you to throw 
	exceptions and catch them for graceful handling.

	Throwing an Exception: 
		When an error or unexpected situation occurs, 
		the program uses the throw keyword to signal an exception.
	Catching an Exception: 
		The program searches for a matching catch block to intercept 
		and handle the thrown exception.
	Handling the Exception: 
		The catch block contains the logic to respond to the error, 
		allowing the program to recover or terminate gracefully.

2. Throwing Exceptions
	Throwing exception means returning 
	some kind of value that represent 
	the exception from the try block. 
	The matching catch block is found using 
	the type of the thrown value. 
	The throw keyword is used to throw the exception.


	There are three types of values that 
	can be thrown as an exception:
		*Built-in Types
		*Standard Exceptions
		*Custom Exceptions

		2.1 Throwing Built-in Types
			You can throw built-in types like int, char, float, etc.
			we can throw objects of classes
			like std::string or any user-defined class.
			throw 42; // Throwing an integer exception
			throw std::string("An error occurred"); // Throwing a string exception
		2.2 Throwing Standard Exceptions
			The C++ Standard Library provides a set of standard exception classes 
			that can be used to represent common error conditions.
			throw std::runtime_error("Runtime error occurred"); // Throwing a standard exception
		https://www.geeksforgeeks.org/cpp/exception-handling-c/
		https://www.notion.so/2d44f7ccca1280c4aa94fc5780e9d8ea?source=copy_link
	*/
