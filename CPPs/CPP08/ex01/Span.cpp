/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:10:11 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/19 12:49:16 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

Span::Span(): N(0)
{
    
}

Span::Span(unsigned int n): N(n)
{
    
}

Span::Span(Span const &copy)
{
    *this = copy;
}

Span &Span::operator=(Span const &copy)
{
    this->N = copy.N;
    this->numbers = copy.numbers;
    return *this;
}

Span::~Span()
{
    
}

void Span::addNumber(int number)
{
    if (numbers.size() >= N)
        throw std::runtime_error("Many numbers");
    
    numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");
    
    std::vector<int> tmp(numbers);
    std::sort(tmp.begin(), tmp.end());

    int aux = tmp[1]- tmp[0];
    int diff;
    size_t i = 2;
    while (i < tmp.size())
    {
        diff = tmp[i] - tmp[i - 1];
        if (diff < aux)
            aux = diff;
        
        i++;
    }
    return aux;
}

int  Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

void Span::printVec() const
{
    unsigned long i = 0;
    while (i < numbers.size())
    {
        cout << numbers[i] << endl;
        i++;
    }
}

void Span::addRange(int start, unsigned int count)
{
    unsigned int i = 0;

    while (i < count)
    {
        addNumber(start + i);
        i++;
    }
}
