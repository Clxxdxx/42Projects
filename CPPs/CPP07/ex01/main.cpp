/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:19:48 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/14 11:12:12 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void sum38(int &i)
{
    i += 38;
    std::cout << i << std::endl;
}
void to_upper(std::string &str)
{
    size_t i = 0;

    while (i < str.length())
    {
        str[i] = std::toupper(str[i]);
        i++;
    }
}


void printString( std::string &str)
{
    std::cout << str << std::endl;
}

int main()
{
    int numbers[] = {1, 2, 3, 4};
    iter(numbers, 2, sum38);

    std::cout << "----" << std::endl;

    std::string words[] = {"hola", "adios", "hello world"};
    iter(words, 2, to_upper);
    iter(words, 3, printString);

    return 0;
}