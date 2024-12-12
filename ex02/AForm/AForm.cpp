/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:10:48 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/11 18:15:00 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("default"), gradeToSign(10), gradeToExe(10)
{
	std::cout << "AForm default constructor called" << std::endl;
	signedForm = false;
}

AForm::AForm(const std::string newName, const int newGradeSign, const int newGradeExe) : name(newName), gradeToSign(newGradeSign), gradeToExe(newGradeExe)
{
	std::cout << "AForm constructor with attributes called" << std::endl;
	if (this->gradeToSign > 150 || this->gradeToExe > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (this->gradeToSign < 1 || this->gradeToExe < 1)
		throw Bureaucrat::GradeTooLowException();
	this->signedForm = false;
}

AForm::AForm(const AForm &cpy) : name(cpy.name), gradeToSign(cpy.gradeToSign), gradeToExe(cpy.gradeToExe)
{
	std::cout << "AForm copy constructor called" << std::endl;
	signedForm = cpy.signedForm;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm	&AForm::operator= (const AForm &cpy)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &cpy)
		std::cerr << "You can't change the attributes" << std::endl;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getSigned(void) const
{
	return (this->signedForm);
}

int	AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExe(void) const
{
	return (this->gradeToExe);
}

void	AForm::beSigned(Bureaucrat &person)
{
	if (!this->signedForm)
	{
		try
		{
			person.signForm(*this);
			this->signedForm = true;
		}
		catch (std::exception &e)
		{
			std::cerr << person.getName() << " couldn't sign " << this->getName() << " because " << e.what() << std::endl;
		}
	}
	else
		std::cerr << this->getName() << " alredy signed" << std::endl;
}

const char *	AForm::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade to high");
}

const char *	AForm::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade to Low");
}

std::ostream	&operator<< (std::ostream &stream, const AForm &file)
{
	stream << file.getName() << ":" << " signed = " << file.getSigned() << ", GradeToSign = " << file.getGradeToSign() << ", GradeToExe = " << file.getGradeToExe();
	return (stream);
}
