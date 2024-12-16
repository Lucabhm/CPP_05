/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:35 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/16 16:29:12 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

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
		void		signForm(Form &file);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *	what() const _NOEXCEPT;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *	what() const _NOEXCEPT;
		};
};

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &person);

#endif