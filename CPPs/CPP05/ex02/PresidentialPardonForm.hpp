#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(string target);
    ~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

    void execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);
#endif