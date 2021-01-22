/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 14:57:33 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 15:19:44 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	return;
}

Intern::Intern(Intern const & src) {
	*this = src;
	return;
}

Intern::~Intern(void) {
	return;
}

AForm					*Intern::newRRF(std::string target_) {
	return new RobotomyRequestForm(target_);
}

AForm					*Intern::newSCF(std::string target_) {
	return new ShrubberyCreationForm(target_);
}

AForm					*Intern::newPPF(std::string target_) {
	return new PresidentialPardonForm(target_);
}

AForm					*Intern::makeForm(std::string type, std::string target_) {
	AForm			*(Intern::*creators[3])(std::string) = {&Intern::newRRF, &Intern::newSCF, &Intern::newPPF};

	std::string		types[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
		if (type.compare(types[i]) == 0) {
			std::cout << "Intern creates " << type << std::endl;
			return (this->*(creators[i]))(target_);
		}
	}
	std::cout << "Intern cannot figure out how to create " << type << std::endl;
	return (NULL);
}

Intern &					Intern::operator=(Intern const & rhs) {
	(void)rhs;
	return *this;
}
