/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:19:02 by clalopez          #+#    #+#             */
/*   Updated: 2026/02/05 16:49:21 by clalopez         ###   ########.fr       */
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
        PmergeMe(){};
        PmergeMe(const PmergeMe& pm);
        PmergeMe& operator=(const PmergeMe& pm);
        ~PmergeMe(){};
        
        template <typename Container>
        void stepOne(Container &container);
        
        template <typename Container>
        void sort(Container& container); 
};

inline int my_pow(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

template <typename Container>
void printCont(Container &container)
{
    for (size_t i = 0; i < container.size(); ++i)
        cout << container[i] << " ";
    cout << endl;
}

template <typename Container>
void PmergeMe::stepOne(Container &container)
{
    int total_pairs = 0;
    int r_lvl = 1;
    int size_pairs = 2;


    while (1)
    {
        total_pairs = container.size() / size_pairs;
        cout << "Total de parejas: " << total_pairs << endl;
        if (total_pairs <= 1)
            break;
                typename Container::iterator it_block_start = container.begin();
        while (std::distance(it_block_start, container.end()) >= size_pairs)
        {
            // Iterador al medio del bloque
            typename Container::iterator it_mid = it_block_start;
            std::advance(it_mid, size_pairs / 2);

            // Iterador al final del bloque
            typename Container::iterator it_block_end = it_block_start;
            std::advance(it_block_end, size_pairs);

            // Encontrar máximo en la primera mitad
            int max_left = *it_block_start;
            typename Container::iterator it = it_block_start;
            for (; it != it_mid; ++it)
                if (*it > max_left)
                    max_left = *it;

            // Encontrar máximo en la segunda mitad
            int max_right = *it_mid;
            it = it_mid;
            for (; it != it_block_end; ++it)
                if (*it > max_right)
                    max_right = *it;

            // Intercambiar bloques completos si es necesario
            if (max_left > max_right)
            {
                typename Container::iterator it_l = it_block_start;
                typename Container::iterator it_r = it_mid;
                for (int i = 0; i < size_pairs / 2; ++i, ++it_l, ++it_r)
                    std::swap(*it_l, *it_r);
            }

            // Avanzar al siguiente bloque
            std::advance(it_block_start, size_pairs);
        }
        
        
        
       
       cout << "Tamaño de las parejas: " << size_pairs << endl;
       r_lvl++;
       size_pairs = my_pow(2, r_lvl);
       cout << "========" << endl;     
    }
    
    
}

#endif