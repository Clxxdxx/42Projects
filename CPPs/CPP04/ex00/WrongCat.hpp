


#ifndef WrongCat_HPP
#define WrongCat_HPP
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class WrongCat: public WrongAnimal {

public:
    WrongCat(void);
	WrongCat(WrongCat const &copy);
	~WrongCat(void);
    WrongCat &operator=(WrongCat const &copy);

    void makeSound() const;
};




#endif