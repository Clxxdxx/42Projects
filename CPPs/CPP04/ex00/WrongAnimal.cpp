#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{

}

WrongAnimal::WrongAnimal(string type)
{
    _type = type;
    cout << "WrongAnimal " << type << " have been created" << endl;
}

WrongAnimal::~WrongAnimal()
{
    cout << "WrongAnimal " << _type << " have been destroyed" << endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	cout << "WrongAnimal copy constructor called" << endl;
	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	cout << "Assignment operator for WrongAnimal called." << endl;
	this->_type = copy._type;
	return (*this);
}

string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
    cout << "WrongAnimal makes a generic sound" << endl;
}
