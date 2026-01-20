/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:17:50 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 14:17:53 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;

class ScalarConverter {
private:
    ScalarConverter();
public:
    static void convert(const string &literal);


};

#endif