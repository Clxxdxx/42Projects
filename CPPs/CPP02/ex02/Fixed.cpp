/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:19:37 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/10 12:07:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _value(0)
{
    //cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &copy)
{
    //cout << "Copy constructor called" << endl;
    *this = copy;
}

Fixed::~Fixed()
{
    //cout << "Destructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    //cout << "Copy assignment operator called" << endl;
    this->_value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    //cout << "getRawBits member funciton called" << endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

Fixed::Fixed(int value)
{
    //cout << "Int constructor called" << endl;
    _value = value * 256;
}

Fixed::Fixed(float value)
{
    //cout << "Float constructor called" << endl;
    _value = roundf(value * 256.0f);
}

float Fixed::toFloat() const
{
    return (float)_value / 256.0f;
}

int Fixed::toInt() const
{
    return _value / 256;
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
    if (!this->getRawBits())
    {
        this->setRawBits(1);
        return *this;
    }
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed &Fixed::operator--()
{
    if (!this->getRawBits())
    {
        this->setRawBits(-1);
        return *this;
    }
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator++(int val)
{
    Fixed aux = *this;
    if (!val)
        val = 1;
    this->setRawBits(this->getRawBits() + val);
    return aux;
}

Fixed Fixed::operator--(int val)
{
    Fixed aux = *this;
    
    if (!val)
        val = 1;
    this->setRawBits(this->getRawBits() - val);
    return aux;
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
