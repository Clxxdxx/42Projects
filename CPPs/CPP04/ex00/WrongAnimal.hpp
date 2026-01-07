/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:21:32 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 12:23:59 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongAnimal_HPP
#define WRONGWrongAnimal_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class WrongAnimal {

protected:
    string _type;
public:
    WrongAnimal(void);
	WrongAnimal(string type);
	WrongAnimal(WrongAnimal const &copy);
	~WrongAnimal(void);
    WrongAnimal &operator=(WrongAnimal const &copy);

    string getType() const;

    void makeSound() const;
};




#endif