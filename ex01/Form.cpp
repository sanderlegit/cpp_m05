/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 12:10:04 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 13:18:31 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("TPS Report"), _signed(0), _signGrade(150), _execGrade(150) {
	return;
}

Form::Form(std::string name_, int signg_, int execg_) : _name(name_), _signed(0), _signGrade(signg_), _execGrade(execg_) {
	if (_signGrade > GRADEMIN || _execGrade > GRADEMIN)
		throw Form::GradeTooLowException();
	else if (_signGrade < GRADEMAX || _execGrade < GRADEMAX)
		throw Form::GradeTooHighException();
	return;
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {
	return;
}

Form::~Form(void) {
	return;
}

std::string const &		Form::getName(void) const {
	return _name;
}

int 					Form::getSignGrade(void) const {
	return _signGrade;
}

int						Form::getExecuteGrade(void) const {
	return _execGrade;
}


int						Form::getSigned(void) const {
	return _signed;
}

void					Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_signed = 1;
}

Form &					Form::operator=(Form const & rhs) {
	(void)rhs;
	return *this;
}

std::ostream &			operator<<(std::ostream & o, Form const & f) {
	o << f.getName() << ", is a form of sign grade " << f.getSignGrade() << ", execute grade " << f.getExecuteGrade() << ", signed " << f.getSigned() << std::endl;
	return o;
}
