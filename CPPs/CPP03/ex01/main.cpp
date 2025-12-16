#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main(void)
{
    cout << "CREATION" << endl;
    ClapTrap a("Pepe");
    ClapTrap b("Luis");

    cout << "\nBASIC ATTACKS" << endl;
    a.attack("Luis");
    b.takeDamage(2);

    b.attack("Pepe");
    a.takeDamage(5);

    cout << "\nREPAIR" << endl;
    a.beRepaired(3);

    cout << "\nMULTIPLE ATTACKS" << endl;
    for (int i = 0; i < 5; i++)
    {
        b.attack("Pepe");
        a.takeDamage(2);
    }

    cout << "\nKILL PEPE" << endl;
    a.takeDamage(100);
    a.attack("Luis");
    a.beRepaired(5);

    cout << "\nENERGY" << endl;
    ClapTrap c("EnergyTest");
    for (int i = 0; i < 12; i++)
	{
		c.attack("Nobody");
	}
    cout << "\nREPAIR" << endl;
    b.beRepaired(3);
    b.beRepaired(3);

    cout << "\nSCAVTRAP TEST" << endl;

    ScavTrap d("ScavTrap");
    d.attack("Joselito");
    d.guardGate();

    cout << "\nDESTRUCTORs" << endl;
    return 0;
}
