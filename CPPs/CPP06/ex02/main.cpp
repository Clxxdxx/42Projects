/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:19:18 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/08 11:54:19 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base* generate(void)
{
    int num = rand() % 3;
    if (num == 0)
    {
        cout << "Object class A instanciated" << endl;
        return new A();
    } else if (num == 1)
    {
        cout << "Object class B instanciated" << endl;
        return new B();
    } else if (num == 2)
    {
       cout << "Object class C instanciated" << endl;
        return new C();
    }
    cout << "Error" << endl;
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        cout << "Type of the object is A" << endl;
    else if (dynamic_cast<B*>(p))
        cout << "Type of the object is B" << endl;
    else if (dynamic_cast<C*>(p))
        cout << "Type of the object is C" << endl;
    else
        cout << "Unknown type" << endl;
}

void identify(Base& p)
{
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        cout << "Type of the object is A" << endl;
        return;
    } catch (std::exception&) {

    }
    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        cout << "Type of the object is B" << endl;
        return;
    } catch (std::exception&) {

    }
    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        cout << "Type of the object is C" << endl;
        return;
    } catch (std::exception&) {

    }
    cout << "Unknown type" << endl;
}

int main()
{
    srand(time(0));
    Base* obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;

    Base* obj2 = generate();
    identify(obj2);
    identify(*obj2);

    delete obj2;

    return 0;
}
