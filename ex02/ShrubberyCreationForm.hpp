/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:45:00 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:43:44 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target_);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);

		void								action(void) const;
		std::string const					&getTarget(void) const;

		ShrubberyCreationForm &				operator=(ShrubberyCreationForm const & rhs);
	private:
		std::string							_target;
};

std::ostream &					operator<<(std::ostream & o, ShrubberyCreationForm const & f);

#endif
