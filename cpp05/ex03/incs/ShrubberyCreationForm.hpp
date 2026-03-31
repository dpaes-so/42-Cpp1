/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:19:44 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/31 15:18:49 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  	public:
  		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &source);
		ShrubberyCreationForm(ShrubberyCreationForm const &source);
		void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &bure);
#endif