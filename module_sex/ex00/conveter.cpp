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

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

static bool isSpecialCase(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff" ||
            literal == "inf" || literal == "inff");
}

void ScalarConverter::convert(const std::string& literal) {
    // 1. معالجة الحالات الخاصة (nan, inf, ...)
    if (isSpecialCase(literal)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (literal.find("nan") != std::string::npos) {
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        } else if (literal[0] == '-') {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        } else {
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
        return;
    }

    // 2. معالجة الحرف المباشر 'a'
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
        return;
    }

    // 3. التحويل لقيمة double أولاً باستخدام C++98 std::strtod
    char* endptr;
    double value = std::strtod(literal.c_str(), &endptr);

    // التحقق من صحة المدخل
    if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // A. طباعة char
    if (value < 0 || value > 127) {
        std::cout << "char: impossible\n";
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "char: Non displayable\n";
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    }

    // B. طباعة int
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << static_cast<int>(value) << "\n";
    }

    // C. طباعة float و double بـ static_cast
    float fValue = static_cast<float>(value);
    std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << "\n";
}