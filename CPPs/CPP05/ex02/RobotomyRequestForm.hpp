#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(string target);
    ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &copy);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

    void execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif