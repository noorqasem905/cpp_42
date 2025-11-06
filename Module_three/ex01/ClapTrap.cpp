/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:06:53 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/06 18:28:54 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    name = "Default_ClapTrap";
    hitpoints = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Parameterized constructor called" << std::endl;
    this->name = name;
    hitpoints = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitpoints, unsigned int energy_points, unsigned int attack_damage)
{
    std::cout << "Parameterized constructor called" << std::endl;
    this->name = name;
    this->hitpoints = hitpoints;
    this->energy_points = energy_points;
    this->attack_damage = attack_damage;
}

ClapTrap::ClapTrap(unsigned int hitpoints, unsigned int energy_points, unsigned int attack_damage)
{
    std::cout << "Parameterized constructor called" << std::endl;
    this->name = "Dufault_ClapTrap";
    this->hitpoints = hitpoints;
    this->energy_points = energy_points;
    this->attack_damage = attack_damage;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

std::string ClapTrap::getName() const{
    return name;
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

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount < hitpoints)
    {
        hitpoints -= amount;
        std::cout << "\e[0;31mClapTrap " << name << " takes "
			<< amount << " points of damage!\e[0m" << std::endl;
        if (hitpoints <= 0)
        {
            std::cout << "\e[0;31mClapTrap " << name << " is out of hitpoints!\e[0m" << std::endl;
        }
    }
    else if (amount >= hitpoints)
    {
        hitpoints = 0;
        std::cout << "\e[0;31mClapTrap " << name << " is out of hitpoints!\e[0m" << std::endl;
    }
    else
    {
        std::cout << "\e[0;31mClapTrap " << name << " is already out of hitpoints!\e[0m" << std::endl;
    }
}


void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hitpoints > 0)
    {
        std::cout << "\e[0;32mClapTrap " << name << " attacks " << target <<
        ", causing " << attack_damage << " points of damage!\e[0m" << std::endl;
        energy_points--;
        if (energy_points <= 0)
        {
            std::cout << "\e[0;31mClapTrap " << name << " is out of energy!\e[0m" << std::endl;
        }
    }
    else if (hitpoints <= 0 && energy_points <= 0)
    {
        std::cout << "\e[0;31mClapTrap " << name << " is out of hitpoints and energy!\e[0m" << std::endl;
    }
    else if (hitpoints <= 0)
    {
        std::cout << "\e[0;31mClapTrap " << name << " is out of hitpoints!\e[0m" << std::endl;
    }
    else if (energy_points <= 0)
    {
        std::cout << "\e[0;31mClapTrap " << name << " is out of energy!\e[0m" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitpoints <= 0)
    {
        std::cout << "\e[0;31mClapTrap " << name << " is out of hitpoints!\e[0m" << std::endl;
        return;
    }
    if (energy_points > 0)
    {
        std::cout << "\e[0;32mClapTrap " << name << " is repaired for " << amount << " hitpoints!\e[0m" << std::endl;
        energy_points--;
        hitpoints += amount;
        if (energy_points <= 0)
        {
            std::cout << "\e[0;31mClapTrap " << name << " is out of energy!\e[0m" << std::endl;
        }
    }
    else if (energy_points <= 0)
    {
        std::cout << "\e[0;31mClapTrap " << name << " is out of energy!\e[0m" << std::endl;
    }
    else
    {
        std::cout << "\e[0;31mClapTrap " << name << " is already at full health!\e[0m" << std::endl;
    }
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Assignment operator called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitpoints = other.hitpoints;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    return *this;
}