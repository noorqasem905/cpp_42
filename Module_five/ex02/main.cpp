/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:00 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/23 12:46:01 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

int main()
{
    std::cout << BOLD BLUE "=== Testing Form Creation and Execution ===" RESET << std::endl;
    
    try {
        Bureaucrat ahmed("Ahmed", 75);
        Bureaucrat talal("Talal", 150);
        Bureaucrat abd("Abd", 2);
        Bureaucrat boss("Boss", 1);

        std::cout << YELLOW "\nBureaucrats:" RESET << std::endl;
        std::cout << ahmed << std::endl;
        std::cout << talal << std::endl;
        std::cout << abd << std::endl;
        std::cout << boss << std::endl;

        // Create concrete form objects (not abstract AForm)
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("target");
        PresidentialPardonForm pardon("criminal");

        std::cout << YELLOW "\nForms:" RESET << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << BOLD BLUE "\n=== Testing Form Signing ===" RESET << std::endl;
        
        // Test signing (ShrubberyCreationForm requires grade 145 to sign)
        ahmed.signForm(shrub);  // Grade 75 - should succeed
        talal.signForm(shrub);  // Grade 150 - should fail
        
        // Test signing (RobotomyRequestForm requires grade 72 to sign)
        ahmed.signForm(robot);  // Grade 75 - should fail
        abd.signForm(robot);    // Grade 2 - should succeed
        
        // Test signing (PresidentialPardonForm requires grade 25 to sign)
        abd.signForm(pardon);   // Grade 2 - should succeed

        std::cout << BOLD BLUE "\n=== Testing Form Execution ===" RESET << std::endl;
        
        // Test execution (ShrubberyCreationForm requires grade 137 to execute)
        ahmed.executeForm(shrub);  // Grade 75 - should succeed if signed
        
        // Test execution (RobotomyRequestForm requires grade 45 to execute)
        abd.executeForm(robot);    // Grade 2 - should succeed if signed
        
        // Test execution (PresidentialPardonForm requires grade 5 to execute)
        abd.executeForm(pardon);   // Grade 2 - should succeed if signed
        
        std::cout << BOLD BLUE "\n=== Testing Execution Without Signing ===" RESET << std::endl;
        
        // Create new forms and try to execute without signing
        ShrubberyCreationForm unsignedShrub("garden");
        boss.executeForm(unsignedShrub);  // Should fail - not signed
        
    } catch (const std::exception& e) {
        std::cout << RED "Error: " RESET << e.what() << std::endl;
    }

    return 0;
}
