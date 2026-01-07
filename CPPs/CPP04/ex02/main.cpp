/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:31:46 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 16:04:46 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	//const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongCat();

	cout << "========================================" << endl;
	
	//meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();
	
	cout << "========================================" << endl;
	
	//delete meta;
	delete i;
	delete j;
	delete k;
	
}