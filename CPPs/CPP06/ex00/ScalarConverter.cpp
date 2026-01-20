/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:17:46 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/09 11:36:39 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

void ScalarConverter::convert(const string &literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];

        cout << "char: '" << c << "'" << endl;
        cout << "int: " << static_cast<int>(c) << endl;
        cout << "float: " << std::fixed << std::setprecision(1)
             << static_cast<float>(c) << "f" << endl;
        cout << "double: " << std::fixed << std::setprecision(1)
             << static_cast<double>(c) << endl;

        return;
    }

    char* end;
    double value = std::strtod(literal.c_str(), &end);
    if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
    {
        cout << "char: impossible" << endl;
        cout << "int: impossible" << endl;
        cout << "float: impossible" << endl;
        cout << "double: impossible" << endl;
        return;
    }

    if (std::isnan(value) || std::isinf(value))
        cout << "char: impossible" << endl;
    else if (value < 0 || value > 127)
        cout << "char: impossible" << endl;
    else if (value < 32 || value == 127)
        cout << "char: Non displayable" << endl;
    else
        cout << "char: '" << static_cast<char>(value) << "'" << endl;

    if (value < static_cast<double>(std::numeric_limits<int>::min()) ||
        value > static_cast<double>(std::numeric_limits<int>::max()) ||
        std::isnan(value) || std::isinf(value))
        cout << "int: impossible" << endl;
    else
        cout << "int: " << static_cast<int>(value) << endl;

    cout << "float: " << std::fixed << std::setprecision(1)
         << static_cast<float>(value) << "f" << endl;

    cout << "double: " << std::fixed << std::setprecision(1)
         << value << endl;
}

