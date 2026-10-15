/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:06:09 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/22 18:11:24 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Vector test: Found value " << *it << std::endl;

        easyfind(vec, 99);
    }
    catch (const std::exception& e) {
        std::cout << "Vector Exception: " << e.what() << std::endl;
    }

    try {
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);

        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "List test: Found value " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "List Exception: " << e.what() << std::endl;
    }

    
    try {
        std::deque<int> deq;
        deq.push_back(5);
        deq.push_back(15);

        std::deque<int>::iterator it = easyfind(deq, 15);
        std::cout << "Deque test: Found value " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Deque Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int> const_vec;
        const_vec.push_back(42);
        const std::vector<int>& ref = const_vec;

        std::vector<int>::const_iterator it = easyfind(ref, 42);
        std::cout << "Const Vector test: Found value " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Const Vector Exception: " << e.what() << std::endl;
    }
    return 0;
}