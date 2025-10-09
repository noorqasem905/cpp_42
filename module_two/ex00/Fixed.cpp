/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:10 by nqasem            #+#    #+#             */
/*   Updated: 2025/10/09 17:48:26 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
private:
    int fixed_point;
    static const int fractional_bits = 8;
public:
    
    Fixed()
    {
        fixed_point = 0;
    }
    Fixed(Fixed const &other)
    {
        fixed_point = other.fixed_point;
    }
    int getRawBits( void ) const
    {
        return fixed_point;
    }
    void setRawBits( int const raw )
    {
        fixed_point = raw;  
    }
    ~Fixed();
};

Fixed::Fixed(/* args */)
{
}

Fixed::~Fixed()
{
}
