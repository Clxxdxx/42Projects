/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:28:41 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/02 14:38:06 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string type): _type(type)
{
    
}

Weapon::~Weapon()
{
    
}

void Weapon::setType(string type)
{
    this->_type = type;
}

const string& Weapon::getType()
{
    return (this->_type);
}
