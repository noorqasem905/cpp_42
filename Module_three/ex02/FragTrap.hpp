/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:48:19 by nqasem            #+#    #+#             */
/*   Updated: 2025/11/10 16:54:27 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap(std::string name);
    FragTrap &operator=(const FragTrap &other);
    FragTrap(const FragTrap& other);
    FragTrap();
    ~FragTrap();
    void highFivesGuys();
};

#endif