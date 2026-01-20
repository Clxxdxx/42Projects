/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:20:01 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/14 12:12:13 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
typedef std::string string;
using std::cout;
using std::endl;

int main()
{
    Array<int> a;
    cout << "Size a: " << a.size() << "\n" << endl;

    Array<int> b(3);
    unsigned int i = 0;
    cout << "b: ";
    while (i < b.size())
    {
        b[i] = i * 10;
        cout << b[i] << " ";
        i++;
    }
    cout << "\nSize b: " << b.size() << endl;
    
    cout << endl;

    Array<int> c(1);
    c[0] = 42;

    cout << "b[0]: " << b[0] << endl;
    cout << "c[0]: " << c[0] << endl;

    Array<int> d;
    d = b;
    d[1] = 99;

    cout << "b[1]: " << b[1] << endl;
    cout << "d[1]: " << d[1] << endl;

    try {
        cout << b[0] << endl;
    } catch (std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
