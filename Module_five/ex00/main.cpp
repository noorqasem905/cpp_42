/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:00 by nqasem            #+#    #+#             */
/*   Updated: 2025/12/25 17:16:55 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
    
    try {
        Bureaucrat T1("Ahmed", 75);
        std::cout << GREEN << "✓ Valid bureaucrat: " << CYAN << T1 << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Error: " << e.what() << RESET << std::endl;
    }
    // T2
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
    
    // T3
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
    
    // Test 4: Testing increment/decrement methods
    try {
        Bureaucrat Abd("Abd", 2);
        std::cout << BLUE << "Initial: " << CYAN << Abd << RESET << std::endl;

        Abd.incrementGrade(); // Should be grade 1 now
        std::cout << BLUE << "After increment: " << CYAN << Abd << RESET << std::endl;

        Abd.incrementGrade(); // This should throw GradeTooHighException
        std::cout << RED << "✗ This should not be printed" << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << GREEN << "✓ Caught GradeTooHighException on increment: " << YELLOW << e.what() << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Wrong exception type: " << e.what() << RESET << std::endl;
    }
    
    // Test 5: Testing decrement at boundary
    try {
        Bureaucrat T4("Final", 149);
        std::cout << BLUE << "Initial: " << CYAN << T4 << RESET << std::endl;

        T4.decrementGrade(); // Should be grade 150 now
        std::cout << BLUE << "After decrement: " << CYAN << T4 << RESET << std::endl;

        T4.decrementGrade(); // This should throw GradeTooLowException
        std::cout << RED << "✗ This should not be printed" << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << GREEN << "Caught GradeTooLowException on decrement: " << YELLOW << e.what() << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "✗ Wrong exe type: " << e.what() << RESET << std::endl;
    }
    
    return 0;
}
