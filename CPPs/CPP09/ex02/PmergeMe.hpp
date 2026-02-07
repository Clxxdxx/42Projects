/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:19:02 by clalopez          #+#    #+#             */
/*   Updated: 2026/02/07 12:58:24 by clalopez         ###   ########.fr       */
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
        void stepOne(Container &container);

        template <typename Container>
        void stepTwo(Container &container);
        
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
void PmergeMe::stepOne(Container &container)
{
    int total_pairs = 0;
    int r_lvl = 1;
    int size_pairs = 2;


    while (1)
    {
        total_pairs = container.size() / size_pairs;
        //cout << "Total de parejas: " << total_pairs << endl;
        if (total_pairs <= 1)
            break;
        typename Container::iterator it_block_start = container.begin();
        while (std::distance(it_block_start, container.end()) >= size_pairs)
        {
            typename Container::iterator it_mid = it_block_start;
            std::advance(it_mid, size_pairs / 2);

            typename Container::iterator it_block_end = it_block_start;
            std::advance(it_block_end, size_pairs);

            int max_left = *it_block_start;
            typename Container::iterator it = it_block_start;
            while (it != it_mid)
            {
                if (*it > max_left)
                    max_left = *it;
                ++it;
            }
            
            int max_right = *it_mid;
            it = it_mid;
            
            while (it != it_block_end)
            {
                if (*it > max_right)
                    max_right = *it;
                ++it;
            }
            

            if (max_left > max_right)
            {
                typename Container::iterator it_l = it_block_start;
                typename Container::iterator it_r = it_mid;
                int i = 0;
                while (i < size_pairs / 2)
                {
                    std::swap(*it_l, *it_r);
                    ++i;
                    ++it_l;
                    ++it_r;
                }
                
            }

            std::advance(it_block_start, size_pairs);
        }
        
        
        
       
       //cout << "Tamaño de las parejas: " << size_pairs << endl;
       r_lvl++;
       size_pairs = my_pow(2, r_lvl);
       //cout << "========" << endl;     
    }
}
template <typename Container>
void PmergeMe::stepTwo(Container &container)
{
    //cout << "====================================" << endl;
    int total_pairs = 0;
    int r_lvl = 1;
    int size_pairs = 2;

    while (1)
    {
        total_pairs = container.size() / size_pairs;
        if (total_pairs <= 1)
            break;       
        r_lvl++;
        size_pairs = my_pow(2, r_lvl);
    }

    
    
    Container main;
    Container pend;
    Container nonPart;
    int j = 0;
    int k = size_pairs * 2;
    cout << "Recursion level: " << r_lvl << endl;
    for (size_t i = 0; i < container.size(); i++)
    {
        if ((int)i >= size_pairs * total_pairs)
        {
            nonPart.push_back(container[i]);
            j++;
        }
        else if (k > 0)
        {
            main.push_back(container[i]);
            k--;
        }
        else if (k < 4)
        {
            pend.push_back(container[i]);
            k++;
        }     
    }
    

    if (pend.empty())
        main.insert(main.end(), nonPart.begin(), nonPart.end());
    
    cout << "Non part: " << endl; 
    printCont(nonPart);

    cout << "Pend: " << endl; 
    printCont(pend);

    cout << "Main: " << endl; 
    printCont(main);
}

#endif