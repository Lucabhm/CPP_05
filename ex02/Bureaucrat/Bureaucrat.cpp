/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:38 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/17 10:21:12 by lbohm            ###   ########.fr       */
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
	std::cout << "Bureaucrat constructor with attributes called" << std::endl;
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
	{
		this->grade = newGrade;
		std::cout << "Changed Grade to = " << this->getGrade() << std::endl;
	}
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::signForm(AForm &file)
{
	try
	{
		file.beSigned(*this);
	}
	catch (const std::string& e)
	{
		std::cerr << e << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " couldn't sign " << file.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char *	Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade to high");
}

const char *	Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade to Low");
}

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &person)
{
	stream << person.getName() << "," << " bureaucrat grade " << person.getGrade();
	return (stream);
}
