/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:06 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/19 10:45:52 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	try
	{
		Bureaucrat				luca("Luca", 10);
		Bureaucrat				nick("Nick", 11);
		ShrubberyCreationForm	treeForm("home");
		RobotomyRequestForm		robotForm("robot");
		PresidentialPardonForm	presiForm("presi");

		std::cout << luca << std::endl;
		luca.setGrade(45);
		std::cout << luca << std::endl;
		nick.signForm(treeForm);
		luca.executeForm(treeForm);
		nick.signForm(robotForm);
		luca.executeForm(robotForm);
		nick.signForm(presiForm);
		luca.setGrade(1);
		luca.executeForm(presiForm);
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
