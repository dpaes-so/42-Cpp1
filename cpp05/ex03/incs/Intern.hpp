/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:19:44 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/31 15:18:49 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
#include "AForm.hpp"

class Bureaucrat;

class Intern
{
  	public:
  		Intern();
		Intern(std::string target);
		~Intern();
		Intern &operator=(Intern const &source);
		Intern(Intern const &source);
		AForm *makeForm(std::string form_req,std::string target);
};

#endif