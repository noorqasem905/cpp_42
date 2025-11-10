/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:07:24 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 17:40:57 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap robot1("F9");
	FragTrap robot2("6-JA");

	robot1.attack("6-JA");
	robot2.highFivesGuys();
	robot2.takeDamage(20);
	robot2.beRepaired(20);
	robot2.attack("F9");
	robot1.takeDamage(20);
	std::cout << robot1.getHitPoints() << std::endl;
	robot1.takeDamage(120);
	robot1.beRepaired(20);
	return 0;
}
