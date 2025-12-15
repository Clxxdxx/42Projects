


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class ClapTrap {

private:
    string _name;
    int _hit_points;
    int _energy_points;
    int _attack_damage;

public:
    ClapTrap();
    ClapTrap(string name);
    ~ClapTrap();

    void attack(const string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};




#endif