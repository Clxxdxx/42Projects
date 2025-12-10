/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:19:51 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/10 15:20:39 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>
#include <iostream>

int	main(void)
{
	PhoneBook PhoneBook;
	string line;
	std::cout << "Welcome to PhoneBook!" << std::endl;

	while (1)
	{
		std::cout << "\033[32mType ADD, SEARCH or EXIT\033[0m" << std::endl;

		if (!std::getline(std::cin, line))
        {
            std::cout << "\n\033[33mExiting PhoneBook.\033[0m" << std::endl;
            break;
        }
		if (line == "ADD")
			PhoneBook.add_contact();
		else if (line == "SEARCH")
			PhoneBook.search_contact();
		else if (line == "EXIT")
			return (0);
		else
			std::cout << "\033[31mInvalid option\033[0m" << std::endl;
	}
	return (0);
}