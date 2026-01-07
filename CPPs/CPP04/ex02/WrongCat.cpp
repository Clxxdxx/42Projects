


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{

}

WrongCat::~WrongCat()
{
    cout << "WrongCat " << _type << " have been destroyed" << endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal(copy)
{
	cout << "WrongCat copy constructor called" << endl;
	*this = copy;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	if (this == &copy)
		return ;
	cout << "Assignment operator for WrongCat called." << endl;
	this->_type = copy._type;
	return (*this);
}

void WrongCat::makeSound() const
{
    cout << _type << " makes miau" << endl;
}