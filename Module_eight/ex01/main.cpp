/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:43:38 by nqasem            #+#    #+#             */
/*   Updated: 2026/03/01 21:49:58 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <string>

void addOneInt(int &a)
{
	++a;
}

void addOneFloat(float &a)
{
    ++a;
}

void printString(const std::string &a) 
{
    std::cout << a << " ";
}

void addOneString(std::string &s)
{
    s += "+";
}

void printInt(const int &content)
{
	std::cout << " " << content;
}

void printFloat(const float &content)
{
	std::cout << " " << content << "f";
}

int main()
{
    // === Test with int ===
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array: ";
    iter(arr1, 5, printInt);
    std::cout << "\nAfter addOne: ";
    iter(arr1, 5, addOneInt);
    iter(arr1, 5, printInt);
    std::cout << "\n\n";

    // === Test with float ===
    float arr2[] = {1.5f, 2.5f, 3.5f};
    std::cout << "Original float array: ";
    iter(arr2, 3, printFloat);
    std::cout << "\nAfter addOne: ";
    iter(arr2, 3, addOneFloat);
    iter(arr2, 3, printFloat);
    std::cout << "\n\n";

    // === Test with std::string ===
    std::string arr3[] = {"hello", "world", "1"};
    std::cout << "Original string array: ";
    iter(arr3, 3, printString);
    std::cout << "\nAfter addOne: ";
    iter(arr3, 3, addOneString);
    iter(arr3, 3, printString);
    std::cout << "\n\n";

    return 0;
}