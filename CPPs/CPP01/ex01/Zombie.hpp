/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:41:55 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/01 12:29:48 by clalopez         ###   ########.fr       */
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
    Zombie( void );
    Zombie(string name);
    ~Zombie();
    
    void announce( void );
};
Zombie* zombieHorde( int N, string name );

#endif