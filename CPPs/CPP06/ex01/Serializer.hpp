


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

typedef std::string string;
using std::cout;
using std::endl;

class Serializer {
private:
    Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif