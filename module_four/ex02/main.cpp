/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:30:01 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/12 21:33:29 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal* animals[10];
    Brain* b = new Brain();
        for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << "-------------------------" << std::endl;
    b->setIdeas("Chase the cat", 0);
    b->setIdeas("Fetch the ball", 1);
    b->setIdeas("Bark at strangers", 2);
    b->getIdeas();
    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
    delete b;
    return 0;
}