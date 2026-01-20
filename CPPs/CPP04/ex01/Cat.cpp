/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:24:52 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/23 11:56:15 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (this == &copy)
		return *this;
	cout << "Assignment operator for Cat called." << endl;
	this->_type = copy._type;
	delete brain;
	brain = new Brain(*copy.brain);
	return (*this);
}

void Cat::makeSound() const
{
    cout << _type << " makes miau" << endl;
}