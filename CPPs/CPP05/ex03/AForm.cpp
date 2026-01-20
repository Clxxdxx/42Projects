/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:15:50 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 14:15:51 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("Default"), isSigned(false), gSign(1), gExecute(2)
{

}

AForm::AForm(const string name, const int gSign, const int gExecute): name(name), isSigned(false), gSign(gSign), gExecute(gExecute)
{
    if (gSign > 150 || gExecute > 150)
    {
       throw(AForm::GradeTooLowException());
    }
    if (gSign < 1 || gExecute < 1)
    {
       throw(AForm::GradeTooHighException());
    } 
}

AForm::~AForm()
{

}

AForm::AForm(AForm const &copy): name(copy.name), isSigned(copy.isSigned), gSign(copy.gSign), gExecute(copy.gExecute)
{
    *this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

const string &AForm::getName() const
{
    return this->name;
}

const bool &AForm::getIsSigned() const
{
    return this->isSigned;
}

const int &AForm::getExecGrade() const
{
    return this->gExecute;
}

const int &AForm::getSignGrade() const
{
    return this->gSign;
}

char const *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

char const *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

char const *AForm::FormNotSignedExcepion::what() const throw()
{
    return "Form not signed";
}

std::ostream &operator<<(std::ostream &o, const AForm &AForm)
{
    o << AForm.getName() << " AForm, signed: " << AForm.getIsSigned() << ", sign grade: " << AForm.getSignGrade() << ", exec grade: " << AForm.getExecGrade();
    return o;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gSign)
		throw (AForm::GradeTooLowException());
	else
	{
		this->isSigned = true;
		std::cout << b.getName() << " successfully signed " << this->name << std::endl;
	}
}