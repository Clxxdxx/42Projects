


#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
    cout << "Dog " << _type << " have been destroyed" << endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
	cout << "Dog copy constructor called" << endl;
	*this = copy;
}

Dog	&Dog::operator=(const Dog &copy)
{
	cout << "Assignment operator for Dog called." << endl;
	this->_type = copy._type;
	brain = new Brain(*copy.brain);
	return (*this);
}

void Dog::makeSound() const
{
    cout << _type << " makes guau" << endl;
}