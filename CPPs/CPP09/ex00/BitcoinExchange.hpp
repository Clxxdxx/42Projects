/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:57:05 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/23 16:09:04 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

typedef std::string string;
using std::cout;
using std::endl;



class Bitcoin {
    private:
        std::map<string, float> data;
        string checkDate(string &line);
        float checkValue(string &line);
        float getClosestValue(const string &date) const;
                
    public:
        Bitcoin();
        ~Bitcoin();
        Bitcoin(Bitcoin const &copy);
        Bitcoin &operator=(Bitcoin const &copy);
        
        void parseLine(string &line);
        string getDate(string &line);
        void loadData(const string& filename);

        class DateFormatException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NotValueFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NegativeValueException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class ValueTooLargeException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class LineFormatException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif