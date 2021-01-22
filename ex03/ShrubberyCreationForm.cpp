/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:45:02 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:43:48 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("garden") {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target_) : AForm("ShrubberyCreationForm", 145, 137), _target(target_) {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}

void									ShrubberyCreationForm::action(void) const {
	std::ofstream		ofs;
	std::string			fname;

	fname = _target;
	fname += "_shrubbery";
	ofs.open(fname.c_str());
	ofs.write("ASCII trees\n", 12);
	ofs.close();
}

std::string const						&ShrubberyCreationForm::getTarget(void) const {
	return _target;
}

ShrubberyCreationForm &					ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	_target = rhs._target;
	return *this;
}

std::ostream &							operator<<(std::ostream & o, ShrubberyCreationForm const & f) {
	o << f.getName() << ", is a form of sign grade " << f.getSignGrade() << ", execute grade " << f.getExecuteGrade() << ", signed " << f.getSigned() << ", target " << f.getTarget() << std::endl;
	return o;
}
