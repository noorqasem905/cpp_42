/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:34:54 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/26 15:39:49 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialization.hpp"

int main()
{
	std::cout << "---- Test 1: Single generate call ----" << std::endl;
	// Base *p = generate();
	std::cout << "Generating instances of A, B, and C:" << std::endl;
	Base *p = new A();
	std::cout << "identify(p): ";
	identify(p);
	std::cout << "identify(*p): ";
	identify(*p);
	delete p;

	p = new B();
	std::cout << "identify(p): ";
	identify(p);
	std::cout << "identify(*p): ";
	identify(*p);
	delete p;

	p = new C();
	std::cout << "identify(p): ";
	identify(p);
	std::cout << "identify(*p): ";
	identify(*p);
	delete p;

	std::cout << "\n---- Test 2: Multiple generate calls ----" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		Base *p2 = generate();
		std::cout << "Test " << i + 1 << " - identify(p2): ";
		identify(p2);
		std::cout << "Test " << i + 1 << " - identify(*p2): ";
		identify(*p2);
		delete p2;
	}

	return 0;
}