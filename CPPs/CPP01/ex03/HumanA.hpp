/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:29:14 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/02 14:48:54 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
class HumanA {

private:
    string _name;
    Weapon &_weapon;
public:
    HumanA(string name, Weapon &weapon);
    ~HumanA();
    
    void attack();
}; 





#endif