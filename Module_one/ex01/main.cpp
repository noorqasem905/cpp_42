/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:17:45 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/07 17:38:16 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombiee.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	const Zombie *h = zombieHorde(8, "hello");
	for(int i = 0;i < 8;i++){
		h->announce();
	}
	delete[] h;
	return (0);
}