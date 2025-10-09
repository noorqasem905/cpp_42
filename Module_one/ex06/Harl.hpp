/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:11:08 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/09 13:54:25 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>


class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
public:
	Harl();
	void complain(std::string level);
	struct Har_function_s
	{
		int	level_index;
		std::string level;
		void (Harl::*func)(void);
	};
	struct Har_function_s har_function[4];
};
#endif