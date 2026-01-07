/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:22:16 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 16:01:48 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
Brain::Brain()
{

}

Brain::~Brain()
{
    cout << "Brain have been destroyed" << endl;
}

Brain::Brain(Brain const &copy)
{
	cout << "Brain copy constructor called" << endl;
	*this = copy;
}

Brain	&Brain::operator=(const Brain &copy)
{
    if (this == &copy)
		return ;
	cout << "Assignment operator for Brain called." << endl;
	int i = 0;
    while (i < 100)
    {
        this->ideas[i] = copy.ideas[i];
        i++;
    }
	return (*this);
}
