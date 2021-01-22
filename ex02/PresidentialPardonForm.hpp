/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:45:00 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:44:04 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <fstream>
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target_);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);

		void								action(void) const;
		std::string const					&getTarget(void) const;

		PresidentialPardonForm &			operator=(PresidentialPardonForm const & rhs);
	private:
		std::string							_target;
};

std::ostream &					operator<<(std::ostream & o, PresidentialPardonForm const & f);

#endif
