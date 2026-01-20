/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:13:15 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 14:13:18 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    private:
        const string name;
        bool isSigned;
        const int gSign;
        const int gExecute;
    public:
        Form();
        Form(const string name, const int gSign, const int gExecute);
        ~Form();
        Form(Form const &copy);
        Form &operator=(Form const &copy);

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

        void beSigned(Bureaucrat &b);


};

std::ostream	&operator<<(std::ostream &str, Form const &f);


#endif