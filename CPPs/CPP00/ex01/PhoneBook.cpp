/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:56:20 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/10 15:21:59 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
PhoneBook::PhoneBook() : current_id(0), nb_contacts(0)
{
}
PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;
	string	darkest_secret;

    if (this->current_id == 8)
	{
        this->current_id = 0;
	}
	std::cout << "Type a name:" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "Type a last name:" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "Type a nickname:" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Type a phone number:" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "Type a dark secret:" << std::endl;
	std::getline(std::cin, darkest_secret);
	if (first_name.empty() || last_name.empty() || nickname.empty()
		|| phone_number.empty() || darkest_secret.empty())
	{
		std::cout << "\033[31mCan't save the contact, please fill all fields\033[0m" << std::endl;
	}
    else
    {
        this->contacts[this->current_id].setFirstname(first_name);
        this->contacts[this->current_id].setLastname(last_name);
        this->contacts[this->current_id].setNickname(nickname);
        this->contacts[this->current_id].setPhoneNumber(phone_number);
        this->contacts[this->current_id].setDarkestSecret(darkest_secret);
        this->current_id++;
        std::cout << "The contact has been added succesfully" << std::endl; 
		if (nb_contacts < 8)
			nb_contacts++;
    }
}

void PhoneBook::search_contact()
{
	int i = 0;
	string str_index;
	string firstname;
	string lastname;
	string nickname;
	int index;
	
	if (this->nb_contacts == 0)
	{
		std::cout << "\033[31mNot contacts available\033[0m" << std::endl;
		return ;
	}
	
    std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < this->nb_contacts)
	{
		firstname = this->contacts[i].getFirstname();
		lastname = this->contacts[i].getLastname();
		nickname = this->contacts[i].getNickname();
		if (firstname.length() > 9)
			firstname = firstname.substr(0, 9) + ".";
		if (lastname.length() > 9)
			lastname = lastname.substr(0, 9) + ".";
		if (nickname.length() > 9)
			nickname = nickname.substr(0, 9) + ".";		
		std::cout << std::setw(5) << i << "|";
		std::cout << std::setw(10) << firstname << "|";
		std::cout << std::setw(10) << lastname << "|";
		std::cout << std::setw(10) << nickname;
		std::cout << std::endl;
		i++;
	}
	std::cout << "Type index for more details " << std::endl;
	std::getline(std::cin, str_index);
	index = atoi(str_index.c_str());
	if ((index == 0 && str_index[0] != '0') || (index > 7 || index < 0)) 
	{
		std::cout << "Please, enter a valid digit" << std::endl;
		return ;
	}
	else if (index >= this->nb_contacts)
	{
		std::cout << "Contact not found" << std::endl;
		return ;
	}
	else
	{
		std::cout << "Firstname: " << this->contacts[index].getFirstname() << std::endl;
		std::cout << "Lastname: " << this->contacts[index].getLastname() << std::endl;
		std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
	}
}
