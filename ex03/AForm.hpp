/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 12:10:06 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 15:17:26 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

# ifndef GRADE_BOUNDS
#  define GRADE_BOUNDS
#  define GRADEMAX	1
#  define GRADEMIN	150
# endif

class Bureaucrat;

class AForm {
	public:
		AForm(void);
		AForm(std::string name_, int signg_, int execg_);
		AForm(AForm const & src);
		virtual ~AForm(void);


		std::string const &		getName(void) const;
		int 					getSignGrade(void) const;
		int						getExecuteGrade(void) const;
		int						getSigned(void) const;
		void					beSigned(Bureaucrat const &b);
		void					execute(Bureaucrat const &executor) const;
		virtual void			action(void) const = 0;

		AForm &					operator=(AForm const & rhs);

		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("form not signed");
				}
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("grade too high");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("grade too low");
				}
		};
	private:
		std::string const		_name;
		bool					_signed;
		int const				_signGrade;
		int const				_execGrade;

};

std::ostream &					operator<<(std::ostream & o, AForm const & f);

#endif
