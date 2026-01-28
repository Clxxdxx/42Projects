/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:06:20 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/28 14:22:34 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Error: Use < ./RPN '8 9 * 9 - 9 - 9 - 4 - 1 +'>" << endl;
        return 1;
    }
    
    try
    {
        RPN rpn;
        rpn.calculate(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

