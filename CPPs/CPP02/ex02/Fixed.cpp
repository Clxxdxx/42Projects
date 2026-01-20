/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:19:37 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/19 11:18:26 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _raw(0)
{
    
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::~Fixed()
{
    
}

Fixed &Fixed::operator=(const Fixed &other)
{
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
    _raw = raw * 256;
}

Fixed::Fixed(float raw)
{
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

//Ex02

bool Fixed::operator>(const Fixed &other) const
{
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res(this->toFloat() + other.toFloat());
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res(this->toFloat() - other.toFloat());
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res(this->toFloat() * other.toFloat());
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed res(this->toFloat() / other.toFloat());
    return res;
}

Fixed &Fixed::operator++()
{
    _raw++;
    return *this;
}


Fixed &Fixed::operator--()
{
    _raw--;
    return *this;
}


Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _raw++;
    return temp;
}


Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _raw--;
    return temp;
}


Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a < b)
        return b;
    else if (a > b)
        return a;
    
    return a;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else if (a > b)
        return b;
    
    return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return b;
    else if (a > b)
        return a;
    
    return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else if (a > b)
        return b;
    
    return a;
}
