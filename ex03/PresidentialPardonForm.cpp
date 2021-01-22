/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:45:02 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:44:02 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("garden") {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target_) : AForm("PresidentialPardonForm", 25, 5), _target(target_) {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src) {
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return;
}

void									PresidentialPardonForm::action(void) const {
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::string const						&PresidentialPardonForm::getTarget(void) const {
	return _target;
}

PresidentialPardonForm &				PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	_target = rhs._target;
	return *this;
}

std::ostream &							operator<<(std::ostream & o, PresidentialPardonForm const & f) {
	o << f.getName() << ", is a form of sign grade " << f.getSignGrade() << ", execute grade " << f.getExecuteGrade() << ", signed " << f.getSigned() << ", target " << f.getTarget() << std::endl;
	return o;
}
