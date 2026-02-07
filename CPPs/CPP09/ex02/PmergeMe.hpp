
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque> 
#include <vector>
#include <fstream>
typedef std::string string;
using std::cout;
using std::endl;

class PmergeMe
{
    private:
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& pm);
        PmergeMe& operator=(const PmergeMe& pm);
        ~PmergeMe();

        template <typename Container>
        typename Container::iterator binaryInsert( Container &c, typename Container::iterator end, int value);
        
        template <typename Container>
        void stepOne(Container &container);

        template <typename Container>
        void stepTwo(Container &container);
        
        template <typename Container>
        void sort(Container& container); 
};


inline int my_pow(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

inline size_t jacobsthal(size_t n)
{
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;

    size_t a = 0;
    size_t b = 1;
    size_t c;

    for (size_t i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}


template <typename Container>
void printCont(Container &container)
{
    for (size_t i = 0; i < container.size(); ++i)
        cout << container[i] << " ";
    cout << endl;
}

template <typename Container>
typename Container::iterator 
PmergeMe::binaryInsert(
    Container &c,
    typename Container::iterator end,
    int value)
{
    typename Container::iterator left = c.begin();
    typename Container::iterator right = end;

    while (left < right)
    {
        typename Container::iterator mid = left + (right - left) / 2;
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    return c.insert(left, value);
}


template <typename Container>
void PmergeMe::stepOne(Container &container)
{
    // ordenar cada par (min, max)
    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
    }

    // ordenar los pares según su máximo
    for (size_t i = 1; i < container.size(); i += 2)
    {
        size_t j = i;
        while (j > 1 && container[j] < container[j - 2])
        {
            std::swap(container[j], container[j - 2]);
            std::swap(container[j - 1], container[j - 3]);
            j -= 2;
        }
    }
}

template <typename Container>
void PmergeMe::stepTwo(Container &container)
{
    Container main;
    Container pend;
    bool has_straggler = false;
    int straggler = 0;

    // 1. Separar en pares: main = máximos, pend = mínimos
    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        if (container[i] < container[i + 1])
        {
            pend.push_back(container[i]);
            main.push_back(container[i + 1]);
        }
        else
        {
            pend.push_back(container[i + 1]);
            main.push_back(container[i]);
        }
    }

    // 2. Guardar straggler si existe
    if (container.size() % 2)
    {
        has_straggler = true;
        straggler = container.back();
    }

    // 3. Insertar el primer pend al principio
    main.insert(main.begin(), pend[0]);

    // 4. Inserciones siguiendo Jacobsthal
    size_t inserted = 1;
    size_t j = 2;

    while (true)
    {
        size_t jac = jacobsthal(j);
        if (jac >= pend.size())
            break;

        for (size_t i = jac; i > inserted; --i)
        {
            binaryInsert(main, main.begin() + i, pend[i]);
        }
        inserted = jac;
        ++j;
    }

    // 5. Insertar los pendientes restantes
    for (size_t i = inserted + 1; i < pend.size(); ++i)
        binaryInsert(main, main.begin() + i, pend[i]);

    // 6. Insertar straggler al final correcto
    if (has_straggler)
        binaryInsert(main, main.end(), straggler);

    container = main;
}

#endif