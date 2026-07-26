/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:06:09 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/26 14:56:26 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    RPN calculator;
    calculator.evaluateExpression(argv[1]);

    return (0);
}