/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:19:44 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/31 15:18:49 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
#include "AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
  	public:
  		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &source);
		RobotomyRequestForm(RobotomyRequestForm const &source);
		void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &bure);
#endif