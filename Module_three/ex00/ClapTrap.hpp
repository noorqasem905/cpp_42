/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:06:56 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/19 21:17:04 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


class  ClapTrap
{
    private:
        std::string name;
        int hitpoints;
        int energy_points;
        int attack_damage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        void setHitPoints(int hp);
        void setEnergyPoints(int ep);
        void setAttackDamage(int ad);
};

#endif