


#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class Animal {

protected:
    string _type;
public:
    Animal(void);
	Animal(string type);
	Animal(Animal const &copy);
	virtual ~Animal(void);
    Animal &operator=(Animal const &copy);

    string getType() const;

    virtual void makeSound() const;
};




#endif