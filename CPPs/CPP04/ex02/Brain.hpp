/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:31:18 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/22 12:31:19 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;


class Brain {

protected:
    string ideas[100];
public:
    Brain(void);
	Brain(Brain const &copy);
	~Brain(void);
    Brain &operator=(Brain const &copy);
};




#endif