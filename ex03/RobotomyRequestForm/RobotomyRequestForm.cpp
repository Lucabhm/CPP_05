/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:55:02 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/16 13:53:04 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm::AForm("default", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor with attributes called" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm &cpy)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &cpy)
		std::cout << "RobotomyRequestForm nothing to copy" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getGradeToExe())
		{
			int	randomInt;

			randomInt = rand() % 2;
			if (randomInt)
			{
				std::cout << "drilling noises" << std::endl;
				std::cout << this->getTarget() << " has been robotomized" << std::endl;
			}
			else
				throw "robotomy failed";
		}
		else
			throw "Grade to Low to execute the Form";
	}
	else
		throw "Form isn't signed";
}

std::string				RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}