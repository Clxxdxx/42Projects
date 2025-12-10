/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:29:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/02 14:44:31 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>
#include <iostream>
#include "Weapon.hpp"
class HumanB {

private:
    string _name;
    Weapon *_weapon;
public:
    HumanB(string name);
    ~HumanB();
    
    void setWeapon(Weapon &weapon);
    void attack();
}; 





#endif