/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:06 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/17 10:29:37 by lbohm            ###   ########.fr       */
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
		AForm					*form1;

		std::cout << luca << std::endl;
		std::cout << nick << std::endl;
		form1 = randomGuy.makeForm("robotomy request", "Test");
		form1->beSigned(nick);
		luca.executeForm(*form1);
		delete form1;
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
