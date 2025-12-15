#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trapA("Pepe");
	ClapTrap	trapB("Luis");


	trapA.attack("Toni");
	trapB.takeDamage(2);
	trapB.attack("Maria");
	trapA.takeDamage(5);
	trapB.attack("Maria");
	trapA.takeDamage(2);

	trapA.attack("Toni");
	trapB.takeDamage(2);
	trapB.attack("Maria");

	trapA.takeDamage(5);
	trapA.attack("Toni");
	trapA.beRepaired(1);
	
	trapB.attack("Maria");
	trapA.takeDamage(2);

	trapB.attack("Maria");
	trapA.takeDamage(2);

	trapB.attack("Maria");
	trapA.takeDamage(2);
	
	trapB.attack("Maria");
	trapA.takeDamage(2);

	trapB.attack("Maria");
	trapA.takeDamage(2);
	
	trapB.beRepaired(3);
	trapB.beRepaired(3);
	trapB.beRepaired(3);
	trapA.beRepaired(3);
	return (0);
}