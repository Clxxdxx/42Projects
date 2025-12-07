

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
    Fixed(Fixed const &copy);
    Fixed();
    ~Fixed();
    Fixed &operator=(const Fixed &copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    Fixed(const int value);
    Fixed(const float value);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif