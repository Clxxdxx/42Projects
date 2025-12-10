/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:21:35 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/28 12:09:07 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype> 

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    std::string str;
    int letter;
    int len;
    int i = 1;
    while (argv[i] != NULL)
    {
        str = argv[i];
        len = str.size();
        letter = 0;
        while (letter < len)
        {
            str[letter] = toupper(str[letter]);
            letter++;
        }
        std::cout << str;
        i++;
    }
    std::cout << std::endl;
    return 1;
}
