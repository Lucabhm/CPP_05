/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:06:58 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/12 18:35:09 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <map>
# include "../AForm/AForm.hpp"
# include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
# include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
# include "../PresidentialPardonForm/PresidentialPardonForm.hpp"

typedef AForm* (*getForm)(std::string);

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &cpy);
		~Intern(void);
		Intern	&operator= (const Intern &cpy);
		AForm	*createShrubbery(std::string target);
		AForm	*createRobotomy(std::string target);
		AForm	*createPresidential(std::string target);
		AForm	*makeForm(std::string formName, std::string targetName);
};

#endif