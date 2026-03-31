/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:19:44 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/31 15:18:49 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
  	public:
  		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &source);
		PresidentialPardonForm(PresidentialPardonForm const &source);
		void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &bure);
#endif