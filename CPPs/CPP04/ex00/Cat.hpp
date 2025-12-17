


#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class Cat: public Animal {

public:
    Cat(void);
	Cat(Cat const &copy);
	~Cat(void);
    Cat &operator=(Cat const &copy);

    void makeSound() const;
};




#endif