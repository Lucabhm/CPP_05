/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:16:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/12 18:42:14 by lbohm            ###   ########.fr       */
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
}

AForm	*Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string targetName)
{
	std::map<std::string, getForm>	forms = {
		{"robotomy request", createRobotomy},
		{"shrubbery request", createShrubbery},
		{"presidential request", createPresidential}
	};
}