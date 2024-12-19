/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:32 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/19 10:11:58 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("default"), gradeToSign(10), gradeToExe(10)
{
	std::cout << "Form default constructor called" << std::endl;
	signedForm = false;
}

Form::Form(const std::string newName, const int newGradeSign, const int newGradeExe) : name(newName), gradeToSign(newGradeSign), gradeToExe(newGradeExe)
{
	std::cout << "Form constructor with attributes called" << std::endl;
	if (this->gradeToSign > 150 || this->gradeToExe > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (this->gradeToSign < 1 || this->gradeToExe < 1)
		throw Bureaucrat::GradeTooLowException();
	this->signedForm = false;
}

Form::Form(const Form &cpy) : name(cpy.name), gradeToSign(cpy.gradeToSign), gradeToExe(cpy.gradeToExe)
{
	std::cout << "Form copy constructor called" << std::endl;
	signedForm = cpy.signedForm;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form	&Form::operator= (const Form &cpy)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &cpy)
		std::cerr << "You can't change the attributes" << std::endl;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->name);
}

bool	Form::getSigned(void) const
{
	return (this->signedForm);
}

int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExe(void) const
{
	return (this->gradeToExe);
}

void	Form::beSigned(Bureaucrat &person)
{
	if (!this->signedForm)
	{
		if (person.getGrade() <= this->getGradeToSign())
		{
			std::cout << person.getName() << " signed " << this->getName() << std::endl;
			this->signedForm = true;
		}
		else
			throw Form::GradeTooLowException();
	}
	else
		throw this->getName() + " already signed";
}

const char *	Form::GradeTooHighException::what() const throw()
{
	return ("Grade to high");
}

const char *	Form::GradeTooLowException::what() const throw()
{
	return ("Grade to Low");
}

std::ostream	&operator<< (std::ostream &stream, const Form &file)
{
	stream << file.getName() << ":" << " signed = " << file.getSigned() << ", GradeToSign = " << file.getGradeToSign() << ", GradeToExe = " << file.getGradeToExe();
	return (stream);
}
