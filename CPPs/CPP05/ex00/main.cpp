#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Claudio", 1);
        cout << a << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "==========================================" << endl;

    try
    {
        Bureaucrat b("Maria", 148);
        cout << b << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << "==========================================" << endl;

    try
    {
        Bureaucrat c("Jose", 149);
        cout << c << endl;
        c.decGrade();
        cout << c << endl;
        c.decGrade();
        cout << c << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "==========================================" << endl;

    try
    {
        Bureaucrat d("Lucia", 2);
        cout << d << endl;
        d.incGrade();
        cout << d << endl;
        d.incGrade();
        cout << d << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}