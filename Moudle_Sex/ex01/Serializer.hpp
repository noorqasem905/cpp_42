/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:43:53 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/26 15:19:32 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_data
{
    int		value;
    std::string	name;
}	Data;

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);
};
#endif