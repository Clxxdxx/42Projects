/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:25:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 12:25:15 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class Dog: public Animal {
private:
    Brain* brain;

public:
    Dog(void);
	Dog(Dog const &copy);
	~Dog(void);
    Dog &operator=(Dog const &copy);

    void makeSound() const;
};




#endif