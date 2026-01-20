/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:08:15 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/23 11:36:20 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	cout << "Wrong animal default have been created" << endl;
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
    if (this == &copy)
		return *this;
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