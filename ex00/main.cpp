/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:30 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/21 17:40:31 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void) {
	Bureaucrat		tmp;

	std::cout << std::endl << "\tMax grade" << std::endl;
	Bureaucrat		jeff("Jeff", 1);
	std::cout << jeff;

	std::cout << std::endl << "\tTest demote" << std::endl;
	jeff.demote();
	std::cout << jeff;

	std::cout << std::endl << "\tTest promote exception" << std::endl;
	try {
		jeff.promote();
		jeff.promote();
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jeff;

	std::cout << std::endl << "\tMin grade" << std::endl;
	Bureaucrat		frad("frad", 150);
	std::cout << frad;

	std::cout << std::endl << "\tTest promote" << std::endl;
	frad.promote();
	std::cout << frad;

	std::cout << std::endl << "\tTest demote exception" << std::endl;
	try {
		frad.demote();
		frad.demote();
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << frad;


	std::cout << std::endl << "\tInvalid, too high" << std::endl;
	try {
		tmp = Bureaucrat("won't work", 0);
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "\tInvalid, too low" << std::endl;
	try {
		tmp = Bureaucrat("won't work", 151);
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
