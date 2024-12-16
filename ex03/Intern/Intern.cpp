/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:16:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/16 13:21:10 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern	&Intern::operator= (const Intern &cpy)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

AForm	*createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string targetName)
{
	AForm	*(*functions[])(std::string target) = {&createRobotomy, &createShrubbery, &createPresidential};
	std::string	forms[] = {"robotomy request", "shrubbery request", "presidential request"};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (functions[i](targetName));
		}
	}
	throw "Form request was wrong";
	return (NULL);
}