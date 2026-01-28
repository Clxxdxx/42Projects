/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:57:08 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/23 16:09:13 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int open_files(char *name)
{
    std::ifstream file(name);
    if (!file.is_open())
    {
        std::cout << "Error al abrir " << name  << std::endl;
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Error: could not open file" << endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (open_files(argv[1]) == 1)
        return 1;
         
    Bitcoin btc;
    btc.loadData("data.csv");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        try
        {
            btc.parseLine(line);
        }
        catch (Bitcoin::DateFormatException &e)
        {
            std::cout << e.what() << " => " << btc.getDate(line) << std::endl;
        }
        catch (std::exception &e)
        {
            cout << e.what() << endl;
        }
    }
    file.close();
    return 0;
}
