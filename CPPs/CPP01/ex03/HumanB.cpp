/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:28:35 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/09 12:41:21 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(string name): _weapon(NULL)
{
    this->_name = name;
    std::cout << "Human B with the name: " << name;
    std::cout << " He hasn't weapon" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "Human B: " << _name << " have been destroyed " << std::endl; 
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    if (this->_weapon)
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << _name << " can't attack" << std::endl;
}