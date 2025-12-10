/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:59:15 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/09 12:05:21 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
    if (argc != 1)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    
    Zombie* z1 = newZombie("Maria");
    Zombie* z2 = newZombie("Claudio");
    Zombie* z3 = newZombie("Jose");
    
    z1->announce();
    delete z1;

    z2->announce();
    delete z2;

    
    z3->announce();
    delete z3;
    
    randomChump("Adios");
}