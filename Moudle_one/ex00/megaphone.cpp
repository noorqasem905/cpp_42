/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:27:49 by nqasem            #+#    #+#             */
/*   Updated: 2025/09/30 17:26:06 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; ++i)
    {
        std::string s = argv[i];
        for (size_t j = 0; j < s.length(); ++j)
            s[j] = std::toupper(s[j]);
        std::cout << s;
    }
    std::cout << std::endl;
    return (0);
}