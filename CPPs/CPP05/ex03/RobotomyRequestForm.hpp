/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:16:31 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/07 14:16:32 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(string target);
    ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &copy);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

    void execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif