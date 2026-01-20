/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:16:15 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/08 11:05:37 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm* form;

    form = intern.makeForm("presidential pardon", "Jose");
    if (form)
    {
        Bureaucrat Pepe("Pepe", 1);
        Pepe.signForm(*form);
        Pepe.executeForm(*form);
        delete form;
    }
    
    return 0;
}