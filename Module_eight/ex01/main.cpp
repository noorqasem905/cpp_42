/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:43:38 by nqasem            #+#    #+#             */
/*   Updated: 2026/10/04 19:42:11 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

int main()
{
    std::cout << BLUE << "=== 1. Subject Test ===" << RESET << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    }

    std::cout << "\n" << BLUE << "=== 2. Test Exceptions (Full / Empty) ===" << RESET << std::endl;
    {
        Span emptySpan(1);
        emptySpan.addNumber(42);
        try {
            emptySpan.addNumber(43); // يجب أن يرمي استثناء
        } catch (const std::exception& e) {
            std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
        }

        try {
            emptySpan.shortestSpan(); // يجب أن يرمي استثناء لأنه عنصر واحد
        } catch (const std::exception& e) {
            std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << "\n" << BLUE << "=== 3. Add 15,000 numbers using Iterators ===" << RESET << std::endl;
    {
        Span bigSpan(15000);
        std::vector<int> bigVector;
        
        // تعبئة الفيكتور بـ 15000 رقم (من 0 إلى 14999 مضروبة في 10)
        for (int i = 0; i < 15000; ++i) {
            bigVector.push_back(i * 10);
        }

        try {
            // إضافتهم دفعة واحدة
            bigSpan.addNumbers(bigVector.begin(), bigVector.end());
            std::cout << GREEN << "Successfully added 15,000 elements!" << RESET << std::endl;
            
            std::cout << "Shortest span: " << bigSpan.shortestSpan() << " (Expected: 10)" << std::endl;
            std::cout << "Longest span:  " << bigSpan.longestSpan() << " (Expected: 149990)" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}