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
    if (this != &other)
        _value = other._value;
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