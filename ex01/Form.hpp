/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 12:10:06 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 13:13:44 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

# ifndef GRADE_BOUNDS
#  define GRADE_BOUNDS
#  define GRADEMAX	1
#  define GRADEMIN	150
# endif

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(std::string name_, int signg_, int execg_);
		Form(Form const & src);
		~Form(void);


		std::string const &		getName(void) const;
		int 					getSignGrade(void) const;
		int						getExecuteGrade(void) const;
		int						getSigned(void) const;
		void					beSigned(Bureaucrat const & b);

		Form &					operator=(Form const & rhs);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Form grade too high");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Form grade too low");
				}
		};
	private:
		std::string const		_name;
		bool					_signed;
		int const				_signGrade;
		int const				_execGrade;

};

std::ostream &					operator<<(std::ostream & o, Form const & f);

#endif
