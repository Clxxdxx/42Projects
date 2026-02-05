/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:19:37 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/28 14:23:20 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _raw(0)
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
    this->_raw = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    return this->_raw;
}

void Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
}

Fixed::Fixed(int raw)
{
    cout << "Int constructor called" << endl;
    _raw = raw * 256;
}

Fixed::Fixed(float raw)
{
    cout << "Float constructor called" << endl;
    _raw = roundf(raw * 256.0f);
}

float Fixed::toFloat() const
{
    return (float)_raw / 256.0f;
}

int Fixed::toInt() const
{
    return _raw / 256;
}

std::ostream &operator<<(std::ostream &o, const Fixed &f) {
    o << f.toFloat();
    return o;
}
