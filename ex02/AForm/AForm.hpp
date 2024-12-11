/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:10:56 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/11 16:09:01 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				signedForm;
		const int			gradeToSign;
		const int			gradeToExe;
	public:
		AForm(void);
		AForm(const std::string newName, const int newGradeSign, const int newGradeExe);
		AForm(const AForm &cpy);
		~AForm(void);
		AForm		&operator= (const AForm &cpy);
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

std::ostream	&operator<< (std::ostream &stream, const AForm &file);

#endif