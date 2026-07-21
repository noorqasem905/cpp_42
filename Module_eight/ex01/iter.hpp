/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:44:00 by nqasem            #+#    #+#             */
/*   Updated: 2026/03/01 23:57:45 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void iter(T* array, size_t len, void (*func)(T&))
{
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

template <typename T>
void iter(const T* array, size_t len, void (*func)(const T&))
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

#endif