#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    Intern intern;
    AForm* form;

    form = intern.makeForm("shrubbery creation", "Jose");
    if (form)
    {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    
    return 0;
}