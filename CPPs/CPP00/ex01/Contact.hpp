/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:56:14 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/27 14:16:59 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
typedef std::string string;
class Contact {

private:
    string firstname;
    string lastname;
    string nickname;
    string phone_number;
    string darkest_secret;

public:
    Contact();
    ~Contact();
    void setFirstname(string firstname);
    void setLastname(string lastname);
    void setNickname(string nickname);
    void setPhoneNumber(string phone_number);
    void setDarkestSecret(string darkest_secret);

    string getFirstname() const;
    string getLastname() const;
    string getNickname() const;
    string getPhoneNumber() const;
    string getDarkestSecret() const;  
};


#endif