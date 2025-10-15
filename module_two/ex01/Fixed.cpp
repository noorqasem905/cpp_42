/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:10 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/13 19:24:15 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout<< "Default constructor called" <<std::endl;
    fixed_point = 0;
}

Fixed::Fixed(Fixed const &other) 
{
    std::cout<< "Copy constructor called" <<std::endl;
    fixed_point = other.getRawBits(); 
}

Fixed &Fixed::operator=(const Fixed  &other)
{
    std::cout<< "Copy assignment operator called" <<std::endl;
    
	fixed_point = other.getRawBits();
    return *this;
} 

Fixed::Fixed(int const int_num)
{
    std::cout<< "Int constructor called" <<std::endl;
    fixed_point = int_num << fractional_bits;
}

Fixed::Fixed(float const float_num)
{
    std::cout<< "Float constructor called" <<std::endl;
    fixed_point =  roundf(float_num * (1 << fractional_bits));
}

int Fixed::getRawBits( void ) const
{
    std::cout<< "getRawBits member function called" <<std::endl;
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    std::cout<< "setRawBits member function called" <<std::endl;
    fixed_point = raw;  
}

Fixed::~Fixed()
{
    std::cout<< "Destructor called" <<std::endl;
}

float Fixed::toFloat( void ) const
{
    return ((float)fixed_point / (1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
    return (fixed_point >> fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}