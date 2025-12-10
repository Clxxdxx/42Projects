/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:56:24 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/27 12:29:55 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    
}
Contact::~Contact()
{
    
}

string Contact::getFirstname() const
{
    return this->firstname;
}

string Contact::getLastname() const
{
    return this->lastname;
}

string Contact::getNickname() const
{
    return this->nickname;
}

string Contact::getPhoneNumber() const
{
    return this->phone_number;
}

string Contact::getDarkestSecret() const
{
    return this->darkest_secret;
}

void Contact::setFirstname(string firstname)
{
    this->firstname = firstname;
}

void Contact::setLastname(string lastname)
{
    this->lastname = lastname;
}

void Contact::setNickname(string nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(string phone_number)
{
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}