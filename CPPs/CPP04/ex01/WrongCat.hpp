/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:29:20 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 12:29:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class WrongCat: public WrongAnimal {

public:
    WrongCat(void);
	WrongCat(WrongCat const &copy);
	~WrongCat(void);
    WrongCat &operator=(WrongCat const &copy);

    void makeSound() const;
};




#endif