/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombiee.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:19:24 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/26 17:30:31 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEE_HPP
#define ZOMBIEE_HPP

#include <iostream>

#include <string>
class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		Zombie();
		void announce() const;
};
Zombie* zombieHorde(int N, std::string name);
#endif