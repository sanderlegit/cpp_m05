/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:30 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 12:07:26 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void) {
	Bureaucrat		tmp;

	std::cout << std::endl << "\tMax grade creation" << std::endl;
	Bureaucrat		jeff("Jeff", 1);
	std::cout << jeff;


	std::cout << std::endl << "\tTest demote" << std::endl;
	std::cout << jeff;
	jeff.demote();
	std::cout << jeff;


	std::cout << std::endl << "\tTest promote exception" << std::endl;
	try {
		jeff.promote();
		jeff.promote();
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << jeff;


	std::cout << std::endl << "\tMin grade creation" << std::endl;
	Bureaucrat		frad("frad", 150);
	std::cout << frad;


	std::cout << std::endl << "\tTest promote" << std::endl;
	std::cout << frad;
	frad.promote();
	std::cout << frad;


	std::cout << std::endl << "\tTest demote exception" << std::endl;
	try {
		frad.demote();
		frad.demote();
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << frad;



	std::cout << std::endl << "\tInvalid creation, too high" << std::endl;
	try {
		tmp = Bureaucrat("won't work", 0);
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "\tInvalid creation, too low" << std::endl;
	try {
		tmp = Bureaucrat("won't work", 151);
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
