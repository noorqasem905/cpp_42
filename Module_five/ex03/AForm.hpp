/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:47:12 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 15:11:41 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    AForm(const std::string &name, int signGrade, int execGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // Pure virtual function makes this an abstract class
    virtual void execute(const Bureaucrat &executor) const = 0;

    const std::string &getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    
    void beSigned(const Bureaucrat &bureaucrat);

    // Exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif