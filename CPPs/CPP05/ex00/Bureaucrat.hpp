


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
typedef std::string string;
using std::cout;
using std::endl;

class Bureaucrat {
    private:
        const string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const string name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat &operator=(Bureaucrat const &copy);

        const string &getName() const;
        const int &getGrade() const;

        void decGrade();
        void incGrade();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };


};
std::ostream	&operator<<(std::ostream &str, Bureaucrat const &grade);


#endif