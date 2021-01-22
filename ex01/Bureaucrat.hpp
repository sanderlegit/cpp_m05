/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:17 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 13:16:04 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <iostream>
# include "Form.hpp"

# ifndef GRADE_BOUNDS
#  define GRADE_BOUNDS
#  define GRADEMAX	1
#  define GRADEMIN	150
# endif

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name_, int grade_);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		void					promote(void);
		void					demote(void);
		std::string const &		getName(void) const;
		int 					getGrade(void) const;
		void					signForm(Form &f);

		Bureaucrat &			operator=(Bureaucrat const & rhs);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Bureaucrat grade too high");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Bureaucrat grade too low");
				}
		};
	private:
		std::string const		_name;
		int						_grade;
};

std::ostream &					operator<<(std::ostream & o, Bureaucrat const & b);

#endif
