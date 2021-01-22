/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:20 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 13:15:48 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	return;
}

Bureaucrat::Bureaucrat(std::string name_, int grade_) : _name(name_) {
	if (grade_ > GRADEMIN)
		throw Bureaucrat::GradeTooLowException();
	else if (grade_ < GRADEMAX)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade_;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	return;
}

void					Bureaucrat::promote(void) {
	if (_grade - 1 < GRADEMAX)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void					Bureaucrat::demote(void) {
	if (_grade + 1 > GRADEMIN)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

std::string const &		Bureaucrat::getName(void) const {
	return _name;
}

int 					Bureaucrat::getGrade(void) const {
	return _grade;
}

Bureaucrat &			Bureaucrat::operator=(Bureaucrat const & rhs) {
	_grade = rhs._grade;
	return *this;
}

std::ostream			&operator<<(std::ostream &o, Bureaucrat const &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return o;
}

void					Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getName() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << _name << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
	}
}
