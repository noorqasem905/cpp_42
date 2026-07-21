/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:00 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/20 18:58:01 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

int main()
{
    std::cout << BLUE << "=== TEST 1: Valid Bureaucrat ===" << RESET << std::endl;
    try {
        Bureaucrat T1("Ahmed", 75);
        std::cout << GREEN << "✓ Valid bureaucrat: " << CYAN << T1 << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Error: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 2: High Grade Constructor ===" << RESET << std::endl;
    try {
        Bureaucrat T2("NQASEM", 0);
        std::cout << RED << "✗ This should not be printed" << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << GREEN << "✓ Caught GradeTooHighException: " << YELLOW << e.what() << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Wrong exception type: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 3: Low Grade Constructor ===" << RESET << std::endl;
    try {
        Bureaucrat T3("Talal", 151);
        std::cout << RED << "✗ This should not be printed" << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << GREEN << "✓ Caught GradeTooLowException: " << YELLOW << e.what() << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Wrong exception type: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 4: Increment Boundary ===" << RESET << std::endl;
    try {
        Bureaucrat Abd("Abd", 2);
        std::cout << BLUE << "Initial: " << CYAN << Abd << RESET << std::endl;

        Abd.incrementGrade(); // Grade 1
        std::cout << BLUE << "After increment: " << CYAN << Abd << RESET << std::endl;

        Abd.incrementGrade(); // Throws Exception
        std::cout << RED << "✗ This should not be printed" << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << GREEN << "✓ Caught GradeTooHighException on increment: " << YELLOW << e.what() << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Wrong exception type: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 5: Decrement Boundary ===" << RESET << std::endl;
    try {
        Bureaucrat T4("Final", 149);
        std::cout << BLUE << "Initial: " << CYAN << T4 << RESET << std::endl;

        T4.decrementGrade(); // Grade 150
        std::cout << BLUE << "After decrement: " << CYAN << T4 << RESET << std::endl;

        T4.decrementGrade(); // Throws Exception
        std::cout << RED << "✗ This should not be printed" << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << GREEN << "✓ Caught GradeTooLowException on decrement: " << YELLOW << e.what() << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Wrong exception type: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 6: Orthodox Canonical Form (Copy & Assignment) ===" << RESET << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copyConstructed(original); // Copy constructor
        
        Bureaucrat assigned("Assigned", 100);
        assigned = original; // Copy assignment operator

        std::cout << GREEN << "Original: " << CYAN << original << RESET << std::endl;
        std::cout << GREEN << "Copy: " << CYAN << copyConstructed << RESET << std::endl;
        std::cout << GREEN << "Assigned: " << CYAN << assigned << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Error during OCF test: " << e.what() << RESET << std::endl;
    }

    return 0;
}