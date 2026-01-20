/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:16:34 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 15:16:09 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("Default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm::AForm(copy), target(copy.target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    AForm::operator=(copy);
	this->target = copy.target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		 throw AForm::FormNotSignedExcepion();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream file((this->target + "_shrubbery").c_str());

	if (!file.is_open())
	{
		std::cout << "Error: Could not open file" << endl;
		return;
	}

	file << "               ,@@@@@@@," << endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << endl;
	file << "       |o|        | |         | |" << endl;
	file << "       |.|        | |         | |" << endl;
	file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << endl;

	file.close();
	std::cout << "Shrubbery created in " << this->target << "_shrubbery" << endl;
}

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}