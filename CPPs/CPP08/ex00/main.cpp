/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:41:55 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/19 12:43:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    
    try
    {
        easyfind(arr, 6);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }

    cout << "====================" << endl;
     
    std::vector<int> arr2;
    arr2.push_back(0);
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(4);
    
    try
    {
        easyfind(arr2, 2);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    return 0;
}