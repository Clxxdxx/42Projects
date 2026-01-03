#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
    cout << "ShrubberyCreationForm Default Constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    cout << "ShrubberyCreationForm " << target << " Constructor called" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    cout << "Destructor ShrubberyCreationForm has called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm::AForm(copy), target(copy.target)
{
    cout << "ShrubberyCreationForm copy constructor have been called";
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