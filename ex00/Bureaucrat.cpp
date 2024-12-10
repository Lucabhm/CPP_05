/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:38 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/10 18:56:08 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string newName, int newGrade) : name(newName)
{
	std::cout << "Bureaucrat constructor with name attribute called" << std::endl;
	this->setGrade(newGrade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->grade = cpy.getGrade();
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator= (const Bureaucrat &cpy)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &cpy)
		this->grade = cpy.getGrade();
	return (*this);
}

Bureaucrat	&Bureaucrat::operator++ (int value)
{
	this->setGrade(--this->grade);
	return (*this);
}

Bureaucrat	&Bureaucrat::operator-- (int value)
{
	this->setGrade(++this->grade);
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::setGrade(int newGrade)
{
	if (newGrade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = newGrade;
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &person)
{
	stream << person.getName() << "," << " bureaucrat grade " << person.getGrade();
	return (stream);
}

const char *	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade to high");
}

const char *	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade to Low");
}