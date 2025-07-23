/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:27:49 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/07 16:49:34 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    to_upper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
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
        for (int j = 0; argv[i][j]; ++j)
        {
            to_upper(argv[i][j]);
            std::cout << argv[i][j];
        }
        if (i < argc - 1)
            std::cout<< " ";
    }
    std::cout << std::endl;
    return (0);
}