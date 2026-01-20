/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:19:52 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/19 10:42:59 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Fixed {

private:
    int _raw;
    static const int _bits;

public:
    Fixed();
    Fixed(Fixed const &copy);
    ~Fixed();
    Fixed &operator=(const Fixed &copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif