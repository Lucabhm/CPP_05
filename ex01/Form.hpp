/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:43 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/11 14:13:09 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				signedForm;
		const int			gradeToSign;
		const int			gradeToExe;
	public:
		Form(void);
		Form(const std::string newName, const int newGradeSign, const int newGradeExe);
		Form(const Form &cpy);
		~Form(void);
		Form		&operator= (const Form &cpy);
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExe(void) const;
		void		beSigned(Bureaucrat &person);
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

std::ostream	&operator<< (std::ostream &stream, const Form &file);

#endif