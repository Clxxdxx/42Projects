/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:14:41 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/08 11:00:44 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Form form0("Form 0", 1, 5);
			cout << form0 << endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << endl;
		}
		
	}

	cout << "\n --------------------- \n\n";

	{
		try
		{
			Bureaucrat mike("Miguel", 2);
			Form form("Form 1", 11, 45);
			cout << mike << endl;
			cout << form << endl;
			mike.signForm(form);
			cout << form << endl;
		}
		catch (std::exception &e)
		{
			cout << e.what() << endl;
		}
	}
	
	cout << "\n --------------------- \n\n";

	{
		try
		{
			Bureaucrat jon("Juan", 35);
			Form form2("Form 2", 20, 45);
			cout << jon << endl;
			cout << form2 << endl;
			jon.signForm(form2);
			cout << form2 << endl;
		}
		catch (std::exception &e)
		{
			cout << e.what() << endl;
		}
	}
	return (0);
}