/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:20:47 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/23 11:35:32 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	cout << "Animal default have been created" << endl;
}

Animal::Animal(string type)
{
    _type = type;
    cout << "Animal " << type << " have been created" << endl;
}

Animal::~Animal()
{
    cout << "Animal " << _type << " have been destroyed" << endl;
}

Animal::Animal(Animal const &copy)
{
	cout << "Animal copy constructor called" << endl;
	*this = copy;
}

Animal	&Animal::operator=(const Animal &copy)
{
	if (this == &copy)
		return *this;
	cout << "Assignment operator for Animal called." << endl;
	this->_type = copy._type;
	return (*this);
}

string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
    cout << "Animal makes a generic sound" << endl;
}
