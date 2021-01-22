/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:30 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 15:25:03 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_intern(void) {
	Intern		idiot;
	Bureaucrat	jesus("jesus", 1);
	AForm		*tmp;

	std::cout << std::endl << "\tCreate forms of all types" << std::endl;
	tmp = idiot.makeForm("robotomy request", "Bender");
	std::cout << *tmp;
	jesus.signForm(*tmp);
	jesus.executeForm(*tmp);
	std::cout << *tmp;
	delete tmp;

	std::cout << std::endl;
	tmp = idiot.makeForm("shrubbery creation", "Bender");
	std::cout << *tmp;
	jesus.signForm(*tmp);
	jesus.executeForm(*tmp);
	std::cout << *tmp;
	delete tmp;

	std::cout << std::endl;
	tmp = idiot.makeForm("presidential pardon", "Bender");
	std::cout << *tmp;
	jesus.signForm(*tmp);
	jesus.executeForm(*tmp);
	std::cout << *tmp;
	delete tmp;

	std::cout << std::endl;
	std::cout << std::endl << "\tCreate forms of nonexistent type" << std::endl;
	idiot.makeForm("potato request", "Bender");
}

int		main(void) {
	test_intern();
	return (0);
}
