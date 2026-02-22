/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:05:34 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 15:18:17 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
AForm("ShrubberyCreationForm", 145, 137), target(target)  // Changed from Form
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
AForm(other), target(other.target)  // Changed from Form
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);  // Changed from Form
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->getIsSigned() == false)
        throw std::runtime_error("Form is not signed.");
    if (executor.getGrade() > this->getExecGrade())
        throw std::runtime_error("Bureaucrat grade too low to execute the form.");
    
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile)
    {
        throw std::runtime_error("Failed to create the output file.");
    }
    outfile << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
    outfile.close();
    if (outfile.fail())
    {
        throw std::runtime_error("Failed to write to the output file.");
    }
}

