/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:56:24 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/23 16:03:26 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
    
}

Bitcoin::~Bitcoin()
{
    
}

Bitcoin &Bitcoin::operator=(Bitcoin const &copy)
{
    if (this != &copy)
    {
        this->data = copy.data;
    }
	return (*this);
}

Bitcoin::Bitcoin(Bitcoin const &copy)
{
    *this = copy;
}

void Bitcoin::loadData(const string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file");

    string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        string date = line.substr(0, 10);
        float value = std::atof(line.substr(11).c_str());
        data[date] = value;
    }
}


string Bitcoin::getDate(string &line)
{
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());

    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << year << "-"
       << std::setw(2) << std::setfill('0') << month << "-"
       << std::setw(2) << std::setfill('0') << day;
    return ss.str();
}

string Bitcoin::checkDate(string &line)
{
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());

    if (day < 1)
        throw Bitcoin::DateFormatException();
    if (month == 2 && day > 28)
        throw Bitcoin::DateFormatException();
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw Bitcoin::DateFormatException();
    else if (day > 31)
        throw Bitcoin::DateFormatException();
    if (month < 1 || month > 12)
        throw Bitcoin::DateFormatException();

    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << year << "-"
       << std::setw(2) << std::setfill('0') << month << "-"
       << std::setw(2) << std::setfill('0') << day;
    return ss.str();
}

float Bitcoin::checkValue(string &line)
{
    string strVal = line.substr(13).c_str();
    if (strVal[0] == '.')
        throw Bitcoin::LineFormatException();
    

    size_t i = 0;
    int count = 0;
    while (i < strVal.length())
    {
        if (strVal[i] == '.')
            count++;
        if ((!isdigit(strVal[i]) && strVal[i] != '.') || count > 1)
        {
            throw Bitcoin::LineFormatException();
        }    
        i++;
    }
    
    
    float value = std::atof(strVal.c_str());
    if (value > 1000)
        throw Bitcoin::ValueTooLargeException();
    else if (value < 0)
        throw Bitcoin::NegativeValueException();
    return value;
}

float Bitcoin::getClosestValue(const string &date) const
{
    std::map<string, float>::const_iterator it = data.lower_bound(date);

    if (it != data.end() && it->first == date)
        return it->second;

    if (it == data.begin())
        throw Bitcoin::NotValueFoundException();

    --it;
    return it->second;
}

void Bitcoin::parseLine(string &line)
{
    int i = 0;
    while (i < 10)
    {
        if ((i == 4) || (i == 7))
        {
            if (line[i] != '-')
            {
                throw Bitcoin::LineFormatException();
            }
        }
        else
        {
            if (!std::isdigit(line[i]))
            {
                throw Bitcoin::LineFormatException();
            }
        }
        i++;
    }

    string date = checkDate(line);
    if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        throw Bitcoin::LineFormatException();

    float value = checkValue(line);

    float closest = getClosestValue(date);

    cout << date << " => " << value << " = " << closest * value  << endl;
}



char const *Bitcoin::DateFormatException::what() const throw()
{
    return "Error: bad input => ";
}

char const *Bitcoin::LineFormatException::what() const throw()
{
    return "Error: invalid format line";
}

char const *Bitcoin::NotValueFoundException::what() const throw()
{
    return "Error: not value found";
}

char const *Bitcoin::ValueTooLargeException::what() const throw()
{
    return "Error: too large a number";
}

char const *Bitcoin::NegativeValueException::what() const throw()
{
    return "Error: not a positive number";
}