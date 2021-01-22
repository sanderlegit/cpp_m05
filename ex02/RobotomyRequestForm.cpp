/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:45:02 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:43:55 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Bender") {
	srand((int)time(0));
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target_) : AForm("RobotomyRequestForm", 72, 45), _target(target_) {
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src) {
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return;
}

void									RobotomyRequestForm::action(void) const {
	std::cout << _target << " has been robotomized *bbrrrzzz zzzsshhhhh* ";
	if (rand() %2) {
		std::cout << "successfully!" << std::endl;
	} else {
		std::cout << "unsuccessfully." << std::endl;
	}
}

std::string const						&RobotomyRequestForm::getTarget(void) const {
	return _target;
}

RobotomyRequestForm &					RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	_target = rhs._target;
	return *this;
}

std::ostream &							operator<<(std::ostream & o, RobotomyRequestForm const & f) {
	o << f.getName() << ", is a form of sign grade " << f.getSignGrade() << ", execute grade " << f.getExecuteGrade() << ", signed " << f.getSigned() << ", target " << f.getTarget() << std::endl;
	return o;
}
