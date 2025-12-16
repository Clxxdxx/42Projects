
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    cout << "ClapTrap Default created" << endl;
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

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	cout << "ClapTrap copy constructor called" << endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	cout << "Assignment operator for ClapTrap called." << endl;
	this->_name = copy._name;
	this->_hit_points= copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
	return (*this);
}

void ClapTrap::attack(const string& target)
{
	if (_energy_points < 1)
	{
		cout << "ClapTrap " << _name << " hasn't got energy points" << endl;
		return;
	}
	if (_attack_damage < 0)
	{
		cout << "ClapTrap " << _name << " doesn't have enough damage" << endl;
		return ;
	}
	if (_hit_points < 1)
	{
		cout << "ClapTrap " << _name << " has no hit points" << endl;
		return;
	}

	_energy_points--;
	cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points < 1)
	{
		cout << "Can't attack ClapTrap " << _name << " he have 0 hit points" << endl;
		return ;
	}
	if (amount < 1)
	{
		cout << "Amount must be positive" << endl;
		return ;
	}
	_hit_points -= amount;
	if (_hit_points < 1)
	{
		cout << "ClapTrap " << _name << " have died" << endl;
		_hit_points = 0;
		return;
	}
	cout << "ClapTrap" << _name << " have received " << amount << " he has now " << _hit_points << " hit points" << endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount < 1)
	{
		cout << "Amount must be positive" << endl;
		return ;
	}
	if (_energy_points < 1)
	{
		cout << "ClapTrap " << _name << " hasn't got energy points" << endl;
		return;
	}
	if (_hit_points < 1)
	{
		cout << "ClapTrap " << _name << " have died, can't be repaired" << endl;
		_hit_points = 0;
		return;
	}
	_hit_points += amount;
	_energy_points--;
	cout << "ClapTrap " << _name << " have been repaired with " << amount << " extra hit points, he have now " <<_hit_points << " hit points" << endl;
}