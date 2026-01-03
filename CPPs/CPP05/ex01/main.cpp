#include "Bureaucrat.hpp"

int main(void)
{
	/* Create a form with grade too high */
	{
		try
		{
			Form form0("Form 0", 1, 5);
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n --------------------- \n\n";

	{
		try
		{
			Bureaucrat mike("Miguel", 15);
			Form form("Form 1", 20, 45);
			std::cout << mike << std::endl;
			std::cout << form << std::endl;
			mike.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";

	{
		try
		{
			Bureaucrat jon("Juan", 35);
			Form form2("Form 2", 20, 45);
			std::cout << jon << std::endl;
			std::cout << form2 << std::endl;
			jon.signForm(form2);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}