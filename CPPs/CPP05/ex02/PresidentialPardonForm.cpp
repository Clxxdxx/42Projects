#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("Default")
{
    cout << "PresidentialPardonForm Default Constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    cout << "PresidentialPardonForm " << target << " Constructor called" << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    cout << "Destructor PresidentialPardonForm has called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm::AForm(copy), target(copy.target)
{
    cout << "PresidentialPardonForm copy constructor have been called";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
    AForm::operator=(copy);
	this->target = copy.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedExcepion();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    cout << target << " has been pardoned by Zaphod Beeblerox" << endl;
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	return str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade();
}