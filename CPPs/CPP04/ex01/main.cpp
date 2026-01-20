/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:25:18 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/23 11:55:18 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const int num = 6;
    Animal* animals[num];

    for (int i = 0; i < num; i++)
    {
		cout << "[" << i << "]";
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
		cout << endl;
    }

	cout << "========================================================" << endl;

    for (int i = 0; i < num; i++)
	{
		cout << "[" << i << "]";
        delete animals[i];
		cout << endl;
	}
	
	cout << "========================================================" << endl;

	Dog* a = new Dog();
    Dog* b = new Dog();

    *a = *b;

    delete a;
    delete b;

    return 0;
}