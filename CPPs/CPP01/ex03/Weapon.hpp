/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:29:17 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/02 12:03:46 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <iostream>
typedef std::string string;

class Weapon {

private:
    string _type;
public:
    Weapon(string type);
    ~Weapon();

    const string& getType();
    void setType(string type);
};





#endif