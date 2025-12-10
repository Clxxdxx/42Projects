/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:06:24 by clalopez          #+#    #+#             */
/*   Updated: 2025/12/04 14:27:15 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

typedef std::string string;

string replace_file(string line, string search, string replace)
{
    int i = 0;
    size_t pos;
    string help = "";
    while (line[i])
    {
        pos = line.find(search, i);
        if (pos != std::string::npos)
        {
            help += line.substr(i, pos - i);
            help += replace;
            i = pos + search.length();
        }
        else
        {
            help += line[i];
            i++;   
        }
    }
    return help;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: too many arguments" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "Error al abrir " << argv[1]  << std::endl;
        return 1;
    }
    
    string search = argv[2];
    string replace = argv[3];
    
    std::ofstream dest("new_file.txt");
    string line;
    while (std::getline(file, line))
    {
        line = replace_file(line, search, replace);
        dest << line << std::endl;
    }
    file.close();
    dest.close();

    return 0;
}