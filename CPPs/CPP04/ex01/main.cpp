#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	/*const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongCat();

	i->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;*/
	
	const int num = 6;
    Animal* animals[num];

    for (int i = 0; i < num; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < num; i++)
        delete animals[i];

    return 0;
	//delete[] animals;
	
}