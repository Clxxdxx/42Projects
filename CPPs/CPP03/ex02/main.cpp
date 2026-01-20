/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:33:49 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 10:33:50 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

    ScavTrap d("Amador");
    d.attack("Joselito");
    d.guardGate();

    cout << "\nFRAGTRAP TEST" << endl;
    FragTrap e("Maria");
    e.highFivesGuys();

    cout << "\nDESTRUCTORs" << endl;
    return 0;
}
