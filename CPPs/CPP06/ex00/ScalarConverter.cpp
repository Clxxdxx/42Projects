#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

void ScalarConverter::convert(const string &literal)
{
    char* end;
    double value = std::strtod(literal.c_str(), &end);

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
