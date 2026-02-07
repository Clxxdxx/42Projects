/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudio <claudio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:45:10 by clalopez          #+#    #+#             */
/*   Updated: 2026/02/07 18:11:29 by claudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>

bool parseInput(char **arg, int *arr, int size)
{
    int i = 1;
    long num;

    while (i <= size)
    {
        char *end;
        num = std::strtol(arg[i], &end, 10);

        if (*end != '\0')
        {
            cout << "Error: argumento no numerico" << endl;
            return false;
        }
        if (num > INT_MAX)
        {
            cout << "Error: numero muy grande" << endl;
            return false;
        }
        if (num < 0)
        {
            cout << "Error: numero negativo" << endl;
            return false;
        }

        arr[i - 1] = num;
        i++;
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
    if (deq.size() == 1)
    {
        cout << deq.front() << endl;
        return 1;
    }
    
    

    pm.stepOne(deq);
    pm.stepTwo(deq);
    printCont(deq);
    
    delete[] arr;
    return 0;
}
