/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:34:54 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/21 14:59:28 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    std::cout << "---- Test 1: Explicit instantiation ----" << std::endl;
    Base *p1 = new A();
    Base *p2 = new B();
    Base *p3 = new C();

    std::cout << "p1 (Pointer): "; identify(p1);
    std::cout << "p1 (Ref):     "; identify(*p1);

    std::cout << "p2 (Pointer): "; identify(p2);
    std::cout << "p2 (Ref):     "; identify(*p2);

    std::cout << "p3 (Pointer): "; identify(p3);
    std::cout << "p3 (Ref):     "; identify(*p3);

    delete p1;
    delete p2;
    delete p3;

    std::cout << "\n---- Test 2: Random generation ----" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        Base *rnd = generate();
        std::cout << "Random Test " << i + 1 << " - Pointer: ";
        identify(rnd);
        std::cout << "Random Test " << i + 1 << " - Reference: ";
        identify(*rnd);
        delete rnd;
    }

    return 0;
}