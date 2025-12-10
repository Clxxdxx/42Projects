/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:04:46 by clalopez          #+#    #+#             */
/*   Updated: 2025/11/28 12:51:15 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
typedef std::string string;

class Zombie {

private:
    string name;

public:
    Zombie(string name);
    ~Zombie();
    
    void announce( void );
    
};

Zombie* newZombie( string name );
void randomChump( string name );
#endif