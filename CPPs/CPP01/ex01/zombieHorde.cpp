/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:41:39 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/01 12:44:27 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, string name )
{
    if (N < 1)
    {
       std::cout << "Can't create zombies, number invalid\n";
       return 0;
    }
    Zombie *horde;
   
    horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
      new (&horde[i]) Zombie(name);
    }
    return horde;
}