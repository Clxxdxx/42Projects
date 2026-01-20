/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:14:34 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/08 11:00:38 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Default"), isSigned(false), gSign(1), gExecute(2)
{

}

Form::Form(const string name, const int gSign, const int gExecute): name(name), isSigned(false), gSign(gSign), gExecute(gExecute)
{
    if (gSign > 150 || gExecute > 150)
    {
       throw(Form::GradeTooLowException());
    }
    if (gSign < 1 || gExecute < 1)
    {
       throw(Form::GradeTooHighException());
    } 
}

Form::~Form()
{

}

Form::Form(Form const &copy): name(copy.name), isSigned(copy.isSigned), gSign(copy.gSign), gExecute(copy.gExecute)
{
    *this = copy;
}

Form &Form::operator=(const Form &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

const string &Form::getName() const
{
    return this->name;
}

const bool &Form::getIsSigned() const
{
    return this->isSigned;
}

const int &Form::getExecGrade() const
{
    return this->gExecute;
}

const int &Form::getSignGrade() const
{
    return this->gSign;
}

char const *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

char const *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
    o << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade();
    return o;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gSign)
		throw (Form::GradeTooHighException());
	else
	{
		this->isSigned = true;
	}
}