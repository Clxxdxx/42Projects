


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class ClapTrap {

protected:
    string _name;
    int _hit_points;
    int _energy_points;
    int _attack_damage;

public:
    ClapTrap(void);
	ClapTrap(string name);
	ClapTrap(ClapTrap const &copy);
	~ClapTrap(void);
    ClapTrap &operator=(ClapTrap const &copy);

    void attack(const string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};




#endif