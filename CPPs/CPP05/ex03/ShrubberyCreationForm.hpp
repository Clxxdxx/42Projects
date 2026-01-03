

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(string target);
    ~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

    void execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form);

#endif