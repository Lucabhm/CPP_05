/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:06 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/10 20:31:26 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	d;
		Bureaucrat	Luca("Luca", 10);
		Bureaucrat	copy(Luca);

		std::cout << "1 " << d << std::endl;
		std::cout << "2 " << Luca << std::endl;
		std::cout << "3 " << copy << std::endl;
		Luca++;
		std::cout << Luca << std::endl;
		std::cout << copy << std::endl;
		std::cout << "1 " << d.getGrade() << std::endl;
		std::cout << "1 " << d.getName() << std::endl;
		d = copy;
		std::cout << "1 " << d.getGrade() << std::endl;
		std::cout << "1 " << d.getName() << std::endl;
		Luca.setGrade(100000);
		std::cout << Luca << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
