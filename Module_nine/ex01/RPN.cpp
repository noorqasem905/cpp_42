/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:50:55 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/23 17:48:47 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::evaluateExpression(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;


	while (iss >> token) {
		if (token.length() == 1 && std::isdigit(token[0])){
			_stack.push(token[0] - '0');
		}
		else if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/")){
			if (_stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;
			}
			double op1 = _stack.top();
			_stack.pop();
			double op2 = _stack.top();
			_stack.pop();
			double result;
			if (token == "+")
				result = op2 + op1;
			else if (token == "-")
				result = op2 - op1;
			else if (token == "*")
				result = op2 * op1;
			else if (token == "/") {
				if (op1 == 0) {
					std::cerr << "Error: Division by zero" << std::endl;
					return;
				}
				result = op2 / op1;
			}
			_stack.push(result);
		}
		else {
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}