#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {

public:
    Intern();
    Intern(Intern const &copy);
    ~Intern();
    Intern &operator=(Intern const &copy);

    AForm* makeForm(string formName, string target);
};

#endif