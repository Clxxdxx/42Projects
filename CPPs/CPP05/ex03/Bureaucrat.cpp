/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:15:58 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 15:15:02 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{

}

Bureaucrat::Bureaucrat(const string name, int grade): name(name)
{
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        this->grade = copy.grade;
    }
	return (*this);
}

const string &Bureaucrat::getName() const
{
    return this->name;
}

const int &Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::decGrade()
{
    if (this->grade + 1 > 150)
    {
        throw(Bureaucrat::GradeTooLowException());
    }
    this->grade++;
}

void Bureaucrat::incGrade()
{
    if (this->grade  - 1 < 1)
    {
        throw(Bureaucrat::GradeTooHighException());
    }
    this->grade--;
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signs " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because: " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}