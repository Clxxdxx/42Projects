/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:56:17 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/28 12:18:22 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <cctype> 
#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int current_id;
    int nb_contacts;

public:
    PhoneBook();
    ~PhoneBook();
    void add_contact();
    void search_contact();

};




#endif