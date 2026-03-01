/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conveter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:38 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/23 14:58:54 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conveter.hpp"
#include <cstdlib>  // Add this include for strtol, strtod, strtof, atoi, atof

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
    }
    return *this;
}

bool ScalarConverter::isSpecialCase(const std::string& literal) {
	return (literal == "nan" || literal == "nanf" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff");
}

bool ScalarConverter::isChar(const std::string &literal) {
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal) {
    char* endptr;
    strtol(literal.c_str(), &endptr, 10);
    return (*endptr == '\0' && endptr != literal.c_str());
}

bool ScalarConverter::isFloat(const std::string &literal) {
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;
    std::string temp = literal.substr(0, literal.length() - 1);
    char* endptr;
    strtof(temp.c_str(), &endptr);
    return (*endptr == '\0' && endptr != temp.c_str());
}

bool ScalarConverter::isDouble(const std::string &literal) {
    char* endptr;
    strtod(literal.c_str(), &endptr);
    return (*endptr == '\0' && endptr != literal.c_str());
}

void ScalarConverter::convert(const std::string& literal) {
    ScalarConverter converter;
    if (converter.isSpecialCase(literal)) {
        converter.printConversion(literal);
        return;
    }
    if (converter.isChar(literal) || converter.isInt(literal) || converter.isFloat(literal) || converter.isDouble(literal)) {
        converter.printConversion(literal);
    } else {
        std::cout << "Invalid literal: " << literal << std::endl;
    }
}

void ScalarConverter::printConversion(const std::string& literal) {
    std::cout << "char: ";
    if (isChar(literal)) {
        std::cout << "'" << literal[0] << "'";
    } else {
        std::cout << "impossible";
    }
    std::cout << std::endl;

    std::cout << "int: ";
    if (isInt(literal)) {
        std::cout << static_cast<int>(atoi(literal.c_str()));
    } else {
        std::cout << "impossible";
    }
    std::cout << std::endl;

    std::cout << "float: ";
    if (isFloat(literal)) {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(atof(literal.c_str())) << "f";
    } else {
        std::cout << "impossible";
    }
    std::cout << std::endl;

    std::cout << "double: ";
    if (isDouble(literal)) {
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(atof(literal.c_str()));
    } else {
        std::cout << "impossible";
    }
    std::cout << std::endl;
}