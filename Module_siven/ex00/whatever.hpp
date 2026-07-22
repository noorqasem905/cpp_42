/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:42:58 by nqasem            #+#    #+#             */
/*   Updated: 2026/07/22 14:26:17 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T const& min(T const& a, T const& b)
{
    return (a < b) ? a : b;
}

template <typename T>
T const& max(T const& a, T const& b)
{
    return (a > b) ? a : b;
}

#endif