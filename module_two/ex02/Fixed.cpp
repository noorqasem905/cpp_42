/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:10 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/15 20:44:33 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    fixed_point = 0;
}

Fixed::Fixed(Fixed const &other) 
{
    fixed_point = other.getRawBits(); 
}

Fixed &Fixed::operator=(const Fixed  &other)
{    
	fixed_point = other.getRawBits();
    return *this;
} 

Fixed::Fixed(int const int_num)
{
    fixed_point = int_num << fractional_bits;
}

Fixed::Fixed(float const float_num)
{
    fixed_point =  roundf(float_num * (1 << fractional_bits));
    std::cout << "Fixed point value is " << fixed_point << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;  
}

Fixed::~Fixed()
{
}

float Fixed::toFloat( void ) const
{
    return ((float)fixed_point / (1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
    return (fixed_point >> fractional_bits);
}

Fixed &Fixed::min( Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

bool	Fixed::operator>( const Fixed &src ) const
{
	return (fixed_point > src.getRawBits());
}

bool	Fixed::operator<( const Fixed &src ) const
{
	return (fixed_point < src.getRawBits());
}

bool	Fixed::operator==( const Fixed &src ) const
{
    return (fixed_point == src.getRawBits());
}

bool	Fixed::operator!=( const Fixed &src ) const
{
    return (fixed_point != src.getRawBits());
}

bool	Fixed::operator<=( const Fixed &src ) const
{
    return (fixed_point <= src.getRawBits());
}

bool	Fixed::operator>=( const Fixed &src ) const
{
    return (fixed_point >= src.getRawBits());
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed	Fixed::operator+( const Fixed &src ) const
{
    Fixed res;
    res.setRawBits(fixed_point + src.getRawBits());
    return res;
}

Fixed	Fixed::operator-( const Fixed &src ) const
{
    Fixed res;
    res.setRawBits(fixed_point - src.getRawBits());
    return res;
}

Fixed	Fixed::operator*( const Fixed &src ) const
{
    Fixed res;
    res.setRawBits((fixed_point * src.getRawBits()) >> fractional_bits);
    return res;
}

Fixed	Fixed::operator/( const Fixed &src ) const
{
    Fixed res;
    res.setRawBits((fixed_point << fractional_bits) / src.getRawBits());
    return res;
}
Fixed	&Fixed::operator++( void )
{
    ++fixed_point;
    return *this;
}

Fixed	&Fixed::operator--( void )
{
    --fixed_point;
    return *this;
}

Fixed	Fixed::operator++( int )
{
    Fixed tmp = *this;
    ++fixed_point;
    return tmp;
}

Fixed	Fixed::operator--( int )
{
    Fixed tmp = *this;
    --fixed_point;
    return tmp;
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b )
{
	return (a < b ? a : b);
}
// Find the max between two Fixed numbers
const Fixed	&Fixed::max( const Fixed &a, const Fixed &b )
{
	return (a > b ? a : b);
}
