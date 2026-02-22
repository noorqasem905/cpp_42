/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:00 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 15:18:40 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"  // Changed from Form.hpp
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
    std::cout << BOLD BLUE "=== Testing Intern and Form Creation ===" RESET << std::endl;
    
    try {
        // Create bureaucrats
        Bureaucrat boss("Boss", 1);
        Bureaucrat supervisor("Supervisor", 50);

        std::cout << YELLOW "\nBureaucrats:" RESET << std::endl;
        std::cout << boss << std::endl;
        std::cout << supervisor << std::endl;

        // Create Intern
        Intern intern;

        std::cout << BOLD BLUE "\n=== Testing Intern Form Creation ===" RESET << std::endl;
        
        // Test valid form creation
        AForm* shrub = intern.makeForm("shrubbery creation", "home");
        AForm* robotomy = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "criminal");

        std::cout << GREEN "✓ Created forms:" RESET << std::endl;
        std::cout << *shrub << std::endl;
        std::cout << *robotomy << std::endl;
        std::cout << *pardon << std::endl;

        std::cout << BOLD BLUE "\n=== Testing Form Signing and Execution ===" RESET << std::endl;
        
        // Sign and execute forms
        boss.signForm(*shrub);
        boss.executeForm(*shrub);

        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);

        boss.signForm(*pardon);
        boss.executeForm(*pardon);

        std::cout << BOLD BLUE "\n=== Testing Invalid Form Creation ===" RESET << std::endl;
        
        // Test invalid form creation
        try {
            AForm* invalid = intern.makeForm("invalid form", "target");
            delete invalid; // This line should not execute
        } catch (const std::exception& e) {
            std::cout << RED "✗ " RESET << e.what() << std::endl;
        }

        // Clean up
        delete shrub;
        delete robotomy;
        delete pardon;

    } catch (const std::exception& e) {
        std::cout << RED "Error: " RESET << e.what() << std::endl;
    }

    return 0;
}
