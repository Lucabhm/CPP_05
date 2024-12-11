/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:07:04 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/11 15:02:44 by lbohm            ###   ########.fr       */
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
		d.beSigned(db);
		db.setGrade(10);
		d.beSigned(db);
		d.beSigned(db);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}