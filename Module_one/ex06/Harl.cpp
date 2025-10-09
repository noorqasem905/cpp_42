/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:11:11 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/09 15:04:08 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	har_function[0].level_index = 0;
	har_function[0].level = "DEBUG";
	har_function[0].func = &Harl::debug;
	har_function[1].level_index = 1;
	har_function[1].level = "INFO";
	har_function[1].func = &Harl::info;
	har_function[2].level_index = 2;
	har_function[2].level = "WARNING";
	har_function[2].func = &Harl::warning;
	har_function[3].level_index = 3;
	har_function[3].level = "ERROR";
	har_function[3].func = &Harl::error;
}
void	Harl::warning(){
	std::cout << "[Warning]\n\nThis is a warning message." << std::endl;
}
void	Harl::debug(){
	std::cout << "[Debug]\n\nThis is a debug message." << std::endl;
}
void	Harl::error()
{
	std::cout << "[Error]\n\nSomething went wrong!" << std::endl;
}
void	Harl::info(){
	std::cout << "[Info]\n\nThis is an informational message." << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (har_function[i].level == level)
		{
			switch (har_function[i].level_index)
			{
				case 0:
					(this->*har_function[0].func)();
				case 1:
					(this->*har_function[1].func)();
				case 2:
					(this->*har_function[2].func)();
				case 3:
					(this->*har_function[3].func)();
					break;
				default:
					std::cout << "No matching level found." << std::endl;
					break;
			}
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}