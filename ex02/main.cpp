/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:30 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:40:46 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_shrub(void) {
	Bureaucrat						jeff("Jeff", 146);
	Bureaucrat						bob("Bob", 137);
	ShrubberyCreationForm			tmp;

	std::cout << std::endl << "\t\tShrubberyCreationForm" << std::endl;
	std::cout << std::endl << "\tCreation" << std::endl;
	ShrubberyCreationForm			form1("nuclear war");
	std::cout << form1;

	std::cout << std::endl << "\tExecute fail" << std::endl;
	std::cout << bob;
	bob.executeForm(form1);
	std::cout << form1;
	bob.demote();

	std::cout << std::endl << "\tSign" << std::endl;
	std::cout << jeff;
	jeff.signForm(form1);
	jeff.promote();
	std::cout << jeff;
	jeff.signForm(form1);
	std::cout << form1;

	std::cout << std::endl << "\tExecute" << std::endl;
	std::cout << bob;
	bob.executeForm(form1);
	bob.promote();
	std::cout << bob;
	bob.executeForm(form1);
	std::cout << form1;
	return;
}

void	test_robot(void) {
	Bureaucrat						jeff("Jeff", 73);
	Bureaucrat						bob("Bob", 45);
	RobotomyRequestForm				tmp;

	std::cout << std::endl << "\t\tRobotomyRequestForm" << std::endl;
	std::cout << std::endl << "\tCreation" << std::endl;
	RobotomyRequestForm			form1("my friend alberto");
	std::cout << form1;

	std::cout << std::endl << "\tExecute fail" << std::endl;
	std::cout << bob;
	bob.executeForm(form1);
	std::cout << form1;
	bob.demote();

	std::cout << std::endl << "\tSign" << std::endl;
	std::cout << jeff;
	jeff.signForm(form1);
	jeff.promote();
	std::cout << jeff;
	jeff.signForm(form1);
	std::cout << form1;

	std::cout << std::endl << "\tExecute" << std::endl;
	std::cout << bob;
	bob.executeForm(form1);
	bob.promote();
	std::cout << bob;
	bob.executeForm(form1);
	bob.executeForm(form1);
	bob.executeForm(form1);
	bob.executeForm(form1);
	bob.executeForm(form1);
	std::cout << form1;
	return;
}

void	test_pardon(void) {
	Bureaucrat						jeff("Jeff", 26);
	Bureaucrat						bob("Bob", 5);
	PresidentialPardonForm			tmp;

	std::cout << std::endl << "\t\tPresidentialPardonForm" << std::endl;
	std::cout << std::endl << "\tCreation" << std::endl;
	PresidentialPardonForm			form1("Donnieboy");
	std::cout << form1;

	std::cout << std::endl << "\tExecute fail" << std::endl;
	std::cout << bob;
	bob.executeForm(form1);
	std::cout << form1;
	bob.demote();

	std::cout << std::endl << "\tSign" << std::endl;
	std::cout << jeff;
	jeff.signForm(form1);
	jeff.promote();
	std::cout << jeff;
	jeff.signForm(form1);
	std::cout << form1;

	std::cout << std::endl << "\tExecute" << std::endl;
	std::cout << bob;
	bob.executeForm(form1);
	bob.promote();
	std::cout << bob;
	bob.executeForm(form1);
	std::cout << form1;
	return;
}

int		main(void) {
	test_shrub();
	test_robot();
	test_pardon();
	return (0);
}
