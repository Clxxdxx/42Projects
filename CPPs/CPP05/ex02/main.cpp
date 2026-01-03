#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Bureaucrat Amancio("Amancio", 1);
    Bureaucrat Maria("Maria", 150);

    ShrubberyCreationForm f1("jardin");
    RobotomyRequestForm    f2("robot");
    PresidentialPardonForm f3("criminal");

    std::cout << "--- Failure Tests ---" << std::endl;
    Maria.signForm(f1);
    Amancio.executeForm(f1);

    std::cout << "\n--- Success Tests ---" << std::endl;
    Amancio.signForm(f1);
    Amancio.signForm(f2);
    Amancio.signForm(f3);

    Amancio.executeForm(f1);
    Amancio.executeForm(f2);
    Amancio.executeForm(f3);

    return 0;
}