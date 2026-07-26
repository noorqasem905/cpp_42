/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:50:55 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/23 17:48:47 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN {
private:
	std::stack<double> _stack;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

	void evaluateExpression(const std::string& expression);
};

#endif