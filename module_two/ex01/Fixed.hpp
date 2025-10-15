/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:13 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/13 19:26:19 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>   

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
    
        Fixed();
        Fixed(Fixed const &other);
        Fixed(int const int_num);
        Fixed(float const float_num);
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed &operator=(const Fixed  &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        ~Fixed();
    };
    
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif