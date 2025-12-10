/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:19:45 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/10 11:15:32 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::endl;

class Fixed {

private:
    int _value;
    static const int _bits;

public:
    //Ex00
    Fixed(Fixed const &copy);
    Fixed();
    ~Fixed();
    Fixed &operator=(const Fixed &copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    //Ex01
    Fixed(const int value);
    Fixed(const float value);
    float toFloat(void) const;
    int toInt(void) const;

    //Ex02
    //Comparison operators
    bool operator>(const Fixed &copy) const;
    bool operator<(const Fixed &copy) const;
    bool operator>=(const Fixed &copy) const;
    bool operator<=(const Fixed &copy) const;
    bool operator==(const Fixed &copy) const;
    bool operator!=(const Fixed &copy) const;
    
    //Arithmetic operators
    Fixed operator+(const Fixed &copy) const;
    Fixed operator-(const Fixed &copy) const;
    Fixed operator*(const Fixed &copy) const;
    Fixed operator/(const Fixed &copy) const;

    //Increments and decrements
    Fixed &operator++(void);
    Fixed operator++(int value);
    Fixed &operator--(void);
    Fixed operator--(int value);
    
    //Overloaded functions
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

    
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif