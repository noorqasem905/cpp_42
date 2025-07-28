/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:14:12 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/28 20:55:26 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	club.setType("some other type of club");
	club.attack();
	// Weapon club1 = Weapon("crude spiked club");
	// club1.setType("some other type of club");
	return 0;
}