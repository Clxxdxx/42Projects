/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:27:54 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/04 12:12:51 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    
}

Harl::~Harl()
{
	
}

void Harl::debug()
{
    cout << MAGENTA << "[DEBUG]" << DEFAULT;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void Harl::info()
{
    cout << GRAY << "[INFO]" << DEFAULT;
	cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << endl;
}

void Harl::warning()
{
    cout << YELLOW << "[WARNING]" << DEFAULT;
    cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << endl;
}

void Harl::error()
{
    cout << RED << "[ERROR]" << DEFAULT;
    cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void Harl::complain(string level)
{
    string levels[4] = {"debug", "info", "warning", "error"};
    void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
        {
           (this->*ptr[i])();
           return ;
        } 
        i++;
    }
    cout << "Error" << endl;
    
}
