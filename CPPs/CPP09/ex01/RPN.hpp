/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:06:26 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/28 14:04:26 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack> 
#include <iomanip>
#include <fstream>
typedef std::string string;
using std::cout;
using std::endl;

class RPN
{
    private:
        std::stack<int> data;
        bool isValidLine(string line);
        
    public:
        RPN();
        ~RPN();
        RPN(RPN const &copy);
        RPN &operator=(RPN const &copy);
        
        void calculate(string line);
        void printVect() const;

        class InvalidLineException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    
};





#endif
