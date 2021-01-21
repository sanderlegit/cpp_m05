/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 16:37:17 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/21 17:22:26 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <iostream>

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
		static const int		_gradeMax = 1;
		static const int		_gradeMin = 150;
};

std::ostream &					operator<<(std::ostream & o, Bureaucrat const & b);

#endif
