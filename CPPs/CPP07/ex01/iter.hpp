/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:19:43 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 14:19:44 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>

void iter(T* array, const size_t len, void (*f)(T&))
{
    size_t i = 0;
    while (i < len)
    {
        f(array[i]);
        i++;
    }
}


#endif