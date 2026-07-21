#include "Form.hpp"
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

int main()
{
    std::cout << BLUE << "=== TEST 1: Form Creation & Invalid Grades ===" << RESET << std::endl;
    try {
        Form f1("Tax Form", 0, 50); // Grade 0 too high
    } catch (const std::exception &e) {
        std::cout << GREEN << "✓ Caught high grade exception: " << YELLOW << e.what() << RESET << std::endl;
    }

    try {
        Form f2("Permit Form", 50, 151); // Grade 151 too low
    } catch (const std::exception &e) {
        std::cout << GREEN << "✓ Caught low grade exception: " << YELLOW << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "=== TEST 2: Signing Form (Success & Failure) ===" << RESET << std::endl;
    Bureaucrat boss("Boss", 10);
    Bureaucrat intern("Intern", 140);
    Form contract("Contract", 50, 20);

    std::cout << CYAN << contract << RESET << std::endl;

    // Intern tries to sign (grade 140 is worse than 50) -> Should fail
    intern.signForm(contract);
    std::cout << CYAN << contract << RESET << std::endl;

    // Boss tries to sign (grade 10 is better than 50) -> Should succeed
    boss.signForm(contract);
    std::cout << CYAN << contract << RESET << std::endl;

    return 0;
}