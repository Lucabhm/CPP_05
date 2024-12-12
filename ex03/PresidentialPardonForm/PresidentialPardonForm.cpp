/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:13:41 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/12 16:59:29 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm::AForm("default", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardon", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor with attributes called" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator= (const PresidentialPardonForm &cpy)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &cpy)
		std::cout << "PresidentialPardonForm nothing to copy" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getGradeToExe())
		{
			std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
		else
			throw PresidentialPardonForm::AForm::GradeTooLowException();
	}
	else
		throw "Form isn't signed";
}

std::string				PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}