/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:35 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/10 16:33:48 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

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
		void	setGrade(int newGrade);
		int		getGrade(void) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char *	what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *	what() const noexcept;
		};
};

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &person);

#endif