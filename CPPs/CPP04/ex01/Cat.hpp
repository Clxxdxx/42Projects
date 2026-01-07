/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:24:57 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 12:25:06 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class Cat: public Animal {
private:
    Brain* brain;

public:
    Cat(void);
	Cat(Cat const &copy);
	~Cat(void);
    Cat &operator=(Cat const &copy);

    void makeSound() const;
};




#endif