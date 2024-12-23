/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:06 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/19 10:09:20 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Intern/Intern.hpp"

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	try
	{
		Bureaucrat				luca("Luca", 1);
		Bureaucrat				nick("Nick", 11);
		Intern					randomGuy;
		AForm					*form1 = NULL;
		AForm					*form2 = NULL;
		AForm					*form3 = NULL;

		std::cout << luca << std::endl;
		std::cout << nick << std::endl;
		try
		{
			form1 = randomGuy.makeForm("robotomy request", "Form1");
			form1->beSigned(nick);
			luca.executeForm(*form1);
		}
		catch(const char *e)
		{
			std::cerr << e << std::endl;
		}
		catch(const std::string e)
		{
			std::cerr << e << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			form2 = randomGuy.makeForm("shrubbery request", "Form2");
			form2->beSigned(nick);
			luca.executeForm(*form2);
		}
		catch(const char *e)
		{
			std::cerr << e << std::endl;
		}
		catch(const std::string e)
		{
			std::cerr << e << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			form3 = randomGuy.makeForm("presidential request", "Form3");
			form3->beSigned(nick);
			luca.executeForm(*form3);
		}
		catch(const char *e)
		{
			std::cerr << e << std::endl;
		}
		catch(const std::string e)
		{
			std::cerr << e << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		if (form1)
			delete form1;
		if (form2)
			delete form2;
		if (form3)
			delete form3;
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
	catch(const std::string e)
	{
		std::cerr << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
