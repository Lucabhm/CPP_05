/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:04 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/19 10:46:09 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form		d("car", 10, 10);
		Bureaucrat	db("Luca", 150);

		std::cout << d << std::endl;
		std::cout << db << std::endl;
		db.signForm(d);
		db.setGrade(10);
		db.signForm(d);
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
	catch (const std::string& e)
	{
		std::cerr << e << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}