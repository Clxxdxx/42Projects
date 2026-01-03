


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