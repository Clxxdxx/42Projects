/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:46:24 by clalopez          #+#    #+#             */
/*   Updated: 2026/02/10 12:05:48 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque> 
#include <vector>
#include <fstream>
typedef std::string string;
using std::cout;
using std::endl;

class PmergeMe
{
    private:
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& pm);
        PmergeMe& operator=(const PmergeMe& pm);
        ~PmergeMe();

        template <typename Container>
        typename Container::iterator
        binaryInsert( Container &c, typename Container::iterator end, int value);
        
        template <typename Container>
        void stepOne(Container &container);

        template <typename Container>
        void stepTwo(Container &container);
        
        template <typename Container>
        void sort(Container& container);
        
        class NumNegativeException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NumTooLargeException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NoNumValueException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

inline size_t jacobsthal(size_t n)
{
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;

    size_t a = 0;
    size_t b = 1;
    size_t c;

    for (size_t i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}


template <typename Container>
void printCont(Container &container)
{
    for (size_t i = 0; i < container.size(); ++i)
        cout << container[i] << " ";
    cout << endl;
}

template <typename Container>
typename Container::iterator 
PmergeMe::binaryInsert(Container &container, typename Container::iterator end, int value)
{
    typename Container::iterator left = container.begin();
    typename Container::iterator right = end;

    while (left < right)
    {
        typename Container::iterator mid = left + (right - left) / 2;
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    return container.insert(left, value);
}


template <typename Container>
void PmergeMe::stepOne(Container &container)
{
    //ordenar cada par
    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
    }

    //ordenar los pares segun el maximo
    for (size_t i = 1; i < container.size(); i += 2)
    {
        size_t j = i;
        while (j > 1 && container[j] < container[j - 2])
        {
            std::swap(container[j], container[j - 2]);
            std::swap(container[j- 1], container[j - 3]);
            j -= 2;
        }
    }
}

template <typename Container>
void PmergeMe::stepTwo(Container &container)
{
    Container main;
    Container pend;
    bool no_participate = false;
    int num_no_participate = 0;

    //Separar pares
    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        pend.push_back(container[i]);
        main.push_back(container[i + 1]);
    }

    if (container.size() % 2)
    {
        no_participate = true;
        num_no_participate = container.back();
    }
    
    //Insertar primer pendiente al principio
    if (!pend.empty())
        main.insert(main.begin(), pend[0]);

    size_t pendIndex = 1;
    size_t jacobIndex = 3;

    //Jacobo
    while (pendIndex < pend.size())
    {
        size_t jac = jacobsthal(jacobIndex);
        size_t endRange = std::min(jac, pend.size());
        
        for (size_t i = endRange; i > pendIndex && i > 0; --i)
            binaryInsert(main, main.end(), pend[i - 1]);
        
        pendIndex = endRange;
        ++jacobIndex;
    }
    
    if (no_participate)
        binaryInsert(main, main.end(), num_no_participate);
    
    container = main;
}

template <typename Container>
void PmergeMe::sort(Container &container)
{
    stepOne(container);
    stepTwo(container);
}


#endif