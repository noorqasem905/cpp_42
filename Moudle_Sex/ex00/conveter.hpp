/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conveter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:52:54 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/23 14:56:53 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter {
	
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

    static void convert(const std::string& literal);
private:
	bool isSpecialCase(const std::string& literal);
    void printConversion(const std::string& literal);
    bool isChar(const std::string &literal);
    bool isInt(const std::string &literal);
    bool isFloat(const std::string &literal);
    bool isDouble(const std::string &literal);
};

#endif