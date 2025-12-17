


#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete brain;
    cout << "Cat " << _type << " have been destroyed" << endl;
}

Cat::Cat(Cat const &copy): Animal(copy)
{
	cout << "Cat copy constructor called" << endl;
	*this = copy;
}

Cat	&Cat::operator=(const Cat &copy)
{
	cout << "Assignment operator for Cat called." << endl;
	this->_type = copy._type;
	brain = new Brain(*copy.brain);
	return (*this);
}

void Cat::makeSound() const
{
    cout << _type << " makes miau" << endl;
}