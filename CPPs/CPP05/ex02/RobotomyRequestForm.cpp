#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    cout << "RobotomyRequestForm Default Constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
    cout << "RobotomyRequestForm " << target << " Constructor called" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    cout << "Destructor RobotomyRequestForm has called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm::AForm(copy), target(copy.target)
{
    cout << "RobotomyRequestForm copy constructor have been called";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    AForm::operator=(copy);
	this->target = copy.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == false)
         throw AForm::FormNotSignedExcepion();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    cout << "PRRRRRRR" << endl;
    if (std::rand() % 2 == 0)
    {
        cout << this->target << " has been robotomized successfully!" << endl;
    }
    else
    {
        cout << "The robotomy on " << this->target << " failed." << endl;
    }
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade();
}