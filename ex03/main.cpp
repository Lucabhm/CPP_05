/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:06 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/12 16:37:44 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"

int	main(void)
{
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
		treeForm.beSigned(nick);
		luca.executeForm(treeForm);
		robotForm.beSigned(nick);
		luca.executeForm(robotForm);
		presiForm.beSigned(nick);
		luca.setGrade(1);
		luca.executeForm(presiForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
