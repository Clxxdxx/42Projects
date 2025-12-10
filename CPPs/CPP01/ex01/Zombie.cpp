/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:41:52 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/01 12:19:28 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( )
{
}

Zombie::Zombie(string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << ": have been destroyed\n";
}

void Zombie::announce(void)
{
    std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}
