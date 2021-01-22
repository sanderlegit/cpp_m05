/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 14:57:35 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 15:13:58 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		AForm					*makeForm(std::string type, std::string target_);
		AForm					*newRRF(std::string target_);
		AForm					*newSCF(std::string target_);
		AForm					*newPPF(std::string target_);

		Intern &				operator=(Intern const & rhs);
	private:
};

#endif
