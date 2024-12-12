/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:12:03 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/12 16:57:52 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm::AForm("default", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor with attributes called" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &cpy)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &cpy)
		std::cout << "ShrubberyCreationForm nothing to copy" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getGradeToExe())
		{
			std::ofstream	file;

			file.open(this->getTarget() + "_shrubbery");
			if (!file.is_open())
				throw "Open failed";
			file << "                  ,@@@@@@@," << std::endl;
			file << "          ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			file << "       ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
			file << "      ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			file << "      %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			file << "      %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			file << "      `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			file << "          |o|        | |         | |" << std::endl;
			file << "          |.|        | |         | |" << std::endl;
			file << "        \\\\ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
			file.close();
		}
		else
			throw "Grade to Low to execute the Form";
	}
	else
		throw "Form isn't signed";
}

std::string				ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}