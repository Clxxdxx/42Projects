/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:15:16 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/08 11:04:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Bureaucrat Amancio("Amancio", 1);
    Bureaucrat Maria("Maria", 146);

    ShrubberyCreationForm f1("jardin");
    RobotomyRequestForm    f2("robot");
    PresidentialPardonForm f3("Florentino Perez");

    cout << "------------------------------" << endl;
    Maria.signForm(f1);
    Amancio.executeForm(f1);

    cout << "\n------------------------------" << endl;
    Amancio.signForm(f1);
    Amancio.signForm(f2);
    Amancio.signForm(f3);

    cout << "\n------------------------------" << endl;

    Amancio.executeForm(f1);
    Amancio.executeForm(f2);
    Amancio.executeForm(f3);

    return 0;
}