#include "iter.hpp"

void sum38(int &i)
{
    i += 38;
}
void to_upper(std::string &str)
{
    size_t i = 0;

    while (i < str.length())
    {
        str[i] = std::toupper(str[i]);
        i++;
    }
}

void printInt( int &i)
{
    std::cout << i << std::endl;
}

void printString( std::string &str)
{
    std::cout << str << std::endl;
}

int main()
{
    int numbers[] = {1, 2, 3, 4};
    iter(numbers, 4, sum38);
    iter(numbers, 4, printInt);

    std::cout << "----" << std::endl;

    std::string words[] = {"hola", "adios", "hello world"};
    iter(words, 3, to_upper);
    iter(words, 3, printString);

    return 0;
}