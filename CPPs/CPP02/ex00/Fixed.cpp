/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudio <claudio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:19:49 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/11 11:16:58 by claudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _value(0)
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &copy)
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    cout << "Copy assignment operator called" << endl;
    this->_value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    cout << "getRawBits member funciton called" << endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}