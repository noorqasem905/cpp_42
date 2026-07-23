/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:43:57 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/23 17:57:16 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valStr, float& value) const {
    std::string trimmedVal = trim(valStr);
    if (trimmedVal.empty()) {
        std::cout << "Error: bad input => empty value" << std::endl;
        return false;
    }

    char* endPtr;
    double val = std::strtod(trimmedVal.c_str(), &endPtr);

    if (*endPtr != '\0') {
        std::cout << "Error: bad input => " << trimmedVal << std::endl;
        return false;
    }
    if (val < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    value = static_cast<float>(val);
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& dbPath) {
    std::ifstream file(dbPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = trim(line.substr(0, commaPos));
            float rate = static_cast<float>(std::atof(line.substr(commaPos + 1).c_str()));
            _database[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string& inputPath) const {
    if (_database.empty()) {
        std::cerr << "Error: database is empty or not loaded." << std::endl;
        return;
    }

    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line.find("date") != std::string::npos && line.find("value") != std::string::npos)
            continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valStr = line.substr(pipePos + 1);

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valStr, value)) {
            continue;
        }

        std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

        if (it != _database.end() && it->first == date) {
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        } else {
            if (it == _database.begin()) {
                std::cout << "Error: date too early." << std::endl;
            } else {
                --it;
                std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
            }
        }
    }
    file.close();
}