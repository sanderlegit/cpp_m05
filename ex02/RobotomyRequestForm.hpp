/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:45:00 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/22 14:43:52 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <fstream>
# include <iostream>
# include <stdlib.h>
# include <time.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target_);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);

		void								action(void) const;
		std::string const					&getTarget(void) const;

		RobotomyRequestForm &				operator=(RobotomyRequestForm const & rhs);
	private:
		std::string							_target;
};

std::ostream &					operator<<(std::ostream & o, RobotomyRequestForm const & f);

#endif
