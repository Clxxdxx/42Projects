/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:45:06 by clalopez          #+#    #+#             */
/*   Updated: 2026/02/09 15:47:08 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::~PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

char const *PmergeMe::NoNumValueException::what() const throw()
{
    return "Error: Non numeric input ";
}

char const *PmergeMe::NumNegativeException::what() const throw()
{
    return "Error: Negative number";
}

char const *PmergeMe::NumTooLargeException::what() const throw()
{
    return "Error: Number too large";
}