/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:24:57 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/19 12:40:17 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

typedef std::string string;
using std::cout;
using std::endl;

class NoOcurrenceException : public std::exception {
    public:
        virtual const char* what() const throw();
};

char const *NoOcurrenceException::what() const throw()
{
    return "No find ocurrence";
}

template <typename T>
void easyfind(T& a, int b)
{
    if (std::find(a.begin(), a.end(), b) == a.end())
    {
        throw(NoOcurrenceException());
    }
    cout << "Found ocurrence: " << b << endl;
}

#endif