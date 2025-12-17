
#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class Dog: public Animal {
private:
    Brain* brain;

public:
    Dog(void);
	Dog(Dog const &copy);
	~Dog(void);
    Dog &operator=(Dog const &copy);

    void makeSound() const;
};




#endif