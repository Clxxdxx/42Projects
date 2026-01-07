/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:20:56 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 16:02:18 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{

}

Cat::~Cat()
{
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
		return ;
	cout << "Assignment operator for Cat called." << endl;
	this->_type = copy._type;
	return (*this);
}

void Cat::makeSound() const
{
    cout << _type << " makes miau" << endl;
}