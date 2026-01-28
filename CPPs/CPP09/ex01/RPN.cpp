/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:06:23 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/28 14:10:44 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
    {
        this->data = copy.data;
    }
	return (*this);
}

RPN::~RPN()
{
    
}

bool RPN::isValidLine(string line)
{
    int i = 0;
    if (!isdigit(line[i]))
        return false;
    
    while (line[i])
    {    
        if (!isdigit(line[i]) && line[i] != ' ' && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/')
            return false;
        if (line[i] == ' ' && line[i + 1] == ' ')
            return false;
        if (isdigit(line[i]) && isdigit(line[i + 1]))
            return false; 
        i++;
    }
    if (line[i - 1] != '+' && line[i - 1] != '/' && line[i - 1] != '*' && line[i - 1] != '-')
        return false; 
    return true;
}

void RPN::calculate(string line)
{
    int i = 0;
    if (!isValidLine(line))
        throw InvalidLineException();

    while (line[i])
    {
        if (line[i] == ' ')
        {
            i++;
            continue;
        }

        if (isdigit(line[i]))
        {
            data.push(line[i] - '0');
        }
        else
        {
            if (data.size() < 2)
                throw InvalidLineException();

            int b = data.top(); 
            data.pop();
            int a = data.top(); 
            data.pop();

            if (line[i] == '+')
                data.push(a + b);
            else if (line[i] == '-')
                data.push(a - b);
            else if (line[i] == '*')
                data.push(a * b);
            else if (line[i] == '/')
            {
                if (b == 0)
                    throw InvalidLineException();
                data.push(a / b);
            }
        }
        i++;
    }

    if (data.size() != 1)
        throw InvalidLineException();
    cout << "Resultado: " << data.top() << endl;
    
}

void RPN::printVect() const
{
    std::stack<int> aux = this->data;
    int index = 0;

    while (!aux.empty())
    {
        std::cout << index << ": " << aux.top() << std::endl;
        aux.pop();
        index++;
    }
}


char const *RPN::InvalidLineException::what() const throw()
{
    return "Error: Invalid line ";
}