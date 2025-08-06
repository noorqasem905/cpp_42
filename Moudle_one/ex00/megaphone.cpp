/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:27:49 by nqasem            #+#    #+#             */
/*   Updated: 2025/08/06 18:44:16 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void    to_upper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

std::string trim(const std::string& str)
{
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        start++;
    if (start == str.length())
        return "";
    size_t end = str.length() - 1;
    while (end > start && std::isspace(str[end]))
        end--;
    return str.substr(start, end - start + 1);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout<< " * LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; ++i)
    {
        std::string s = argv[i];
        s = trim(s);
        for (size_t j = 0; j < s.length(); ++j)
            to_upper(s[j]);
        std::cout << s;
        if (i < argc - 1)
            std::cout<< " ";
    }
    std::cout << std::endl;
    return (0);
}