/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:44:00 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/22 14:32:34 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t len, F func)
{
    if (!array)
        return;
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(const T* array, size_t len, F func)
{
    if (!array)
        return;
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

#endif