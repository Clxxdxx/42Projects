#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
typedef std::string string;
using std::cout;
using std::endl;

int main()
{
    Array<int> a;
    cout << "Size a: " << a.size() << endl;

    Array<int> b(3);
    unsigned int i = 0;
    while (i < b.size())
    {
        b[i] = i * 10;
        i++;
    }

    cout << "b: ";
    i = 0;
    while (i < b.size())
    {
        cout << b[i] << " ";
        i++;
    }

    cout << endl;

    Array<int> c(b);
    c[0] = 42;

    cout << "b[0]: " << b[0] << endl;
    cout << "c[0]: " << c[0] << endl;

    Array<int> d;
    d = b;
    d[1] = 99;

    cout << "b[1]: " << b[1] << endl;
    cout << "d[1]: " << d[1] << endl;

    try {
        cout << b[10] << endl;
    } catch (std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
