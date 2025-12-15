
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{

}

ClapTrap::ClapTrap(string name): _hit_points(10), _energy_points(10) ,_attack_damage(0)
{
    cout << "ClapTrap " << name << " created with 10 hit points, 10 energy points and 0 attack damage" << endl;
    _name = name;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap " << _name << " have been destroyed" << endl;
}

void ClapTrap::attack(const string& target)
{
    if (_energy_points < 1)
    {
        cout << "ClapTrap " << _name << " doesn't have energy points" << endl;
        return ;
    }
    cout << "Claptrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount < 1)
    {
        cout << "Amount can't be negative" << endl;
        return;
    }
    if (_hit_points < 1)
    {
        cout << "ClapTrap " << _name << " doesn't have live points" << endl;
        return ;
    }
    cout << "Claptrap " << _name << " have received " << amount << " damage " << endl;
    _hit_points -= amount;
    if (_hit_points < 1)
    {
        cout << "ClapTrap " << _name << " have died" << endl;
        return ;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount < 1)
    {
        cout << "Amount can't be negative" << endl;
        return;
    }
    if (_energy_points < 1)
    {
        cout << "ClapTrap " << _name << " doesn't have energy points" << endl;
        return ;
    }
    _hit_points += amount;
    _energy_points--; 
    cout << "ClapTrap " << _name << " have been repaired, now " << _hit_points << " hit points and " << _energy_points << " energy points" << endl;
}