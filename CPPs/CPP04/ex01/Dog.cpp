/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:08:08 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/23 11:55:50 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (this == &copy)
		return *this;
	
	cout << "Assignment operator for Dog called." << endl;
	this->_type = copy._type;
	delete brain;
	brain = new Brain(*copy.brain);
	return (*this);
}

void Dog::makeSound() const
{
    cout << _type << " makes guau" << endl;
}