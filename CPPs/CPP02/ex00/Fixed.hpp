

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>

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
};

#endif