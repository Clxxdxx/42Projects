#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{

}

Bureaucrat::Bureaucrat(const string name, int grade): name(name)
{
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	cout << "Bureaucrat copy constructor called" << endl;
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        this->grade = copy.grade;
    }
	cout << "Assignment operator for Bureaucrat called." << endl;
	return (*this);
}

const string &Bureaucrat::getName() const
{
    return this->name;
}

const int &Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::decGrade()
{
    if (this->grade + 1 > 150)
    {
        throw(Bureaucrat::GradeTooLowException());
    }
    this->grade++;
}

void Bureaucrat::incGrade()
{
    if (this->grade  - 1 < 1)
    {
        throw(Bureaucrat::GradeTooHighException());
    }
    this->grade--;
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signs " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because: " << e.what() << std::endl;
	}
}