/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:45:10 by clalopez          #+#    #+#             */
/*   Updated: 2026/02/11 15:18:38 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <ctime>
bool parseInput(char **arg, int *arr, int size)
{
    int i = 1;
    long num;

    
    try
    {
        while (i <= size)
        {
            char *end;
            num = std::strtol(arg[i], &end, 10);
    
            if (*end != '\0')
                throw PmergeMe::NoNumValueException();
            if (num > INT_MAX)
                throw PmergeMe::NumTooLargeException();
            if (num < 0)
                throw PmergeMe::NumNegativeException();
            arr[i - 1] = num;
            i++;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Error: Use < ./PmergeMe 8 9 7 5 19 4 1 >" << endl;
        return 1;
    }
    PmergeMe pm;

    int size = argc - 1;
    
    int *arr = new int[size];
    if (!parseInput(argv, arr, size))
        return 1;
    std::vector<int> vec;
    std::deque<int> deq;
    for (int i = 0; i < size; i++)
    {
        vec.push_back(arr[i]);
        deq.push_back(arr[i]);
    }
    
    cout << "Before: ";
    printCont(deq);
    
    //Algoritm with deque
    cout << "After: ";
    clock_t ini_deq = clock();
    pm.sort(deq);
    clock_t end_deq = clock();
    printCont(deq);
    
    float time_deq = (float(end_deq - ini_deq) / CLOCKS_PER_SEC) * 10;
    cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << time_deq << " us" << endl;
    
    //Algoritm with vector
    clock_t ini_vec = clock();
    pm.sort(vec);
    clock_t end_vec = clock();
    float time_vec = (float(end_vec - ini_vec) / CLOCKS_PER_SEC) * 10;
    cout << "Time to process a range of " << deq.size() << " elements with std::vector : " << time_vec << " us" << endl;

    delete[] arr;
    return 0;
}
