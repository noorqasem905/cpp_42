/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:54:29 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/24 09:54:47 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    randomChump("StackZombie");

    Zombie* heapZ = newZombie("HeapZombie");
    heapZ->announce();
    delete heapZ;
}
