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