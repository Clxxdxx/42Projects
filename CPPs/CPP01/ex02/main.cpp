/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:00:24 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/04 14:33:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
    if (argc != 1)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    
    std::cout << "Str memory address: " << &str << std::endl;
    std::cout << "StrPTR memory address: " << stringPTR << std::endl;
    std::cout << "StrREF memory address: " << &stringREF << std::endl;

    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Str value address: " << str << std::endl;
    std::cout << "StrPTR value address: " << *stringPTR << std::endl;
    std::cout << "StrREF value address: " << stringREF << std::endl;

    return 1;
}