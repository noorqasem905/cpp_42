/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:00 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/22 14:15:11 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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
    std::cout << BOLD BLUE "=== testing Form Creation ===" RESET << std::endl;
    
    try {
        // correct form creation
        Form formA("Tax Form", 50, 25);
        std::cout << GREEN "✓ " RESET << formA << std::endl;

        // incorrect form creation (high)
        Form invalidForm1("Invalid", 0, 25);
    } catch (const std::exception& e) {
        std::cout << RED "✗ " RESET << e.what() << std::endl;
    }
    
    try {
        //  invalid form creation (low)
        Form invalidForm2("Invalid", 151, 25);
    } catch (const std::exception& e) {
        std::cout << RED "✗ " RESET << e.what() << std::endl;
    }
    
    std::cout << BOLD BLUE "\n=== Testing Form Signing ===" RESET << std::endl;
    
    try {
        Bureaucrat ahmed("Ahmed", 75);
        Bureaucrat talal("Talal", 150);
        Bureaucrat abd("Abd", 2);
        Bureaucrat boss("Boss", 1);

        Form formA("FormA", 50, 100);
        Form formB("FormB", 100, 150);
        Form formC("FormC", 1, 1);

        std::cout << YELLOW "Initial forms:" RESET << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;

        std::cout << YELLOW "\nBureaucrats:" RESET << std::endl;
        std::cout << ahmed << std::endl;
        std::cout << talal << std::endl;
        std::cout << abd << std::endl;
        std::cout << boss << std::endl;

        std::cout << YELLOW "\nSigning attempts:" RESET << std::endl;
        
        // Ahmed (grade 75) tries to sign FormA (requires grade 50) - should fail
        ahmed.signForm(formA);
        
        // Talal (grade 150) tries to sign FormB (requires grade 100) - should fail
        talal.signForm(formB);
        
        // Abd (grade 2) tries to sign FormA (requires grade 50) - should succeed
        abd.signForm(formA);
        
        // Boss (grade 1) tries to sign FormB (requires grade 100) - should succeed
        boss.signForm(formB);
        
        // Try to sign already signed form
        abd.signForm(formA);
        
        std::cout << YELLOW "\nFinal form states:" RESET << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

    } catch (const std::exception& e) {
        std::cout << RED "Error: " RESET << e.what() << std::endl;
    }
    
    return	0;
}