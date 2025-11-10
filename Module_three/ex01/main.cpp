/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:07:24 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 17:27:41 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap robot1("M9");
	ScavTrap robot2("6-JA");

	robot1.attack("6-JA");
	robot2.guardGate();
	robot2.takeDamage(20);
	robot2.beRepaired(20);
	robot2.attack("M9");
	robot1.beRepaired(20);
	robot1.beRepaired(20);
	robot1.takeDamage(120);
	robot1.takeDamage(20);
	ScavTrap robot3(robot1);
	robot3.attack("6-JA");
	robot3.takeDamage(20);
	robot3 = robot2;
	robot3.attack("6-JA");
	robot3.takeDamage(20);
	return 0;
}