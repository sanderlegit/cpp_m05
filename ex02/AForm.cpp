/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 12:10:04 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:43:37 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("TPS Report"), _signed(0), _signGrade(150), _execGrade(150) {
	return;
}

AForm::AForm(std::string name_, int signg_, int execg_) : _name(name_), _signed(0), _signGrade(signg_), _execGrade(execg_) {
	if (_signGrade > GRADEMIN || _execGrade > GRADEMIN)
		throw AForm::GradeTooLowException();
	else if (_signGrade < GRADEMAX || _execGrade < GRADEMAX)
		throw AForm::GradeTooHighException();
	return;
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {
	return;
}

AForm::~AForm(void) {
	return;
}

std::string const &		AForm::getName(void) const {
	return _name;
}

int 					AForm::getSignGrade(void) const {
	return _signGrade;
}

int						AForm::getExecuteGrade(void) const {
	return _execGrade;
}


int						AForm::getSigned(void) const {
	return _signed;
}

void					AForm::beSigned(Bureaucrat const & b) {
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else
		_signed = 1;
	return;
}

void					AForm::execute(Bureaucrat const &executor) const {
	if (!_signed)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
	else
		action();
	return;
}

AForm &					AForm::operator=(AForm const & rhs) {
	(void)rhs;
	return *this;
}

std::ostream &			operator<<(std::ostream & o, AForm const & f) {
	o << f.getName() << ", is a form of sign grade " << f.getSignGrade() << ", execute grade " << f.getExecuteGrade() << ", signed " << f.getSigned() << std::endl;
	return o;
}
