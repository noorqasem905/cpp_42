/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:21:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/12/31 19:30:02 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

// Forward declaration
class Form;

class Bureaucrat
{

	private:
		const std::string 	name;
		int 				grade;
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		std::string getName() const;
		void signForm(Form &form);
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

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



#endif // BUREAUCRAT_HPP