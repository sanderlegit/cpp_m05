/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:30 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 13:23:40 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void) {
	Bureaucrat		jeff("Jeff", 1);
	Form			tmp;

	std::cout << std::endl << "\tMin grade creation" << std::endl;
	Form			form1("nuclear war", 150, 1);
	std::cout << form1;

	std::cout << std::endl << "\tMax grade creation" << std::endl;
	Form			form2("new paint", 1, 30);
	std::cout << form2;

	std::cout << std::endl << "\tSign" << std::endl;
	std::cout << jeff << form1;
	jeff.signForm(form1);
	std::cout << form1;

	std::cout << std::endl << "\tSign exception" << std::endl;
	while (jeff.getGrade() < 20)
		jeff.demote();
	std::cout << jeff << form2;
	jeff.signForm(form2);
	std::cout << form2;

	std::cout << std::endl << "\tInvalid creation, too high" << std::endl;
	try {
		tmp = Form("won't work", 0, 1);
	} catch (Form::GradeTooHighException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		tmp = Form("won't work", 1, 0);
	} catch (Form::GradeTooHighException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "\tInvalid creation, too low" << std::endl;
	try {
		tmp = Form("won't work", 151, 150);
	} catch (Form::GradeTooLowException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		tmp = Form("won't work", 150, 151);
	} catch (Form::GradeTooLowException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
