/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:06:56 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/06 18:29:13 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class  ClapTrap
{
    private:
        std::string name;
        unsigned int hitpoints;
        unsigned int energy_points;
        unsigned int attack_damage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, unsigned int hitpoints,
                unsigned int energy_points, unsigned int attack_damage);
        ClapTrap(unsigned int hitpoints,
                unsigned int energy_points, unsigned int attack_damage);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        void setHitPoints(int hp);
        void setEnergyPoints(int ep);
        void setAttackDamage(int ad);
};

#endif