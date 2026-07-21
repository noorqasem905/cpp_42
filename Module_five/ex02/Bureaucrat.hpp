/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:21:13 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/21 11:40:56 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm; // Forward Declaration

class Bureaucrat
{
private:
	const std::string name;
	int grade;
	Bureaucrat(); // Private Default Constructor

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	// أضف هاتين الدالتين هنا:
	void signForm(AForm &form);
	void executeForm(const AForm &form);
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
			~GradeTooHighException() throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
			~GradeTooLowException() throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif