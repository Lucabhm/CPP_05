/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:35 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/19 09:51:17 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "../AForm/AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string newName, int newGrade);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat(void);
		Bureaucrat	&operator= (const Bureaucrat &cpy);
		Bureaucrat	&operator++ (int value);
		Bureaucrat	&operator-- (int value);
		std::string	getName(void) const;
		void		setGrade(int newGrade);
		int			getGrade(void) const;
		void		signForm(AForm &file);
		void		executeForm(AForm const &form);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *	what() const throw();
		};
};

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &person);

#endif