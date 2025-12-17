#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    cout << "ScavTrap Default created with " << _hit_points << " hit points, " << _energy_points << " energy points and " << _attack_damage << " attack damage" << endl;

}

FragTrap::FragTrap(const string &name): ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    cout << "FragTrap " << name << " created with " << _hit_points << " hit points, " << _energy_points << " energy points and " << _attack_damage << " attack damage" << endl;
  
}

FragTrap::~FragTrap()
{
    cout << "FragTrapp" << _name << " have been destroyed" << endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    cout << "FragTrap copy construcotr called" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    ClapTrap::operator=(copy);
    cout << "FragTrapp copy operator called" << endl;
    return *this;
}

void FragTrap::highFivesGuys()
{
    cout << "FragTrap " << _name << " request a positive high five" <<endl;
}