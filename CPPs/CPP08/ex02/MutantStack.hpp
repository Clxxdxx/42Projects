/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:44:55 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/16 14:13:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
typedef std::string string;
using std::cout;
using std::endl;

template <class T>
class MutantStack : public std::stack<T> {
        
    public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin(){
            return this->c.begin();
    }
    
    iterator end(){
            return this->c.end();
    }
};



#endif