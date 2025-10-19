/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:06:53 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/19 21:18:34 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap()
{
    name = "Default";
    hitpoints = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hitpoints = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
}

int ClapTrap::getHitPoints() const{
    return hitpoints;
}

int ClapTrap::getEnergyPoints() const{
    return energy_points;
}

int ClapTrap::getAttackDamage() const{
    return attack_damage;
}

void ClapTrap::setHitPoints(int hp){
    hitpoints = hp;
}

void ClapTrap::setEnergyPoints(int ep){
    energy_points = ep;
}

void ClapTrap::setAttackDamage(int ad){
    attack_damage = ad;
}

void takeDamage(unsigned int amount){}
void attack(const std::string& target)
{
    std::cout << "Attacking " << target << std::endl;
}
void beRepaired(unsigned int amount){}
