/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:33:27 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 10:33:28 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    cout << "ScavTrap Default created with " << _hit_points << " hit points, " << _energy_points << " energy points and " << _attack_damage << " attack damage" << endl;
}

ScavTrap::ScavTrap(const string &name) : ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    cout << "ScavTrap " << name << " created with " << _hit_points << " hit points, " << _energy_points << " energy points and " << _attack_damage << " attack damage" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    cout << "ScavTrap copy constructor called" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    ClapTrap::operator=(copy);
    cout << "ScavTrap assignment operator called" << endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    cout << "ScavTrap " << _name << " destroyed" << endl;
}

void ScavTrap::attack(const string &target)
{
    if (_hit_points < 1 || _energy_points < 1)
    {
        cout << "ScavTrap " << _name << " cannot attack" << endl;
        return;
    }
    _energy_points--;
    cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage" << endl;
}

void ScavTrap::guardGate()
{
    cout << "ScavTrap " << _name << " is now in Gate keeper mode." << endl;
}
