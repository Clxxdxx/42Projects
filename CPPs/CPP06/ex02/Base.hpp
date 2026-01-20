/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:19:04 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/08 12:29:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <string>
#include <stdint.h>

typedef std::string string;
using std::cout;
using std::endl;

class Base {
public:
    virtual ~Base();
};

#endif