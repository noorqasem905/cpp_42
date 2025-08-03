/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:11:11 by nqasem            #+#    #+#             */
/*   Updated: 2025/08/03 18:04:32 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	har_function[0].level = "DEBUG";
	har_function[0].func = &Harl::debug;
	har_function[1].level = "INFO";
	har_function[1].func = &Harl::info;
	har_function[2].level = "WARNING";
	har_function[2].func = &Harl::warning;
	har_function[3].level = "ERROR";
	har_function[3].func = &Harl::error;
}
void	Harl::warning(){
	std::cout << "Warning: This is a warning message." << std::endl;
}
void	Harl::debug(){
	std::cout << "Debug: This is a debug message." << std::endl;
}
void	Harl::error()
{
	std::cout << "Error: Something went wrong!" << std::endl;
}
void	Harl::info(){
	std::cout << "Info: This is an informational message." << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (har_function[i].level == level)
		{
			(this->*har_function[i].func)();
			return;
		}
	}
	std::cout << "No matching level found." << std::endl;
}