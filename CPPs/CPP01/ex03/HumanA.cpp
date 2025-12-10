/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:28:32 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/02 14:47:58 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(string name, Weapon &weapon): _name(name), _weapon(weapon)
{
    std::cout << "Human A with the name: " << name;
    std::cout << " have been created with the weapon: " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "Human A: " << _name << " have been destroyed " << std::endl; 
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
