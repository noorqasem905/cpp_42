/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:44:00 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/22 18:44:03 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename Func>
void iter(T* array, size_t len, Func func)
{
    if (!array || !func)
        return;
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

#endif