#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(Intern const &copy)
{
    *this = copy;
}

Intern &Intern::operator=(Intern const &copy)
{
    (void)copy;
    return *this;
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(string formName, string target)
{
    string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*all_forms[3])(const string target) = {&makeShrubbery, &makeRobotomy, &makePresident};
    int i = 0;
    while (i < 3)
    {
        if (forms[i] == formName)
        {
           cout << "Intern creates " << formName << endl;
           return all_forms[i](target);
        }
        i++;
    }
    cout << "Form not exist" <<endl;
    return NULL;
}