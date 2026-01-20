/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:10:14 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/14 16:26:30 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
typedef std::string string;
using std::cout;
using std::endl;

class Span {
    private:
        unsigned int N;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &copy);
        ~Span();
        Span &operator=(const Span &copy);

        void addNumber(int value);
        int shortestSpan();
        int longestSpan();

        void printVec() const;
        void addRange(int firstNum, unsigned int size);
};


#endif