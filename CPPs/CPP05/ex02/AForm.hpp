/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:14:58 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 14:15:01 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
    private:
        const string name;
        bool isSigned;
        const int gSign;
        const int gExecute;
    public:
        AForm();
        AForm(const string name, const int gSign, const int gExecute);
        virtual ~AForm();
        AForm(AForm const &copy);
        AForm &operator=(AForm const &copy);

        const string &getName() const;
        const bool &getIsSigned() const;
        const int &getSignGrade() const;
        const int &getExecGrade() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedExcepion : public std::exception {
            public:
                virtual const char* what() const throw();
        };

       void beSigned(Bureaucrat &b);
       virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream	&operator<<(std::ostream &str, AForm const &f);


#endif