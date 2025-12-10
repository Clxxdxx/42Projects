/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:41:49 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/04 11:04:51 by clalopez         ###   ########.fr       */
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
	int N = 12;
	Zombie *horde;
	horde = zombieHorde(N, "Claudio");
	for (int i = 0; i < N; i++)
	{
		std::cout << "Pos: " << i << ", announce: ";
		horde[i].announce();
	}

	delete[] horde;

	return (0);
}